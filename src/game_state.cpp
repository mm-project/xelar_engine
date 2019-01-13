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
	set_timer_checkpoints();
	//create_enemies();
	//create_world();
    
    init();
}

void LeGameState::set_timer_checkpoints() {
	m_timer.add_continuous_checkpoint(std::bind(&LePlayer::update,&m_player,std::placeholders::_1),10);
	m_timer.add_continuous_checkpoint(std::bind(&LeBackground::update,&m_background,std::placeholders::_1),10);
}


void LeGameState::init() {
	SDL_Log("LeGameState: init");
	//init_player();
	//init_enemies();
	init_world();
}

void LeGameState::init_world()
{
	m_is_gameover = false;
	m_current_score = 0;
	m_current_time = 0;
    
    set_background_image("./bin/sky_bg.jpg");
    m_background.init();
}


void LeGameState::draw() {
	m_background.draw();
    m_player.draw();
}


void LeGameState::update(unsigned int t) {
	
	if (! m_is_gameover ) {
		m_timer.step(t);
		m_current_time=+t;
	}
	
}

void LeGameState::notify_mouse_pressed(unsigned int b) {
    //LeInterLayer::notify_mouse_pressed(b);
    if (m_is_gameover)  {
		LeStateManager::get()->set_state(ST_MENU);	
		return;
	}	
	//FIXME members from parent
    m_player.set_destination(m_cursor_x,m_cursor_y);
}

/*
void LeGameState::check_intersection() {
	//if (!m_is_gameover) 
    //return;
	if ( m_player.is_vulnarable() ) {
		for( auto it : m_enemies ) {
			if ( has_intersetion(m_player.m_old_x,m_player.m_old_y,m_player.m_height,m_player.m_width,it.m_old_x,it.m_old_y,it.m_height,it.m_width) ) {	
				if ( m_player.damage() )
					m_current_trouble_obj = it;
					m_is_gameover = true;
					return;
				} else {
					m_lifes--;
					m_player_hit = true;
					m_is_player_vulnarable = false;
					last_hit_time = m_current_time;
					//m_timer.add_singleshot_checkpoint(std::bind(&LeGameState::set_player_vulnarable,this),2000);
				}
			}
		}
	}
*/
