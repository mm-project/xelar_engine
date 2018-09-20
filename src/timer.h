#ifndef timer_h
#define timer_h

#include "common.h"

//#include <map>
#include <vector>



class LeTimer {
	public: 
			LeTimer () {
				//m_last_time  = 0;
				//budul jan
			}
			
			void add_continuous_checkpoint(const actionFun& f, unsigned int t) {
				//m_fun2freq.push_back(std::make_pair(f,t));
				//aactionFun* ff = &f;
				//m_fun2freq[&f] = t;
				m_structure.push_back(LeHavaqakanStruktura(f, t));
			}

			//void add_singlefire_checkpoint(const actionFun& f, unsigned int t) {
			//
			//}
			
			void step(unsigned int t) {
				//LOG("current: %i , last: %i \n",t,m_last_time);
				for(auto it : m_structure ) {
					//LOG(" --> current: %i , last: %i , sum: %i , funct: \n",t,m_last_time,m_last_time+it->second);
					if ( t > it.last_time + it.freq ) {
							//LOG("   ----> current: %i , last: %i , sum: %i , funct \n",t,m_last_time,m_last_time+it->second);
							//it->second+=m_last_time;
							//actionFun f = *(it->first);
							//f();
							it.f();
					}
				it.last_time = t;
				}	
			}
	
	private:
		struct LeHavaqakanStruktura {
			LeHavaqakanStruktura(const actionFun& f = nullptr, unsigned t = 0, unsigned g = 0):f(f),freq(t),last_time(g) {}
			actionFun f;
			unsigned int last_time;
			unsigned int freq;
		};
		
	private:
		std::vector<LeHavaqakanStruktura> m_structure;  
		
		//std::map<actionFun,unsigned int>  m_fun2freq_2;
		//unsigned int m_last_time;

		//std::vector<std::pair<actionFun,unsigned int> > m_fun2freq;
		//std::vector<unsigend int> m_last_times;
		
};
#endif