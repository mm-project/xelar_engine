#ifndef menu_h
#define menu_h

#include <vector>

#include "object.h"
#include "menuitem.h"
#include "common.h"

class LeMenuItem;

class LeMenu {

	public: 
		
		LeMenuItem* add_item(const LeObj& o);
		LeMenuItem* add_action_item(const LeObj& o, const actionFun& f);
		
		std::vector<LeMenuItem*> get_items() const;
		LeMenuItem* get_item_by_pos(unsigned int x, unsigned int y);
		
	private:
		std::vector<LeMenuItem*> m_items;
};	

#endif