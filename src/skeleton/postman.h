#ifndef postman_h
#define postman_h

#include "callback.h"
#include "service.h"

#include <map>
#include <vector>
#include <string>
#include <functional>


class LePostman : public LeService<LePostman>
{
    public:
		friend class LeService<LePostman>;

private:
	LePostman() {}
	LePostman(const LePostman&);
	LePostman operator=(const LePostman&);

    public:
        LeCallbackType add_callback_type(const std::string&);
        //LeCallbackType get_callback_type(const std::string&);
        
        LeCallback register_callback(const LeCallbackType& t, callBackFun1 f);
        LeCallback register_callback(const LeCallbackType& t, callBackFun2 f);
        void deregister_callback(LeCallbackType& t, int id);

        void notify(LeCallbackType&);
        void notify(LeCallbackType&, LeCallbackData&);

    private:
        std::map<LeCallbackType,std::vector<LeCallback>> m_type2vecfun;
        std::map<int,LeCallbackType> m_index2type;
        int m_types_count;
};




#endif
