#pragma once
#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>

struct xinfo
{
    Display *display;
    Window root_window;
    int depth;
    int screen;
    Visual *m_visual;

};