#include "../service.h"

#include <iostream>
class A : public LeService<A> 
{
    public:    
        void print() { 
            std::cout << "executed print from A" << std::endl;
        }
};

class B : public LeService<B> 
{
    public:    
        void print() { 
            std::cout << "executed print from B" << std::endl;
        }
};


int main() 
{
    B::get()->print();
    A::get()->print();
}
