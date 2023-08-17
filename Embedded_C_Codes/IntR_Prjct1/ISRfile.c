#include "Intrheader.h"

extern flag1=1;
ISR(PCINT0_vect)
{
    cli();
    flag1=~flag1;
    sei();
}

