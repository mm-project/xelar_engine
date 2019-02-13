#include "sdl_renderer.h"
#include "scene_controller.h"

#include "../skeleton/common.h"

#include <string>
#include <map>
#include <utility>
#include <cassert>

#include <stdio.h>


//TODO game title from outside

LeSdlRenderer::LeSdlRenderer(){ //const char* title) {
	m_init_success = true;
	//FIXME what if init failed? exit?
    //FIXME fix title
	if ( !init("Game demo") ) 
		exit(1);
        
    m_dx = 0;
    m_dy = 0;
    m_kx = 1;
    m_ky = 1;
    //assert(0);
}


std::pair<SDL_Texture*,SDL_Rect> LeSdlRenderer::get_image_info(const char* ipath) {
    //FIXME ASSERT THAT ENTRY EXISITS
    
    return m_name2texture[ipath];
}

ImgInfo LeSdlRenderer::register_image(const char* ipath) {
#ifdef IMAGE_RENDER
	SDL_Surface* sf  = IMG_Load(ipath);
	//printf("IMG_Load: %s\n", IMG_GetError());
	//assert(0);
	//FIXME need to check before registering.
	//SDL_ShowSimpleMessageBox(0, "Reg image: %s\n", IMG_GetError(), NULL);
	SDL_Texture* itexture = SDL_CreateTextureFromSurface(m_render,sf);
	//FIXME on windows lead to crash
	//	delete sf;

	auto w = 0;
	auto h = 0;
	SDL_QueryTexture(itexture, NULL, NULL, &w, &h);

	SDL_Rect irect;
	irect.w = w;
	irect.h = h;
	
    m_name2surface[ipath] = sf;
	m_name2texture[ipath] = std::make_pair(itexture,irect);
	return std::make_pair(ipath,std::make_pair(w,h));
#else
	return std::make_pair("", std::make_pair(0, 0));
#endif
}

bool  LeSdlRenderer::init_sdl_ttf() {
#ifdef TEXT_RENDER
	if(!TTF_WasInit() && TTF_Init()==-1) {
		SDL_ShowSimpleMessageBox(0, "TTF_Init: %s\n", TTF_GetError(), NULL);
		m_init_success = false;
		//exit(1);
	}

	/*m_ttf_font = TTF_OpenFont("FreeSans.ttf", 50); 
	if(!m_ttf_font) {  
		SDL_ShowSimpleMessageBox(0, "TTF_OpenFont: %s\n", TTF_GetError(),NULL);
		m_init_success = false;
		//exit(1);
	}*/
#else
	//SDL_ShowSimpleMessageBox(0, "No SDL_ttf","Error",NULL);
	return false;
#endif
	return false;
}

bool LeSdlRenderer::init_sdl_image() {
#ifdef IMAGE_RENDER
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		SDL_ShowSimpleMessageBox(0, "SDL_image could not initialize! SDL_image Error:", IMG_GetError(), NULL);
		m_init_success = false;
	}
#else
	SDL_ShowSimpleMessageBox(0, "No SDL_image","Error",NULL);
	return true;
#endif
	return true;
}

bool LeSdlRenderer::init_sdl() {
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		SDL_ShowSimpleMessageBox( 0, "SDL could not initialize! SDL Error: %s\n", SDL_GetError(), NULL );
		m_init_success = false;
	}
	return true;
}

bool LeSdlRenderer::create_window(const char* title) {
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( m_window == NULL ) 	{
		SDL_ShowSimpleMessageBox(0, "Window could not be created! SDL Error: %s\n", SDL_GetError(),NULL);
		m_init_success = false;
	} else {
		//Create renderer for window
		m_render = SDL_CreateRenderer( m_window, -1, 0 );
		if( m_render == NULL ) 	{
			SDL_ShowSimpleMessageBox(0, "Renderer could not be created! SDL Error: %s\n", SDL_GetError(),NULL );
			m_init_success = false;
		} else {
			SDL_RenderSetScale(m_render,1,1);	
			SDL_RenderSetLogicalSize(m_render, SCREEN_WIDTH, SCREEN_HEIGHT);
			if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
				LOG( "Warning: Linear texture filtering not enabled!" );
		}			
	}
	return true;
}

//TODO seperate each init to different inits. 
bool LeSdlRenderer::init(const char* title)
{
	LOG("init start\n");
	
	init_sdl();
	init_sdl_image();
	init_sdl_ttf();
	create_window(title);

return m_init_success;
}


void LeSdlRenderer::close()
{
	//Destroy window        
	SDL_DestroyRenderer( m_render );
	SDL_DestroyWindow( m_window );
	m_window = NULL;
	m_render = NULL;

	//Quit SDL subsystems
#ifdef IMAGE_RENDER	
	IMG_Quit();
#endif	
	SDL_Quit();
}


