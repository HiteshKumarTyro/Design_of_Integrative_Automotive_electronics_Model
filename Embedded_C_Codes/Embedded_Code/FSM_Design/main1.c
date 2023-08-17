/*
 */

#include "FSMHeader.h"

struct
{
    volatile unsigned int flag1:2 ;

}FLAG_BIT;
volatile unsigned int Counter=0;

int main(void)
{

    // GPIO Configurations
    SET_BIT(DDRC,PC5);
    SET_BIT(PORTC,PC5);
    SET_BIT(DDRC,PC6);
    SET_BIT(PORTC,PC6);
    CLR_BIT

    //Interrupt Configurations
    SET_BIT(SREG,7);
    SET_BIT(EICRA,ISC10);
    CLR_BIT(EICRA,ISC11);
    SET_BIT(EICRA,ISC00);
    CLR_BIT(EICRA,ISC01);
    SET_BIT(EIMSK,INT1);
    SET_BIT(EIMSK,INT0);

    FLAG_BIT.flag1=0;
    while(1)
    {
        if (FLAG_BIT.flag1==0)
        {
            TOGGLE_BIT(PORTC,PC5);
            TOGGLE_BIT(PORTC,PC6);
            Delay_Timer(1000);
        }
        else if (FLAG_BIT.flag1==1)
        {
            SET_BIT(PORTC,PC5);
            SET_BIT(PORTC,PC6);
            Delay_Timer(50);
        }
        else if (FLAG_BIT.flag1==2)
        {
            CLR_BIT(PORTC,PC5);
            CLR_BIT(PORTC,PC6);
            Delay_Timer(50);
        }

    }

    return 0;
}

ISR(INT0_vect)
{
    cli();
    if(FLAG_BIT.flag1==0)
    {
        FLAG_BIT.flag1=1;
    }
    else if (FLAG_BIT.flag1==2)
    {
        FLAG_BIT.flag1=0;
    }
    sei();
}

ISR(INT2_vect)
{
    cli();
    if(FLAG_BIT.flag1==1)
    {
        FLAG_BIT.flag1=2;
    }
    sei();
}
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

