/*
 * 		@file STM32_CoreInit.c
 * 		@date 25-01-2012
 * 		@author Damian Burek
 * 		@brief The file contains basic system initialization function
 *
 */

#ifndef STM32_INIT_H_
#define STM32_INIT_H_

#define AHB_FREQ 	50000000
#define APB1_FREQ 	( AHB_FREQ / 2 )
#define APB2_FREQ 	AHB_FREQ;

/**
 * Primary Core initialization
 */
void STM32_CoreInit(void);

/**
 * Clock basic Settings
 */
void STM32_ClockInit(void);


#endif /* STM32_INIT_H_ */
