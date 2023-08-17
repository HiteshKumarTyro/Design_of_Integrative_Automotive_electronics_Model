#ifndef FSMHEADER_H
#define FSMHEADER_H

#include <avr/io.h>

#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

void State_FSM(void);

#endif // FSMHEADER_H

