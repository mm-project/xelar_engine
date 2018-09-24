#ifndef common_h
#define common_h

#include <functional>

typedef std::function<void()> actionFun;
typedef unsigned int uint;

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