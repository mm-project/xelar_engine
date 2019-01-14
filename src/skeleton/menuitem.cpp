#include "menuitem.h"

#include "menu.h"
#include "object.h"
#include "common.h"

#include <functional>

LeMenuItem::LeMenuItem(const LeObj& o, const actionFun& f ) {
	m_object = o;
	m_having_submenu = false;
	m_has_action = false;
	m_action_function = f;
	if ( m_action_function != nullptr ) m_has_action = true;
}

LeObj LeMenuItem::get_object() const {
	return m_object;
}

LeMenu* LeMenuItem::add_submenu(LeMenu* m) {
	if(!m_having_submenu) {
		m_submenu = m; //new LeMenu;
		m_having_submenu = true;
	}
	return m_submenu;
}

bool LeMenuItem::has_submenu() {
	return m_having_submenu;
}

LeMenu* LeMenuItem::get_submenu() {
	return m_submenu;
}

void LeMenuItem::execute_action() {
	if (!m_has_action) return;
	m_action_function();
}
