#ifndef player_h
#define player_h

#include "mover.h"
#include "sdl_wrapper.h"
#include "resource_manager.h"

class LePlayer //: public LeImageObject 
{
    public:
        
        LeImg get_rsc(LeImageName name) {
                return LeResourceManager::get()->get(name);
        }

        LePlayer() {
            m_obj = LeObj(get_rsc(IMG_PLAYER),100,100,16,16);
            init_player();
            
        }

        //LePlayer(LeObjMoverBase& mover):mover(mover) {
            //mover.move();
        //}
    
    public:
        void init_player()
        {
        }

        void update() {
            m_mover.move(m_obj);
        }

        void damage() {
            set_player_vulnarable();
            m_lifes--;
            //if ( m_lifes ) 
                //notify_dead();
            
        }
        
        
        void set_player_vulnarable() {
            m_is_vulnarable = true;
            m_is_hit = false;
        }

        void set_destination(unsigned int x, unsigned int y) {
            m_obj.m_x = x;
            m_obj.m_y = y;
        }

        void draw() {
            if( m_player_hit) 
                //id damaged, draw me blinking
                if ( m_need_to_draw ) 
                    draw_obj_in_movement2(m_obj);
                else
                    return;
            draw_obj_in_movement2(m_obj);
        }

        void draw_obj_in_movement2(LeObj& obj) {
            LeSdlWrapper::m_renderer_controller->draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
        }

    private:
        //LeRenderer m_renderer;
        //LeObjMoverBase mover;
        
        unsigned int m_lifes;
		
        bool m_is_vulnarable;
		bool m_is_hit;
		bool m_need_to_draw;
        bool m_player_hit;

        unsigned int m_last_blink_time;
        unsigned int m_last_hit_time;

        LeObj m_obj;
        LeObjMover<MV_STRAIGHT> m_mover;
};



#endif
