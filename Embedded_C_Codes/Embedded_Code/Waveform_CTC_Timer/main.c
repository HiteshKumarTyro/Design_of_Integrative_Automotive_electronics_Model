/*
 */

#include "Theader.h"

int main(void)
{

    // GPIO Configurations
    SET_BIT(DDRC,PC5);
    CLR_BIT(PORTC,PC5);

    //Timer Configurations
    SET_BIT(SREG,7);
    CLR_BIT(TCCR0A,COM0A1);
    SET_BIT(TCCR0A,COM0A0);
    SET_BIT(TCCR0A,WGM01);
    CLR_BIT(TCCR0A,WGM00);
    CLR_BIT(TCCR0B,WGM02);
    SET_BIT(TCCR0B,CS00);
    CLR_BIT(TCCR0B,CS01);
    SET_BIT(TCCR0B,CS02);
    OCR0A=127;
    TCNT0=0;

    while(1)
    ;

    return 0;
}
