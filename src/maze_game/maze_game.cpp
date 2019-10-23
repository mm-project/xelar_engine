#include "resources.hpp"
#include "maze_game.hpp"
#include "game_window.hpp"
#include "../skeleton/state_manager.h"


XGame::XGame() {
	m_state_mgr = LeStateManager::get();
    m_resources = LeResourceManager::get();

    m_resources->set_mus_path(RESPATH);
    m_resources->set_img_path(RESPATH);
    m_resources->set_snd_path(RESPATH);
}


void XGame::init() {
    m_state_mgr->reg_state(ST_GAME,new GameWindow);
    
    register_images();   
}

void XGame::start() {
	//todo check for some conditions
	m_state_mgr->set_start_state(ST_GAME);
}

void XGame::stop() {
	//save as ?
}

void XGame::register_images() {
     register_resources();
}



