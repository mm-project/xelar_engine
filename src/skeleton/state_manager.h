#ifndef state_manager_h
#define state_manager_h

#include "resource_manager.h"
#include "service.h"

#include "../renderer/interlayer.h"

#include <map>


enum LeStateType {ST_MENU = 1, ST_GAME };
// zharangac a u vochmi ban avel u asxatuma, ha
class LeStateManager : public LeService<LeStateManager>
{
	public:	
		friend class LeService<LeStateManager>;

private:
		LeStateManager();

		LeStateManager(const LeStateManager&);
		LeStateManager& operator=(const LeStateManager&);

public:
		void reg_state( LeStateType st, LeInterLayer* i );
		void set_state( LeStateType st );
		void set_start_state( LeStateType st );

        LeResourceManager get_resource_manager();
        
	private:
		std::map<LeStateType,LeInterLayer*> m_statename2state;
		LeInterLayer* m_current_state;
        LeResourceManager m_resource_manager;
        
};

#endif
