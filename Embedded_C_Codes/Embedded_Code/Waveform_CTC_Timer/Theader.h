#ifndef THEADER_H
#define THEADER_H

#include <avr/io.h>
#include <stdint.h>
//#include <util/delay.h>
#include <avr/interrupt.h>


#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

/*void Delay_Timer(int);

struct
{
    volatile unsigned int flag1:1 ;
    volatile unsigned int flag2:1 ;

}FLAG_BIT;*/

#endif // THEADER_H

