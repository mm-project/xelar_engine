#ifndef game_state_h
#define game_state_h

#include "state_manager.h"

class LeGameState : public LeInterLayer
{
	virtual void init() {
			SDL_Log("LeGameState: init");
			m_clicked = true;
			
			m_x = 0;
			m_y = 0;
			m_size = 10;
			
			rect_size = 50;
			rect_x = 0;
			rect_y = 0;
			
			m_refresh_time = 300;
	}
	
	
	virtual void draw() {
			SDL_Log("LeGameState: draw");
			set_drawing_color(255,255,0);
			draw_point(m_y,m_x,m_size);

			set_drawing_color(0,0,255);
			if (m_clicked) {			
				set_drawing_color(255,0,0);
			}
			draw_image("./bin/debilik.png",rect_x,rect_y,5,5);
			draw_image("./bin/debilik2.png",m_x,m_y,3,3);
			
			
			//set_drawing_color(255,255,0);
			//draw_line(rect_x, rect_y, m_y, m_x);
			//draw_line(rect_x, rect_y, m_y, m_x);
			//draw_line(0, rect_y, 0, m_x);
			//draw_line(rect_x, 0, m_y, 0);
			render_hud();
		}
	
	
	virtual void update(unsigned int t) {
			update_hud();
			if ( t > m_update_time + m_refresh_time ) {
				rect_x = rand()%400;
				rect_y = rand()%400;
				m_update_time = t;
			}
			
			m_clicked = false;
			if ( check_intersection() )
					m_clicked = true;
					//m_refresh_time = 100000;
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
		
		unsigned int m_refresh_time;
		
		unsigned int m_update_time;

		
	
};

#endif