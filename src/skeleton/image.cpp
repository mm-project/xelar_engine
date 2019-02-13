#include "image.h"

#include <iostream>
#include <cassert>

LeImg::LeImg(const std::pair<std::string, std::pair<unsigned int ,unsigned int > > & p) {
	std::cout << "construct " << p.first << std::endl;
    //assert(0);
    m_path = p.first;
	m_w = p.second.first;
	m_h = p.second.second;
    is_init = true;
}

std::string LeImg::get_path() const {
    //assert(is_init);
    std::cout << "--->>>>>" << m_path  << std::endl;
    return m_path;
}


unsigned int LeImg::get_width() const {
	return m_w;
}

unsigned int LeImg::get_height() const {
	return m_h;
}

		



