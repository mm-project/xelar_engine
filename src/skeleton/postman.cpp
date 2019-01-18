#include "postman.h"

#include <iostream>
#include <cassert>
#include <typeinfo>

LePostman* LePostman::m_instance = 0;

LeCallback::LeCallback(callBackFun1 f1, int id, LeCallbackType t):m_f2(NULL),m_f1(f1),m_internal_id(id),m_type(t) {
}

LeCallback::LeCallback(callBackFun2 f2, int id, LeCallbackType t):m_f1(NULL),m_f2(f2),m_internal_id(id),m_type(t) {
}

void LeCallback::purge() {
    LePostman::get()->deregister_callback(m_type,m_internal_id);
}

void LeCallback::call() {
    if ( m_f2 != NULL ) m_f2();
    //assert(0);
}

void LeCallback::call(LeCallbackData& data) {
    if ( m_f1 != NULL ) m_f1(data);
}


LeCallback LePostman::register_callback(LeCallbackType t,callBackFun1 f) {
    m_type2vecfun[t].push_back(LeCallback(f,m_type2vecfun[t].size()+1,t));
    return m_type2vecfun[t].back();
}

LeCallback LePostman::register_callback(LeCallbackType t,callBackFun2 f) {
    m_type2vecfun[t].push_back(LeCallback(f,m_type2vecfun[t].size()+1,t));
    return m_type2vecfun[t].back();
}

void LePostman::deregister_callback(LeCallbackType t, int id) {
    m_type2vecfun[t].erase(m_type2vecfun[t].begin()+id); 
}

void LePostman::notify(LeCallbackType t) {
    std::cout << "notify" << std::endl;
    for( auto it : m_type2vecfun[t] ) {
        it.call();
    }
}

void LePostman::notify(LeCallbackType t,LeCallbackData& data) {
    std::cout << "notify" << std::endl;
    for( auto it : m_type2vecfun[t] ) {
        it.call(data);
    }
}

/*
void on_my_handler() {
    std::cout << "-->handler called" << std::endl;
}

void on_my_handler1() {
    std::cout << "-->handler1 called" << std::endl;
}

void on_my_complex_handler(LeCallbackData& d) {
    //std::cout <<  << std::endl; 
    //std::cout << "--"<< typeid(d).name() << "-->very complex handler called"  << dynamic_cast<customdata&>(d).get() << std::endl;
}


int main()
{
    //LePostman* p;
    //customdata d(1);
    LePostman::get()->notify(CB_GAMEOVER);

    LeCallback cb(LePostman::get()->register_callback(CB_GAMEOVER,on_my_handler));
    LeCallback cb1(LePostman::get()->register_callback(CB_GAMEOVER,on_my_complex_handler));

    LePostman::get()->notify(CB_GAMEOVER);
 
    cb.purge();
    LePostman::get()->notify(CB_GAMEOVER);
 
    
    cb1.purge();
    
    LePostman::get()->notify(CB_GAMEOVER);
  
}
*/

