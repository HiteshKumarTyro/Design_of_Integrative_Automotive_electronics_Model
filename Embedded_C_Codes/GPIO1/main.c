/*
 */

#include "main.h"
#include "toggle.h"

int main(void)
{

    // GPIO Configurations
    SET_BIT(DDRC,PC6); // Setting PC6 as output pin
    SET_BIT(PORTC,PC6);

    while(1)
    {
        /*SET_BIT(PORTC,PC6);
        _delay_ms(1000);
        CLR_BIT(PORTC,PC6);
        _delay_ms(1000); */
        TOGGLE_BIT(PORTC,PC6);
        _delay_ms(1000);
    }

    return 0;
}
