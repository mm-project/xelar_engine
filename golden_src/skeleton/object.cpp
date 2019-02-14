#include "object.h"
#include "image.h"
#include "common.h"

#include <string>
#include <iostream>

LeObj::LeObj() {
//fixme 
	m_uninitialized = false;
	
}

LeObj::LeObj(const  LeImg& img, unsigned int x, unsigned int y, unsigned int crop_factor_x, unsigned int crop_factor_y )
{
	m_uninitialized = true;
	m_img_path = img.get_path();
	m_width = img.get_width()/crop_factor_y;
	m_height = img.get_height()/crop_factor_x;
	m_x = x;
	m_y = y;
	m_c_x = crop_factor_x;
	m_c_y = crop_factor_y;
	m_old_x = x;
	m_old_y = y;
	m_angle = 0;
	m_need_flip = false;
	m_visible = true;
	m_movable = true;;

}

void LeObj::change_img(const  LeImg& img) {
	
}

bool LeObj::is_cord_in_my_bbox(unsigned x, unsigned y) 
{
	
	return (x > m_x && x < m_x + m_height &&
			y > m_y && y < m_y + m_width);
		
}

bool LeObj::is_intersecting_with_other_obj(const LeObj& o) {
	return is_cord_in_my_bbox(o.m_old_x,o.m_old_y) || is_cord_in_my_bbox(o.m_old_x+o.m_height,o.m_old_y+o.m_width);

}

