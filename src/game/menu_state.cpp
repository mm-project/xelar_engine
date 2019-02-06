#include "menu_state.h"
#include "resources.h"
#include "../skeleton/state_manager.h"
#include "../skeleton/common.h"

void LeMenuState::init() {
	SDL_Log("LeMenuState: init");

	//m_top_menu.add_action_item(LeObj(get_rsc("play.png"),100,210,3,3),std::bind(&LeMenuState::action_play, this));
	
	/**/

    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_PLAY),90,150,1,1));//,std::bind(&LeMenuState::action_play, this));
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_RESUME),190,150,1,1));
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_SETTINGS),270,150,1,1))->add_submenu(&m_settings_menu);
    m_top_menu.add_item(LeObj(get_rsc(IMG_MENU_QUIT),360,150,1,1));
     
    
    m_settings_menu.add_item(LeObj(get_rsc(IMG_MENU_QUIT),90,150,1,1));
				
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
	get_renderer()->set_drawing_color(255,255,0);
	get_renderer()->draw_rect(obj.m_x-10,obj.m_y-10,obj.m_height+10,obj.m_width+10);
}
	
