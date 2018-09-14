#ifndef game_state_h
#define game_state_h

#include "state_manager.h"
#include "object.h"

#include <cassert>
#include <vector>
#include <algorithm>

class LeGameState : public LeInterLayer
{
	public:

	//class LeObj;
	
	LeGameState() {
			register_image("./bin/debilik.png");
			register_image("./bin/debilik2.png");
			register_image("./bin/debilik3.png");
			register_image("./bin/debilik4.png");
			
			register_image("./bin/coin.png");
			register_image("./bin/player.png");
	}
	
	
	virtual void init() {
			SDL_Log("LeGameState: init");
			m_clicked = true;
			
			m_update_time = 0;
			
			m_x = 0;
			m_y = 0;
			m_player = LeObj("./bin/player.png",0,0,15,15);
			
			m_refresh_enemy_time = 10;
			
			
			for(int i=0; i<20; i++ ) {
				m_coins.push_back(LeObj("./bin/coin.png",rand()%600,rand()%700,20,20));
			}
			

			m_enemies.push_back(LeObj("./bin/debilik.png",rand()%600,rand()%700,6,6));
			//m_enemies.push_back(LeObj("./bin/debilik2.png",rand()%600,rand()%700,5,5));
			m_enemies.push_back(LeObj("./bin/debilik3.png",rand()%600,rand()%700,6,6));
			m_enemies.push_back(LeObj("./bin/debilik4.png",rand()%600,rand()%700,4,4));
			
			rand_position(m_player);
			rand_position(m_enemies[0]);
			
	}
	
	
	virtual void draw() {
			//SDL_Log("LeGameState: draw");
			draw_bonuses();
			draw_enemies();
			draw_boundaries();
			draw_player();

	}
	
	void draw_boundaries() {
	}
	
	
	void draw_obj(LeObj& obj) {
		draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
	}
	
	void draw_obj1(LeObj& obj) {
		draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y);
	}
	
	
	void draw_player() {
		//draw_image("./bin/player.png",m_y,m_x,15,15);
		draw_obj1(m_player);
		
	}
	
	void draw_enemies() {
		//std::for_each(m_enemies.begin(),m_enemies.end(), std::bind1st(std::mem_fun(&LeGameState::draw_obj1), this));
		for(int i=0;i<m_enemies.size();i++) draw_obj1(m_enemies[i]);
	}
	

	void draw_bonuses() {
		//std::for_each(m_enemies.begin(),m_enemies.end(),draw_obj1);
		for(int i=0;i<m_coins.size();i++) draw_obj(m_coins[i]);
	}
	
	
	virtual void update(unsigned int t) {
			//assert(0);
			if ( t > m_update_time + m_refresh_enemy_time ) {
				//assert(0);
				update_enemies();
				m_update_time = t;
			}
		//m_clicked = !m_clicked;
	}

	virtual void notify_mouse_pressed(unsigned int) {
			//SDL_Log("LeGameState: notify_mouse_pressed");
			m_clicked = !m_clicked;
			m_pressed_x = m_x;
			m_pressed_y = m_y;
			m_player.m_x = m_pressed_y;
			m_player.m_y = m_pressed_x;
			
	}
	
	virtual void notify_key_pressed(unsigned int) {
			//SDL_Log("LeGameState: notify_key_pressed");
			LeStateManager::get()->set_state(ST_PAUSE);
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			//SDL_Log("LeGameState: notify_mouse_moved");
			m_x = x;
			m_y = y;
			
	}
	
	private:
		
		void update_enemies() {
			//update_automove_object(m_enemies[0],true);
			update_automove_object(m_player,false);
			
			for(int i=0;i<m_enemies.size();i++) update_automove_object(m_enemies[i],true);
			//std::for_each(m_enemies.begin(),m_enemies.end(),update_debilik_position);

		}
		
		void  update_automove_object(LeObj& obj, bool rand) {
			update_object_position(obj);
			if ( obj.m_old_x ==obj.m_x && obj.m_old_y ==obj.m_y ) {
				//assert(0);
				if(rand) rand_position(obj);
			}		
		}
		
		void update_object_position(LeObj& obj) {
			if (obj.m_x < obj.m_old_x ) obj.m_old_x--;
			if (obj.m_x > obj.m_old_x ) obj.m_old_x++;
			if (obj.m_y < obj.m_old_y ) obj.m_old_y--;
			if (obj.m_y > obj.m_old_y ) obj.m_old_y++;
		}
		
	
		
		void rand_position(LeObj& o) {
				o.m_x = rand()%500;
				o.m_y = rand()%600;
		}
		
	
		/*
		bool check_intersection(unsigned int x, unsigned int y, unsigned int x1, unsigned int y1) {
				return ( (obj.m_x-rect_size < m_y-m_size ) && (obj.m_x+rect_size > m_y+m_size ) 
					&&  (obj.m_y-rect_size < m_x-m_size ) && (obj.m_y+rect_size > m_x+m_size ) 
				);
		}
				
	
		void render_hud() {
			set_drawing_color(255,255,255);
			draw_rect(400,0,100,800);
			
		}
		
		
		void update_hud() {
		
		}*/
		
	//private:


		
	private:	
		bool m_clicked;
		unsigned int m_pressed_x; 
		unsigned int m_pressed_y;
		
		unsigned int m_x; 
		unsigned int m_y;
		
		//unsigned int m_size;

		
		unsigned int m_refresh_enemy_time;
		unsigned int m_update_time;
		
		LeObj m_player;
		std::vector<LeObj> m_coins;
		std::vector<LeObj> m_enemies;
		
	
};

#endif