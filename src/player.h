#ifndef player_h
#define player_h

#include "mover.h"


class LePlayer
{
    public:
        
        LePlayer() {
            //mover.move();
        }

        //LePlayer(LeObjMoverBase& mover):mover(mover) {
            //mover.move();
        //}
    
    public:
        void update() {
            //mover.move();
        }
        
        void damage();
        
        void set_player_vulnarable() {
            m_is_vulnarable = true;
            m_is_hit = false;
        }
        
    
    private:
        LeObjMoverBase mover;
        unsigned int m_lifes;
		bool m_is_vulnarable;
		unsigned int last_hit_time;
		bool m_is_hit;
		bool m_need_to_draw;
		unsigned int last_blink_time;

};



#endif
