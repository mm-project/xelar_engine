#ifndef state_manager_h
#define state_manager_h

#include "interlayer.h"

#include <map>

#include <iostream>

enum LeState {ST_MENU = 1, ST_PAUSE, ST_GAME, ST_COUNT };

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
			std::cout << "Regstate -> " << st << " " << i << std::endl;
			m_statename2state[st] = i;
		}

		void set_state( LeState st ) {
			LOG("STATEMANAGER: set_state %i\n",(int)st);
			m_current_state = m_statename2state[st];
			m_current_state->init();
			LOG("STATEMANAGER: m_current_state %p\n",(void*)m_current_state );
			LeInterLayer::set_rendering_controller(m_current_state);
		}
	
		void set_start_state( LeState st ) {
			set_state(ST_GAME);
			m_current_state->enter_event_loop();
		}
	
	
	static LeStateManager* m_instance;
	
	private:
		std::map<LeState,LeInterLayer*> m_statename2state;
		LeInterLayer* m_current_state;

			
};

#endif