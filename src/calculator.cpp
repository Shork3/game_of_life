#include "calculator.hpp"
#include "displayinfo.hpp"
#include "point.hpp"
#include <cstdint>

calculator::calculator(const uint16_t x, const uint16_t y, rules rule):
    m_length_x(y), m_length_y(y)
{
    m_game_field_1 = new uint8_t*[m_length_y];
    m_game_field_2 = new uint8_t*[m_length_y];

    for(int i = 0; i < m_length_y; ++i)
    {
        m_game_field_1[i] = new uint8_t[m_length_x];
        m_game_field_2[i] = new uint8_t[m_length_x];
    }

    m_chad_massive = new uint8_t**[2];
    m_chad_massive[0] = m_game_field_1;
    m_chad_massive[1] = m_game_field_2;

}

void calculator::start()
{
    m_is_start = true;
}

void calculator::stop()
{
    m_is_start = false;
}

void calculator::set_start_figure(figure *start_figure)
{
    int length = start_figure->m_count;

    for (int i = 0; i < length; ++i)
    {
        m_game_field_1
            [get_closed_field_y(start_figure->m_points[i].m_x)]
            [get_closed_field_x(start_figure->m_points[i].m_y)] = 1;
    }
}
calculator::~calculator()
{
    for(int i = 0; i < m_length_y; ++i)
    {
        delete [] m_game_field_1[i];
    }
    delete [] m_game_field_1;

    for(int i = 0; i < m_length_y; ++i)
    {
        delete [] m_game_field_2[i];
    }
    delete [] m_game_field_2;
    delete [] m_chad_massive;
};


void calculator::next_step(int step)
{
    for(int y = 0; y < m_length_y; ++y)
    {
        for(int x = 0; x < m_length_x; ++x)
        {
            if(m_chad_massive[m_current_massive][y][x]==0)
            {
                continue;
            }

            if(m_chad_massive[m_current_massive][y][x] == 1)
            {
                cell_status_update(point(y, x));
                cell_status_update(point(y-1,x));
                cell_status_update(point(y-1,x+1)); 
                cell_status_update(point(y,x+1)); 
                cell_status_update(point(y+1,x+1)); 
                cell_status_update(point(y+1,x)); 
                cell_status_update(point(y+1,x-1));
                cell_status_update(point(y,x-1));
                cell_status_update(point(y-1,x-1));
            }
        }
    }
    
    clear_current_game_field();
    m_current_massive = !m_current_massive;
    --step;
    if(step > 0)
    {
        next_step(step);
    }
}

void calculator::cell_status_update(const point position)
{
    //узнаем количество соседей

    uint8_t neighbors_numbers = 0;
    int x = position.m_x;
    int y = position.m_y;

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y-1)]
        [get_closed_field_x(x)]; 

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y-1)]
        [get_closed_field_x(x+1)];

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y)]
        [get_closed_field_x(x+1)]; 

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y+1)]
        [get_closed_field_x(x+1)];

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y+1)]
        [get_closed_field_x(x)]; 

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y+1)]
        [get_closed_field_x(x-1)];

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y)]
        [get_closed_field_x(x-1)];

    neighbors_numbers += m_chad_massive
        [m_current_massive]
        [get_closed_field_y(y-1)]
        [get_closed_field_x(x-1)];

    switch (neighbors_numbers) 
    {
        case 2:
            m_chad_massive
                [!m_current_massive]
                [get_closed_field_y(y)]
                [get_closed_field_x(x)] = 
            m_chad_massive
                [m_current_massive]
                [get_closed_field_y(y)]
                [get_closed_field_x(x)];
            break;

        case 3:
            m_chad_massive
                [!m_current_massive]
                [get_closed_field_y(y)]
                [get_closed_field_x(x)] = 1;
            break;

        default:
            m_chad_massive
                [!m_current_massive]
                [get_closed_field_y(y)]
                [get_closed_field_x(x)] = 0;
            break;                                    
    }
}

void calculator::clear_current_game_field()
{
    for(int y = 0; y < m_length_y; ++y)
    {
        for(int x = 0; x < m_length_x; ++x)
        {
            m_chad_massive[m_current_massive][y][x] = 0;
        }
    }
}

int calculator::get_closed_field_y(int y)
{
    if(y<0)
    {
        y = m_length_y + y;
    }
    else if(y > m_length_y - 1)
    {
        y = y - m_length_y;
    }

    return y;
}

int calculator::get_closed_field_x(int x)
{
    if(x < 0)
    {
        x = m_length_x + x;
    }
    else if (x > m_length_x - 1) 
    {
        x = x - m_length_x;
    }

    return  x;
}

void calculator::main_while()
{
    if(m_is_start)
    {
        next_step(m_step);
    }
}

display_info calculator::get_display_info()
{
    return display_info(m_length_y, m_length_x, m_chad_massive[m_current_massive]);
}



