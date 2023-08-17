/*
 */

#include "CPWMheader.h"

struct
{
    volatile unsigned int flag0:1;
    volatile unsigned int flag1:1;
    volatile unsigned int flag2:1;

}FLAG_BIT;

int main(void)
{

    // GPIO Configurations
    SET_BIT(DDRD,PD6);
    CLR_BIT(PORTD,PD6);
    SET_BIT(DDRC,PC5);
    CLR_BIT(PORTC,PC5);
    CLR_BIT(DDRD,PD2);
    SET_BIT(PORTD,PD2);
    CLR_BIT(DDRD,PD7);
    SET_BIT(PORTD,PD7);
    CLR_BIT(DDRB,PB2);
    SET_BIT(PORTB,PB2);

    //External Interrupt Configurations
    SET_BIT(SREG,7);
    SET_BIT(EICRA,ISC00);
    CLR_BIT(EICRA,ISC01);
    SET_BIT(EIMSK,INT0);

    //Internal Interrupt Configurations
    SET_BIT(PCICR,PCIE0);
    SET_BIT(PCMSK0,PCINT2);
    SET_BIT(PCICR,PCIE2);
    SET_BIT(PCMSK2,PCINT23);

    //FAST PWM Mode
    SET_BIT(TCCR0A,WGM00);
    SET_BIT(TCCR0A,WGM01);
    CLR_BIT(TCCR0B,WGM02);

    //Inverting Mode
    SET_BIT(TCCR0A,COM0A1);
    SET_BIT(TCCR0A,COM0A0);

    //Prescelar Selection
    SET_BIT(TCCR0B,CS00);
    CLR_BIT(TCCR0B,CS01);
    SET_BIT(TCCR0B,CS02);

    TCNT0=0;
    OCR0A=255;
    FLAG_BIT.flag0=1;
    FLAG_BIT.flag1=1;
    FLAG_BIT.flag2=1;

    while(1)
    {

    }

    return 0;
}

ISR(PCINT0_vect)
{
    cli();
    if(FLAG_BIT.flag0==1)
    {
        OCR0A=179;
        FLAG_BIT.flag0=~FLAG_BIT.flag0;
    }
    else if(FLAG_BIT.flag0==0 && FLAG_BIT.flag1==0)
    {
        OCR0A=255;
        FLAG_BIT.flag0=~FLAG_BIT.flag0;
    }
    sei();
}

ISR(PCINT2_vect)
{
    cli();
    if(FLAG_BIT.flag1==1)
    {
        OCR0A=89;
        FLAG_BIT.flag1=~FLAG_BIT.flag1;
    }
    else if(FLAG_BIT.flag1==0 && FLAG_BIT.flag1==0)
    {
        OCR0A=255;
        FLAG_BIT.flag1=~FLAG_BIT.flag1;
    }
    sei();
}

ISR(INT0_vect)
{
    cli();
    OCR0A=255;
    sei();
}


