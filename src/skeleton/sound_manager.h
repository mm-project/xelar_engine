#ifndef sound_manager_h
#define sound_manager_h

#include "resource_manager.h"
#include "service.h"

//#include <SDL2/SDL_mixer.h>

class LeSoundManager : public LeService<LeSoundManager>
{
    public: 
		friend class LeService<LeSoundManager>;
    
    private:
            LeSoundManager();

			LeSoundManager(const LeSoundManager&);
			LeSoundManager& operator=(const LeSoundManager&);
    public:
            //void play(LeSoundName name);
            //void play(LeMusicName name);

    private: 
            bool init();
            
    private:
            //Mix_Chunk* wave;
            //Mix_Music *music;
    
    
};

#endif
