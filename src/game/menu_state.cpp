#include "menu_state.h"
#include "resources.h"
#include "../skeleton/state_manager.h"
#include "../skeleton/common.h"

void LeMenuState::init() {
	SDL_Log("LeMenuState: init");

	//m_top_menu.add_action_item(LeObj(get_rsc("play.png"),100,210,3,3),std::bind(&LeMenuState::action_play, this));
	
	/**/

    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),100,210,3,3),std::bind(&LeMenuState::action_play, this));
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),190,210,3,3))->add_submenu(&m_settings_menu);
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),280,210,3,3));
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),360,210,3,3));
    m_settings_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),190,210,3,3))->add_submenu(&m_top_menu);
				
    /**/
		
	LeMenuStateBase::set_current_menu(m_top_menu);	
}

void LeMenuState::action_play() {
	LeStateManager::get()->set_state(ST_GAME);
}

void LeMenuState::draw() {
	draw_highlights();
	LeMenuStateBase::draw();
}

void LeMenuState::draw_highlights() {
	LeMenuItem* mi = LeMenuStateBase::get_active_item();
    if(mi)
		highligt_menu_item(mi);
}

void LeMenuState::highligt_menu_item(LeMenuItem* i) {
	LeObj obj = i->get_object();
	set_drawing_color(255,255,0);
	draw_rect(obj.m_x,obj.m_y,obj.m_height,obj.m_width);
}
	
