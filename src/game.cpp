#include "game.h"
#include "state_manager.h"
#include "game_state.h"
#include "menu_state.h"


LeGame::LeGame() {
	m_state_mgr = LeStateManager::get();

	m_state_mgr->reg_state(ST_MENU,new LeMenuState);
	m_state_mgr->reg_state(ST_GAME,new LeGameState);
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
