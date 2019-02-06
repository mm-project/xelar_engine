#ifndef player_h
#define player_h

#include "resources.h"

#include "../skeleton/mover.h"
#include "../skeleton/resource_manager.h"
#include "../skeleton/image_object.h"

#include "../renderer/scene_controller.h"

#include "../physics/physics_manager.h"

class LePlayer : public LeImageObject 
{
    public:
        
        LePlayer():LeImageObject(int(IMG_PLAYER),100,100,16,16) {
            init();
			//m_m = LePhysicsManager::get();

			//b = m_m->create_body(LeBody::Type::DYNAMIC, m_obj.m_width, m_obj.m_height);
        }

    public:
        void init()
        {
            m_lifes = 5;
            
            set_nonvulnarable();
            //m_is_vulnarable = true;
            //m_is_hit = true;
            
            m_need_to_draw = true;
            m_draw_blink_speed = 10;
            m_invulnarability_time = 3000;
            m_last_blink_time = 0;
            m_last_hit_time = 0;
        }

        void update(unsigned int t) {
            m_current_time = t;
            if ( t > m_last_blink_time + m_draw_blink_speed ) {
                m_need_to_draw=!m_need_to_draw;
                m_last_blink_time = t;
            }
            
            if ( !m_is_vulnarable && t > m_last_hit_time + m_invulnarability_time ) {
                set_vulnarable();
            }
		
            //m_mover.move(m_obj);
			//m_m->update();

			//m_obj.m_old_y = b->get_current_x();
			//m_obj.m_old_x = b->get_current_y();
        }

        bool damage() {
            if (!m_is_vulnarable)
                return false;
                
            //killed if m_lifes is 0
            if (--m_lifes)
                return true;
            else
                m_last_hit_time = m_current_time;
                set_nonvulnarable();            
                return false;
        }

        void set_nonvulnarable() {
            m_is_vulnarable = false;
            m_is_hit = true;
        }

        void set_vulnarable() {
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
		//LeBody* b;
		//LePhysicsManager* m_m;


        unsigned int m_last_blink_time;
        unsigned int m_last_hit_time;
        unsigned m_invulnarability_time;
        unsigned int m_draw_blink_speed;
        unsigned int m_current_time;

        LeObjMover<MV_STRAIGHT> m_mover;
};



#endif
