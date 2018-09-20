#ifndef common_h
#define common_h

#include <functional>

typedef std::function<void()> actionFun;
typedef unsigned int uint;


#ifdef OS_ANDROID
	#define LOG SDL_Log
#else
	#define LOG printf
#endif

#ifndef DEBUG
#	define LOG ;
#endif


#endif