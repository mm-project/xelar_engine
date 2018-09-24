#ifndef image_h
#define image_h

#include <string>
#include <map>

class LeImg 
{
	public:	
		LeImg(const std::pair<std::string, std::pair<unsigned int ,unsigned int > > & p);

	public:	
		std::string get_path() const;
		unsigned int get_width() const;
		unsigned int get_height() const;
		
		
	private:
		unsigned int m_w;
		unsigned int m_h;
		std::string m_path;
};



#endif