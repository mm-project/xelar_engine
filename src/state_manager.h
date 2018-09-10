#ifndef state_manager_h
#define state_manager_h

#include "interlayer.h"

#include <map>

enum LeState {ST_MENU, ST_PAUSE, ST_GAME};

class LeStateManager
{
	public:	
		static LeStateManager* get() {
			if( ! m_instance ) m_instance = new LeStateManager;
			return m_instance;
		}
		
		LeStateManager() {
		}

		void reg_state( LeState st, LeInterLayer* i ) {
			m_statename2state[st] = i;

		}

		void set_state( LeState st ) {
			m_current_state = m_statename2state[st];
			m_current_state->set_rendering_controller(m_current_state);
		}
	
		void set_start_state( LeState st ) {
			m_current_state = m_statename2state[st];
			m_current_state->init("GAME");
			m_current_state->set_rendering_controller(m_current_state);
			m_current_state->enter_event_loop();
		}
	
	
	static LeStateManager* m_instance;
	
	private:
		std::map<LeState,LeInterLayer*> m_statename2state;
		LeInterLayer* m_current_state;

			
};

#endif