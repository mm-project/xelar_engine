#ifndef sdl_renderer_h
#define sdl_renderer_h

#include "renderer_base.h"

#include <SDL.h>
#include <stdio.h>

#ifdef TEXT_RENDER
	#include <SDL_ttf.h>
#endif

#ifdef IMAGE_RENDER
	#include <SDL_image.h>
#endif


#ifdef DOS_ANDROID
	#define LOG SDL_Log
#else
	#define LOG printf
#endif


#include <string>
#include <map>
#include <utility>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class LeSdlRendererManager 
{

	public:
		//TODO fixme game name in the title

	static LeSdlRendererManager* get() {
		if ( ! m_instance ) m_instance = new LeSdlRendererManager();
		return m_instance;
	}
	
	LeSdlRendererManager(){ //const char* title) {
		init("Game demo");
		change_background_image();
	}


	//TODO redudant set render color?

	SDL_Renderer* get_renderer() {
		return m_render;
	}
	
	//private:

#ifdef TEXT_RENDER
	TTF_Font* m_ttf_font;
#endif	
	SDL_Texture* m_bg_texture;
	SDL_Window* m_window;
	SDL_Renderer* m_render;
	static LeSdlRendererManager* m_instance;

	

	//TODO seperate each init to different inits. 
	bool init(const char* title)
	{
		LOG("init start\n");
		
		bool success = true;

		#ifdef TEXT_RENDER
			if(!TTF_WasInit() && TTF_Init()==-1) {
				LOG("TTF_Init: %s\n", TTF_GetError());
				exit(1);
			}

			m_ttf_font = TTF_OpenFont("./deps/FreeSans.ttf", 10); 
			if(!m_ttf_font) {  
				LOG("TTF_OpenFont: %s\n", TTF_GetError());
			//exit(1);
			}
		#endif	

		//Initialize SDL
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
			LOG( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
			success = false;
		} else {
		//Set texture filtering to linear
			if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
				LOG( "Warning: Linear texture filtering not enabled!" );
			}

			//Create window
			m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			if( m_window == NULL ) 	{
				LOG( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				//Create renderer for window
				m_render = SDL_CreateRenderer( m_window, -1, 0 );
				if( m_render == NULL ) 	{
					LOG( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
					success = false;
				}
				///*
				else
				{
				//Initialize renderer color
				//SDL_SetRenderDrawColor( m_render, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				//*
				int imgFlags = IMG_INIT_PNG;
					if( !( IMG_Init( imgFlags ) & imgFlags ) )
					{
					LOG( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
					}
				
				}
				/**/
			}
		}

	SDL_RenderSetScale(m_render,1,1);
	return success;
	}

	/*
	SDL_Texture* loadTexture( std::string path )
	{
		    SDL_Surface *background = SDL_LoadBMP("hockeyrink.bmp");
	if(background == NULL)
    {
        SDL_ShowSimpleMessageBox(0, "Background init error",         SDL_GetError(), window);
    }

    if(renderer == NULL)
    {
        SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,background);
	
		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL )
		{
			printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			if( newTexture == NULL )
			{
				printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			}

			//Get rid of old loaded surface
			SDL_FreeSurface( loadedSurface );
		}

		    SDL_RenderCopy(renderer, texture, NULL, NULL);

		return newTexture;
	}
*/

	void close()
	{
		//Destroy window        
		SDL_DestroyRenderer( m_render );
		SDL_DestroyWindow( m_window );
		m_window = NULL;
		m_render = NULL;

		//Quit SDL subsystems
		//IMG_Quit();
		SDL_Quit();
	}


	void scene_clear() {
		//LOG("SDL render: clear \n");
		SDL_SetRenderDrawColor(m_render,0,0,0,255);
		SDL_RenderClear( m_render );
		SDL_SetRenderDrawColor(m_render,0,0,0,255);
	}

	//TODO redudant set render color?
	void scene_draw() {
		//LOG("SDL render: draw exact \n");
		SDL_SetRenderDrawColor( m_render, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderPresent( m_render );
	}


	void change_background_image() {
		//SDL_Surface* background = SDL_LoadBMP("./bin/sky_bg.png");
		SDL_Surface* background = IMG_Load("./bin/sky_bg.jpg");
		if(background == NULL)
		{
			SDL_ShowSimpleMessageBox(0, "Background init error",         SDL_GetError(), m_window);
		}

		if(m_render == NULL)
		{
			SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), m_window);
		}

		m_bg_texture = SDL_CreateTextureFromSurface(m_render,background);
		if(m_bg_texture  == NULL)
		{
			SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), m_window);
		}
		
		SDL_RenderCopy(m_render, m_bg_texture, NULL, NULL);
		delete background;

	}
	
	void render_background_image() {
		SDL_RenderCopy(m_render, m_bg_texture, NULL, NULL);
	
	}
	

};



