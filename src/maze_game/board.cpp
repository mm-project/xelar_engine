#include "board.hpp"
#include "maze.hpp"
#include "player.hpp"
#include "level.hpp"
#include "maze_game.hpp"

#include "../renderer/sdl_wrapper.h"
#include "../skeleton/drawing_rect.h"
#include "../skeleton/common.h"

#include <iostream>

#define RENDERER LeSdlWrapper::m_renderer_controller

Board::Board()
        : m_maze(0)
        , level_count(1)
{
        m_player = new Player();
        m_level = new Level1();
        
        //connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(repaint()));
        newGame();
        loadSettings();

}

Board::~Board()
{
        delete m_maze;
        delete m_player;
}

void Board::newGame()
{
        delete m_level;
        m_level = new Level1();
        level_count = 1;
        m_player->m_player_angle = 90;
        generate();
        m_player->m_player.ry() = m_start.x() * m_level->get_delta_column() + 5;
        //update();
}

void Board::generate()
{
        int columns = m_level->get_column();
        int rows = columns;

        // Create new maze
        delete m_maze;
        m_maze = new Maze;
        m_maze->generate(columns, rows);
        m_start = m_maze->start_point();
}

void Board::draw()
{
        renderMaze();
        RENDERER->getpixel(m_player->m_player.x(),m_player->m_player.y());
}

void Board::renderMaze()
{
        RENDERER->set_drawing_color(255,0,0);
        int r = 5, c = 5;
        for (int i = 0; i < m_level->get_column(); ++i ) {
              for (int j = 0; j < m_level->get_row(); ++j) {
                        const Cell& cell = m_maze->cell(i,j);
                        if (cell.topWall()) {
                                RENDERER->draw_line(r,c, r + m_level->get_delta_row(), c);
                        }
                        if (cell.leftWall()) {
                                RENDERER->draw_line(r,c,r, c + m_level->get_delta_column());
                        }
                        if (j == m_level->get_row() -1 && cell.rightWall())
                        {
                                RENDERER->draw_line(r + m_level->get_delta_row(),c,r + m_level->get_delta_row() , c + m_level->get_delta_column());
                        }
                        if (i == m_level->get_column() - 1) {
                               RENDERER->draw_line(r,c + m_level->get_delta_column(),r+m_level->get_delta_row(),c + m_level->get_delta_column());
                        }
                        r+=m_level->get_delta_row();
              }
              r = 5 ;//m_level->get_delta_row();
              c += m_level->get_delta_column();
        }

        RENDERER->draw_image(get_rsc(int(IMG_CHEESE)).get_path().c_str(),50,50,2,2);
        RENDERER->draw_image(get_rsc(int(IMG_PLAYER)).get_path().c_str(),m_player->m_player.y(),m_player->m_player.x(),1,1,m_player->m_player_angle,false,1);

        //RENDERER->set_drawing_color(0,0,255);
        //RENDERER->draw_rect(m_player->bounding_rect.y1(),m_player->bounding_rect.x1(),m_player->bounding_rect.h(),m_player->bounding_rect.w());
        
        RENDERER->set_drawing_color(255,0,255);
        RENDERER->draw_point(m_player->m_player.y(),m_player->m_player.x());//,10);

}

bool Board::check_in_bounding_box()
{
    /*    
    //RENDERER->getpixel(m_player->bounding_rect.x1(),m_player->bounding_rect.y1());
        int i = m_player->bounding_rect.x1() / m_level->get_delta_column();
        int j = m_player->bounding_rect.y1() / m_level->get_delta_row();
        i = i * m_level->get_delta_column() + 5;
        j = j * m_level->get_delta_row() + 5;
        for (int i_ = i; i_ < i + m_level->get_delta_column(); ++i_) {
                r.draw1(i_,j);
                //tmp[0]=std::make_pair(i_,j);
                if (m_player->bounding_rect.contains(i_, j)) {
                        //pixel is not red
                        if (RENDERER->getpixel(i_,j) != 255) {
                                return true;
                        }
                }
        }
        i = i + m_level->get_delta_column();
        for (int j_= j; j_ < j + m_level->get_delta_row(); ++j_) {
                //tmp[1]=std::make_pair(i,j_);    
                if (m_player->bounding_rect.contains(i, j_)) {
                        //color = img.pixel(i, j_);
                        if (RENDERER->getpixel(i,j_) != 255) {
                                return true;
                        }
                }
        }
        i -= m_level->get_delta_column();
        for (int j_= j; j_ < j + m_level->get_delta_row(); ++j_) {
                //tmp[2]=std::make_pair(i,j_);
                if (m_player->bounding_rect.contains(i, j_)) {
                        //color = img.pixel(i, j_);
                        if (RENDERER->getpixel(i,j_) != 255) {
                                return true;
                        }
                }
        }
        j = j + m_level->get_delta_row();
        for (int i_ = i; i_ < i + m_level->get_delta_column(); ++i_) {
                //RENDERER->set_drawing_color(255,0,255);
                //RENDERER->draw_circle(i_,j,5);
                if (m_player->bounding_rect.contains(i_, j)) {
                        //color = img.pixel(i_, j);
                        if (RENDERER->getpixel(i_,j) != 255) {
                                return true;
                        }
                }
        }
     /**/
     return false;
}

