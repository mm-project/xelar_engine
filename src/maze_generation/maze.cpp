#include "maze.hpp"

#include <cstdlib>
#include <stack>
#include <ctime>

void maze_generator::generate(size_t columns, size_t rows)
{
	m_columns = columns;
	m_rows = rows;
	m_cells = std::vector< std::vector<cell> >(m_columns, std::vector<cell>(m_rows));
	m_visited = std::vector < std::vector<bool> >(m_columns, std::vector<bool>(m_rows));

	generate();
}

void maze_generator::generate()
{
	srand(time(0));
	point current(rand() % m_rows, 0);
	m_start = current;
	std::stack<point> cells;
	m_cells[m_start.x()][m_start.y()].remove_left_wall(); //maybe right wall
	cells.push(m_start);
	m_visited[m_start.x()][m_start.y()] = true;

	while (!cells.empty()) {
		point neighbour = remove_neighbour(current);
		if (neighbour.x() != -1) {
			merge_cells(current, neighbour);
			cells.push(neighbour);
			current = neighbour;
		}
		else {
			current = cells.top();
			cells.pop();
		}
	}
	m_visited.clear();
}

point maze_generator::remove_neighbour(const point& cell)
{
	// find unvisited neighbours
	point neighbours[4];
	int found = 0;
	if (cell.x() > 0) {
		point n(cell.x() - 1, cell.y());
		if (m_visited.at(n.x()).at(n.y()) == false) {
			neighbours[found] = n;
			found++;
		}
	}
	if (cell.y() > 0) {
		point n(cell.x(), cell.y() - 1);
		if (m_visited.at(n.x()).at(n.y()) == false) {
			neighbours[found] = n;
			found++;
		}
	}
	if (cell.y() < m_visited.at(cell.x()).size() - 1) {
		point n(cell.x(), cell.y() + 1);
		if (m_visited.at(n.x()).at(n.y()) == false) {
			neighbours[found] = n;
			found++;
		}
	}
	if (cell.x() < m_visited.size() - 1) {
		point n(cell.x() + 1, cell.y());
		if (m_visited.at(n.x()).at(n.y()) == false) {
			neighbours[found] = n;
			found++;
		}
	}

	// get random retrun
	if (found) {
		const point& n = neighbours[rand() % found];
		m_visited[n.x()][n.y()] = true;
		return n;
	} 
	return point(-1, -1);
}

void maze_generator::merge_cells(const point& p1, const point& p2)
{
	if (p1.y() == p2.y()) {
		if (p1.x() < p2.x()) {
			m_cells[p1.x()][p1.y()].remove_buttom_wall();
			m_cells[p2.x()][p2.y()].remove_top_wall();
		}
		else {
			m_cells[p1.x()][p1.y()].remove_top_wall();
			m_cells[p2.x()][p2.y()].remove_buttom_wall();
		}
	}
	else if (p1.x() == p2.x()) {
		if (p1.y() < p2.y()) {
			m_cells[p1.x()][p1.y()].remove_right_wall();
			m_cells[p2.x()][p2.y()].remove_left_wall();
		}
		else {
			m_cells[p1.x()][p1.y()].remove_left_wall();
			m_cells[p2.x()][p2.y()].remove_right_wall();
		}
		if (p2.y() == m_columns - 1) {
			m_cells[p2.x()][p2.y()].remove_right_wall();
		}
	}
}