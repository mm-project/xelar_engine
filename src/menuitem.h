#ifndef menuitem_h
#define menuitem_h


#include "object.h"

class LeMenuItem 
{
	public:	
		LeMenuItem(const LeObj& o) {
			m_object = o;
		}
		
		LeObj get_object() const {
			return m_object;
		}
		
		//LeMenu* create_submenu() {
			//m_children = new LeMenu;
		//	return m_submenu;
		//}
		
		//LeMenuItem* add_item(const std::string& name) {
			//m_children->add_item(name);
		//}
		
	private:
		//LeMenu* m_submenu;
		LeObj m_object;
};


#endif