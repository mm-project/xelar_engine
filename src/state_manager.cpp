#include "common.h"
#include "state_manager.h"
#include "interlayer.h"

LeStateManager* LeStateManager::get() {
	if( ! m_instance ) m_instance = new LeStateManager;
	return m_instance;
}

LeStateManager::LeStateManager() {
}

void LeStateManager::reg_state( LeStateType st, LeInterLayer* i ) {
	m_statename2state[st] = i;
}

void LeStateManager::set_state( LeStateType st ) {
	LOG("STATEMANAGER: set_state %i\n",(int)st);
	m_current_state = m_statename2state[st];
	m_current_state->init();
	LOG("STATEMANAGER: m_current_state %p\n",(void*)m_current_state );
	LeInterLayer::set_rendering_controller(m_current_state);
}

void LeStateManager::set_start_state( LeStateType st ) {
	set_state(ST_GAME);
	m_current_state->enter_event_loop();
}
	
