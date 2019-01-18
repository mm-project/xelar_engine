#ifndef postman_h
#define postman_h

#include <map>
#include <vector>
//#include <string>
#include <functional>

class LeCallbackData 
{
    public:
        virtual ~LeCallbackData() {}
};

class customdata: public LeCallbackData 
{
    public:
        customdata(int i):m_i(i) {}
        int get() { return m_i; }

    private:
        int m_i;
};

typedef std::function<void(LeCallbackData&)> callBackFun1;
typedef std::function<void()> callBackFun2;

enum LeCallbackType {CB_GAMEOVER};

class LeCallback 
{
    friend class LePostman;
    
    public:
        void purge();
        void call();
        void call(LeCallbackData& data);
        
    private:
        LeCallback(callBackFun1 f1, int id, LeCallbackType t);
        LeCallback(callBackFun2 f2, int id, LeCallbackType t);
        
    private:
        callBackFun1 m_f1;
        callBackFun2 m_f2;
        int m_internal_id;
        LeCallbackType m_type;
};

class LePostman
{
    public:
        static LePostman* get() {
            if (!m_instance) m_instance = new LePostman;
            return m_instance;
        };
    
    public:
        //void register_callback(LeCallbackType,std::string,callBackFun1 f);
        //void register_callback(LeCallbackType,std::string,callBackFun2 f);
        //void unregister_callback(????);
        
        //template<typename T>
        LeCallback register_callback(LeCallbackType t, callBackFun1 f);
        LeCallback register_callback(LeCallbackType t, callBackFun2 f);
        void deregister_callback(LeCallbackType t, int id);

        void notify(LeCallbackType);
        void notify(LeCallbackType, LeCallbackData&);

    private:
        std::map<LeCallbackType,std::vector<LeCallback>> m_type2vecfun;
        
    public:
        static LePostman* m_instance;
};




#endif
