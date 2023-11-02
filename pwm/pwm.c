#include "pwm.h"

void PWM_Initialize()
{
    /*
        Initialize timer/counter0
    */

    // set PD6 and PD5 (OC0A and OC0B) as outputs
    DDRD |= (1 << PD6) | (1 << PD5);

    // set compare match mode
    TCCR0A |= (1 << COM0A1); // non-inverting mode
    TCCR0A |= (1 << COM0B1);

    // set waveform generation mode
    TCCR0A |= (1 << WGM00) | (1 << WGM01); // fast PWM
    
    // select clock and prescaler
    TCCR0B |= (1 << CS00); // no prescaler f = 62.5 kHz

    /*
        Initialize timer/counter2
    */

    // set PB3 and PD4 (OC2A and OC2B) as outputs
    DDRB |= (1 << PB3);
    DDRD |= (1 << PD3);

    // set compare match mode
    TCCR2A |= (1 << COM2A1); // non-inverting mode
    TCCR2A |= (1 << COM2B1);

    // set waveform generation mode
    TCCR2A |= (1 << WGM20) | (1 << WGM21); // fast PWM

    // select clock and prescaler
    TCCR2B |= (1 << CS20); // no prescaler f = 62.5 kHz
}

void PWM_Write(uint8_t channel, uint8_t value)
{
    switch (channel)
    {
        case 0:
            OCR0A = value;
            break;
        case 1:
            OCR0B = value;
            break;
        case 2:
            OCR2A = value;
            break;
        case 3:
            OCR2B = value;
            break;
        default:
            break;
    }
}