#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void PWM_Initialize(void);
void PWM_Write(uint8_t, uint8_t);

#endif