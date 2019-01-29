#ifndef CELL_HPP
#define CELL_HPP

class cell
{
	enum wall_type{ 
		RIGHT = 1,
		LEFT = 2,
		TOP = 4,
		BUTTOM = 8
	};

public:
	cell();

	bool left_wall() const;
	bool right_wall() const;
	bool top_wall() const;
	bool buttom_wall() const;

	void remove_left_wall();
	void remove_right_wall();
	void remove_top_wall();
	void remove_buttom_wall();

private:
	int m_wall;	
};
#endif
