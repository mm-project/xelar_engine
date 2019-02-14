#ifndef drawing_rect_h
#define drawing_rect_h

#include "../renderer/interlayer.h"

class LeDrawingRect : public LeInterLayer
{

public:
 
    //LeDrawingRect(int x,int y):m_x(x),m_y(y) {
    LeDrawingRect() {
        //m_old_controller = LeSdlWrapper::m_renderer_controller;
        //LeSdlWrapper::set_rendering_controller(this);
    }
    
    void draw1(int x, int y) {
        std::cout << "draw" << std::endl;
        set_drawing_color(0,255,255);
        draw_circle1(x,y,20);
    }

    ~LeDrawingRect() {
        //LeSdlWrapper::set_rendering_controller(m_old_controller);
    }
    
    void init() {
    }
    
    void draw() {
    }
    
    void update(unsigned int) { }
    void notify_mouse_pressed(unsigned int) {  }
    void notify_key_pressed(unsigned int x) {  }
    void notify_mouse_move(unsigned int x, unsigned int y) { }

    private:
        LeSdlWrapper* m_old_controller;
        int m_x;
        int m_y;
};

#endif
