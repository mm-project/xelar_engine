#include "x_game.h"
#include "game_state.h"

#include "../skeleton/state_manager.h"



#ifdef OS_WINDOWS
    #define RESPATH "C:\\Users\\elen\\Desktop\\sdl_game\\ForLevonjanik\\Debug\\"
#else
    #define RESPATH "./bin/"
#endif


XGame::XGame() {
	m_state_mgr = LeStateManager::get();
    m_resources = LeResourceManager::get();

    m_resources->set_mus_path(RESPATH);
    m_resources->set_img_path(RESPATH);
    m_resources->set_snd_path(RESPATH);
}


void XGame::init() {
    register_images();

    m_state_mgr->reg_state(ST_GAME,new LeGameState);
}

void XGame::start() {
	//todo check for some conditions
	m_state_mgr->set_start_state(ST_GAME);
}

void XGame::stop() {
	//save as 
}

void XGame::register_images() {
    m_resources->register_image(int(IMG_SKY_BACKGROUND), "sky_bg.jpg");
    m_resources->register_image(int(IMG_PLAYER),"player.png");
    m_resources->register_image(int(IMG_COIN),"coin.png");
    m_resources->register_image(int(IMG_ENEMY1),"debilik1.png");
    m_resources->register_image(int(IMG_ENEMY2),"debilik3.png");
    m_resources->register_image(int(IMG_ENEMY3),"debilik4.png");
    m_resources->register_image(int(IMG_LIFE),"life.png");
}



