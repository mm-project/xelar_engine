
class Test 
{
    public:
            Test() {
            };
            
            void virtual run() {}
};

#ifdef TEST_INDIVIDUAL
    #define TEST_BEGIN class test : public Test { void run() 
    #define TEST_END };
#else
    #define TEST_BEGIN int main()
    #define TEST_END 
#endif
