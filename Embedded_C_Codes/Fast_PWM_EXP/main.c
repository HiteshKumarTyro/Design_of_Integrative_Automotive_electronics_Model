/*
 */

#include "fast.h"

int main(void)
{

    SET_BIT(DDRD,PD6);
    SET_BIT(TCCR0A,WGM00);
    SET_BIT(TCCR0A,WGM01);
    CLR_BIT(TCCR0B,WGM02);
    SET_BIT(TCCR0A,COM0A1);
    SET_BIT(TCCR0A,COM0A0);
    SET_BIT(TCCR0B,CS00);
    CLR_BIT(TCCR0B,CS01);
    SET_BIT(TCCR0B,CS02);
    OCR0A=127;
    TCNT0=0;

    while(1)
    ;

    return 0;
}
