#include "timer.h"
#include "common.h"

LeTimer::LeTimer () {
	//m_last_time  = 0;
	//budul jan
}

void LeTimer::add_continuous_checkpoint(const actionFun& f, unsigned int t) {
	m_structure.push_back(LeHavaqakanStruktura(f, t));
}

//void add_singlefire_checkpoint(const actionFun& f, unsigned int t) {
//
//}

void LeTimer::step(unsigned int current_time ) {
	for( auto it : m_structure ) {
		//LOG(" --> current: %i , last: %i , sum: %i\n", current_time, it.last_time,  it.last_time + it.freq);
		if ( current_time > it.last_time + it.freq ) {
			//LOG("     --> current: %i , last: %i , sum: %i\n", current_time, it.last_time,  it.last_time + it.freq);
			//it->second+=m_last_time;
			//actionFun f = *(it->first);
			//f();
			it.f();
			it.last_time = current_time;
		}
	}	
}
	
