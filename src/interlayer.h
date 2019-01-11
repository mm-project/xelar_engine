#ifndef interlayer_h
#define interlayer_h

#include "sdl_wrapper.h"
#include "object.h"

class LeInterLayer : public LeSdlWrapper
{
	public:
		///rendering interlayer
		//virtual void scene_prepare() { draw(); } ;
		
		//controlls interlayer
		virtual void notify_mouse_pressed(unsigned int) = 0;
		virtual void notify_key_pressed(unsigned int) = 0;
		virtual void notify_mouse_move(unsigned int x, unsigned int y) = 0;
		
		virtual void draw() = 0;
		virtual void init() = 0;
		virtual void update(unsigned int) = 0;	

    public:
        void draw_obj_in_movement2(LeObj& obj) {
            draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
        }

        
};


#endif
