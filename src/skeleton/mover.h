#ifndef mover_h
#define mover_h

#include "object.h"

#include <cassert>
#include <iostream>

enum LeMoverType { MV_STRAIGHT, MV_RAND, MV_RAND_ORTHO };

class LeObjMoverBase
{
    public:
        LeObjMoverBase() {
        }
        
    public:
        
        void step(LeObj& obj) {
            //assert(0);
            if ( obj.m_x < obj.m_old_x ) obj.m_old_x--;
            if ( obj.m_x > obj.m_old_x ) obj.m_old_x++;
            if ( obj.m_y < obj.m_old_y ) obj.m_old_y--;
            if ( obj.m_y > obj.m_old_y ) obj.m_old_y++;
        }
        
        void rand_position(LeObj& o) {
            o.m_x = rand()%900;
            o.m_y = rand()%900;
        }

        void rand_line(LeObj& o) {
            o.m_old_y = 1000;
            o.m_y = 0;
            o.m_x = o.m_old_x;
        }

    //private:
};

/*
void LeGameState::update_automove_object(LeObj& obj, bool rand) {
	update_object_position(obj);
	if ( obj.m_old_x ==obj.m_x && obj.m_old_y ==obj.m_y ) {
		//assert(0);
		if(rand) rand_position(obj);
	}		
}

void LeGameState::update_automove_object2(LeObj& obj) {
	update_object_position(obj);
	if ( -300 == obj.m_old_y ) obj.m_old_x = rand()%600;
	if ( obj.m_old_y == obj.m_y  ) {
		//assert(0);
		rand_line(obj);
	}		
}
*/

template < LeMoverType >
class LeObjMover;


template<>
class LeObjMover<MV_STRAIGHT> : public LeObjMoverBase
{
    public:	
        void move(LeObj& o) {
            step(o);
        }
};


template<>
class LeObjMover<MV_RAND> : public LeObjMoverBase
{
    public:	
        void move(LeObj& o) {
            step(o);
        }
};


#endif
