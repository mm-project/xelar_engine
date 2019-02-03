#include "menu_state_base.h"
#include "menuitem_drawer_base.h"
#include "../skeleton/state_manager.h"
#include "../skeleton/common.h"


LeMenuStateBase::LeMenuStateBase(LeMenuItemDrawerBase* d):m_current_item(0),m_item_drawer(d) {
}

LeMenuStateBase::LeMenuStateBase():m_current_item(0),m_item_drawer(new LeMenuItemDrawerBase) {

    
}

void LeMenuStateBase::set_current_menu(const LeMenu& m) {
    m_current_menu = m;
}

LeMenuItem* LeMenuStateBase::get_active_item() {
    return m_current_item;
}


void LeMenuStateBase::draw() {
	draw_menu(m_current_menu);
}

void LeMenuStateBase::update(unsigned int currentTime) {
		

}

void LeMenuStateBase::notify_mouse_pressed(unsigned int) {
	
    if ( !m_current_item ) 
        return;

    if ( m_current_item->has_submenu() )
		m_current_menu = *m_current_item->get_submenu();
	else
		m_current_item->execute_action();
}

void LeMenuStateBase::notify_key_pressed(unsigned int) {
}

void LeMenuStateBase::notify_mouse_move(unsigned int x, unsigned int y) {
	m_current_item = 0;
	if ( LeMenuItem* i = m_current_menu.get_item_by_pos(y,x) )
		m_current_item = i;
}


void LeMenuStateBase::draw_menu(const LeMenu& menu) {
	std::vector<LeMenuItem*> vec = menu.get_items();
	for(int i = 0; i<vec.size(); ++i) {
		m_item_drawer->draw_menu_item(vec[i]);
	}
}


	
