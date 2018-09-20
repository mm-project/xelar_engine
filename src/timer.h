#ifndef timer_h
#define timer_h

#include "common.h"

#include <map>



class LeTimer {
	public: 
			LeTimer () {
				m_current_time  = 0;
			}
			
			void add_continuous_checkpoint(actionFun f, unsigned int t) {
				actionFun* ff = &f;
				m_fun2freq[&f] = t;
			}

			//void add_singlefire_checkpoint(const actionFun& f, unsigned int t) {
			//
			//}
			
			void step(unsigned int t) {
				LOG("current: %i , last: %i \n",t,m_current_time);
				for(auto it = m_fun2freq.begin(); it != m_fun2freq.end(); ++it ) {
					LOG(" --> current: %i , last: %i , sum: %i , funct %p \n",t,m_current_time,m_current_time+it->second,(void*)it->first);
					if ( t + it->second > m_current_time ) {
							LOG("   ----> current: %i , last: %i , sum: %i , funct %p \n",t,m_current_time,m_current_time+it->second,(void*)it->first);
							it->second+=m_current_time;
							//actionFun f = *(it->first);
							//f();
						}
					}
				m_current_time = t;
			}
	
	private:
		std::map<actionFun*,unsigned int> m_fun2freq;
		//std::map<actionFun,unsigned int>  m_fun2freq_2;
		unsigned int m_current_time;
		
};
#endif