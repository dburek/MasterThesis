/*
 * 		@file STM32_PeriphInit.c
 * 		@date 14-03-2012
 * 		@author Damian Burek
 * 		@brief The file contains basic peripherials initialization function
 */

#ifndef STM32_PERIPHINIT_H_
#define STM32_PERIPHINIT_H_

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_tim.h"

/**
 * Primary Core initialization
 */
void STM32_PeriphInit(void);


/**
 * GPIO basic Settings
 */
void STM32_GPIOInit(void);


/**
 * USART basic Settings
 */
void STM32_USARTInit(void);


/**
 * ADC basic Settings
 */
void STM32_ADCInit(void);


/**
 * TIMbasic Settings
 */
void STM32_TIMInit(void);


#endif /* STM32_PERIPHINIT_H_ */

