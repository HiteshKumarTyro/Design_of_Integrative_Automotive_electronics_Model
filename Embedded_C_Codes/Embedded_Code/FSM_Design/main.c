/*
 */

#include "FSMHeader.h"

int main(void)
{

    // GPIO Configurations
    SET_BIT(DDRC,PC5);
    SET_BIT(PORTC,PC5);
    SET_BIT(DDRC,PC6);
    SET_BIT(PORTC,PC6);
    CLR_BIT(DDRB,PB0);
    SET_BIT(PORTB,PB0);
    CLR_BIT(DDRD,PD6);
    SET_BIT(PORTD,PD6);

    //Interrupt Configurations
    SET_BIT(SREG,7);
    SET_BIT(PCICR,PCIE0);
    SET_BIT(PCMSK0,PCINT0);
    SET_BIT(PCICR,PCIE2);
    SET_BIT(PCMSK2,PCINT22);

    State_FSM();

    return 0;
}


