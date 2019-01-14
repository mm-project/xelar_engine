#ifndef player_h
#define player_h

#include "../skeleton/mover.h"
#include "../skeleton/resource_manager.h"
#include "../skeleton/image_object.h"

#include "../renderer/sdl_wrapper.h"

class LePlayer : public LeImageObject 
{
    public:
        
        LePlayer():LeImageObject(IMG_PLAYER,100,100,16,16) {
            init_player();
        }

    public:
        void init_player()
        {
            m_lifes = 5;
            
            m_is_vulnarable = true;
            m_is_hit = false;
            m_need_to_draw = true;
            m_player_hit = false;

            m_last_blink_time = 0;
            m_last_hit_time = 0;
        }

        void update(unsigned int) {
            m_mover.move(m_obj);
        }

        bool damage() {
            set_player_vulnarable();
            if (--m_lifes);
                return true;
            return false;
        }

        void set_player_vulnarable() {
            m_is_vulnarable = true;
            m_is_hit = false;
        }

        bool is_vulnarable() {
            return m_is_vulnarable;
        }

        void draw() {
            if( m_player_hit ) 
                //id damaged, draw me blinking
                if ( m_need_to_draw ) 
                    draw_obj_in_movement2();
                else
                    return;
            draw_obj_in_movement2();
        }


    private:
        unsigned int m_lifes;
		
        bool m_is_vulnarable;
		bool m_is_hit;
		bool m_need_to_draw;
        bool m_player_hit;

        unsigned int m_last_blink_time;
        unsigned int m_last_hit_time;

        LeObjMover<MV_STRAIGHT> m_mover;
};



#endif