class LeSdlWrapper : public LeRenderBase , public LeEventControllerBase
{

public:
	//TODO fixme game name in the title
	LeSdlWrapper(){ //const char* title) {
		m_render_manager = LeSdlRendererManager::get();
		m_render = m_render_manager->get_renderer();
	}

/*	
virtual void draw() {
	scene_clear();
	scene_prepare();
	scene_draw();
}
*/	

/*
virtual void update() {

}
*/

	
virtual void enter_event_loop() {
	//SDL_Log("hav");
	unsigned int lastTime = 0, currentTime;
	unsigned int last_x = 0;
	unsigned int last_y = 0 ;

	SDL_Event e;
	bool quit = false;
	while( !quit ) {
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 10) {

			while( SDL_PollEvent( &e ) != 0 ) {
				if ( m_renderer_controller ) {
					if ( e.type == SDL_QUIT ) quit = true;
					else if ( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) m_renderer_controller->notify_mouse_pressed(1);
					else if ( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT )m_renderer_controller->notify_mouse_pressed(0);
					else if ( e.type == SDL_MOUSEMOTION  ) {
						//check_select_active_object(e.motion.x, e.motion.y);
						last_x = e.motion.x;
						last_y = e.motion.y;
						m_renderer_controller->notify_mouse_move(last_x,last_y);
					}
					//if ( e.type == SDL_MOUSEWHEEL)
					//if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) 
					//if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x) 
				}
			}

			//SDL_Log("hatuk");
			//get_active_rnderer(
			//LOG("this %p m_renderer_controller %p \n",(void*)this,(void*)m_renderer_controller);
			if(m_renderer_controller) {
				//SDL_Log("?????\n");
				m_render_manager->scene_clear();
				m_render_manager->render_background_image();
				m_renderer_controller->update(currentTime);
				m_renderer_controller->draw();
				m_render_manager->scene_draw();
			}
						
			lastTime = currentTime;  
		}
	}
}



static void set_rendering_controller(LeSdlWrapper* controller){
	//LOG("set_rendering_controller %p --> %p\n",(void*)this, (void*)controller);
	LOG("set_rendering_controller %p \n",(void*)controller);       
	m_renderer_controller = controller;
}

private:
	LeSdlRendererManager* m_render_manager;
	
	

private:
	static LeSdlWrapper* m_renderer_controller;
	SDL_Renderer* m_render;
	std::map<std::string,std::pair<SDL_Texture*,SDL_Rect> > name2texture;
	

public:
			
	void draw_point(unsigned int y, unsigned int x, unsigned int radius) { 
		SDL_Point center;
		center.x = x;
		center.y = y;
		draw_circle(center,radius);
	}

	void set_drawing_color(int r, int g, int b) {
		SDL_SetRenderDrawColor(m_render,r,g,b,255);
	}

	void set_drawing_color(SDL_Color c) {
		SDL_SetRenderDrawColor(m_render,c.r,c.g,c.b,255);
	}


	void draw_text(const char* s, unsigned int y, unsigned int x)
	{
	#ifdef TEXT_RENDER
		SDL_Point p;
		p.x=x;
		p.y=y;
		SDL_Color c = {255, 0, 0};  
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(m_ttf_font, s , c); 
		SDL_Texture* Message = SDL_CreateTextureFromSurface(m_render, surfaceMessage); 

		SDL_Rect Message_rect; 
		Message_rect.x = p.x;  
		Message_rect.y = p.y; 
		Message_rect.w = 80; 
		Message_rect.h = 40; 

		SDL_RenderCopy(m_render, Message, NULL, &Message_rect); 
	#endif		
	}


	//todo more clever way?
	std::pair<std::string, std::pair<unsigned int,unsigned int> > register_image(const char* ipath) {
		SDL_Surface* sf  = IMG_Load(ipath);
		SDL_Texture* itexture = SDL_CreateTextureFromSurface(m_render,sf);
		delete sf;

		auto w = 0;
		auto h = 0;
		SDL_QueryTexture(itexture, NULL, NULL, &w, &h);
	
		SDL_Rect irect;
		irect.w = w;
		irect.h = h;
		
		name2texture[ipath] = std::make_pair(itexture,irect);
		return std::make_pair(ipath,std::make_pair(w,h));
	}
	
	void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph) {
		std::pair<SDL_Texture*,SDL_Rect> info = name2texture[ipath];
		
		SDL_Rect irect;
		irect.x = x;
		irect.y = y;
		irect.w = info.second.w/cropw;
		irect.h = info.second.h/croph;
	
		SDL_RenderCopy(m_render, info.first, NULL, &irect);
	}
	
	void draw_square(unsigned int y, unsigned int x, unsigned int delta) {
		draw_rect(y-delta,x-delta,2*delta,2*delta);
	}  

	void draw_rect(unsigned int y, unsigned int x, unsigned int delta2, unsigned int delta1 ) {
		SDL_Rect rectToDraw = {x,y,delta1,delta2};
		SDL_RenderDrawRect(m_render,&rectToDraw);
		SDL_RenderFillRect(m_render, &rectToDraw);
	}  

	void draw_line(unsigned int y1, unsigned int x1, unsigned int y2, unsigned int x2) {
		SDL_RenderDrawLine(m_render,x1,y1,x2,y2);
	}


	void draw_circle(const SDL_Point& center, int radius)//, SDL_Color color)
	{
	for (int w = 0; w < radius * 2; w++)
		for (int h = 0; h < radius * 2; h++) {
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx*dx + dy*dy) <= (radius * radius)) {
				SDL_RenderDrawPoint(m_render, center.x + dx, center.y + dy);
			}
		}
	}

};



#endif