#ifndef game_h
#define game_h

#include "../skeleton/state_manager.h"
#include "../renderer/interlayer.h"


class LeGame
{
	public:
		//LeGame();

		virtual void init() = 0;
        virtual void start() = 0;
		virtual void stop() = 0;

	
};

#endif
