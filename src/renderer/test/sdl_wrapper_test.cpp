#include "../interlayer.h"
#include "../sdl_wrapper.h"
#include "../sdl_wrapper.cpp"
#include "../sdl_renderer.h"
#include "../sdl_renderer.cpp"

#include "../../physics/physics_manager.h"
#include "../../skeleton/resource_manager.h"

#include "../../physics/physics_manager.cpp"
#include "../../skeleton/resource_manager.cpp"

#include "../../skeleton/image.cpp"
#include "../../skeleton/image.h"

class LeSdlWrapperTest: public LeInterLayer 
{
    public:
    
    void draw1() {
        set_drawing_color(255,255,0);
        draw_point(190,190,5);

        set_drawing_color(255,0,255);
        draw_line(60,999,590,10);
        
        set_drawing_color(0,255,255);
		draw_square(0,90,95);
		
        set_drawing_color(0,0,255);
        draw_rect(446,37,48,39 );
        
        set_drawing_color(0,255,0);
		draw_circle(53,49,48);
    }
    
    
};

int main() {

LeSdlWrapperTest w;
//w.draw1();
//w.dump("shot1.bmp");

w.draw_image("../../../bin/coin.png",0,0,100,100);
w.dump("shot2.bmp");

//w->enter_event_loop();

/*
w.set_drawing_color(255,255,0);

        w.draw_point(10,10,5);
		w.draw_line(0,0,10,10);
		w.draw_square(0,0,5);
		w.draw_rect(6,7,8,9 );
		w.draw_circle(3,9,8);
		
        w.dump("shot1.bmp");
*/    
}
