/*
 */

#include "TIntRHeader.h"

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
    //OCR0A=255;
    //OCR0B=100;
    SET_BIT(TIMSK0,OCIE0A);
    SET_BIT(TIMSK0,OCIE0B);
    TCNT0=0;

    while(1)
    ;

    return 0;
}

ISR(TIMER0_COMPA_vect)
{
    cli();
    CLR_BIT(PORTC,PC5);
    sei();
}

ISR(TIMER0_COMPB_vect)
{
    cli();
    SET_BIT(PORTC,PC5);
    sei();
}
