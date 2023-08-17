#include "Sensorvalue.h"

unsigned int Sensor_Value()
{
    unsigned int s_value;
    SET_BIT(ADCSRA,ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    s_value = ADCH;
    s_value = s_value << 8;
    s_value = s_value | ADCL;
    return s_value;
}
