#include "j_gui_lib.hpp"

namespace just
{
    j_button::j_button(point position, uint16_t width, uint16_t height, std::string text, void (*event_func)(event)): 
        j_applet(position, width, height, event_func), m_text(text)
    {
        
    }
    j_button::~j_button(){}

    void j_button::update() 
    {  
        j_applet::update();

        // m_visual = XDefaultVisual(m_display, m_screen);   
        // m_applet_window = XCreateWindow(
        // m_display, 
        // m_root_window, 
        // 10, 10, 20, 20, 0, 
        // m_depth, 
        // InputOutput, 
        // m_visual, 
        // CWBackPixel | CWBorderPixel | CWBorderWidth, 
        // &m_attributes);
    }
}