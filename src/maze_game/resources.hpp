#ifndef resources_h
#define resources_h

#include "../skeleton/common.h"
#include "../skeleton/resource_manager.h"


#ifdef OS_WINDOWS
    #define RESPATH "C:\\Users\\elen\\Desktop\\sdl_game\\ForLevonjanik\\Debug\\"
#elif OS_ANDROID
    #define RESPATH ""
#else
    #define RESPATH "./bin/"
#endif


enum LeImageName { IMG_PLAYER,  IMG_CHEESE };

namespace {
    void register_resources() {
        LeResourceManager* m_resources = LeResourceManager::get();
        m_resources->register_image(int(IMG_PLAYER),"mouse.png");
        m_resources->register_image(int(IMG_CHEESE),"cheese.png");
    /**/
        
    }
}

#endif
