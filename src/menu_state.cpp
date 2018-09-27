#include "menu_state.h"
#include "state_manager.h"

void LeMenuState::init() {
	SDL_Log("LeMenuState: init");
	m_current_item = 0;

	m_top_menu.add_item(LeObj(register_image("play.png"),100,210,3,3));
	
	/*
		m_top_menu.add_item(LeObj(register_image("play.png"),100,210,3,3));

		m_top_menu.add_item(LeObj(register_image("play.png"),100,210,3,3));
		m_top_menu.add_item(LeObj(register_image("play1.png"),190,210,3,3))->add_submenu(&m_settings_menu);
		m_top_menu.add_item(LeObj(register_image("play2.png"),280,210,3,3));
		m_top_menu.add_item(LeObj(register_image("play3.png"),360,210,3,3));
		
		
		
		//m_settings_menu.add_item(LeObj(register_image("./bin/play.png"),100,210,3,3),std::bind(&LeGameSettings::turnoff_sound, this, std::placeholders::_1));
		m_settings_menu.add_item(LeObj(register_image("./bin/play.png"),190,210,3,3))->add_submenu(&m_top_menu);
				
		/**/
		
	m_current_menu = m_top_menu;	
}

void LeMenuState::action_play() {
	LeStateManager::get()->set_state(ST_GAME);
}

void LeMenuState::draw() {
	//set_drawing_color(255,0,0);
	//draw_rect(0,0,100,100);
	//LOG("LeMenuState: draw\n");
	//set_drawing_color(255,255,0);
	
	draw_highlights();
	draw_menu(m_current_menu);
}

void LeMenuState::draw_highlights() {
	if(m_current_item)
		highligt_menu_item(m_current_item);
}

void LeMenuState::update(unsigned int currentTime) {
		

}

void LeMenuState::notify_mouse_pressed(unsigned int) {
	//SDL_Log("===LeMenuState: notify_mouse_pressed\n");
	//LeStateManager::get()->set_state(ST_GAME);
	if ( !m_current_item ) return;
	if ( m_current_item->has_submenu() )
		m_current_menu = *m_current_item->get_submenu();
	else
		action_play();
		//m_current_item->execute_action();
	//if ( m_menu->on_clied(1,22) )
	//m_current_menu = 
		
}

void LeMenuState::notify_key_pressed(unsigned int) {
		//LOG("LeMenuState: notify_key_pressed\n");
		
}

void LeMenuState::notify_mouse_move(unsigned int x, unsigned int y) {
	//LOG("LeMenuState: notify_mouse_moved\n");
	m_current_item = 0;
	if ( LeMenuItem* i = m_current_menu.get_item_by_pos(y,x) )
		m_current_item = i;
}


void LeMenuState::draw_menu(const LeMenu& menu) {
	std::vector<LeMenuItem*> vec = menu.get_items();
	for(int i = 0; i<vec.size(); ++i) {
		draw_menu_item(vec[i]);
	}
}

void LeMenuState::draw_menu_item(LeMenuItem* i) {
	//draw_rect(i.get_object()*100,100,30,100);
	if(!i) return;
	LeObj obj = i->get_object();
	draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
}

void LeMenuState::highligt_menu_item(LeMenuItem* i) {
	//SDL_Log("Highlit item %p",(void*)i);
	//assert(0);
	if(!i) return;
	LeObj obj = i->get_object();
	set_drawing_color(255,255,0);
	draw_rect(obj.m_x,obj.m_y,obj.m_height,obj.m_width);
	
	//draw_rect(0,0,10,10);
	
	//draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
}
	