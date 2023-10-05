#ifndef REMOTECONTROLL
#define REMOTECONTROLL

#include "displayinfo.hpp"
#include "point.hpp"
#include "figure.hpp"

class i_remote_controll
{
public:
    virtual void next_step(int step = 1) = 0;
    virtual void set_start_figure(figure*) = 0;
    virtual display_info get_display_info() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif
