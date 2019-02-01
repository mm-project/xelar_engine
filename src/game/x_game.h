#ifndef x_game_h
#define x_game_h

#include "../skeleton/game.h"

#include "../skeleton/resource_manager.h"
#include "../skeleton/state_manager.h"

enum LeImageName { IMG_SKY_BACKGROUND,   IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3, IMG_LIFE };
enum LeSoundName { SND_COIN,  SND_SWIM,  SND_DAMAGE, SND_FUCK, SND_WIN };
enum LeMusicName { MUS_GAME,  MUS_MENU,  MUS_PAUSE };


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
