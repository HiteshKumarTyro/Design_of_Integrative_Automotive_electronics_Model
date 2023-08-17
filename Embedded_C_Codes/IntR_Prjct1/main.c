/*
 */

#include "Intrheader.h"

volatile unsigned int flag1 = 0;

int main(void)
{
    //GPIO Configurations
    SET_BIT(DDRD,PD0);
    SET_BIT(PORTD,PD0);
    CLR_BIT(DDRB,PB0);
    SET_BIT(PORTB,PB0);

    //Interrupts Initializations
    SET_BIT(SREG,7);
    SET_BIT(PCICR,PCIE0);
    SET_BIT(PCMSK0,PCINT0);

    flag1=0;

    while(1)
    {
        if(flag1)
        {
            TOGGLE_BIT(PORTD,PD0);
            _delay_ms(500);
        }

    }

    return 0;
}

ISR(PCINT0_vect)
{
    cli();
    flag1=~flag1;
    sei();
}
