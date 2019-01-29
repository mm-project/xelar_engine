#include "point.hpp"

point::point(int x, int y)
	: m_x_coord(x), m_y_coord(y)
{}

void point::set_x(int x)
{
	m_x_coord = x;
}

void point::set_y(int y)
{
	m_y_coord = y;
}

int point::x() const
{
	return m_x_coord;
}

int point::y() const
{
	return m_y_coord;
}