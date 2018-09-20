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
		m_width = img.get_width()/crop_factor_y;
		m_height = img.get_height()/crop_factor_x;
		m_x = x;
		m_y = y;
		m_c_x = crop_factor_x;
		m_c_y = crop_factor_y;
		m_old_x = x;
		m_old_y = y;	
	}
	
	void change_img(const  LeImg& img) {
		
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
	
	bool is_intersecting(const LeObj& o) {
		
		//return (m_x < o.m_x && m_x + m_height > o.m_x + o.m_height &&
		//	m_y > o.m_y && m_y + m_width < o.m_y + o.m_width);
	
		Point l1,r1,l2,r2;
		l1.x = m_x;
		l1.y = m_y;
		r1.x = m_x + m_width;
		r1.y = m_y + m_height;
		
		l2.x = o.m_x;
		l2.y = o.m_y;
		r2.x = o.m_x + o.m_width;
		r2.y = o.m_y + o.m_height;
		
		return doOverlap(l1,r1,l2,r2);
	}
	
	struct Point 
	{ 
		int x, y; 
	}; 
  
	bool doOverlap(Point l1, Point r1, Point l2, Point r2) 
	{ 
		// If one rectangle is on left side of other 
		if (l1.x > r2.x || l2.x > r1.x) 
			return false; 
	  
		// If one rectangle is above other 
		if (l1.y < r2.y || l2.y < r1.y) 
			return false; 
		
		return true;
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