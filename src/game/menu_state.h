#ifndef menu_state_h
#define menu_state_h

#include "../skeleton/menu_state_base.h"

class LeMenuState : public LeMenuStateBase
{

	public:
		virtual void init();
		virtual void draw();
	
	public:
		void action_play();
		
	private:
		void draw_highlights();
        void highligt_menu_item(LeMenuItem* i);
	
	
	private:
		LeMenu m_top_menu;
        LeMenu m_settings_menu;
	
};

#endif
