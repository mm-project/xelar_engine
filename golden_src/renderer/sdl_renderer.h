#ifndef sdl_renderer_h
#define sdl_renderer_h


#include "renderer_base.h"
#include "../skeleton/service.h"

#include <SDL.h>

#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif

#include <map>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

typedef std::pair<std::string, std::pair<unsigned int,unsigned int> > ImgInfo;

class LeSdlRendererManager : public LeService<LeSdlRendererManager>
{
		
	public:
		friend class LeService<LeSdlRendererManager>;

private:
		LeSdlRendererManager();

		LeSdlRendererManager(const LeSdlRendererManager&);
		LeSdlRendererManager& operator=(const LeSdlRendererManager&);


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
        ImgInfo register_image(const char* ipath);
        std::pair<SDL_Texture*,SDL_Rect> get_image_info(const char* ipath);
        
	private:
		bool init_sdl();
		bool init_sdl_image();
		bool init_sdl_ttf();
		bool create_window(const char* title);

	private:
        std::map<std::string,std::pair<SDL_Texture*,SDL_Rect> > m_name2texture;
        std::map<std::string,SDL_Surface*> m_name2surface;

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
