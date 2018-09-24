#ifndef interlayer_h
#define interlayer_h

#include "sdl_wrapper.h"

class LeInterLayer : public LeSdlWrapper
{
	public:
		///rendering interlayer
		//virtual void scene_prepare() { draw(); } ;
		
		//controlls interlayer
		virtual void notify_mouse_pressed(unsigned int) = 0;
		virtual void notify_key_pressed(unsigned int) = 0;
		virtual void notify_mouse_move(unsigned int x, unsigned int y) = 0;
		
		virtual void draw() = 0;
		virtual void init() = 0;
		virtual void update(unsigned int) = 0;	
};


#endif