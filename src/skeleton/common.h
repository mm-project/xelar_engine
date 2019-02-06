#ifndef common_h
#define common_h

#include "service.h"
#include "image.h"
#include "resource_manager.h"

#include <functional>
#include <cassert>

typedef std::function<void(int)> updateFun;
typedef std::function<void()> actionFun;
typedef unsigned int uint;

//FIXME move to common.cpp to avoid duplication in unnmammed namespace
namespace {
    LeImg get_rsc(int id) {
        return LeResourceManager::get()->get_img(id);
    }
}

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
