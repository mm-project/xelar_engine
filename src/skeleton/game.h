#ifndef game_h
#define game_h

#include "../skeleton/state_manager.h"
#include "../renderer/interlayer.h"


class LeGame
{
	public:
		LeGame();

		void start();
		void stop();

        void  register_entry_point(LeInterLayer* s) {
            m_state_mgr->reg_state(ST_GAME,s);
        }

	private:
		LeStateManager* m_state_mgr;
			
	
};

#endif
