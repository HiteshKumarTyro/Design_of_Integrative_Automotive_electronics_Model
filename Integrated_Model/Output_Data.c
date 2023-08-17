#include <stdio.h>
#include "data_table.h" 

/* analogInputs signal*/
#define Analog_input1_Index 07
#define Analog_input2_Index 14
#define Analog_input3_Index 21
#define Analog_input4_Index 28
#define Analog_input5_Index 35
 
/* digitalInputs signal*/
#define Digital_input1_Index 10
#define Digital_input2_Index 20
#define Digital_input3_Index 30
#define Digital_input4_Index 40
#define Digital_input5_Index 50
 
/* analogInputs signal variable*/
unsigned short Analog_input1;
unsigned short Analog_input2;
unsigned short Analog_input3;
unsigned short Analog_input4;
unsigned short Analog_input5;
 
/* digitalInputs signal variable*/
unsigned short Digital_input1;
unsigned short Digital_input2;
unsigned short Digital_input3;
unsigned short Digital_input4;
unsigned short Digital_input5;
 

void readInputs()
{
	 put_data(Analog_input1_index, Analog_input1);
	 put_data(Analog_input2_index, Analog_input2);
	 put_data(Analog_input3_index, Analog_input3);
	 put_data(Analog_input4_index, Analog_input4);
	 put_data(Analog_input5_index, Analog_input5);
 
	 put_data(Digital_input1_index, Digital_input1);
	 put_data(Digital_input2_index, Digital_input2);
	 put_data(Digital_input3_index, Digital_input3);
	 put_data(Digital_input4_index, Digital_input4);
	 put_data(Digital_input5_index, Digital_input5);
 
}