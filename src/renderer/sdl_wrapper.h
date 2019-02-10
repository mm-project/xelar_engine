#ifndef sdl_wrapper_h
#define sdl_wrapper_h

#include "../skeleton/common.h"
#include "renderer_base.h"
#include "sdl_renderer.h"


#include <iostream>
#include <map>
#include <string>

#include <SDL.h>

#include <cassert>

/*
#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif
*/

class LeSdlWrapper : public LeRenderBase , public LeEventControllerBase
{

	public:
		LeSdlWrapper();

        public:
		virtual void enter_event_loop();
		
        
        int t_x(int x) {
            return m_kx*x+m_dx;
            
        }

        int t_y(int y) {
            return m_ky*y+m_dy;
        }


		inline unsigned int scr_w() {
			return m_render_manager->get_screen_width();
		}

		inline unsigned int scr_h() {
			return m_render_manager->get_screen_height();
		}
		
		
		bool has_intersetion(int y1, int x1, int h1, int w1, int y2, int x2, int h2, int w2 )
		{
			SDL_Rect* A = new SDL_Rect{x1,y1,w1,h1};
			SDL_Rect* B = new SDL_Rect{x2,y2,w2,h2};
			
			int r = SDL_HasIntersection(A,B);
			delete A;
			delete B;
			
			return r;
		}

	public:
		static void set_rendering_controller(LeSdlWrapper* controller);

		

	public:
		void set_drawing_color(int r, int g, int b);
		void set_background_image(const char* path);
		
        void draw_text(const char* s, unsigned int y, unsigned int x, unsigned int sy, unsigned int sx);	
		
        void draw_point(unsigned int y, unsigned int x);
		void draw_line(unsigned int y1, unsigned int x1, unsigned int y2, unsigned int x2);
		void draw_square(unsigned int y, unsigned int x, unsigned int delta);
		void draw_rect(unsigned int y, unsigned int x, unsigned int delta2, unsigned int delta1 );
		void draw_circle(unsigned int y, unsigned int x, int radius);
		
        void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph);
		void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph, double angle, bool needflip, unsigned int flipdir);	
		bool draw_scroll_background(unsigned int delta);
        void draw_static_background();
        
        //floats not supported
        //void zoom(float factor);
        
        void zoomin(int factor);
        void zoomout(int factor);
        void fzoomin(int step);
        void fzoomout(int step);
        

        void pan_up(int step);
        void pan_down(int step);
        void pan_left(int step);
        void pan_right(int step);
        void pan_to_x_y(int x, int y);
    
        SDL_Surface* get(bool d) {
            const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
            const int width = scr_w();
            const int height = scr_h();
            //auto renderer = sdl2Core->GetRenderer();
			if (!morqur_surface)
				morqur_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
            //assert(surface);
            if (morqur_surface == nullptr) return 0;
            SDL_RenderReadPixels(m_render, NULL, format, morqur_surface->pixels, morqur_surface->pitch);
            if(d) SDL_SaveBMP(morqur_surface, "screenshot.bmp");
            return morqur_surface;
        }

        int getpixel(int y, int x) {
            SDL_Surface* surface = morqur_surface; //get(false);
            if (surface == nullptr) return -1;
            int bpp = surface->format->BytesPerPixel;
            Uint8 *p = (Uint8 *)surface->pixels + t_y(y) * surface->pitch + t_x(x) * bpp;
            Uint8 red, green, blue, alpha;
            SDL_GetRGBA(*(Uint32*)p, surface->format, &red, &green, &blue, &alpha);
            std::cout << (int)red << " " << (int)green << " " << (int)blue << " " << (int)alpha  << std::endl;
            //SDL_GetRGBA(*p, surface->format, &red, &green, &blue, &alpha);
            return (int)red;
        }
        
        
        

	public:
		std::pair<std::string, std::pair<unsigned int,unsigned int> > register_image(const char* ipath);

    //private:
    //    int t_x(int x);
    //     int t_y(int y);


	private:
		//todo more clever way?
		//void register_font(const char* ipath);
		
		SDL_Renderer* m_render;
		SDL_Surface* morqur_surface;
        
        SDL_Texture* m_bg_texture;
        unsigned int m_bg_texture_width;
        unsigned int m_bg_texture_height;
        
		LeSdlRendererManager* m_render_manager;
        

        unsigned int m_dx;
        unsigned int m_dy;
        
        unsigned int m_kx;
        unsigned int m_ky;
        
        
        /*
        std::map<std::string,std::pair<SDL_Texture*,SDL_Rect> > name2texture;
		#ifdef TEXT_RENDER
			std::map<std::string,std::pair<TTF_Font*,SDL_Rect> > name2font;
		#endif
        */
public:
        //TODO REMOVE
        void draw_circle1(unsigned int y, unsigned int x, int radius)
        {
            
            //SDL_RenderClear(  LeSdlRendererManager::get()->get_renderer() );
            SDL_SetRenderDrawColor( LeSdlRendererManager::get()->get_renderer(), 255, 0, 0, 0xFF );
            for (int w = 0; w < radius * 2; w++) {
                for (int h = 0; h < radius * 2; h++) {
                    int dx = radius - w; // horizontal offset
                    int dy = radius - h; // vertical offset
                    if ((dx*dx + dy*dy) <= (radius * radius)) {
                        SDL_RenderDrawPoint(LeSdlRendererManager::get()->get_renderer(), x+dx, y+dy);
                    }
                }
            }
            SDL_RenderPresent( LeSdlRendererManager::get()->get_renderer() );
        }
    
	public:
		static LeSdlWrapper* m_renderer_controller;

};



#endif
