#ifndef sdl_renderer_h
#define sdl_renderer_h

#include "renderer_base.h"

#include <SDL.h>

#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif



const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

class LeSdlRendererManager 
{

	public:
		static LeSdlRendererManager* get();
		
	public:	
		LeSdlRendererManager();


	public:
		SDL_Renderer* get_renderer();
	

	public:
		bool init(const char*);
		void close();
		void scene_clear();
		void scene_draw();
		void set_background_image(const char* path);
		
		unsigned int get_screen_width() {
			return SCREEN_WIDTH;
		}
		
		unsigned int get_screen_height() {
			return SCREEN_HEIGHT;
		}
		
	public:
		void render_background_image();
	
		void draw_text(const char* s, unsigned int y, unsigned int x, unsigned int sy, unsigned int sx);

	private:
		bool init_sdl();
		bool init_sdl_image();
		bool init_sdl_ttf();
		bool create_window(const char* title);

	private:
	#ifdef TEXT_RENDER
		TTF_Font* m_ttf_font;
	#endif	
		SDL_Texture* m_bg_texture;
		SDL_Window* m_window;
		SDL_Renderer* m_render;
		
		bool m_init_success;

	public:	
		static LeSdlRendererManager* m_instance;
};







#endif