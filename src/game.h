#ifndef game_h
#define game_h

#include "state_manager.h"
#include "menu_state.h"
#include "game_state.h"
#include "pause_state.h"

#include <iostream>

class LeGame
{
	public:
		LeGame() {
			m_state_mgr = LeStateManager::get();

			m_state_mgr->reg_state(ST_MENU,new LeMenuState);
			m_state_mgr->reg_state(ST_PAUSE,new LePauseState);
			m_state_mgr->reg_state(ST_GAME,new LeGameState);
		}

		void start() {
			m_state_mgr->set_start_state(ST_GAME);
			
		}

		void stop() {
			//save as 
                        //m_state_mgr-
                        //LeStateManager.set
		}

	private:
            LeStateManager* m_state_mgr;
            //rendering manager
            //sound manager
			
	
};

#endif