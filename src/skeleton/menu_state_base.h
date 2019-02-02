#ifndef menu_state_base_h
#define menu_state_base_h

#include "../renderer/interlayer.h"
#include "menu.h"
								 
class LeMenuStateBase : public LeInterLayer
{

    public:
		virtual void draw();
		virtual void update(unsigned int currentTime);

	public:
		virtual void notify_mouse_pressed(unsigned int);
		virtual void notify_key_pressed(unsigned int);
		virtual void notify_mouse_move(unsigned int x, unsigned int y);

	
	public:
		void set_current_menu(const LeMenu& m);
        LeMenuItem* get_active_item();
        
	private:
		void draw_menu(const LeMenu& menu);
		void draw_menu_item(LeMenuItem* i);

    private:
		LeMenu m_current_menu;
		LeMenuItem* m_current_item;
	
};

#endif
