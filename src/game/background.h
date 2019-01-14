#ifndef image_background_h
#define image_background_h

#include "../skeleton/mover.h"
#include "../renderer/sdl_wrapper.h"
#include <iostream>

class LeBackground
{
    
public:
    LeBackground() {
    }
    
    void init() {
        //LeSdlWrapper::m_renderer_controller->set_background_image("sky_bg.png");
        m_last_update = 0;
        m_need_update = true;
        m_delta = 0;
    }
    
    void update(unsigned int t) {
        if ( t > m_last_update + 20 ) {
            m_last_update = t;
            m_need_update = true;
        }
    }

    void draw() {
        if ( m_need_update ) {
            m_need_update = false;
            m_delta = m_delta + 1;
        }
        
        if ( LeSdlWrapper::m_renderer_controller->draw_scroll_background(m_delta) )
            m_delta = 0;
    }
    
    
private:
    unsigned int m_last_update;
    bool m_need_update;
    unsigned m_delta;
    
    
};

#endif
