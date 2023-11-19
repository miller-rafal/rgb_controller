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

const RGB colors[] = 
{
    { .r = 0x00, .g = 0x00, .b = 0xff },
    { .r = 0x00, .g = 0xff, .b = 0x00 },
    { .r = 0x00, .g = 0xff, .b = 0xff },
    { .r = 0xff, .g = 0x00, .b = 0x00 },
    { .r = 0xff, .g = 0x00, .b = 0xff },
    { .r = 0xff, .g = 0xff, .b = 0x00 },
    { .r = 0xff, .g = 0xff, .b = 0xff }
};

int main(void)
{
    PWM_Initialize();

    while(1)
    {
        for(uint8_t i = 0; i < 7; i++)
        {
            RGB_Write(&colors[i]);
            _delay_ms(1000);
        }
    }

    return 0;
}
