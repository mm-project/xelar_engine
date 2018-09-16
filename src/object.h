#ifndef object_h
#define object_h

#include <string>

class LeObj {

public: 
	LeObj() {
	//fixme 
	}
	
	LeObj(const char* imgnmae, unsigned int x,	unsigned int y, unsigned int c_x, unsigned int c_y)  {
		m_img_path = imgnmae;
		m_x = x;
		m_y = y;
		m_c_x = c_x;
		m_c_y = c_y;
		m_old_x = 0;
		m_old_y = 0;
	}
	
	bool is_intersecting() {
	
	}
	
std::string m_img_path;
unsigned int m_old_x;
unsigned int m_old_y;
unsigned int m_x;
unsigned int m_y;
unsigned int m_c_x;
unsigned int m_c_y;
};	


#endif