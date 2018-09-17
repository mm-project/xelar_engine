#ifndef menuitem_h
#define menuitem_h


#include "object.h"
#include "menu.h"

class LeMenu;

class LeMenuItem 
{
	public:	
		LeMenuItem(const LeObj& o) {
			m_object = o;
			m_having_submenu = false;
		}
		
		LeObj get_object() const {
			return m_object;
		}
		
		LeMenu* add_submenu(LeMenu* m) {
			if(!m_having_submenu) {
				m_submenu = m; //new LeMenu;
				m_having_submenu = true;
			}

			return m_submenu;
		}
		
		bool has_submenu() {
			return m_having_submenu;
		}
		
		LeMenu* get_submenu() {
			return m_submenu;
		}
		
		void execute_action() {
			//m_function();
		}
		//LeMenuItem* add_item(const std::string& name) {
			//m_children->add_item(name);
		//}
		//std::function action()
		
	private:
		LeMenu* m_submenu;
		LeObj m_object;
		bool m_having_submenu;
		bool m_has_action;
		//std::function m_function;
};


#endif