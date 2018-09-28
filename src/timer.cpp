#include "timer.h"
#include "common.h"

LeTimer::LeTimer () {
	//m_last_time  = 0;
	//budul jan
	m_fired = 0;
}

void LeTimer::add_continuous_checkpoint(const actionFun& f, unsigned int t) {
	m_structure.push_back(LeHavaqakanStruktura(f, t));
}

void LeTimer::add_singleshot_checkpoint(const actionFun& f, unsigned int t) {
	m_structure2.push_back(LeHavaqakanStruktura(f, t));
	m_fired++;
}

void LeTimer::step(unsigned int current_time ) {
	for( auto it : m_structure ) {
		if ( current_time > it.last_time + it.freq ) {
			it.f();
			it.last_time = current_time;
		}
	}	
	
	
	for( auto it : m_structure2 ) {
		if ( current_time > it.last_time + it.freq ) {
			it.f();
			it.last_time = current_time;
			m_fired--;
		}
		
	}
	
	if(m_fired == 0 && m_structure2.size() != 0 )
		m_structure2.clear();	
}
	
