#ifndef sdl_wrapper_h
#define sdl_wrapper_h

#include "common.h"
#include "renderer_base.h"
#include "sdl_renderer.h"


#include <map>
#include <string>

#include <SDL.h>

#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif


class LeSdlWrapper : public LeRenderBase , public LeEventControllerBase
{

	public:
		LeSdlWrapper();


	public:
		virtual void enter_event_loop();
		
		unsigned int scr_w() {
			return m_render_manager->get_screen_width();
		}

		unsigned int scr_h() {
			return m_render_manager->get_screen_height();
		}
		
		
		bool has_intersetion(uint y1, uint x1, uint h1, uint w1, uint y2, uint x2, uint h2, uint w2 ) {
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

	public:
		std::pair<std::string, std::pair<unsigned int,unsigned int> > register_image(const char* ipath);


	private:
		//todo more clever way?
		//void register_font(const char* ipath);
		
		SDL_Renderer* m_render;
		LeSdlRendererManager* m_render_manager;
		std::map<std::string,std::pair<SDL_Texture*,SDL_Rect> > name2texture;
		#ifdef TEXT_RENDER
			std::map<std::string,std::pair<TTF_Font*,SDL_Rect> > name2font;
		#endif

	public:
		static LeSdlWrapper* m_renderer_controller;

};



#endif