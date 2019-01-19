#include "../postman.h"
#include "../callback.h"

#include <iostream>
#include <cassert>
#include <typeinfo>

/*
class customtype: public LeCallbackType
{
    public:
        customtype(int i):LeCallbackType("customType"),m_i(i) {}
        int get() { return m_i; }

    private:
        int m_i;
};
*/

class customdata: public LeCallbackData 
{
    public:
        customdata(int i):m_i(i) {}
        int get() { return m_i; }

    private:
        int m_i;
};


class A
{
    
    public:
        void on_my_mem_fun() {
            std::cout << "-->handler called" << std::endl;
        }
        
        void on_my_mem_fun1(LeCallbackData& d) {
            std::cout << "--"<< typeid(d).name() << "-->very complex handler called"  << dynamic_cast<customdata&>(d).get() << std::endl;
        }
};




//*
void on_my_handler() {
    std::cout << "-->simple handler called" << std::endl;
}

void on_my_handler1() {
    std::cout << "-->handler1 called" << std::endl;
}

void on_my_complex_handler(LeCallbackData& d) {
    //std::cout <<  << std::endl;
    //checktype
    try {
        std::cout << "--"<< typeid(d).name() << "-->very complex handler called"  << dynamic_cast<customdata&>(d).get() << std::endl;
    } catch(std::bad_cast) {
        std::cout << " complex handler called but not for our datatype expected" << std::endl;
    }
}


int main()
{
    customdata d(1);
    LePostman* p = LePostman::get();
    
    LeCallbackType t1 = p->add_callback_type("cbGameOver");
    LeCallbackType t2 = p->add_callback_type("cbNetworkIssue");

        p->notify(t1);
        p->register_callback(t1,on_my_handler1);
        LeCallback cb(p->register_callback(t2,on_my_handler));
        LeCallback cb1(p->register_callback(t1,on_my_complex_handler));

        p->notify(t2);
        p->notify(t2,d);

        cb.purge();

        p->notify(t2);

        cb1.purge();
        cb.purge();
        
        p->notify(t1);
}

