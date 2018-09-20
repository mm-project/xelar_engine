#ifndef menuitem_h
#define menuitem_h


#include "object.h"
#include "menu.h"
#include "common.h"

#include <functional>

class LeMenu;



class LeMenuItem 
{
	public:	
		LeMenuItem(const LeObj& o, const actionFun& f = nullptr ) {
			m_object = o;
			m_having_submenu = false;
			m_has_action = false;
			m_action_function = f;
			if ( m_action_function != nullptr ) m_has_action = true;
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
			if (!m_has_action) return;
			m_action_function();
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
		actionFun m_action_function;
};

//class LeMenuItemWithAction
//{
//	
//};



#endif