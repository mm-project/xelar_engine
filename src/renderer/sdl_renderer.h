#ifndef sdl_renderer_h
#define sdl_renderer_h

#ifdef OS_ANDROID
    #include "SDL_internal.h"
    //#include "SDL_android.h"
    #include "../../../SDL2/src/core/android/SDL_android.h"
#endif

#include "rendering_controller_impl_base.h"
#include "../skeleton/service.h"
#include "../skeleton/common.h"

#include <SDL.h>

#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif

#include <map>
#include <iostream>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

#ifdef OS_ANDROID
    const int SCREEN_RES_W = 1080;
    const int SCREEN_RES_H = 2160;
#else
    const int SCREEN_RES_W = SCREEN_WIDTH;
    const int SCREEN_RES_H = SCREEN_HEIGHT;
#endif


    
typedef std::pair<std::string, std::pair<unsigned int,unsigned int> > ImgInfo;

extern SDL_bool Android_JNI_GetAccelerometerValues(float values[3]);

class LeSdlRenderer : public LeService<LeSdlRenderer> , public LeRenderingControllerImplBase
{
    
    public:
        friend class LeService<LeSdlRenderer>;
        static LeSdlRenderer* m_instance;
        static  LeSdlRenderer* get() {
            if ( ! m_instance ) m_instance = new LeSdlRenderer;
            return m_instance;
        }

    //private:
		LeSdlRenderer();


    public:
		void enter_event_loop();
		
		
        inline unsigned int scr_w() {
            return get_screen_width();
        }

        inline unsigned int scr_h() {
            return get_screen_height();
        }

        unsigned int get_screen_width() {
            return SCREEN_WIDTH;
        }

        unsigned int get_screen_height() {
            return SCREEN_HEIGHT;
        }

        float m_accel_vals[3];
        void gyro_upd()
        {
        #ifdef OS_ANDROID
            Android_JNI_GetAccelerometerValues(m_accel_vals);
            SDL_Log("\nDesplazamiento x: %f desplazamiento y: %f  Desplazamiento z: %f.\n",m_accel_vals[0],m_accel_vals[1],m_accel_vals[2]);
        #endif
        }

        virtual float* get_accel_vals() {
            return m_accel_vals;
        }
    
	public:
		//set/various
        void set_drawing_color(int r, int g, int b);
		void set_background_image(const char* path);
        bool has_intersetion(int y1, int x1, int h1, int w1, int y2, int x2, int h2, int w2 );
		
        void take_snapshot(bool d) {
            //get(d);
        }
        
        SDL_Surface* get(bool d) {
            const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
            const int width = scr_w();
            const int height = scr_h();
            //auto renderer = sdl2Core->GetRenderer();
			if (!morqur_surface)
				morqur_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
            //assert(surface);
            //if (morqur_surface == nullptr) return 0;
            SDL_RenderReadPixels(m_render, NULL, format, morqur_surface->pixels, morqur_surface->pitch);
            if(d) SDL_SaveBMP(morqur_surface, "screenshot.bmp");
            return morqur_surface;
        }

        int getpixel(int y, int x) {
            SDL_Surface* surface = morqur_surface; //get(false);
            if (surface == nullptr) return -1;
            int bpp = surface->format->BytesPerPixel;
            Uint8 *p = (Uint8 *)surface->pixels + t_x(x) * surface->pitch + t_y(y) * bpp;
            Uint8 red, green, blue, alpha;
            SDL_GetRGBA(*(Uint32*)p, surface->format, &red, &green, &blue, &alpha);
            //std::cout << (int)red << " " << (int)green << " " << (int)blue << " " << (int)alpha  << std::endl;
            //SDL_GetRGBA(*p, surface->format, &red, &green, &blue, &alpha);
            return (int)red;
        }
        
        
        //text
        void draw_text(const char* s, unsigned int y, unsigned int x, unsigned int sy, unsigned int sx);	
    
        //shape
        void draw_point(unsigned int y, unsigned int x);
		void draw_line(unsigned int y1, unsigned int x1, unsigned int y2, unsigned int x2);
		void draw_square(unsigned int y, unsigned int x, unsigned int delta);
		void draw_rect(unsigned int y, unsigned int x, unsigned int delta2, unsigned int delta1 );
		void draw_circle(unsigned int y, unsigned int x, int radius);
		
        //image
        void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph);
		void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph, double angle, bool needflip, unsigned int flipdir);	
	
        //background
        void draw_static_background();
        bool draw_scroll_background(unsigned int delta);
        
        //zoom
        void zoomin(int factor);
        void zoomout(int factor);
        void fzoomin(int step);
        void fzoomout(int step);
        
        //pan
        void pan_up(int step);
        void pan_down(int step);
        void pan_left(int step);
        void pan_right(int step);
        void pan_to_x_y(int x, int y);
        
        int t_x(int x);
        int t_y(int y);

	public:
		void render_background_image();
        ImgInfo register_image(const char* ipath);
        std::pair<SDL_Texture*,SDL_Rect> get_image_info(const char* ipath);
        
	private:
		bool init(const char*);
		void close();
		void scene_clear();
		void scene_draw();

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
        
        unsigned int m_bg_texture_width;
        unsigned int m_bg_texture_height;

        unsigned int m_dx;
        unsigned int m_dy;
        
        unsigned int m_kx;
        unsigned int m_ky;
        
        
        SDL_Surface* morqur_surface;
        /*
		#ifdef TEXT_RENDER
			std::map<std::string,std::pair<TTF_Font*,SDL_Rect> > name2font;
		#endif
        */

};



#endif
