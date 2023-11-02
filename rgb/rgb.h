#ifndef RGB_H
#define RGB_H

#include "../pwm/pwm.h"

// PWM channels used for outputting RGB components

#define R_CHANNEL 0
#define G_CHANNEL 1
#define B_CHANNEL 2

typedef struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB;

void RGB_Write(RGB*);

#endif