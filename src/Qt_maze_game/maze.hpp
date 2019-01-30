#ifndef _maze_hpp_
#define _maze_hpp_

#include "cell.hpp"

#include "../skeleton/point.h"

#include <vector>

class Maze
{
public:
	virtual ~Maze()
		{ }

	int columns() const
		{ return m_columns; }
	int rows() const
		{ return m_rows; }
	const Cell& cell(int column, int row) const
		{ return m_cells.at(column).at(row); }
	Cell& cellMutable(int column, int row)
		{ return m_cells[column][row]; }

	void generate(int columns, int rows);
	//bool load();
	//void save() const;

        LePoint start_point() const {return m_start;}
protected:
	void mergeCells(const LePoint& cell1, const LePoint& cell2);

private:
	void generate();

	int m_columns;
	int m_rows;
        std::vector< std::vector<bool> > m_visited;
        std::vector< std::vector<Cell> > m_cells;
        LePoint m_start;
};

#endif
