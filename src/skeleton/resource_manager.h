#ifndef resource_manager_h
#define resource_manager_h

#include "service.h"
#include "image.h"
#include "../renderer/sdl_renderer.h"
//#include "enumarations"

#include <map>
#include <string>

enum LeImageName { IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3, IMG_LIFE };
enum LeSoundName { SND_COIN,  SND_SWIM,  SND_DAMAGE, SND_FUCK, SND_WIN };
enum LeMusicName { MUS_GAME,  MUS_MENU,  MUS_PAUSE };


class LeResourceManager: public LeService<LeResourceManager>
{
	public:
        LeResourceManager();
        //FIXME compiler is not happy
        static LeResourceManager* get() { return LeService<LeResourceManager>::get(); }

	public:
        LeImg get(LeImageName n);
        
    private:
        void register_image(LeImageName name, std::string filename);

    private:
        void register_images();
        //id register_sounds();
        //id register_music();

    private:
        std::map<LeImageName,LeImg> m_ienum2obj;
        std::string m_img_path;
        std::string m_snd_path;
        std::string m_mus_path;
        LeSdlRendererManager* m_rendering_manager;
        
};

#endif
