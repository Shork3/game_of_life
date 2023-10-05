#include "j_gui_lib.hpp"
#include "point.hpp"
#include "iostream"
namespace just
{
    j_window::j_window(point position, uint16_t width, uint16_t height, std::string title):
        m_position(position), m_width(width), m_height(height), m_title(title)
    {
        
    }

    j_window::~j_window() 
    {
        
    }

    void j_window::draw()
    {

    }

    void j_window::add(j_applet *applet)
    {
        m_applets.push_back(applet);
    }

    int j_window::run()
    {
        if((m_display = XOpenDisplay(NULL)) == NULL)
        {
            std::cout<<"Не удалось подключится к дисплей серверу."<<std::endl;
            return 1;
        }
    
        XColor color;
        color.red = 60000;
        color.green = 10;
        color.blue = 30000;
        Colormap colormap = DefaultColormap(m_display, m_screen);         
        XAllocColor(m_display, colormap, &color); 

        m_root_window = XDefaultRootWindow(m_display);
        m_screen = XDefaultScreen(m_display);
        m_depth = DefaultDepth(m_display, m_screen);   
        m_visual = XDefaultVisual(m_display, m_screen);
        m_attributes.background_pixel = color.pixel;
        
        m_this_window = XCreateWindow(
            m_display, 
            m_root_window, 
            100, 100, 500, 500, 0, 
            m_depth, 
            InputOutput, 
            m_visual, 
            CWBackPixel | CWBorderPixel | CWBorderWidth, 
            &m_attributes);

        XMapWindow(m_display, m_this_window);
        XFlush(m_display);



        for(int i = 0; i < m_applets.size(); ++i)
        {
            m_applets[i]->init(xinfo{m_display, m_this_window, m_depth, m_screen, m_visual});
        }
        while (1)
        {
            for(int i = 0; i < m_applets.size(); ++i)
            {
                m_applets[i]->update();
            }
        }

        return 0;
    }
}