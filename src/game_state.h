#ifndef game_state_h
#define game_state_h

#include "state_manager.h"
#include "object.h"
#include "image.h"
#include "timer.h"


#include <vector>

class LeGameState : public LeInterLayer
{
	public:
		LeGameState();	
	

	public:
		virtual void init();
		virtual void draw();
		virtual void update(unsigned int t);
		
		
		virtual void notify_mouse_pressed(unsigned int);
		virtual void notify_key_pressed(unsigned int);
		virtual void notify_mouse_move(unsigned int x, unsigned int y);
	
	
	private:
		void set_timer_checkpoints();

	private:
		void draw_boundaries();
		void draw_obj(LeObj& obj);
		void draw_obj_in_movement(LeObj& obj);
		void draw_obj_in_movement2(LeObj& obj);
		void draw_player();
		void draw_enemies();
		void draw_bonuses();
		void draw_info();
	
	private:
		void update_player();
		void update_enemies();
		void update_fast_enemies();
		void update_slow_enemies();
		void update_automove_object(LeObj& obj, bool rand);
		void update_automove_object2(LeObj& obj);
		void update_object_position(LeObj& obj);
		void check_intersection();
	
	private:	
		void rand_position(LeObj& o);
		void rand_line(LeObj& o);
	
	
	private:	
		unsigned int m_pressed_x; 
		unsigned int m_pressed_y;
		
		unsigned int m_x; 
		unsigned int m_y;
		
		
		LeObj m_player;
		LeObj m_current_trouble_obj;
		std::vector<LeObj> m_coins;
		std::vector<LeObj> m_enemies;
		std::vector<LeImg> m_imgs;
		
		LeTimer m_timer; 
		
		bool m_is_gameover;
		unsigned int m_current_score;
		unsigned int m_current_time;

};

#endif