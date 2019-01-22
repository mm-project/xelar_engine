#include "game_state.h"
#include "player.h"

#include "../skeleton/image.h"
#include "../skeleton/state_manager.h"
#include "../skeleton/sound_manager.h"
#include "../skeleton/mover.h"

#include "../renderer/interlayer.h"
#include "../renderer/sdl_wrapper.h"


#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <cassert>
#include <cmath>

LeGameState::LeGameState() {	
	create_enemies();
	//create_world();
    
	set_timer_checkpoints();

    init();
}

void LeGameState::set_timer_checkpoints() {
	m_timer.add_continuous_checkpoint(std::bind(&LeEnemy::update,&m_enemies[0],std::placeholders::_1),10);
	m_timer.add_continuous_checkpoint(std::bind(&LePlayer::update,&m_player,std::placeholders::_1),10);
    m_timer.add_continuous_checkpoint(std::bind(&LeBackground::update,&m_background,std::placeholders::_1),10);
    //m_timer.add_continuous_checkpoint(std::bind(&LeGameState::check_intersection,this,std::placeholders::_1),10);
    
}


void LeGameState::create_enemies() {
    m_enemies.push_back(m_enemy);
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
   
	//FIXME !!!
	set_background_image(get_rsc(IMG_SKY_BACKGROUND).get_path().c_str());
    m_background.init();
}


void LeGameState::draw() {
	m_background.draw();
    m_player.draw();
    m_enemies[0].draw();
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


void LeGameState::check_intersection(unsigned int) {
	if ( m_player.is_vulnarable() ) {
		for( auto it : m_enemies ) {
			if ( has_intersetion(m_player.m_obj.m_old_x,m_player.m_obj.m_old_y,m_player.m_obj.m_height,m_player.m_obj.m_width,it.m_obj.m_old_x,it.m_obj.m_old_y,it.m_obj.m_height,it.m_obj.m_width) ) {	
				m_player.damage();
			}
		}
	}
}

