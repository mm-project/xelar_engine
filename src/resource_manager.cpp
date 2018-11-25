#include "resource_manager.h"
#include "sdl_renderer.h"
#include "image.h"


LeResourceManager::LeResourceManager() {	
    m_rendering_manager = LeSdlRendererManager::get();
    m_img_path  = m_snd_path = m_mus_path = "./bin/";
    register_images();
    //register_sounds();
    //register_music();
}

LeImg LeResourceManager::get(LeImageName n) {
    return m_ienum2obj[n];
}

void LeResourceManager::register_image(LeImageName name, std::string filename) {
    m_ienum2obj[name]=LeImg(m_rendering_manager->register_image((m_img_path+filename).c_str()));
}

void LeResourceManager::register_images() 
{
    register_image(IMG_PLAYER,"player.png");
    register_image(IMG_COIN,"coin.png");
    register_image(IMG_ENEMY1,"debilik1.png");
    register_image(IMG_ENEMY2,"debilik2.png");
    register_image(IMG_ENEMY3,"debilik3.png");
    register_image(IMG_LIFE,"life.png");
}

/*
void LeResourceManager::register_sounds() 
{
    register_sound(SND_COIN,"coin.wav");
    register_sound(SND_SWIM,"swim.wav");
    register_sound(SND_DAMAGE,"damage.wav");
    register_sound(SND_FUCK,"loose.wav");
    register_sound(SND_WIN,"win.wav");
}

void LeResourceManager::register_musics() 
{
    register_music(MUS_GAME,"loop.mp3");
    register_music(MUS_MENU,"menu.mp3");
}
*/


