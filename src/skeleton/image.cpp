#include "image.h"

LeImg::LeImg(const std::pair<std::string, std::pair<unsigned int ,unsigned int > > & p) {
	m_path = p.first;
	m_w = p.second.first;
	m_h = p.second.second;
}

std::string LeImg::get_path() const {
	return m_path;
}


unsigned int LeImg::get_width() const {
	return m_w;
}

unsigned int LeImg::get_height() const {
	return m_h;
}

		



