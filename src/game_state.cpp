#include "game_state.h"
#include "interlayer.h"
#include "state_manager.h"

#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

LeGameState::LeGameState() {	
	//m_resources = LeResourceManager::get();
	
	//m_imgs.push_back(m_resouces->get_image(IMG_ENEMY));
	
	m_imgs.push_back(register_image("debilik.png"));  //0
	m_imgs.push_back(register_image("debilik2.png")); //1
	m_imgs.push_back(register_image("debilik3.png")); //2
	m_imgs.push_back(register_image("debilik4.png")); //3
	
	m_imgs.push_back(register_image("coin.png"));     //4
	m_imgs.push_back(register_image("player.png"));   //5
	m_imgs.push_back(register_image("live.png"));     //6
	
	
	set_timer_checkpoints();
	create_enemies();
	create_world();
	

	m_x = 0;
	m_y = 0;

}

void LeGameState::create_enemies() {
	m_enemies.push_back(LeObj(m_imgs[0],rand()%600,rand()%700,7,7));
	//m_enemies.push_back(LeObj(m_imgs[1],rand()%600,rand()%700,5,5));
	m_enemies.push_back(LeObj(m_imgs[2],rand()%600,rand()%700,6,6));
	m_enemies.push_back(LeObj(m_imgs[3],rand()%600,rand()%700,4,4));
}

void LeGameState::create_world() {
	for(int i=0; i<30; i++ ) {
		m_coins.push_back(LeObj(m_imgs[4],rand()%900,rand()%900,10,10));
	}	
}

void LeGameState::LeGameState::init() {
	SDL_Log("LeGameState: init");
	
	init_player();
	init_enemies();
	init_world();
}

void LeGameState::init_player()
{
	m_player = LeObj(m_imgs[5],0,0,16,16);
	m_lifes = 5;
	m_is_player_vulnarable = true;
}

void LeGameState::init_world()
{

	m_is_gameover = false;
	m_current_score = 0;
	m_current_time = 0;
	
	m_coins.clear();
	create_world();
	set_background_image("sky_bg.jpg");
}

void LeGameState::init_enemies()
{
	rand_position(m_enemies[0]);
	rand_position(m_enemies[1]);
	rand_position(m_enemies[2]);
	///rand_position(m_enemies[3]);

}



void LeGameState::draw() {
	//SDL_Log("LeGameState: draw");
	draw_bonuses();
	draw_enemies();
	draw_boundaries();
	draw_info();
	draw_player();

}

void LeGameState::draw_boundaries() {
}


void LeGameState::draw_obj(LeObj& obj) {
	draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
}

void LeGameState::draw_obj_in_movement(LeObj& obj) {
	draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y);
}


void LeGameState::draw_obj_in_movement2(LeObj& obj) {
	draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
}

void LeGameState::draw_player() {
	//draw_image("player.png",m_y,m_x,15,15);
	draw_obj_in_movement2(m_player);
	if ( m_is_gameover ) {
		set_drawing_color(255,255,0);
		draw_rect(m_current_trouble_obj.m_old_x,m_current_trouble_obj.m_old_y,m_current_trouble_obj.m_height,m_current_trouble_obj.m_width);		
		set_drawing_color(0,255,0);
		draw_rect(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width);	
	}
}

void LeGameState::draw_enemies() {
	//std::for_each(m_enemies.begin(),m_enemies.end(), std::bind1st(std::mem_fun(&LeGameState::draw_obj_in_movement), this));
	for(int i=0;i<m_enemies.size();i++) draw_obj_in_movement(m_enemies[i]);
}


void LeGameState::draw_bonuses() {
	//std::for_each(m_enemies.begin(),m_enemies.end(),draw_obj_in_movement);
	for(int i=0;i<m_coins.size();i++) draw_obj(m_coins[i]);
}


void LeGameState::draw_info() {
	std::stringstream z,z1,z2;
	z << "Score: " << m_current_score << "    Time: " << m_current_time << "    Lifes: ";
	//z1 << "Score: " << m_current_score;
	//z2 << "Time: " << m_current_time;
	
	
	set_drawing_color(255,255,255);
	//draw_rect(400,0,100,800);
	uint starty = scr_h()-100;
	uint startx = 0;

	uint endy = starty+350;
	uint endx = startx+100;
	
	draw_text(z.str().c_str(),starty,startx,endy,endx);
	for(int i=0; i<m_lifes; i++)
		draw_image("live.png",endx/3,endy+i*50,5,5);
	
}

void LeGameState::update(unsigned int t) {
	
	if (! m_is_gameover ) {
		m_timer.step(t);
		m_current_time=+t;
	}
}

void LeGameState::update_fast_enemies() {
	update_automove_object(m_enemies[0],true);
}


void LeGameState::update_slow_enemies() {
	update_automove_object2(m_enemies[1]);
	update_automove_object2(m_enemies[2]);
}


