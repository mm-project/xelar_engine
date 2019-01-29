#include "game.h"

#include "../skeleton/state_manager.h"


LeGame::LeGame() {
	m_state_mgr = LeStateManager::get();

}

void LeGame::start() {
	//todo check for some conditions
	//maybe load something
	m_state_mgr->set_start_state(ST_GAME);
	
}

void LeGame::register_entry_point(LeInterLayer* scene) {
    m_state_mgr->reg_state(ST_GAME,scene);
}


void LeGame::stop() {
	//save as 
	//m_state_mgr-
	//LeStateManager.set
}
