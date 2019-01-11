#include "image.h"
#include "game_state.h"
#include "interlayer.h"
#include "state_manager.h"
#include "sound_manager.hpp"
#include "mover.h"
#include "player.h"

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <cassert>
#include <cmath>



LeGameState::LeGameState() {	
    m_resources = LeStateManager::get()->get_resource_manager();

	set_timer_checkpoints();
	create_enemies();
	create_world();
	

	m_x = 0;
	m_y = 0;
    m_pressed_x = 0;
    m_pressed_y = 0;
   	
    //m_player.m_x = 0;
	//m_player.m_y = 0;
    
    //LePlayer player(m_rand_mover);
    
}

LeImg LeGameState::get_rsc(LeImageName name) {
    return m_resources.get(name);
}

void LeGameState::create_enemies() {
	m_enemies.push_back(LeObj(get_rsc(IMG_ENEMY1),rand()%600,rand()%700,7,7));
	//m_enemies.push_back(LeObj(get_rsc(1),rand()%600,rand()%700,5,5));
	m_enemies.push_back(LeObj(get_rsc(IMG_ENEMY2),rand()%600,rand()%700,6,6));
	m_enemies.push_back(LeObj(get_rsc(IMG_ENEMY3),rand()%600,rand()%700,4,4));
}

void LeGameState::create_world() {
	for(int i=0; i<30; i++ ) {
		//m_coins.push_back(LeObj(get_rsc(IMG_COIN),rand()%500,rand()%500,13,13));
		m_coins.push_back(LeObj(get_rsc(IMG_COIN),rand()%(scr_h()),rand()%(scr_w()+600),13,13));        
	}	
}

void LeGameState::LeGameState::init() {
	SDL_Log("LeGameState: init");

    LeSoundManager::get()->play(MUS_GAME);
	init_player();
	init_enemies();
	init_world();
    //m_rand_mover.set_obj(m_player);
}

void LeGameState::init_player()
{
	//m_player = LePlayer(LeObj(get_rsc(IMG_PLAYER),100,100,16,16));
	
    m_last_blink_time = 0;
    m_last_background_update = 0;
    m_background_delta = 1;
   
}

void LeGameState::init_world()
{
    m_need_backround_update = true;
	m_is_gameover = false;
	m_current_score = 0;
	m_current_time = 0;
    m_last_coin_created = 0;
	
	m_coins.clear();
	create_world();
	set_background_image("sky_bg.jpg");
}

void LeGameState::init_enemies()
{
	//rand_position(m_enemies[0]);
	//rand_position(m_enemies[1]);
	//rand_position(m_enemies[2]);

}

void LeGameState::draw() {
	//SDL_Log("LeGameState: draw");
	//draw_background();
    //draw_bonuses();
	//draw_enemies();
	//draw_boundaries();
	//draw_info();
	//draw_player();
    //draw_line(m_y,m_x,m_player.m_y,m_player.m_x);
}

void LeGameState::draw_background() {
    if ( m_need_backround_update ) {
        m_need_backround_update = false;
        m_background_delta = m_background_delta + 1;
    }
    
    if ( LeSdlWrapper::draw_scroll_background(m_background_delta) )
        m_background_delta = 0;
}

/*
void LeGameState::draw_obj_in_movement2(LeObj& obj) {
	draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
}
*/

/*
void LeGameState::draw_player() {
	if( m_player_hit) 
		if ( m_need_draw_player ) 
			draw_obj_in_movement2(m_player);
		else
			return;
		
	draw_obj_in_movement2(m_player);
	
	/*if ( m_is_gameover ) {
		set_drawing_color(255,255,0);
		draw_rect(m_current_trouble_obj.m_old_x,m_current_trouble_obj.m_old_y,m_current_trouble_obj.m_height,m_current_trouble_obj.m_width);		
		set_drawing_color(0,255,0);
		draw_rect(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width);	
	}
}
*/
/*
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



void LeGameState::draw_enemies() {
	//std::for_each(m_enemies.begin(),m_enemies.end(), std::bind1st(std::mem_fun(&LeGameState::draw_obj_in_movement), this));
	for(int i=0;i<m_enemies.size();i++) draw_obj_in_movement(m_enemies[i]);
}


void LeGameState::draw_bonuses() {
	//std::for_each(m_enemies.begin(),m_enemies.end(),draw_obj_in_movement);
	for(int i=0;i<m_coins.size();i++) {
        draw_obj(m_coins[i]);
    }
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
		draw_image("live.png",endy/3,endx+i*50,5,5);
	

   
}
*/

void LeGameState::update(unsigned int t) {
	
	if (! m_is_gameover ) {
		m_timer.step(t);
		m_current_time=+t;
		
        //if ( !m_player.is_vulnarable() && t > m_player.last_hit_time() + 3000 ) {
		//	m_player.set_vulnarable();
		//}
		
		//if ( t > last_blink_time + 100 ) {
			//LOG("m_need_draw_player %d \n",m_need_draw_player);	
			//std::cout << "aaaaaa" << m_need_draw_player << std::endl;
		//	m_need_draw_player=!m_need_draw_player;
		//	last_blink_time = t;
		//}
		
		//if ( t > m_last_background_update + 20 ) {
        //    update_coins();
        //    m_last_background_update = t;
        //    m_need_backround_update = true;
        //}
        
		if ( t > m_last_coin_created + 300 ) {
                if ( rand()%14 == 3 )
                    m_coins.push_back(LeObj(get_rsc(IMG_COIN),rand()%scr_h(),scr_w()+rand()%scr_w(),13,13));
            m_last_coin_created = t;
        }
        
	}
	
}

/*
void LeGameState::update_coins() {
	for(int i=0;i<m_coins.size();i++) {
        m_coins[i].m_y=m_coins[i].m_y-1;
    }
}

void LeGameState::update_fast_enemies() {
    //m_rand_mover.move(m_player);
}


void LeGameState::update_slow_enemies() {
    //m_rand_mover.move(m_player);
}
*/

void LeGameState::set_timer_checkpoints() {
	//m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_player,this),10);
	//m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_fast_enemies,this),200);
	//m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_slow_enemies,this),3000);
	//m_timer.add_continuous_checkpoint(std::bind(&LeGameState::check_intersection,this),10);		
}

#define PI 3.14159265
void LeGameState::notify_mouse_pressed(unsigned int) {
	if (m_is_gameover)  {
		LeStateManager::get()->set_state(ST_MENU);	
		return;
	}	
	m_pressed_x = m_x;
	m_pressed_y = m_y;
	
    //m_player.m_x = m_pressed_y;
	//m_player.m_y = m_pressed_x;
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

/*
void LeGameState::update_player() {
    //m_rand_mover.move(m_player);
}
*/

void LeGameState::check_intersection() {
	//if (!m_is_gameover) 
		return;
	
	/*check
	std::vector<LeObj> delcoins;
	for(  auto it : m_coins ) 
		if (  has_intersetion(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width,it.m_old_x,it.m_old_y,it.m_height,it.m_width) ) 
			delcoins.push_back(it),m_current_score++;


	//erase
	for( int i=0; i<delcoins.size(); ++i )
		m_coins.erase(std::find(m_coins.begin(), m_coins.end(), delcoins[i]));
	*/

	//std::vector<int> delcoins;
	//for(  int i=0; i<m_coins.size(); ++i ) 
		//if ( m_player.is_intersecting_with_other_obj(m_coins[i]) ) 
			//delcoins.push_back(i),m_current_score++;
}
