#ifndef menu_state_h
#define menu_state_h

#include <cassert>

#include "state_manager.h"
#include "menu.h"
#include "object.h"


class LeMenuState : public LeInterLayer
{
	virtual void init() {
			SDL_Log("LeMenuState: init");
			current_item = 0;
			
			//*
				m_top_menu.add_item(LeObj(register_image("./bin/play.png"),100,100,3,3));
				m_top_menu.add_item(LeObj(register_image("./bin/play1.png"),200,100,3,3));
				m_top_menu.add_item(LeObj(register_image("./bin/play2.png"),300,100,3,3));
				//m_top_menu.add_item(LeObj(register_image("./bin/exit.png")),0,0,10,10);
				
				
			m_current_menu = m_top_menu;	
			/**/
	}
	
	virtual void draw() {
			//set_drawing_color(255,0,0);
			//draw_rect(0,0,100,100);
			//LOG("LeMenuState: draw\n");
			set_drawing_color(255,255,0);
			draw_menu(m_current_menu);
			draw_highlights();
	}

	void draw_highlights() {
			if(current_item)
					highligt_menu_item(current_item);
	}
	
	virtual void update(unsigned int currentTime) {
			
	
	}

	virtual void notify_mouse_pressed(unsigned int) {
			//SDL_Log("===LeMenuState: notify_mouse_pressed\n");
			//LeStateManager::get()->set_state(ST_GAME);
			
			//if ( m_menu->on_clied(1,22) )
			//m_current_menu = 
			
	}
	
	virtual void notify_key_pressed(unsigned int) {
			//LOG("LeMenuState: notify_key_pressed\n");
			
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			LOG("LeMenuState: notify_mouse_moved\n");
			current_item = 0;
			if ( LeMenuItem* i = m_current_menu.get_item_by_pos(x,y) )
				current_item = i;
				//highligt_menu_item(i);
                        
	}
	

private:
	
	void draw_menu(LeMenu& menu) {
		std::vector<LeMenuItem*> vec = m_top_menu.get_items();
		for(int i = 0; i<vec.size(); ++i) {
			draw_menu_item(vec[i]);
			//SDL_Log("aaaaaaaaaa\n");
			
		}
		//SDL_Log("1111\n");
			
	}
	
	void draw_menu_item(LeMenuItem* i) {
		//draw_rect(i.get_object()*100,100,30,100);
		if(!i) return;
		LeObj obj = i->get_object();
		draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
	}

	void highligt_menu_item(LeMenuItem* i) {
		SDL_Log("Highlit item %p",(void*)i);
		//assert(0);
		if(!i) return;
		LeObj obj = i->get_object();
		set_drawing_color(255,255,0);
		//draw_rect(obj.m_x,obj.m_y,obj.m_height+1,obj.m_width+1);
		draw_rect(0,0,10,10);
		
		//draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
	}
	
	
private:
	LeMenu m_current_menu;
	LeMenu m_top_menu;
	LeMenu m_settings_menu;
	
	LeMenuItem* current_item;
	

	
	
};

#endif