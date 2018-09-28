#ifndef object_h
#define object_h

#include "image.h"
#include "common.h"

#include <string>

class LeObj {

	public: 
		LeObj(); 
		LeObj(const  LeImg& img, unsigned int x, unsigned int y, unsigned int crop_factor_x, unsigned int crop_factor_y );

	public: 
		void change_img(const  LeImg& img);
		bool is_cord_in_my_bbox(unsigned x, unsigned y);
		bool is_intersecting_with_other_obj(const LeObj& o);
		
		bool operator==(const LeObj& o) {
			return
			m_uninitialized == o.m_uninitialized &&
			m_img_path == o.m_img_path &&
			m_width == o.m_width &&
			m_height == o.m_height &&
			m_x == o.m_x &&
			m_y == o.m_y &&
			m_c_x == o.m_c_x &&
			m_c_y == o.m_c_y &&
			m_old_x == o.m_old_x &&
			m_old_y == o.m_old_y &&
			m_angle == o.m_angle &&
			m_need_flip == o.m_need_flip  &&
			m_visible == o.m_visible &&
			m_movable == o.m_movable;
			/**/
		}
		
		
	//private:	
		std::string m_img_path;
		unsigned int m_old_x;
		unsigned int m_old_y;
		unsigned int m_x;
		unsigned int m_y;
		unsigned int m_c_x;
		unsigned int m_c_y;
		unsigned int m_angle;
		bool m_need_flip; 
		uint m_flip_mode; 
		
		unsigned m_width;
		unsigned m_height;
		
		bool m_uninitialized;

		bool m_visible;
		bool m_movable;

};	


#endif