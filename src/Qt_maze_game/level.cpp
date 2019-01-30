#include "level.hpp"
#include "board.hpp"

Level_interface::Level_interface(int c, int r, int dc, int dr)
        : m_column(c)
          , m_row(r)
          , m_delta_column(dc)
          , m_delta_row(dr)
{}

Level_interface::~Level_interface()
{}

Level1::Level1() : Level_interface(13, 13, 50, 50)
{}

Level1::~Level1()
{}

void Level1::changeState(Board* b)
{
        b->changeState(new Level2());
}

int Level1::get_column() const
{
        return m_column;
}

int Level1::get_row() const
{
        return m_row;
}

int Level1::get_delta_column() const
{
        return m_delta_column;
}

int Level1::get_delta_row() const
{
        return m_delta_row;
}

Level2::Level2() : Level_interface(16, 16, 42, 42)
{}

Level2::~Level2()
{}

void Level2::changeState(Board* b)
{
        b->changeState(new Level3());
}

int Level2::get_column() const
{
        return m_column;
}

int Level2::get_row() const
{
        return m_row;
}

int Level2::get_delta_column() const
{
        return m_delta_column;
}

int Level2::get_delta_row() const
{
        return m_delta_row;
}

Level3::Level3() : Level_interface(17, 17, 39, 39)
{}

Level3::~Level3()
{}

void Level3::changeState(Board* b)
{
        b->changeState(new Level1());
}

int Level3::get_column() const
{
        return m_column;
}

int Level3::get_row() const
{
        return m_row;
}

int Level3::get_delta_column() const
{
        return m_delta_column;
}

int Level3::get_delta_row() const
{
        return m_delta_row;
}
