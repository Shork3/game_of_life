#ifndef OUTPUT
#define OUTPUT

#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "point.hpp"
#include <string>
#include "xinfo.hpp"
namespace just
{
    struct event
    {
    public:
        int test;
    };
    
    class j_applet 
    {
    private:
        bool m_is_init = false;
        point m_position;
        uint16_t m_width;
        uint16_t m_height;
        xinfo m_xinfo;
    public: 
        Window m_applet_window;

        void init(const xinfo &xinfo);
        j_applet(point position, uint16_t width, uint16_t htight, void (*event_func)(event) = nullptr);
        ~j_applet();
        virtual void update();
        point get_position();
        void set_position(point position);
        // uint16_t get_width();
        // uint16_t get_height();
        // void set_width(uint16_t width);
        // void set_height(uint16_t height);
        xinfo get_xinfo();
        bool is_init();
    };

    class j_window
    {
    private:
        int m_depth;
        Display *m_display;
        int m_screen;
        Window m_root_window;
        Window m_this_window;
        point m_position;
        uint16_t m_width;
        uint16_t m_height;
        std::string m_title;
        std::vector<j_applet*> m_applets;
        int m_applets_count;
        Visual *m_visual;
        XSetWindowAttributes m_attributes;
        void draw();
        
    public:
        j_window(point position, uint16_t width, uint16_t height, std::string title);
        ~j_window();
        void add(j_applet* applet);
        void close();
        int run();
    };

    class j_button: public j_applet
    {
    private:
        std::string m_text;

    public:
        j_button(point position, uint16_t width, uint16_t height, std::string text, void (*event_func)(event));
        ~j_button();

        void update() override;
    };   
}

#endif
