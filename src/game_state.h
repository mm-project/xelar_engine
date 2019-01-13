#ifndef game_state_h
#define game_state_h

#include "state_manager.h"
#include "object.h"
#include "image.h"
#include "timer.h"
#include "mover.h"
#include "player.h"
#include "background.h"
#include "resource_manager.h"

#include <vector>

class LeGameState : public LeInterLayer
{
	public:
		LeGameState();	
	

	public:
		virtual void init();
		virtual void draw();
		virtual void update(unsigned int t);
		
		
	public:		
		virtual void notify_mouse_pressed(unsigned int);
		//virtual void notify_key_pressed(unsigned int);
		//virtual void notify_mouse_move(unsigned int x, unsigned int y);
	
	
	private:
		void set_timer_checkpoints();
        //LeImg get_rsc(LeImageName name);

    //creates
    private:
		//void create_world();
		//void create_enemies();

	//initid
    private:
		//void init_player();
		void init_world();
		//void init_enemies();
        
	//draws	
	private:
        //void draw_background();
        //void draw_player();
	
	//updates
	private:
        void update_player();
	

    private:
		//void check_intersection();
		
	
	private:	
		LeTimer m_timer; 

        LePlayer m_player;
        LeBackground m_background;
        
        LeObj m_current_trouble_obj;
		std::vector<LeObj> m_coins;
		std::vector<LeObj> m_enemies;

		bool m_is_gameover;
		unsigned int m_current_score;
		unsigned int m_current_time;
};

#endif
