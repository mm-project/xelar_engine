#ifndef menu_state_h
#define menu_state_h

#include "state_manager.h"
#include "menu.h"

class LeMenuState : public LeInterLayer
{
	virtual void init() {
			SDL_Log("LeMenuState: init");
			
				m_top_menu.add_item(LeObject("Play");
				m_top_menu.add_item("Settings");
				m_top_menu.add_item("About");
				m_top_menu.add_item("Exit");
				
				
			m_current_menu = top_menu;	
	}
	
	virtual void draw() {
			//set_drawing_color(255,0,0);
			//draw_rect(0,0,100,100);
			//LOG("LeMenuState: draw\n");
			set_drawing_color(255,255,0);
			draw_menu(m_current_menu);
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
			//LOG("LeMenuState: notify_mouse_moved\n");
			//m_menu->
                        
	}
	

private:
	void draw_menu(LeMenu& menu) {
		std::vector<LeMenuItem*> vec = menu.get_items();
		for(int i = 0; i<vec.size(); ++i) {
			SDL_Log("aaaaaaaaaa\n");
			
			draw_rect(i*100,100,30,100);
		}
		SDL_Log("1111\n");
			
	}
	
private:
	LeMenu m_current_menu;
	LeMenu m_top_menu;
	LeMenu m_settings_menu;
	

	
	
};

#endif