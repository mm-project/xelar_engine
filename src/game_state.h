#ifndef game_state_h
#define game_state_h

#include "state_manager.h"
#include <cassert>

class LeGameState : public LeInterLayer
{
	/*public:

	LeGameState() {
			register_image("./bin/debilik.png");
	}
	*/
	
	virtual void init() {
			register_image("./bin/debilik.png");

			SDL_Log("LeGameState: init");
			m_clicked = true;
			
			m_update_time = 0;
			
			m_x = 0;
			m_y = 0;
			m_size = 10;
			
			rect_size = 50;
			rect_x = 0;
			rect_y = 0;
			
			
			old_rect_x = 0;
			old_rect_y = 0;
			
			m_refresh_enemy_time = 10;
			
			rand_position();
	}
	
	
	virtual void draw() {
			SDL_Log("LeGameState: draw");

			draw_image("./bin/debilik.png",old_rect_x,old_rect_y,5,5);
		}
	
	
	virtual void update(unsigned int t) {
			//assert(0);
			if ( t > m_update_time + m_refresh_enemy_time ) {
				//assert(0);
				update_debilik_position();
				if ( old_rect_x == rect_x && old_rect_y == rect_y ) {
					//assert(0);
					rand_position();
				}
			
				m_update_time = t;
			}
			
			
		//m_clicked = !m_clicked;
	}

	virtual void notify_mouse_pressed(unsigned int) {
			SDL_Log("LeGameState: notify_mouse_pressed");
			m_clicked = !m_clicked;
	}
	
	virtual void notify_key_pressed(unsigned int) {
			SDL_Log("LeGameState: notify_key_pressed");
			LeStateManager::get()->set_state(ST_MENU);
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			SDL_Log("LeGameState: notify_mouse_moved");
			m_x = x;
			m_y = y;
			
	}
	
	private:
		void update_debilik_position() {
			if ( rect_x < old_rect_x  ) old_rect_x--;
			if ( rect_x > old_rect_x  ) old_rect_x++;
			if ( rect_y < old_rect_y  ) old_rect_y--;
			if ( rect_y > old_rect_y  ) old_rect_y++;
				
		}
		
		void rand_position() {
				rect_x = rand()%200;
				rect_y = rand()%200;
		}
		
		bool check_intersection() {
				return ( ( rect_x-rect_size < m_y-m_size ) && ( rect_x+rect_size > m_y+m_size ) 
					&&  ( rect_y-rect_size < m_x-m_size ) && ( rect_y+rect_size > m_x+m_size ) 
				);
		}
				
	
		void render_hud() {
			set_drawing_color(255,255,255);
			draw_rect(400,0,100,800);
			
		}
		
		
		void update_hud() {
		
		}
		
	private:
		bool m_clicked;
		unsigned int m_x; 
		unsigned int m_y;
		unsigned int m_size;

		unsigned int rect_x; 
		unsigned int rect_y;
		unsigned int rect_size; 
		
		unsigned int old_rect_x; 
		unsigned int old_rect_y;
		
		unsigned int m_refresh_enemy_time;
		
		unsigned int m_update_time;

		
	
};

#endif