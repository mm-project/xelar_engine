#ifndef POINT_HPP
#define POINT_HPP

class point
{
public:
	point(int = 0, int = 0);

	void set_x(int);
	void set_y(int);

	int x() const;
	int y() const;

private:
	int m_x_coord;
	int m_y_coord;
};

#endif