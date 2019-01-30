#ifndef rect_h
#define rect_h

class LeRect
{
    public: 
        LeRect():m_x1(0),m_y1(0),m_x2(0),m_y2(0) {}
        LeRect(int x1, int y1, int x2, int y2):m_x1(x1),m_y1(y1),m_x2(x2),m_y2(y2) {}
        void setRect(int x1, int y1, int x2, int y2) {
            m_x1 = x1;
            m_y1 = y1;
            m_x2 = x2;
            m_y2 = y2;
        }
        int x1() { return m_x1; }
        int y1() { return m_y1; }
        bool contains(int x, int y) { return false;}

    private:
        int m_x1;
        int m_y1;
        int m_x2;
        int m_y2;
        
};
#endif