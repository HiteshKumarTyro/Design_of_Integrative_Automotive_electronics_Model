#ifndef MAIN_H
#define MAIN_H

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)

#endif // MAIN_H
