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