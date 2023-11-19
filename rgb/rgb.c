#include "rgb.h"

void RGB_Write(RGB* rgb)
{
    // calculate PWM duty cycles (%) based on RGB components
    uint8_t r_dc = ((rgb->r / 255) * 100);
    uint8_t g_dc = ((rgb->g / 255) * 100);
    uint8_t b_dc = ((rgb->b / 255) * 100);

    PWM_Write(R_CHANNEL, r_dc);
    PWM_Write(G_CHANNEL, g_dc);
    PWM_Write(B_CHANNEL, b_dc);
}