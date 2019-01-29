#include "game.h"
#include "window.hpp"

#include "../skeleton/state_manager.h"


LeGame::LeGame() {
	m_state_mgr = LeStateManager::get();

	m_state_mgr->reg_state(ST_GAME,new window);
}

void LeGame::start() {
	//todo check for some conditions
	//maybe load something
	m_state_mgr->set_start_state(ST_GAME);
	
}

void LeGame::stop() {
	//save as 
	//m_state_mgr-
	//LeStateManager.set
}
