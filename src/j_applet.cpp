#include "j_gui_lib.hpp"
#include "point.hpp"
#include "xinfo.hpp"
#include <iostream>
namespace just
{
    j_applet::j_applet(point position, uint16_t width, uint16_t height, void (*event_func)(event)):
        m_position(position), m_width(width), m_height(height)
    {

    }

    j_applet::~j_applet()
    {

    }

    void j_applet::init(const xinfo &xinfo)
    {
        m_xinfo = xinfo;
        m_applet_window = XCreateSimpleWindow(m_xinfo.display, m_xinfo.root_window, m_position.m_x, m_position.m_y, m_width, m_height, 1, 1, 1);
        XMapWindow(m_xinfo.display, m_applet_window);
        XFlush(m_xinfo.display);
        std::cout<<"init"<<std::endl;
    }

    void j_applet::update()
    {
        //std::cout<<"work"<<std::endl;
    }

    point j_applet::get_position()
    {
        return m_position;
    }

    void j_applet::set_position(point position)
    {
        m_position = position;
    }  

    xinfo j_applet::get_xinfo()
    {
        return xinfo
        {
            m_xinfo.display, 
            m_applet_window, 
            m_xinfo.depth, 
            m_xinfo.screen, 
            m_xinfo.m_visual
        };
    }

    bool j_applet::is_init()
    {
        return m_is_init;
    }


}