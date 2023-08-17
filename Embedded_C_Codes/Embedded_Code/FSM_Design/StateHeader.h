#ifndef STATEHEADER_H
#define STATEHEADER_H

#include <stdint.h>
#include <avr/interrupt.h>

struct
{
    volatile unsigned int flag1:1 ;
    volatile unsigned int flag2:1 ;

}FLAG_BIT;

void Delay_Timer(int);

#endif
