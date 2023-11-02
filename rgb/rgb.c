#include "rgb.h"

void RGB_Write(RGB* rgb)
{
    PWM_Write(R_CHANNEL, rgb->r);
    PWM_Write(G_CHANNEL, rgb->g);
    PWM_Write(B_CHANNEL, rgb->b);
}