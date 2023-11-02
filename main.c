/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <util/delay.h>

#include "pwm/pwm.h"
#include "rgb/rgb.h"

#define MAX 0x64
#define OFF 0x00

RGB red =
{
    .r = 100,
    .g = 0,
    .b = 0
};

RGB green =
{
    .r = 0,
    .g = 100,
    .b = 0
};

RGB blue =
{
    .r = 0,
    .g = 0,
    .b = 100
};

int main(void)
{
    PWM_Initialize();

/*
    PWM_Write(0, 50);
    PWM_Write(1, 50);
    PWM_Write(2, 50);
    PWM_Write(3, 50);

    while(1){ }
*/
    
    //int8_t red = MAX, green = OFF, blue = OFF;
    
    //int8_t delta_r = -1, delta_g = 1, delta_b = 1;

    while(1)
    {
        RGB_Write(&red);
        _delay_ms(1000);

        RGB_Write(&green);
        _delay_ms(1000);

        RGB_Write(&blue);
        _delay_ms(1000);
/*
    red += delta_r;
    green += delta_g;
    blue += delta_b;

    if(red == OFF || red == MAX)
    {
        delta_r = -delta_r;
    }

    if(green == OFF || green == MAX)
    {
        delta_g = -delta_g;
    }

    if(blue == OFF || blue == MAX)
    {
        delta_b = -delta_b;
    }
*/
    //_delay_ms(10);
    }

    return 0;
}
