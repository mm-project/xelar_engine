#ifndef mover_h
#define mover_h

#include "object.h"

#include <cassert>
#include <iostream>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum LeMoverType { MV_STRAIGHT, MV_RAND, MV_RAND_ORTHO, MV_LINE };

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


template < LeMoverType >
class LeObjMover;


template<>
class LeObjMover<MV_STRAIGHT> : public LeObjMoverBase
{
    public:	
        void move(LeObj& obj) {
            step(obj);
        }
};


template<>
class LeObjMover<MV_RAND> : public LeObjMoverBase
{
    public:	
        void move(LeObj& obj) {
            step(obj);
            if ( obj.m_old_x == obj.m_x && obj.m_old_y ==obj.m_y ) {
                //assert(0);
                rand_position(obj);
            }		
        }
};

template<>
class LeObjMover<MV_LINE> : public LeObjMoverBase
{
    public:	
        void move(LeObj& obj) {
            step(obj);
            if ( -900 == obj.m_old_y ) obj.m_old_x = rand()%600;
            if ( obj.m_old_y == obj.m_y  ) {
                rand_line(obj);
            }		
        }
};


#endif