void LeSdlRenderer::scene_clear() {
	//LOG("SDL render: clear \n");
	SDL_SetRenderDrawColor(m_render,0,0,0,255);
	SDL_RenderClear( m_render );
	SDL_SetRenderDrawColor(m_render,0,0,0,255);
}

//TODO redudant set render color?
void LeSdlRenderer::scene_draw() {
	//LOG("SDL render: draw exact \n");
	SDL_SetRenderDrawColor( m_render, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderPresent( m_render );
}

/*
void LeSdlRenderer::set_background_image(const char* path) {
#ifdef IMAGE_RENDER
	SDL_Surface* background = IMG_Load(path);
	if(background == NULL) {
		SDL_ShowSimpleMessageBox(0, "Background init error", SDL_GetError(), m_window);
	}

	if(m_render == NULL) {
		SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), m_window);
	}

	m_bg_texture = SDL_CreateTextureFromSurface(m_render,background);
	if(m_bg_texture  == NULL) {
		SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), m_window);
	}
	
	//SDL_RenderCopy(m_render, m_bg_texture, NULL, NULL);
	//delete background;
#endif
}
*/

void LeSdlRenderer::render_background_image() {
	//if ( m_bg_texture )
		//SDL_RenderCopy(m_render, m_bg_texture, NULL, NULL);
}

void LeSdlRenderer::draw_text(const char* s, unsigned int y, unsigned int x, unsigned int sy, unsigned int sx)
{
#ifdef TEXT_RENDER
	if(!m_ttf_font) 
		return;
	
	SDL_Point p;
	p.x=x;
	p.y=y;
	SDL_Color c = {255, 255, 255};  
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(m_ttf_font, s , c); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(m_render, surfaceMessage); 

	SDL_Rect Message_rect; 
	Message_rect.x = p.x;  
	Message_rect.y = p.y; 
	Message_rect.w = sy; 
	Message_rect.h = sx; 

	SDL_RenderCopy(m_render, Message, NULL, &Message_rect); 
#endif		
}



void LeSdlRenderer::draw_point(unsigned int y, unsigned int x) { 
	//draw_circle(y,x,1);
      SDL_RenderDrawPoint(m_render, t_x(x), t_y(y));
}

void LeSdlRenderer::set_drawing_color(int r, int g, int b) {
    SDL_SetRenderDrawColor(m_render,r,g,b,255);
}


void LeSdlRenderer::set_background_image(const char* ipath) {
    register_image(ipath);
    auto info = get_image_info(ipath);
    m_bg_texture = info.first; 
    m_bg_texture_width = info.second.w;
    m_bg_texture_height = info.second.h;
    
}

void LeSdlRenderer::draw_static_background() {
        SDL_Rect srect;
        srect.x = t_x(0);
        srect.y = t_y(0);
        srect.w = t_x(scr_w());
        srect.h = t_y(scr_h());
        SDL_RenderCopy(m_render, m_bg_texture, &srect, NULL);
}

bool LeSdlRenderer::draw_scroll_background(unsigned int delta) {	
    //set_background_image(path);
	//FIXME background texture constant and have set_background_image 
    
    //unsigned int height = scr_h();
    if ( delta + scr_w() < m_bg_texture_width ) {
        SDL_Rect srect;
        srect.x = delta;
        srect.y = 0;
        srect.w = scr_w();
        srect.h = scr_h();
        SDL_RenderCopy(m_render, m_bg_texture, &srect, NULL);
    } else {
        unsigned int diff1 = m_bg_texture_width - delta;
        //unsigned int diff2 = scr_w() - delta;
       
        SDL_Rect drect1;
        drect1.x = 0;
        drect1.y = 0;
        drect1.w = diff1;
        drect1.h = scr_h();
        
        
        SDL_Rect srect1;
        srect1.x = delta;
        srect1.y = 0;
        srect1.w = diff1;
        srect1.h = scr_h();
        

        SDL_Rect drect2;
        drect2.x = diff1;
        drect2.y = 0;
        drect2.w = scr_w();
        drect2.h = scr_h();
        
        
        SDL_Rect srect2;
        srect2.x = 0;
        srect2.y = 0;
        srect2.w = diff1;
        srect2.h = scr_h();

        SDL_RenderCopy(m_render, m_bg_texture, &srect1, &drect1);
        SDL_RenderCopy(m_render, m_bg_texture, NULL, &drect2);
        if ( diff1 == 0 )
            return true;
    }

    return false;
    
}


void LeSdlRenderer::draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph) {
	//assert(0);
    //return;
    std::pair<SDL_Texture*,SDL_Rect> info = get_image_info(ipath);
	
	SDL_Rect irect;
	irect.x = t_x(x);
	irect.y = t_y(y);
	irect.w = (info.second.w/cropw)*m_kx;
	irect.h = (info.second.h/croph)*m_ky;

	SDL_RenderCopy(m_render, info.first, NULL, &irect);
}

