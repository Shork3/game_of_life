#include "calculator.hpp"
#include "iostream"
#include "j_gui_lib.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include "point.hpp"
#include <ctime>
#include <numeric>
#include <unistd.h>
#include <thread>
#include "figure.hpp"
void func(just::event e)
{
    std::cout<<"проверка"<<std::endl;
}

int main(int argc, char **argv)
{
    using namespace just;

    figure f_glider = {"glider", 
        new point[5]{
        point(0,0), 
        point(0,1), 
        point(0,2), 
        point(1,2), 
        point(2,1)}, 5};

    calculator calculator(48, 48);
    calculator.set_start_figure(&f_glider);

    j_window main_window(point(0,0), 200, 200, "test");

    j_button button(point(100,100), 100, 100, "my button", func);
    main_window.add(&button);

    return main_window.run();
}