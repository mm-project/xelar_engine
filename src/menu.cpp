#include "menuitem.h"
#include "menu.h"


#include <iostream>

LeMenuItem* LeMenu::add_item(const LeObj& o) {
		LeMenuItem* item = new LeMenuItem(o);
		m_items.push_back(item);
		return item;
}

std::vector<LeMenuItem*>  LeMenu::get_items() const {
	return m_items;
}
	

LeMenuItem*  LeMenu::get_item_by_pos(unsigned int x, unsigned int y)	{
	for(int i = 0; i<m_items.size(); ++i) {
		if ( m_items[i]->get_object().is_cord_in_my_bbox(x,y) )
			return m_items[i];
	}
	return 0;
}
