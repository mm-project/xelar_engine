#include "window.hpp"

#include "maze.hpp"


window::window()
{
	m_maze = new maze_generator();
	m_maze->generate(20, 20);
}

void window::draw()
{
	set_drawing_color(100,100,100);
    int r = 20, c = 20;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			const cell& cell = m_maze->get_cell(i, j);
			if (cell.top_wall()) {
				draw_line(r, c, r + 20, c);
			}
			if (cell.left_wall()) {
				draw_line(r, c, r, c + 20);
			}
			if (j == 19 && cell.right_wall()) {
				draw_line(r + 20, c, r + 20, c + 20);
			}
			if (i == 19) {
				draw_line(r, c + 20, r + 20, c + 20);
			}
			r += 20;
		}
		r = 20;
		c += 20;
	}
}
