#include "game.hpp"
#include <iostream>


GameWindow::GameWindow():m_continue(false)
{
        m_board = new Board();
}


void GameWindow::make_connections()
{

    
}

void GameWindow::NewGame()
{
        m_continue = false;
        m_board->newGame();
}

void GameWindow::level_changed()
{
        m_continue = true;
}

void GameWindow::win()
{
        m_continue = false;
}

void GameWindow::Continue()
{
        if (!m_continue) return;
        m_board->continueGame();
}


