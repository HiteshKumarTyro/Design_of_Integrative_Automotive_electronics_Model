#include "ADCinitial.h"

void adc_temp_start()
{
    SET_BIT(ADCSRA,ADEN);
    CLR_BIT(ADMUX,ADLAR);

    //ADC pin Selection
    CLR_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);

    //External Reference
    CLR_BIT(ADMUX,REFS1);
    CLR_BIT(ADMUX,REFS0);
}

void adc_hum_start()
{
    SET_BIT(ADCSRA,ADEN);
    CLR_BIT(ADMUX,ADLAR);

    //ADC pin Selection
    CLR_BIT(ADMUX,MUX0);
    SET_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    SET_BIT(ADMUX,MUX3);

    //External Reference
    CLR_BIT(ADMUX,REFS1);
    CLR_BIT(ADMUX,REFS0);
}

void adc_stop()
{
    CLR_BIT(ADCSRA,ADEN);
}
