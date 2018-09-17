#ifndef image_h
#define image_h

#include <string>
#include <map>

class LeImg 
{
	public:	
		LeImg(const std::pair<std::string, std::pair<unsigned int ,unsigned int > > & p) {
			m_path = p.first;
			m_w = p.second.first;
			m_h = p.second.second;
		}
		
		std::string get_path() const {
			return m_path;
		}
		
		
		unsigned int get_width() const {
			return m_w;
		}
		
		unsigned int get_height() const {
			return m_h;
		}
		
		
	private:
		unsigned int m_w;
		unsigned int m_h;
		std::string m_path;
};



#endif