#include "FSMHeader.h"
#include "StateHeader.h"

void State_FSM()
{
    FLAG_BIT.flag1=0;
    FLAG_BIT.flag2=0;
    while(1)
    {
        if (FLAG_BIT.flag1==0 && FLAG_BIT.flag2==1)
        {
            CLR_BIT(PORTC,PC5);
            CLR_BIT(PORTC,PC6);
        }
        else if (FLAG_BIT.flag1==1 && FLAG_BIT.flag2==0)
        {
            SET_BIT(PORTC,PC5);
            SET_BIT(PORTC,PC6);
        }
        else if (FLAG_BIT.flag1==0 && FLAG_BIT.flag2==0)
        {
            TOGGLE_BIT(PORTC,PC5);
            TOGGLE_BIT(PORTC,PC6);
            Delay_Timer(1000);
        }

    }
}

ISR(PCINT0_vect)
{
    cli();
    if(FLAG_BIT.flag1==0 && FLAG_BIT.flag2==0)
        FLAG_BIT.flag1=~FLAG_BIT.flag1;
    else if(FLAG_BIT.flag1==0 && FLAG_BIT.flag2==1)
        FLAG_BIT.flag1=~FLAG_BIT.flag1;
    else if(FLAG_BIT.flag1==1 && FLAG_BIT.flag2==1)
    {
        FLAG_BIT.flag1=0;
        FLAG_BIT.flag2=0;
    }
    sei();
}

ISR(PCINT2_vect)
{
    cli();
    if(FLAG_BIT.flag1==1 && FLAG_BIT.flag2==0)
    {
        FLAG_BIT.flag1=0;
        FLAG_BIT.flag2=1;
    }
    sei();
}

