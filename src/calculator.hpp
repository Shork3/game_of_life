#ifndef GAME
#define GAME

#include <cstdint>
#include <iostream>
#include "point.hpp"
#include "remotecontrol.hpp"

enum class rules
{
    e_classic
};

class calculator: public i_remote_controll
{
private:
    uint8_t **m_game_field_1;
    uint8_t **m_game_field_2; 
    const uint8_t **m_const_game_field1;
    const uint8_t **m_const_game_field2;
    uint8_t ***m_chad_massive; //массив для массивов массивов ( game_field_1 и game_field_2 )
    bool m_current_massive = 0;
    const int m_length_x;
    const int m_length_y;
    void cell_status_update(const point);
    void clear_current_game_field();
    int get_closed_field_y(int);
    int get_closed_field_x(int);
    int m_rate;
    int m_step;
    bool m_is_start = false;

public:
    calculator(const uint16_t x, const uint16_t y, rules rule = rules::e_classic);
    void set_start_figure(figure *figure) override;
    display_info get_display_info() override;
    void next_step(int step = 1) override;
    void start() override;
    void stop() override;
    void main_while();
    ~calculator();
};

#endif
