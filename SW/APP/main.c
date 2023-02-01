/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Eng_Omar
 */


/*includes*/
#include <avr/io.h>
#include "Interrupt.h"

/*******************************************************/
/*Constants*/




/*******************************************************/
/*golbal variables*/


/*******************************************************/

/*functions prototypes*/

void interrupt_function_int0(void);
/*This function contain "what to do when int0 fires" and its adderess will be updated by
 *the function Update_ptr2function_int0()*/

void interrupt_function_int1(void);
/*This function contain "what to do when int1 fires" and its adderess will be updated by
 *the function Update_ptr2function_int1()*/

void interrupt_function_int2(void);
/*This function contain "what to do when int2 fires" and its adderess will be updated by
 *the function Update_ptr2function_int2()*/
/*******************************************************/
int main(void)
{




	DDRC  = DDRC | (1<<PC0);     // Configure pin PC0 in PORTC as output pin to be toggled each interrupt
	PORTC = PORTC & (~(1<<PC0)); // Initialization Led is off at the beginning(Negative Logic)

	DDRC= DDRC |(1<<PC1);        // configure pin1 to be output
	PORTC= PORTC & (~(1<<PC1));  // make the first output of pin 1 to be Zero

	DDRC= DDRC |(1<<PC2);        // configure pin2 to be output
	PORTC= PORTC & (~(1<<PC2));  // make the first output of pin 1 to be Zero

	DDRC= DDRC |(1<<PC3);        // configure pin3 to be output
	PORTC= PORTC & (~(1<<PC3));  // make the first output of pin 1 to be Zero

	interrupt_intilization(Ext_int1,Rising);

    Update_ptr2function_int0(interrupt_function_int0);

    Update_ptr2function_int1(interrupt_function_int1);

    Update_ptr2function_int2(interrupt_function_int2);

	while(1)
	{
		PORTC = PORTC | (1<<PC1);
		_delay_ms(200);
		PORTC = PORTC & (~(1<<PC1));
		_delay_ms(200);

	}
	return 0;

}






/*******************************************************/
/*Functions body*/
void interrupt_function_int0(void)
{
	PORTC = PORTC | (1<<PC0);
	_delay_ms(1000);
	PORTC = PORTC & (~(1<<PC0));
	_delay_ms(1000);
}

void interrupt_function_int1(void)
{
	PORTC = PORTC | (1<<PC2);
	_delay_ms(1000);
	PORTC = PORTC & (~(1<<PC2));
	_delay_ms(1000);
}

void interrupt_function_int2(void)
{
	PORTC = PORTC | (1<<PC3);
	_delay_ms(1000);
	PORTC = PORTC & (~(1<<PC3));
	_delay_ms(1000);
}
