#ifndef game_h
#define game_h

#include "../skeleton/state_manager.h"
#include "../renderer/interlayer.h"

class LeGame
{
	public:
		LeGame();
        void register_entry_point(LeInterLayer*);
		void start();
		void stop();
        

	private:
		LeStateManager* m_state_mgr;
			
	
};

#endif