void Board::keyPressEvent(int keypress)
{
        //RENDERER->set_drawing_color(0,0,255);
        
        
        LeRect rect(910,400, 50, 50);
        //std::cout << keypress << std::endl;
        if (keypress == 120) {
            RENDERER->fzoomin(2);
        }

        if (keypress == 122) {
            RENDERER->fzoomout(2);
        }

        if (keypress == m_left) {
                m_player->m_player_angle = 270;
                int i = 0;
                while (i < 7) {
                        if (check_in_bounding_box()) {
                        break;
                        }
                        ++i;
                        --m_player->m_player.rx();
                }
                if (rect.contains(m_player->m_player.x() + 46, m_player->m_player.y() + 26)) {
                        go_to_next_level();
                }
                m_player->setRect(270);
                if (i != 7) {
                        return;
                }
                m_player->m_player_angle = 270;
        } else if (keypress == m_right) {
                m_player->m_player_angle = 90;
                int i = 0;
                while (i < 7) {
                        if (check_in_bounding_box()) {
                        break;
                        }
                        ++i;
                        ++m_player->m_player.rx();
                }
                if (rect.contains(m_player->m_player.x() + 46, m_player->m_player.y() + 26)) {
                        go_to_next_level();
                }
                m_player->setRect(90);
                if (i != 7) {
                        return;
                }
                m_player->m_player_angle = 90;
        } else if (keypress == m_up) {
                m_player->m_player_angle = 360;
                int i = 0;
                while (i < 7) {
                        if (check_in_bounding_box()) {
                        break;
                        }
                        ++i;
                        --m_player->m_player.ry();
                }
                if (rect.contains(m_player->m_player.x() + 46, m_player->m_player.y() + 26)) {
                        go_to_next_level();
                }
                m_player->setRect(360);
                if (i != 7) {
                        return;
                }
                m_player->m_player_angle = 360;
        } else if (keypress == m_down) {
                m_player->m_player_angle = 180;
                int i = 0;
                while (i < 7) {
                        if (check_in_bounding_box()) {
                        break;
                        }
                        ++i;
                        ++m_player->m_player.ry();
                }
                if (rect.contains(m_player->m_player.x() + 46, m_player->m_player.y() + 26)) {
                        go_to_next_level();
                }
                m_player->setRect(180);
                if (i != 7) {
                        return;
                }
                m_player->m_player_angle = 180;
        } else {
                return;
        }
        //update();

       
}

void Board::loadSettings()
{
        m_up = 1073741906;
        m_down = 1073741905;
        m_left = 1073741904;
        m_right = 1073741903;
        //update();
}

void Board::go_to_next_level()
{
        /*
        m_player->m_player.rx() = 0;
        m_player->m_player.ry() = 0;
        m_level->changeState(this);

        if (level_count == 3) {
                LePostman::notify("win");
        } else {
                ++level_count;
                LePostman::notify("level_changed");
        } */
}

void Board::continueGame()
{
        m_player->m_player_angle = 90;
        generate();
        m_player->m_player.ry() = m_start.x() * m_level->get_delta_column() + 5;
        //update();
}

void Board::reset()
{
        m_player->m_player_angle = 180;
        LePoint t(0, 10);
        m_start = t;
        m_player->m_player = t;
        //update();
}

void Board::changeState(Level_interface* i)
{
        delete m_level;
        m_level = i;
}
