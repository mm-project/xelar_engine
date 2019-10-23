#ifndef _cell_hpp_
#define _cell_hpp_

class Cell
{
public:
	Cell();

	bool leftWall() const
		{ return m_left_wall; }
	bool rightWall() const
		{ return m_right_wall; }
	bool topWall() const
		{ return m_top_wall; }
	bool bottomWall() const
		{ return m_bottom_wall; }
	void removeLeftWall()
		{ m_left_wall = false; }
	void removeRightWall()
		{ m_right_wall = false; }
	void removeTopWall()
		{ m_top_wall = false; }
	void removeBottomWall()
		{ m_bottom_wall = false; }

private:
	bool m_left_wall;
	bool m_right_wall;
	bool m_top_wall;
	bool m_bottom_wall;
};

#endif

