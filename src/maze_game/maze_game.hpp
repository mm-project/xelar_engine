#ifndef x_game_h
#define x_game_h

#include "../skeleton/game.h"

#include "../skeleton/resource_manager.h"
#include "../skeleton/state_manager.h"


class XGame: public LeGame
{
    public:
		XGame();
    
    public:
		virtual void init();
        virtual void start();
		virtual void stop();
	
    public:
        void register_images();
    
    private:
		LeStateManager* m_state_mgr;
        LeResourceManager* m_resources;
			
};


#endif
