#ifndef menuitem_drawer_base_h
#define menuitem_drawer_base_h

#include "menuitem.h"
#include "object.h"

#include "../renderer/sdl_wrapper.h"

class LeMenuItemDrawerBase
{
    public:

        virtual void draw_menu_item(LeMenuItem* i) {
            //TODO exception/error handling?
            if(!i) return;
            LeObj obj = i->get_object();
            LeSdlWrapper::m_renderer_controller->draw_image(obj.m_img_path.c_str(),obj.m_x,obj.m_y,obj.m_c_x,obj.m_c_y);
        }

};



#endif

