#ifndef menu_state_h
#define menu_state_h

#include "interlayer.h"
#include "menu.h"

							 
								 
class LeMenuState : public LeInterLayer
{

	public:
		virtual void init();
		virtual void draw();
		virtual void update(unsigned int currentTime);

	public:
		virtual void notify_mouse_pressed(unsigned int);
		virtual void notify_key_pressed(unsigned int);
		virtual void notify_mouse_move(unsigned int x, unsigned int y);

	
	public:
		void action_play();
		
	private:
		void draw_highlights();
		void draw_menu(const LeMenu& menu);
		void draw_menu_item(LeMenuItem* i);
		void highligt_menu_item(LeMenuItem* i);
	
	
	private:
		LeMenu m_current_menu;
		LeMenu m_top_menu;
		LeMenu m_settings_menu;
		
		LeMenuItem* m_current_item;
	
};

#endif