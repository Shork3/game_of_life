#include "displayinfo.hpp"
#include "point.hpp"
#include <cstdint>

display_info::display_info(uint16_t x, uint16_t y,  uint8_t  **pointer):
    m_x_width(x), m_y_higth(y), m_game_field(pointer)
{

}

display_info::~display_info()
{

}