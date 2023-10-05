#ifndef POINT
#define POINT

class point
{
public:
    int m_x;
    int m_y;
    point(int y, int x): m_x(x), m_y(y){}
    point(): m_x(0), m_y(0){}
};

#endif
