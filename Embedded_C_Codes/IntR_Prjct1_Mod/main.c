/*
 */

#include "Intrheader.h"

struct
{
    volatile unsigned int flag1:1 ;

}FLAG_BIT;

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

    FLAG_BIT.flag1=0;

    while(1)
    {
        if(FLAG_BIT.flag1)
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
    FLAG_BIT.flag1=~FLAG_BIT.flag1;
    sei();
}
