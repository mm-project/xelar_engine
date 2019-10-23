#include "win.hpp"
#include "game_window.hpp"


#include "../skeleton/state_manager.h"
#include "../skeleton/common.h"

void WinWindow::on_mouse_clicked()
{
     LeStateManager::get()->set_state(ST_GAME);
}

void WinWindow::draw()
{
//FIXME
    
}
