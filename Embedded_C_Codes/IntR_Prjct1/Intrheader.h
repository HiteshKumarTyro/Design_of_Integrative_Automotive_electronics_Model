#ifndef INTRHEADER_H
#define INTRHEADER_H

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

#endif // INTRHEADER_H
