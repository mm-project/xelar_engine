#ifndef game_h
#define game_h

#include "../skeleton/state_manager.h"


class LeGame
{
	public:
		LeGame();

		void start();
		void stop();

	private:
		LeStateManager* m_state_mgr;
			
	
};

#endif
