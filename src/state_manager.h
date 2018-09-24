#ifndef state_manager_h
#define state_manager_h

#include "interlayer.h"

#include <map>


enum LeStateType {ST_MENU = 1, ST_GAME };

class LeStateManager
{
	public:	
		static LeStateManager* get();

	public:	
		LeStateManager();
		void reg_state( LeStateType st, LeInterLayer* i );
		void set_state( LeStateType st );
		void set_start_state( LeStateType st );
	
	
	private:
		std::map<LeStateType,LeInterLayer*> m_statename2state;
		LeInterLayer* m_current_state;

	public:
		static LeStateManager* m_instance;

			
};

#endif