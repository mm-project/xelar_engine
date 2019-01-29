#ifndef MAZE_GENERATOR_INTERFACE_HPP
#define MAZE_GENERATOR_INTERFACE_HPP

#include "cell.hpp"

#include <vector>

class maze_generator_interface
{
public:
	maze_generator_interface() : m_columns(0), m_rows(0) {}

	virtual ~maze_generator_interface() {}

public:
	virtual int columns() const { return m_columns; }
	virtual int rowws() const { return m_rows; }
	
	virtual void generate(size_t, size_t) = 0;

	const cell& get_cell(const size_t& i, const size_t& j) { return m_cells[i][j]; }
protected:
	size_t m_columns;
	size_t m_rows;

	std::vector<std::vector<cell>> m_cells;
};

#endif