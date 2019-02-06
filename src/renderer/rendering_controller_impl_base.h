#ifndef rendering_controller_impl_base
#define rendering_controller_impl_base

#include "../skeleton/service.h"

#include <cassert>
#include <string>
#include <map>

class LeRenderingControllerImplBase// : public LeService<LeRenderingControllerImplBase>
{
    public:
        virtual void enter_event_loop() {
            assert(0);
            while ( !need_to_quit() && is_enought_time_passed() ) {
                process_events();
                process_drawing();
            }
        }

        virtual  bool need_to_quit()  { } 
        virtual  bool is_enought_time_passed(){ }
        virtual  void process_events() { } ;
        virtual  void process_drawing(){ }
        
    		//set/various
        virtual void set_drawing_color(int r, int g, int b){ }
		virtual void set_background_image(const char* path){ }
        virtual bool has_intersetion(int y1, int x1, int h1, int w1, int y2, int x2, int h2, int w2 ){ }
		
        //text
        virtual void draw_text(const char* s, unsigned int y, unsigned int x, unsigned int sy, unsigned int sx){ }	
    
        //shape
        virtual void draw_point(unsigned int y, unsigned int x, unsigned int radius){ }
		virtual void draw_line(unsigned int y1, unsigned int x1, unsigned int y2, unsigned int x2){ }
		virtual void draw_square(unsigned int y, unsigned int x, unsigned int delta){ }
		virtual void draw_rect(unsigned int y, unsigned int x, unsigned int delta2, unsigned int delta1 ){ }
		virtual void draw_circle(unsigned int y, unsigned int x, int radius){ }
		
        //image
        virtual void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph){ }
		virtual void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph, double angle, bool needflip, unsigned int flipdir){ }	
	
        //background
        virtual void draw_static_background(){ }
        virtual bool draw_scroll_background(unsigned int delta){ }
        
        //zoom
        virtual void zoomin(int factor){ }
        virtual void zoomout(int factor){ }
        virtual void fzoomin(int step){ }
        virtual void fzoomout(int step){ }
        
        //pan
        virtual void pan_up(int step){ }
        virtual void pan_down(int step){ }
        virtual void pan_left(int step){ }
        virtual void pan_right(int step){ }
        virtual void pan_to_x_y(int x, int y){ }

		virtual std::pair<std::string, std::pair<unsigned int,unsigned int> > register_image(const char* ipath){ }

        virtual int t_x(int x){ }
        virtual int t_y(int y){ }
};

#endif
