#ifndef menu_h
#define menu_h

#include <vector>
#include <string>

class LeMenu;

class LeMenuItem 
{
	public:	
		LeMenu* get() {
			//m_children = new LeMenu;
			return m_children;
		}
		
		//LeMenuItem* add_item(const std::string& name) {
			//m_children->add_item(name);
		//}
		
	private:
		LeMenu* m_children;
};


class LeMenu {

	public: 
		
		LeMenuItem* add_item(const std::string& name) {
				LeMenuItem* item = new LeMenuItem;
				m_items.push_back(item);
				return item;
		}
		
		std::vector<LeMenuItem*> get_items() {
			return m_items;
		}
			
	private:
		std::vector<LeMenuItem*> m_items;
};	

#endif