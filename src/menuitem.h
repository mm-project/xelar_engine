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
		LeMenuItem(const LeObj& o, const actionFun& f = nullptr );		

	public:	
		LeObj get_object() const;
		LeMenu* add_submenu(LeMenu* m);
		bool has_submenu();
		LeMenu* get_submenu();
		void execute_action();
		
	private:
		LeMenu* m_submenu;
		LeObj m_object;
		bool m_having_submenu;
		bool m_has_action;
		actionFun m_action_function;
};



#endif