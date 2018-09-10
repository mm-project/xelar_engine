#ifndef game_state_h
#define game_state_h

#include "state_manager.h"

class LeGameState : public LeInterLayer
{
	virtual void draw() {
			set_drawing_color(255,0,0);
			draw_rect(0,0,100,100);
	}

	virtual void notify_mouse_pressed(unsigned int) {
			SDL_Log("LeGameState: notify_mouse_pressed");
	}
	
	virtual void notify_key_pressed(unsigned int) {
			SDL_Log("LeGameState: notify_key_pressed");
			LeStateManager::get()->set_state(LeState::ST_MENU);
	}
	
	virtual void notify_mouse_move(unsigned int x, unsigned int y) {
			SDL_Log("LeGameState: notify_mouse_moved");
	}
	

	
};

#endif