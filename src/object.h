#ifndef object_h
#define object_h

#include "image.h"

#include <string>
#include <iostream>

class LeObj {

public: 
	LeObj() {
	//fixme 
	}
	
	LeObj(const  LeImg& img, unsigned int x, unsigned int y, unsigned int crop_factor_x, unsigned int crop_factor_y )
	{
		m_img_path = img.get_path();
		m_width = img.get_width();
		m_height = img.get_height();
		m_x = x;
		m_y = y;
		m_c_x = crop_factor_x;
		m_c_y = crop_factor_y;
		m_old_x = x;
		m_old_y = y;	
	}
	
	/*
	LeObj(const char* imgnmae, unsigned int x,	unsigned int y, unsigned int c_x, unsigned int c_y, 
		unsigned width = 0, unsigned height = 0) 
		: m_width(width), m_height(height)		
	{
		m_img_path = imgnmae;
		m_x = x;
		m_y = y;
		m_c_x = c_x;
		m_c_y = c_y;
		m_old_x = 0;
		m_old_y = 0;
	}
	*/
	
	bool is_cord_in_my_bbox(unsigned x, unsigned y) 
	{
			//std::cout << "(" << m_x << " " << m_y << ")   " << "(" << x << " " << y << ")   " << "(" << m_x + m_width << " " <<  m_y + m_height << ")" << std::endl;
			//  m_y + m_height
			return (x > m_x && x < m_x + m_height &&
					y > m_y && y < m_y + m_width);
			
	}
	
std::string m_img_path;
unsigned int m_old_x;
unsigned int m_old_y;
unsigned int m_x;
unsigned int m_y;
unsigned int m_c_x;
unsigned int m_c_y;
unsigned m_width;
unsigned m_height;
};	


#endif