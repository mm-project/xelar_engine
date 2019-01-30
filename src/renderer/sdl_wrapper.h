#ifndef sdl_wrapper_h
#define sdl_wrapper_h

#include "../skeleton/common.h"
#include "renderer_base.h"
#include "sdl_renderer.h"


#include <iostream>
#include <map>
#include <string>

#include <SDL.h>

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
		
        void draw_point(unsigned int y, unsigned int x, unsigned int radius);
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
    
        SDL_Surface* get() {
            const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
            const int width = 640;
            const int height = 400;
            //auto renderer = sdl2Core->GetRenderer();

            SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
            SDL_RenderReadPixels(m_render, NULL, format, surface->pixels, surface->pitch);
             SDL_SaveBMP(surface, "screenshot.bmp");
            return surface;
        }

        void getpixel(int x, int y) {
            
            SDL_Surface* surface = get();
            int bpp = surface->format->BytesPerPixel;
            Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

            Uint8 red, green, blue, alpha;

            SDL_GetRGBA(*p, surface->format, &red, &green, &blue, &alpha);

            std::cout << (int)red << " " << (int)green << " " << (int)blue << " " << (int)alpha  << std::endl;

        }
        
	public:
		std::pair<std::string, std::pair<unsigned int,unsigned int> > register_image(const char* ipath);

    private:
        inline int t_x(int x);
        inline int t_y(int y);


	private:
		//todo more clever way?
		//void register_font(const char* ipath);
		
		SDL_Renderer* m_render;
        
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
		static LeSdlWrapper* m_renderer_controller;

};



#endif
