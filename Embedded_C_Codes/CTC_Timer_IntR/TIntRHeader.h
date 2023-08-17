#ifndef TINTRHEADER_H
#define TINTRHEADER_H

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>


#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

#endif // TINTRHEADER_H


