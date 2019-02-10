#ifndef image_h
#define image_h

#include <string>
#include <map>

#include <cassert>

class LeImg 
{
	public:	
        LeImg():m_w(0),m_h(0),m_path("ERROR"),is_init(false) {
         //assert(0);
        }
        
		LeImg(const std::pair<std::string, std::pair<unsigned int ,unsigned int > > & p);

	public:	
		std::string get_path() const;
		unsigned int get_width() const;
		unsigned int get_height() const;
		
		
	private:
		unsigned int m_w;
		unsigned int m_h;
		std::string m_path;
        bool is_init;
};



#endif
