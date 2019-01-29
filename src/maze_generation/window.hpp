#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "maze_generator_interface.hpp"
#include "../renderer/interlayer.h"

class maze_generator_interface;

//LeInterLayer is scene controller ! :)
class window : public LeInterLayer
{
    public:
            window();  
    

    public:
            virtual void init() {}
            virtual void draw();
            virtual void update(unsigned int t) {}
            
            
    public:         
            virtual void notify_mouse_pressed(unsigned int) {}
            virtual void notify_key_pressed(unsigned int) {}
            virtual void notify_mouse_move(unsigned int x, unsigned int y) {}

private:
	maze_generator_interface* m_maze;
};
#endif