void LeSdlRenderer::draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph, double angle, bool needflip, uint flipmode) {
	//return;
    std::pair<SDL_Texture*,SDL_Rect> info = get_image_info(ipath);
	
	//fixme get rid of this temp. variables
	SDL_Rect irect;
	irect.x = t_x(x);
	irect.y = t_y(y);
	irect.w = m_kx*info.second.w/cropw;
	irect.h = m_ky*info.second.h/croph;

	if ( needflip ) {
		SDL_RenderCopyEx(m_render, info.first, NULL, &irect, angle, NULL , SDL_FLIP_NONE );	
		
		return;
	}
	
	SDL_RenderCopyEx(m_render, info.first, NULL, &irect, angle, NULL, SDL_FLIP_NONE );	
}


void LeSdlRenderer::draw_square(unsigned int y, unsigned int x, unsigned int delta) {
	draw_rect(y-delta,x-delta,2*delta,2*delta);
}  

void LeSdlRenderer::draw_rect(unsigned int y, unsigned int x, unsigned int delta2, unsigned int delta1 ) {
	SDL_Rect rectToDraw = {t_x(x),t_y(y),delta1,delta2};
	SDL_RenderDrawRect(m_render,&rectToDraw);
	SDL_RenderFillRect(m_render, &rectToDraw);
}  

void LeSdlRenderer::draw_line(unsigned int y1, unsigned int x1, unsigned int y2, unsigned int x2) {
	SDL_RenderDrawLine(m_render,t_x(x1),t_y(y1),t_x(x2),t_y(y2));
}


void LeSdlRenderer::draw_circle(unsigned int y, unsigned int x, int radius)
{
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(m_render, t_x(x + dx), t_y(y + dy));
            }
        }
    }
}

void LeSdlRenderer::pan_to_x_y(int x, int y) 
{
    m_dx = x;
    m_dy = y;
}

/*
void LeSdlRenderer::zoom(float factor) {
     if ( m_kx > 1 ) {
        m_kx *= factor;
        m_ky *= factor;
     }
}
*/

void LeSdlRenderer::fzoomin(int factor) {
    m_kx *= factor;
    m_ky *= factor;
}

void LeSdlRenderer::fzoomout(int factor) {
    if ( m_kx > 1 ) {
        m_kx /= factor;
        m_ky /= factor;
    }
}

void LeSdlRenderer::zoomin(int step) {
    m_kx += step;
    m_ky += step;
}

void LeSdlRenderer::zoomout(int step) {
    if ( m_kx > 1 ) {
        m_kx -= step;
        m_ky -= step;
    }
}

void LeSdlRenderer::pan_up(int step) {
     m_dy -= step;
}

void LeSdlRenderer::pan_down(int step) {
    m_dy += step;
}

void LeSdlRenderer::pan_left(int step) {
    m_dx -= step;
}

void LeSdlRenderer::pan_right(int step) {
    m_dx += step;
}

inline int LeSdlRenderer::t_x(int x) {
    return m_kx*x+m_dx;
    
}

inline int LeSdlRenderer::t_y(int y) {
    return m_ky*y+m_dy;
}




void LeSdlRenderer::enter_event_loop() {
	//SDL_Log("hav");
	unsigned int lastTime = 0, currentTime;
	unsigned int last_x = 0;
	unsigned int last_y = 0 ;

	SDL_Event e;
	bool quit = false;
	while( !quit ) {
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 10) {
            LeSceneController* m_renderer_controller = get_controller();
			while (SDL_PollEvent( &e )) {
				if ( m_renderer_controller ) {
					if ( e.type == SDL_QUIT ) quit = true;

                    else if ( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) m_renderer_controller->notify_mouse_pressed(1);
					else if ( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT )m_renderer_controller->notify_mouse_pressed(0);
					else if ( e.type == SDL_MOUSEMOTION  ) {
						last_x = e.motion.x;
						last_y = e.motion.y;
						m_renderer_controller->notify_mouse_move(last_x,last_y);
					}
					else if ( e.type == SDL_KEYDOWN ) { m_renderer_controller->notify_key_pressed(int(e.key.keysym.sym)); }
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
				scene_clear();
				//render_background_image();
				m_renderer_controller->update(currentTime);
				m_renderer_controller->draw();
				scene_draw();
			}
			lastTime = currentTime;  
		}
	}
}

bool LeSdlRenderer::has_intersetion(int y1, int x1, int h1, int w1, int y2, int x2, int h2, int w2 )
{
    SDL_Rect* A = new SDL_Rect{x1,y1,w1,h1};
    SDL_Rect* B = new SDL_Rect{x2,y2,w2,h2};
    
    int r = SDL_HasIntersection(A,B);
    delete A;
    delete B;
    
    return r;
}
