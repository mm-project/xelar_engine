#include "win.hpp"
#include "game.hpp"


#include "../skeleton/state_manager.h"

void WinWindow::on_mouse_clicked()
{
     LeStateManager::get()->set_state(ST_GAME);
}

void WinWindow::draw()
{
    draw_image("./bin/Win.png",0,0,5,5);
}
