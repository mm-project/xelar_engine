#ifndef MAZE_GENERATOR_HPP
#define MAZE_GENERATOR_HPP

#include "point.hpp"
#include "maze_generator_interface.hpp"

// recursive backtracer algorithm
class maze_generator : public maze_generator_interface
{
public:
	
	virtual void generate(size_t, size_t) override;

private:	
	void generate();

	point remove_neighbour(const point&);
	void merge_cells(const point&, const point&);

private:
	std::vector<std::vector<bool>> m_visited;	

	point m_start;
};

#endif