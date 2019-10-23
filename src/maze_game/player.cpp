#include "player.hpp"

Player::Player() : m_player(0,0),
                m_player_angle(180)
                   , bounding_rect(0,0,0,0)
{
}

void Player::setRect(int angle)
{
        if (angle == 90) {
                bounding_rect.setRect(m_player.x() + 20, m_player.y() +15, 30, 20);
        } else if (angle == 180) {
                bounding_rect.setRect(m_player.x() + 15, m_player.y() +20, 20, 30);
        } else if (angle == 270) {
                bounding_rect.setRect(m_player.x(), m_player.y() +15, 30, 20);
        } else {
                bounding_rect.setRect(m_player.x() + 15, m_player.y(), 20, 30);
        }
}


