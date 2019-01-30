#include "maze.hpp"

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

namespace {

LePoint randomNeighbor(std::vector< std::vector<bool> >& visited, const LePoint& cell)
{
	// Find unvisited neighbors
	LePoint neighbors[4];
	int found = 0;
	if (cell.x() > 0) {
		LePoint n(cell.x() - 1, cell.y());
		if (visited.at(n.x()).at(n.y()) == false) {
			neighbors[found] = n;
			found++;
		}
	}
	if (cell.y() > 0) {
		LePoint n(cell.x(), cell.y() - 1);
		if (visited.at(n.x()).at(n.y()) == false) {
			neighbors[found] = n;
			found++;
		}
	}
	if (cell.y() < visited.at(cell.x()).size() - 1) {
		LePoint n(cell.x(), cell.y() + 1);
		if (visited.at(n.x()).at(n.y()) == false) {
			neighbors[found] = n;
			found++;
		}
	}
	if (cell.x() < visited.size() - 1) {
		LePoint n(cell.x() + 1, cell.y());
		if (visited.at(n.x()).at(n.y()) == false) {
			neighbors[found] = n;
			found++;
		}
	}

	// Return random neighbor
	if (found) {
		const LePoint& n = neighbors[rand() % found];
		visited[n.x()][n.y()] = true;
		return n;
	} else {
		return LePoint(-1,-1);
	}
}

}

void Maze::generate()
{
	m_visited = std::vector< std::vector<bool> >(columns(), std::vector<bool>(rows()));

        std::stack<LePoint> cells;
        srand(time(0));
	LePoint current(rand() % m_rows, 0);
        m_start = current;
        m_cells[current.x()][current.y()].removeLeftWall();
        cells.push(current);
	m_visited[current.x()][current.y()] = true;

        while (!cells.empty()) {
                LePoint neighbour = randomNeighbor(m_visited, current);
                if (neighbour.x() != -1){
                        mergeCells(current, neighbour);
                        cells.push(neighbour);
                        current = neighbour;
                } else {
                        current = cells.top();
                        cells.pop();
                }
        }
	m_visited.clear();
}

void Maze::generate(int columns, int rows)
{
	m_columns = columns;
	m_rows = rows;
	m_cells = std::vector< std::vector<Cell> >(m_columns, std::vector<Cell>(m_rows));
	generate();
}

void Maze::mergeCells(const LePoint& cell1, const LePoint& cell2)
{
	if (cell1.y() == cell2.y()) {
		if (cell2.x() >= cell1.x()) {
			m_cells[cell1.x()][cell1.y()].removeBottomWall();
			m_cells[cell2.x()][cell2.y()].removeTopWall();
		} else if (cell2.x() < cell1.x()) {
			m_cells[cell1.x()][cell1.y()].removeTopWall();
			m_cells[cell2.x()][cell2.y()].removeBottomWall();
		}
	} else if (cell1.x() == cell2.x()) {
		if (cell2.y() > cell1.y()) {
			m_cells[cell1.x()][cell1.y()].removeRightWall();
			m_cells[cell2.x()][cell2.y()].removeLeftWall();
		} else if (cell2.y() < cell1.y()) {
			m_cells[cell1.x()][cell1.y()].removeLeftWall();
			m_cells[cell2.x()][cell2.y()].removeRightWall();
		}
                if (cell2.y() == m_columns -1) {
                        m_cells[cell2.x()][cell2.y()].removeRightWall();
                }
	}
}

