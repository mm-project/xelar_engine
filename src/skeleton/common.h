#ifndef common_h
#define common_h

#include "service.h"
#include "image.h"
#include "resource_manager.h"

#include <functional>

typedef std::function<void(int)> updateFun;
typedef std::function<void()> actionFun;
typedef unsigned int uint;

//FIXME move to common.cpp to avoid duplication in unnmammed namespace
namespace {
    LeImg get_rsc(LeImageName name) {
        return LeResourceManager::get()->get_img(name);
    }
}

#ifdef OS_WINDOWS
	#define RES_PATH_PREFIX 
#endif

#ifdef OS_LINUX
	#define RES_PATH_PREFIX ./bin
#endif

#ifdef OS_ANDROID
	#define RES_PATH_PREFIX
	#define LOG SDL_Log
#else
	#define LOG printf
#endif

/*
#ifndef DEBUG
#	define LOG ;
#endif
/**/



#endif
