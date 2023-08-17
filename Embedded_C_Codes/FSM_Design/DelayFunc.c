#include "FSMHeader.h"
#include <avr/interrupt.h>

volatile unsigned int Counter=0;

void Delay_Timer(int count1)
{
    Counter=0;
    count1=count1/16;
    CLR_BIT(TCCR0A,WGM00);
    CLR_BIT(TCCR0A,WGM01);
    CLR_BIT(TCCR0B,WGM02);
    SET_BIT(TCCR0B,CS00);
    CLR_BIT(TCCR0B,CS01);
    SET_BIT(TCCR0B,CS02);
    TCNT0=0;
    SET_BIT(TIMSK0,TOIE0);
    while(Counter<count1){}

}
ISR(TIMER0_OVF_vect)
{
    cli();
    Counter++;
    CLR_BIT(TIFR0,TOV0);
    sei();

}
