#include "image.h"
#include "game_state.h"
#include "interlayer.h"
#include "state_manager.h"
#include "sound_manager.hpp"
#include "mover.h"
#include "player.h"

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <cassert>
#include <cmath>

LeGameState::LeGameState() {	
    m_resources = LeStateManager::get()->get_resource_manager();

	set_timer_checkpoints();
	//create_enemies();
	//create_world();
}

void LeGameState::LeGameState::init() {
	SDL_Log("LeGameState: init");

	//init_player();
	//init_enemies();
	init_world();
    //m_rand_mover.set_obj(m_player);
}

void LeGameState::init_world()
{
	m_is_gameover = false;
	m_current_score = 0;
	m_current_time = 0;
	//create_world();
	set_background_image("sky_bg.jpg");
}


void LeGameState::draw() {
	m_player.draw();
}

void LeGameState::update_player() {
	m_player.update();
}

void LeGameState::update(unsigned int t) {
	
	if (! m_is_gameover ) {
		m_timer.step(t);
		m_current_time=+t;
	}
	
}

void LeGameState::set_timer_checkpoints() {
	m_timer.add_continuous_checkpoint(std::bind(&LeGameState::update_player,this),10);
}


void LeGameState::notify_mouse_pressed(unsigned int b) {
    LeInterLayer::notify_mouse_pressed(b);

    if (m_is_gameover)  {
		LeStateManager::get()->set_state(ST_MENU);	
		return;
	}	
	
	//FIXME members from parent
    m_player.set_destination(m_cursor_x,m_cursor_y);
}


