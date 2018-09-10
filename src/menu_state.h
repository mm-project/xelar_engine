#ifndef menu_state_h
#define menu_state_h

#include "state_manager.h"

class LeMenuState : public LeInterLayer
{
	virtual void draw() {
			set_drawing_color(255,255,0);
			draw_rect(0,0,100,100);
	}

	virtual void notify_mouse_pressed(unsigned int) {
			SDL_Log("LeMenuState: notify_mouse_pressed");
	}
	
	virtual void notify_key_pressed(unsigned int) {
			SDL_Log("LeMenuState: notify_key_pressed");
			LeStateManager::get()->set_state(LeState::ST_GAME);
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			SDL_Log("LeMenuState: notify_mouse_moved");
	}
	

	
};

#endif