#include "cell.hpp"

cell::cell(): m_wall(0)
{
	m_wall |= RIGHT;
	m_wall |= LEFT;
	m_wall |= TOP;
	m_wall |= BUTTOM;
}

bool cell::left_wall() const 
{
	return (m_wall & LEFT);
}

bool cell::right_wall() const
{
	return (m_wall & RIGHT);
}

bool cell::top_wall() const
{
	return (m_wall & TOP);
}

bool cell::buttom_wall() const
{
	return (m_wall & BUTTOM);
}

void cell::remove_left_wall()
{
	m_wall &= ~LEFT;
}

void cell::remove_right_wall()
{
	m_wall &= ~RIGHT;
}

void cell::remove_top_wall()
{
	m_wall &= ~TOP;
}

void cell::remove_buttom_wall()
{
	m_wall &= ~BUTTOM;
}