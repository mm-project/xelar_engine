#ifndef service_h
#define service_h

template <typename T>
class LeService
{
    public:
        //static T* get();
        static T* get() 
		{
            if(!m_instance) m_instance = new T;
            return m_instance;
        }

    private:
        static T* m_instance;
};

template <typename T>
T* LeService<T>::m_instance = 0;

#endif
