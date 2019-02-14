#ifndef _player_hpp_
#define _player_hpp_

#include "../skeleton/point.h"
#include "../skeleton/rect.h"

struct Player
{
        Player();

        void setRect(int);

        LePoint m_player;
        int m_player_angle;
        LeRect bounding_rect;
};

#endif
