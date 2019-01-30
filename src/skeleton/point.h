#ifndef point_h
#define point_h

class LePoint
{
    public: 
        LePoint():m_x(0),m_y(0) {}
        LePoint(int x, int y):m_x(x),m_y(y) {}
        int x() const { return m_x; }
        int y() const { return m_y; }
        int& ry() { return m_y; }
        int& rx() { return m_x; }
        

    private:
        int m_x;
        int m_y;
};
#endif
