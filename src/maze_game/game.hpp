#ifndef zGAME_HPP
#define zGAME_HPP


#include "board.hpp"
#include "win.hpp"
#include "score.hpp"
#include "players.hpp"

#include "../renderer/interlayer.h"

class GameWindow : public LeInterLayer
{
public:
        GameWindow();

        ~GameWindow();

        void make_connections();

        void Quit();

public:
        void NewGame();
        void level_changed();
        void Continue();
        void win();

public:
        void init() {
                    register_image("./bin/cheese.png");
                    register_image("./bin/mouse.png");
        } 
        
        void update(unsigned int) { }  
        void draw() { m_board->draw(); }
        void notify_mouse_pressed(unsigned int) {  }
        void notify_key_pressed(unsigned int x) { m_board->keyPressEvent(x);  }
        void notify_mouse_move(unsigned int x, unsigned int y) { }


private:
        Board* m_board;

        bool m_continue;
};

#endif
