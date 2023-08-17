/*
 */

#include "Hvacsystem.h"

struct
{
    volatile unsigned int flag0:1;
    volatile unsigned int tempValue:10;
    volatile unsigned int humiValue:10;
    volatile unsigned int pwmV:8;

}H_CTRL;

int main(void)
{

    //INITIALIZATIONS
    H_CTRL.flag0=0;

    while(1)
    {
        if(READ_BIT(PINB,PB5)==0x20)
        {

        }
    }

    return 0;
}

ISR(INT1_vect)
{

}

ISR(PCINT1_vect)
{

}
