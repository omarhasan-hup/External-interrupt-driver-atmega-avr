/*
 * Interrupt.h
 *
 *  Created on: Dec 22, 2022
 *      Author: Eng_Omar
 */

#ifndef HAL_INTERRUPT_HAL_INTERRUPT_H_
#define HAL_INTERRUPT_HAL_INTERRUPT_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
/*******************************************************************************/

/*******************************************************************************
 *                      Definations & Enumurtions &static types                              *
 *******************************************************************************/
/*this data type will be used to check on the interrupt numbers to chosee whihc interrupt
 *will be activaed in the intaliaztion function*/

typedef enum{
	Ext_int0,
	Ext_int1,
	Ext_int2
}Ext_inter_num;

/*This data type will be used to chosee which edge to be slected on the interrupt rising or falling */

typedef enum{
	Rising,
	Falling
}Ext_Int_Edge;
/*******************************************************************************
 *                      Functions prototypes                                               *
 *******************************************************************************/
void interrupt_intilization(Ext_inter_num interr_num,Ext_Int_Edge Interr_edge);

void Update_ptr2function_int0(void (*ptr2function)(void));

void Update_ptr2function_int1(void (*ptr2function_int1)(void));

void Update_ptr2function_int2(void (*ptr2function_int2)(void));

/*******************************************************************************/
#endif /* HAL_INTERRUPT_HAL_INTERRUPT_H_ */
