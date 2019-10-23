#ifndef interlayer_h
#define interlayer_h

#include "scene_controller.h"
//#include "object.h"

class LeInterLayer : public LeSceneController
{
	public:
		void enter_event_loop() {
            //LeSceneController* scene = LeSceneController::get_current_controller();
            //if (scene)
                //scene->enter_event_loop();
            std::cout << "entering event loop on renderer_controller:" << get_renderer() << std::endl; 
            get_renderer()->enter_event_loop();
        }
        
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
		
        virtual void draw()  { } 
		
		virtual void init() { }
		
		virtual void update(unsigned int) {}	

    public:
        /*void draw_obj_in_movement2(LeObj& obj) {
            draw_image(obj.m_img_path.c_str(),obj.m_old_x,obj.m_old_y,obj.m_c_x,obj.m_c_y,obj.m_angle,obj.m_need_flip,0);//obj.m_flip_mode);
        }
        */
        //public get_last   
        //LeImg LeGameState::get_rsc(LeImageName name) {
        //        return m_resources.get(name);
        //}
        
    //FIXME
    //private:
        uint m_clicked_x; 
        uint m_clicked_y; 
        uint m_cursor_x;
        uint m_cursor_y;
    

        
};


#endif
