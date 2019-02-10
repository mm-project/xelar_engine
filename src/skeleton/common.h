#ifndef common_h
#define common_h

#include "service.h"
#include "image.h"
#include "resource_manager.h"

#include <functional>
#include <cassert>
#include <iostream>

typedef std::function<void(int)> updateFun;
typedef std::function<void()> actionFun;
typedef unsigned int uint;

//FIXME move to common.cpp to avoid duplication in unnmammed namespace
namespace {
    LeImg get_rsc(int id) {
        return LeResourceManager::get()->get_img(id);
    }
    
    std::string get_path(int id) {
        return get_rsc(id).get_path();
    }
}

#ifdef OS_ANDROID
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
