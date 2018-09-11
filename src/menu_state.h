#ifndef menu_state_h
#define menu_state_h

#include "state_manager.h"

class LeMenuState : public LeInterLayer
{
	virtual void draw() {
			//scene_clear();
			//set_drawing_color(255,0,0);
			//draw_rect(0,0,100,100);
			//scene_draw();
			LOG("LeMenuState: draw\n");
	}

	virtual void notify_mouse_pressed(unsigned int) {
			SDL_Log("===LeMenuState: notify_mouse_pressed\n");
			LeStateManager::get()->set_state(ST_GAME);
	}
	
	virtual void notify_key_pressed(unsigned int) {
			//LOG("LeMenuState: notify_key_pressed\n");
			
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			//LOG("LeMenuState: notify_mouse_moved\n");
                        
	}
	

	
};

#endif