#ifndef rect_h
#define rect_h

#include <cmath>
#include <iostream>
class LeRect
{
    public: 
        LeRect():m_x1(0),m_y1(0),m_x2(0),m_y2(0) {}
        LeRect(int x1, int y1, int x2, int y2):m_x1(x1),m_y1(y1),m_x2(x2),m_y2(y2) {}
        void setRect(int x1, int y1, int w, int h) {
            m_x1 = x1;
            m_y1 = y1;
            m_x2 = x1 + w;
            m_y2 = y1 + h;
        }
        
        int x1() { return m_x1; } 
        int y1() { return m_y1; }

        int x2() { return m_x2; }
        int y2() { return m_y2; }

        int w() { return abs(m_y2-m_y1); }
        int h() { return abs(m_x2-m_x1); }
        
        bool contains(int x, int y) { 
                //std::cout << "X: << " << x << " Y: "<< y <<  " m_x1: " << m_x1 << " m_x2: "<< m_x2 <<  " m_y1 : " << m_y1 << " m_y2: " << m_y2 << std::endl;
            return (x > m_x1 && x < m_x2  &&
                    y > m_y1 && y < m_y2 );
            
            }


    private:
        int m_x1;
        int m_y1;
        int m_x2;
        int m_y2;
        
};
#endif
