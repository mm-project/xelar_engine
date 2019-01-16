#ifndef enemy_h
#define enemy_h

#include "../skeleton/mover.h"
#include "../skeleton/resource_manager.h"
#include "../skeleton/image_object.h"

#include "../renderer/sdl_wrapper.h"


#include <iostream>

class LeEnemy : public LeImageObject 
{
    public:
        
        LeEnemy():LeImageObject(IMG_ENEMY1,100,100,6,6) {
            //LeImageObject::set_mover(m_mover);
            init();
        }

    public:
        void init()
        {

        }

        void update(unsigned int t) {
            m_mover.move(m_obj);
            //std::cout << this << std::endl;

        }

        void draw() {
            LeImageObject::draw_obj_in_movement2();
        }


    private:
        LeObjMover<MV_RAND> m_mover;
};



#endif
