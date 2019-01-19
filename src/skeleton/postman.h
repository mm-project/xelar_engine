#ifndef postman_h
#define postman_h

#include "callback.h"

#include <map>
#include <vector>
#include <string>
#include <functional>


class LePostman
{
    public:
        static LePostman* get() {
            if (!m_instance) m_instance = new LePostman;
            return m_instance;
        };
    
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
        
    public:
        static LePostman* m_instance;
};




#endif
