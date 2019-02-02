#ifndef resources_h
#define resources_h

#include "../skeleton/common.h"
#include "../skeleton/resource_manager.h"


enum LeImageName { IMG_SKY_BACKGROUND,   IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3, IMG_LIFE, IMG_MENU_PLAY };
enum LeSoundName { SND_COIN,  SND_SWIM,  SND_DAMAGE, SND_FUCK, SND_WIN };
enum LeMusicName { MUS_GAME,  MUS_MENU,  MUS_PAUSE };

namespace {
    void register_resources() {
        LeResourceManager* m_resources = LeResourceManager::get();
        m_resources->register_image(int(IMG_SKY_BACKGROUND), "sky_bg.jpg");
        m_resources->register_image(int(IMG_PLAYER),"player.png");
        m_resources->register_image(int(IMG_COIN),"coin.png");
        m_resources->register_image(int(IMG_ENEMY1),"debilik1.png");
        m_resources->register_image(int(IMG_ENEMY2),"debilik3.png");
        m_resources->register_image(int(IMG_ENEMY3),"debilik4.png");
        m_resources->register_image(int(IMG_LIFE),"life.png");
        m_resources->register_image(int(IMG_MENU_PLAY),"play.png");
    }
}

#endif
