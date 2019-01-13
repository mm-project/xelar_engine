#ifndef game_state_h
#define game_state_h

#include "state_manager.h"
#include "object.h"
#include "image.h"
#include "timer.h"
#include "mover.h"
#include "player.h"
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
        LeResourceManager m_resources;
		
        unsigned int m_pressed_x; 
		unsigned int m_pressed_y;
		
		unsigned int m_x; 
		unsigned int m_y;
		
		
		LePlayer m_player;

        LeObj m_current_trouble_obj;
		std::vector<LeObj> m_coins;
		std::vector<LeObj> m_enemies;
		std::vector<LeImg> m_imgs;
		
		LeTimer m_timer; 
		
		bool m_is_gameover;
		unsigned int m_current_score;
		unsigned int m_current_time;
	
        unsigned int m_last_background_update;
        unsigned int m_background_delta;
        bool m_need_backround_update;

        unsigned int m_last_coin_created;
    
        
};

#endif
