#ifndef DISPLAY_INFO
#define DISPLAY_INFO

#include <cstdint>
#include "point.hpp"

struct display_info
{
public:
    uint8_t **m_game_field;
    uint16_t m_x_width;
    uint16_t m_y_higth;
    display_info(uint16_t  x, uint16_t y,  uint8_t **pointer);
    ~display_info();
};

#endif
