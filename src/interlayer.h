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
		virtual void notify_mouse_pressed(unsigned int) {  
            m_clicked_x = m_cursor_x;
            m_clicked_y = m_cursor_y;
        }
		virtual void notify_key_pressed(unsigned int) { }
		
		virtual void notify_mouse_move(unsigned int x, unsigned int y) { 
            m_cursor_x = x;
            m_cursor_y = y;
        }
		
		virtual void draw() = 0;
		virtual void init() = 0;
		virtual void update(unsigned int) = 0;	

    public:
        /*void draw_obj_in_movement2(LeObj& obj) {
            draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
        }
        */
        //public get_last   
        //LeImg LeGameState::get_rsc(LeImageName name) {
        //        return m_resources.get(name);
        //}
        
    //private:
        uint m_clicked_x; 
        uint m_clicked_y; 
        uint m_cursor_x;
        uint m_cursor_y;
    

        
};


#endif
