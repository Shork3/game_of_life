#ifndef FIGURE
#define FIGURE

#include <string>
#include "point.hpp"

struct figure 
{
public:
    const std::string m_name;
    const point* m_points;
    const int m_count;
};

#endif
