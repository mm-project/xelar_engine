#ifndef enemy_h
#define enemy_h

#include "resources.h"

#include "../skeleton/mover.h"
#include "../skeleton/resource_manager.h"
#include "../skeleton/image_object.h"

#include "../renderer/sdl_wrapper.h"

#include "../physics/physics_manager.h"

#include <iostream>

class LeEnemy : public LeImageObject 
{
    public:
        
        LeEnemy():LeImageObject(int(IMG_ENEMY1),100,100,6,6) {
            //LeImageObject::set_mover(m_mover);
            init();
			m_m = LePhysicsManager::get();
			b = m_m->create_body(LeBody::Type::STATIC, m_obj.m_width, m_obj.m_height);
        }

    public:
        void init()
        {

        }

        void update(unsigned int t) {
            //m_mover.move(m_obj);
            //std::cout << this << std::endl;

			//m_m->update();

			//m_obj.m_old_y = b->get_current_x();
			//m_obj.m_old_x = b->get_current_y();
        }

        void draw() {
            LeImageObject::draw_obj_in_movement2();
        }


    private:
        LeObjMover<MV_RAND> m_mover;
		LeBody* b;
		LePhysicsManager* m_m;
};



#endif
