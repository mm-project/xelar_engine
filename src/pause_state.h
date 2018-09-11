#ifndef pause_state_h
#define pause_state_h

#include "state_manager.h"

class LePauseState : public LeInterLayer
{
	virtual void draw() {
			set_drawing_color(0,0,255);
			draw_rect(0,0,100,100);
	}

	virtual void notify_mouse_pressed(unsigned int) {
			SDL_Log("LePauseState: notify_mouse_pressed");
			LeStateManager::get()->set_state(ST_GAME);
	}
	
	virtual void notify_key_pressed(unsigned int) {
			SDL_Log("LePauseState: notify_key_pressed");
			
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			SDL_Log("LePauseState: notify_mouse_moved");
	}
	

	
};

#endif