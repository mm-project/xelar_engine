#ifndef menu_state_h
#define menu_state_h

#include <cassert>

#include "state_manager.h"
#include "menu.h"
#include "object.h"
#include "game_settings.h"

/*
	m_req = new Request(Requester::Type::GET,m_req_str,
								 std::bind(&SimpleGetHandler::on_error, this, std::placeholders::_1),
								 std::bind(&SimpleGetHandler::on_pass, this, std::placeholders::_1)
								 );
   std::bind(&LeMenuState::on_error, this, std::placeholders::_1)								 
*/
								 
class LeMenuState : public LeInterLayer
{
	virtual void init() {
		SDL_Log("LeMenuState: init");
		m_current_item = 0;
		
		//*
			m_top_menu.add_item(LeObj(register_image("./bin/play.png"),100,210,3,3));
			m_top_menu.add_item(LeObj(register_image("./bin/play1.png"),190,210,3,3))->add_submenu(&m_settings_menu);
			m_top_menu.add_item(LeObj(register_image("./bin/play2.png"),280,210,3,3));
			m_top_menu.add_item(LeObj(register_image("./bin/play3.png"),360,210,3,3));
			
			
			
			//m_settings_menu.add_item(LeObj(register_image("./bin/play.png"),100,210,3,3),std::bind(&LeGameSettings::turnoff_sound, this, std::placeholders::_1));
			m_settings_menu.add_item(LeObj(register_image("./bin/play.png"),190,210,3,3))->add_submenu(&m_top_menu);
					
			
		m_current_menu = m_top_menu;	
			/**/
	}
	
	
	virtual void draw() {
		//set_drawing_color(255,0,0);
		//draw_rect(0,0,100,100);
		//LOG("LeMenuState: draw\n");
		//set_drawing_color(255,255,0);
		
		draw_highlights();
		draw_menu(m_current_menu);
	}

	void draw_highlights() {
		if(m_current_item)
			highligt_menu_item(m_current_item);
	}
	
	virtual void update(unsigned int currentTime) {
			
	
	}

	virtual void notify_mouse_pressed(unsigned int) {
		SDL_Log("===LeMenuState: notify_mouse_pressed\n");
		//LeStateManager::get()->set_state(ST_GAME);
		if ( !m_current_item ) return;
		if ( m_current_item->has_submenu() )
			m_current_menu = *m_current_item->get_submenu();
		else
			m_current_item->execute_action();
		//if ( m_menu->on_clied(1,22) )
		//m_current_menu = 
			
	}
	
	virtual void notify_key_pressed(unsigned int) {
			//LOG("LeMenuState: notify_key_pressed\n");
			
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
		//LOG("LeMenuState: notify_mouse_moved\n");
		m_current_item = 0;
		if ( LeMenuItem* i = m_current_menu.get_item_by_pos(y,x) )
			m_current_item = i;
	}
	

private:
	
	void draw_menu(const LeMenu& menu) {
		std::vector<LeMenuItem*> vec = menu.get_items();
		for(int i = 0; i<vec.size(); ++i) {
			draw_menu_item(vec[i]);
		}
	}
	
	void draw_menu_item(LeMenuItem* i) {
		//draw_rect(i.get_object()*100,100,30,100);
		if(!i) return;
		LeObj obj = i->get_object();
		draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
	}

	void highligt_menu_item(LeMenuItem* i) {
		//SDL_Log("Highlit item %p",(void*)i);
		//assert(0);
		if(!i) return;
		LeObj obj = i->get_object();
		set_drawing_color(255,255,0);
		draw_rect(obj.m_x,obj.m_y,obj.m_height,obj.m_width);
		
		//draw_rect(0,0,10,10);
		
		//draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
	}
	
	
private:
	LeMenu m_current_menu;
	LeMenu m_top_menu;
	LeMenu m_settings_menu;
	
	LeMenuItem* m_current_item;
	

	
	
};

#endif