void LeGameState::set_timer_checkpoints() {
	m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_player,this),3);
	m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_fast_enemies,this),200);
	m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_slow_enemies,this),3000);
	m_timer.add_continuous_checkpoint(std::bind(&LeGameState::check_intersection,this),1);		
}

#define PI 3.14159265
void LeGameState::notify_mouse_pressed(unsigned int) {
	//SDL_Log("LeGameState: notify_mouse_pressed");
	//m_clicked = !m_clicked;
	if (m_is_gameover)  {
		LeStateManager::get()->set_state(ST_MENU);	
		return;
	}	
	m_pressed_x = m_x;
	m_pressed_y = m_y;
	m_player.m_x = m_pressed_y;
	m_player.m_y = m_pressed_x;

	
	//*
	if ( m_player.m_x > m_player.m_old_x ) 
	if ( m_player.m_x < m_player.m_old_x ) m_player.m_need_flip = false;
	if ( m_player.m_x < m_player.m_old_x ) m_player.m_need_flip = false;
	
	/**/
	
	//m_player.m_x = m_pressed_y;
	//m_player.m_y = m_pressed_x;
	//m_player.m_angle = 0;
	m_player.m_angle = atan2(m_player.m_x - m_player.m_old_x,m_player.m_y - m_player.m_old_y) * 180 / PI;
	
}

void LeGameState::notify_key_pressed(unsigned int) {
	//SDL_Log("LeGameState: notify_key_pressed");
	//LeStateManager::get()->set_state(ST_PAUSE);
}

void LeGameState::notify_mouse_move(unsigned int x, unsigned int y) {
		//SDL_Log("LeGameState: notify_mouse_moved");
		m_x = x;
		m_y = y;
		
}

void LeGameState::update_player() {

	update_automove_object(m_player,false);
}

void LeGameState::update_enemies() {
	update_automove_object(m_enemies[0],true);
	update_automove_object2(m_enemies[1]);
	update_automove_object2(m_enemies[2]);
	//update_automove_object2(m_enemies[1]);
	
	
	//update_automove_object(m))
	//for(int i=0;i<m_enemies.size();i++) update_automove_object(m_enemies[i],true);
	//std::for_each(m_enemies.begin(),m_enemies.end(),update_debilik_position);
}

void LeGameState:: update_automove_object(LeObj& obj, bool rand) {
	update_object_position(obj);
	if ( obj.m_old_x ==obj.m_x && obj.m_old_y ==obj.m_y ) {
		//assert(0);
		if(rand) rand_position(obj);
	}		
}

void LeGameState:: update_automove_object2(LeObj& obj) {
	update_object_position(obj);
	if ( 0 == obj.m_old_y ) obj.m_old_x = rand()%600;
	if ( obj.m_old_y ==obj.m_y  ) {
		//assert(0);
		rand_line(obj);
	}		
}

void LeGameState::update_object_position(LeObj& obj) {
	if (obj.m_x < obj.m_old_x ) obj.m_old_x--;
	if (obj.m_x > obj.m_old_x ) obj.m_old_x++;
	if (obj.m_y < obj.m_old_y ) obj.m_old_y--;
	if (obj.m_y > obj.m_old_y ) obj.m_old_y++;
}



void LeGameState::rand_position(LeObj& o) {
		o.m_x = rand()%900;
		o.m_y = rand()%900;
}

void LeGameState::rand_line(LeObj& o) {
		o.m_old_y = 1000;
		o.m_y = 0;
		o.m_x = o.m_old_x;
}

void LeGameState::set_player_vulnarable() {
	m_is_player_vulnarable = true;
}

void LeGameState::check_intersection() {
	//if (!m_is_gameover) 
	//	return;
	if ( m_is_player_vulnarable )
		for( auto it : m_enemies )
			if ( has_intersetion(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width,it.m_old_x,it.m_old_y,it.m_height,it.m_width) ) {	
				if ( m_lifes == 0) {
					m_current_trouble_obj = it;
					//m_is_gameover = true;
					return;
				} else {
					m_lifes--;
					m_is_player_vulnarable = false;
					m_timer.add_singleshot_checkpoint(std::bind(&LeGameState::set_player_vulnarable,this),2000);
				}
			}
		
	
	//check
	std::vector<LeObj> delcoins;
	for(  auto it : m_coins ) 
		if (  has_intersetion(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width,it.m_old_x,it.m_old_y,it.m_height,it.m_width) ) 
			delcoins.push_back(it),m_current_score++;


	//erase
	for( int i=0; i<delcoins.size(); ++i )
		m_coins.erase(std::find(m_coins.begin(), m_coins.end(), delcoins[i]));
	

	//std::vector<int> delcoins;
	//for(  int i=0; i<m_coins.size(); ++i ) 
		//if ( m_player.is_intersecting_with_other_obj(m_coins[i]) ) 
			//delcoins.push_back(i),m_current_score++;
	
	//m_coins.erase(remove(m_coins.begin(), m_coins.end(), m_coins[delcoins[i]]), m_coins.end());
	
	//assert(0);	
		//SDL_Log("11111\n");
	//else
		//LOG("22222\n");
	//}
}
