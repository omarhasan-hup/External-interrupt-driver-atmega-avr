/*
 * interrupt.c
 *
 *  Created on: Dec 22, 2022
 *      Author: Eng_Omar
 */
/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "Interrupt.h"

/*******************************************************************************
 *                      Global variables                                               *
 *******************************************************************************/
/*This is a global pointer to function which be updated with the adresse of the function needed to be
 *excuted when the interrupt number Zero fires*/
void (*Call_back_func_ptr2int0)(void)=NULL;

/*This is a global pointer to function which be updated with the adresse of the function needed to be
 *excuted when the interrupt number One fires*/
void (*Call_back_func_ptr2int1)(void)=NULL;

/*This is a global pointer to function which be updated with the adresse of the function needed to be
 *excuted when the interrupt number Two fires*/
void (*Call_back_func_ptr2int2)(void)=NULL;


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*This function is used to configure the interrupts. It takes the number of external interrupts 0 | 1 | 2 to be intilaized
 *and on which edge rising or fallen*/
void interrupt_intilization(Ext_inter_num interr_num,Ext_Int_Edge Interr_edge)
{
	/*First we need to clear the I bit to disable the interrupts during the intialization*/
	SREG =SREG & (~(1<<7));
	/*check which interrupt to be activated */
	if(interr_num==Ext_int0)
	{
		DDRD=DDRD&(~(1<<2));  // make pin 2 in PortD to be input for the interrupt INT0
		/*Interrupt number 0 is to be activated*/
		/*enable the interrupt number 0 which is located in the bit 6 in GICR register*/
		GICR=GICR |(1<<INT0);
		/*Then check which of the edges will fire the interrupt*/
		if(Interr_edge == Rising)
		{
			/*interrupt number 0 is to be generated on the Rising edge*/
			MCUCR=MCUCR |((1<<ISC00)|(1<<ISC01));
		}
		else if (Interr_edge == Falling)
		{
			/*interrupt number 0 is to be generated on the Falling edge*/
			MCUCR=MCUCR |(1<<ISC01);
			MCUCR=MCUCR &(~(1<<ISC00));
		}
		else
		{
			/*If there is any input except for rising and falling edge then it will not work*/
		}

	}
	else if(interr_num==Ext_int1)
	{
		DDRD=DDRD&(~(1<<3));  // make pin 3 in PortD to be input for the interrupt INT1
		/*Interrupt number 1 is to be activated*/
		/*enable the interrupt number 1 which is located in the bit 7 in GICR reg*/
		GICR=GICR |(1<<INT1);
		/*Then check which of the edges will fire the interrupt*/
		if(Interr_edge == Rising)
		{
			/*interrupt number 0 is to be generated on the Rising edge*/
			MCUCR=MCUCR |((1<<ISC11)|(1<<ISC10));
		}
		else if (Interr_edge == Falling)
		{
			/*interrupt number 0 is to be generated on the Falling edge*/
			MCUCR=MCUCR |(1<<ISC11);
			MCUCR=MCUCR &(~(1<<ISC10));
		}
		else
		{
			/*If there is any input except for rising and falling edge then it will not work*/
		}

	}

	else if(interr_num==Ext_int2)
	{
		DDRB=DDRB&(~(1<<PB2));  // make pin 3 in PortD to be input for the interrupt INT2
		/*Interrupt number 0 is to be activated*/
		/*enable the interrupt number 1 which is located in the bit 7 in GICR reg*/
		GICR=GICR |(1<<INT2);
		/*Then check which of the edges will fire the interrupt*/
		if(Interr_edge == Rising)
		{
			/*interrupt number 0 is to be generated on the Rising edge*/
			MCUCSR=MCUCSR |(1<<ISC2);
		}
		else if (Interr_edge == Falling)
		{
			/*interrupt number 0 is to be generated on the Falling edge*/
			MCUCSR=MCUCSR &(~(1<<ISC2));
		}
		else
		{
			/*If there is any input except for rising and falling edge then it will not work*/
		}

	}

	/*Set the I bit again to enable the interrupts*/
	SREG=SREG|(1<<7);
}

/*This function will be used to update the pointer to application function address to the external interrupt 0 */
void Update_ptr2function_int0(void (*ptr2function)(void))
{
	/*Update the pointer to function in the interrupt module with the address of the function
	 *The application module want to excute when the interrupt number Zero is fired */
	Call_back_func_ptr2int0=ptr2function;
}

/*This function will be used to update the pointer to application function address to the external interrupt 1 */
void Update_ptr2function_int1(void (*ptr2function_int1)(void))
{
	/*Update the pointer to function in the interrupt module with the address of the function
	 *The application module want to excute when the interrupt number Zero is fired */
	Call_back_func_ptr2int1=ptr2function_int1;
}

/*This function will be used to update the pointer to application function address to the external interrupt 2 */
void Update_ptr2function_int2(void (*ptr2function_int2)(void))
{
	/*Update the pointer to function in the interrupt module with the address of the function
	 *The application module want to excute when the interrupt number Zero is fired */
	Call_back_func_ptr2int2=ptr2function_int2;
}


ISR(INT0_vect)
{
	/*If the interrupt is fired then we want to excute the function of the application has sent us its addrese
	 * in the pointer to function update*/
	if(Call_back_func_ptr2int0!=NULL)
	{
		/*If the pointer has an address of afunction then it will excute it*/
		Call_back_func_ptr2int0();
	}
}

ISR(INT1_vect)
{
	/*If the interrupt is fired then we want to excute the function of the application has sent us its addrese
	 * in the pointer to function update*/
	if(Call_back_func_ptr2int1!=NULL)
	{
		/*If the pointer has an address of afunction then it will excute it*/
		Call_back_func_ptr2int1();
	}
}

ISR(INT2_vect)
{
	/*If the interrupt is fired then we want to excute the function of the application has sent us its addrese
	 * in the pointer to function update*/
	if(Call_back_func_ptr2int2!=NULL)
	{
		/*If the pointer has an address of afunction then it will excute it*/
		Call_back_func_ptr2int2();
	}
}
