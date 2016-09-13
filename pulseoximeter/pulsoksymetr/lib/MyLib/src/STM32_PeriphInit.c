/*
 * STM32_PeriphInit.c
 *
 *  Created on: 11-03-2012
 *      Author: Damian Burek
 */


#include "STM32_PeriphInit.h"
#include "STM32_CoreInit.h"

/**
 *	@brief Basic system configuration: Peripherials
 *	@param  None
 *	@retval None
 */

void STM32_PeriphInit(void){

	/* GPIO Basic Settings */
	STM32_GPIOInit();
	/* USART Basic Settings */
	STM32_USARTInit();
	/* ADC Basic Settings */
	STM32_ADCInit();
	/* TIM Basic Settings */
//	STM32_TIMInit();
}


/**
 * @brief  GPIO Basic Settings
 * @param  None
 * @retval None
 */
void STM32_GPIOInit(void){

	/* GPIOx Clock Enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC |
		       	RCC_APB2Periph_GPIOD, ENABLE);

	/* Declaration of GPIO Init Structure */
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

	/* GPIOx Initialization*/
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}
/*----------END of GPIO Settings-----------*/


/**
 * @brief  USART Basic Settings
 * @param  None
 * @retval None
 */
void STM32_USARTInit ( void ) 
{

	/* USARTx Clock Enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* Declaration of USART Init Structure */
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_Mode=USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;

	/* USARTx Initialization */
	USART_Init(USART1,&USART_InitStructure);

	/* USART1 TX pin enable (GPIO:PA9 - alternate function USART1_TX) */

	/* Declaration of GPIO Init Structure */
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;

	/* GPIOx Initialization*/
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* USARTx ON*/
	USART_Cmd(USART1, ENABLE);
}


/**
 * @brief  ADC Basic Settings
 * @param  None
 * @retval None
 */
void STM32_ADCInit ( void )
{
	/* ADC Clock Enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* setting ADC Clock, APB2_Clk/ADC_prescaler=ADC_Clock, 50Mhz/8=6.25MHz < 14MHz(max) */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);

	/* Declaration of USART Init Structure */
	ADC_InitTypeDef ADC_InitStructure;

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;

	/* ADC Initialization */
	ADC_Init(ADC1, &ADC_InitStructure);

	/* ADC Channels settings*/
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_1Cycles5);

	/* ADC pin enable (GPIO:PC0 - analog) */
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* ADC ON*/
	ADC_Cmd(ADC1, ENABLE);
}


/**
 * @brief  TIM Basic Settings
 * @param  None
 * @retval None
 */
void STM32_TIMInit ( void ) 
{
	uint16_t TimeBasePeriod = ( uint16_t ) ( APB1_FREQ / 4000 ); 
	uint16_t OC1Period = TimeBasePeriod - 2000;
	uint16_t OC2Period = 2000; 
	uint16_t OC3Period = TimeBasePeriod - 300;
	uint16_t OC4Period = 300;


	/* TIM3 Clock Enable */
	RCC_APB1PeriphClockCmd ( RCC_APB1Periph_TIM3, ENABLE );
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); 
	
	/* Declaration of Init Structure */
	TIM_TimeBaseInitTypeDef TIM_TimeBase_Structure;

	TIM_TimeBase_Structure.TIM_Prescaler = 4;
	TIM_TimeBase_Structure.TIM_CounterMode = TIM_CounterMode_CenterAligned1; 
	TIM_TimeBase_Structure.TIM_Period = TimeBasePeriod;
	TIM_TimeBase_Structure.TIM_ClockDivision = TIM_CKD_DIV1;  
	TIM_TimeBase_Structure.TIM_RepetitionCounter = 0; 
 	
	/* TIM3 Time Base Initialization */
	TIM_TimeBaseInit( TIM3, &TIM_TimeBase_Structure );

	/* GPIO: TIM3 Channel 1-2  pin enable (GPIO:PA6 PA7 - push-pull) */
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 

	GPIO_Init ( GPIOA, &GPIO_InitStructure );
	
	/* GPIO: TIM3 Channel 3-4 pin enable (GPIO:PB0 PB1 - push-pull) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 

	GPIO_Init ( GPIOB, &GPIO_InitStructure );

	/* TIM3 Channel 1 PWM Mode configuration */ 
	TIM_OCInitTypeDef TIM_OCInitStruct;

	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 
    	TIM_OCInitStruct.TIM_Pulse = OC1Period; 
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low;        
        
        TIM_OC1Init(TIM3, &TIM_OCInitStruct); 
        TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); 

	/* TIM3 Channel 2 PWM Mode configuration */ 
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 
    	TIM_OCInitStruct.TIM_Pulse = OC2Period; 
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;        
        
        TIM_OC2Init(TIM3, &TIM_OCInitStruct); 
        TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); 

	/* TIM3 Channel 3 PWM Mode configuration */ 
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 
    	TIM_OCInitStruct.TIM_Pulse = OC3Period; 
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
        
        TIM_OC3Init(TIM3, &TIM_OCInitStruct); 
        TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); 

	/* TIM3 Channel 4 PWM Mode configuration */ 
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 
    	TIM_OCInitStruct.TIM_Pulse = OC4Period; 
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;        
        
        TIM_OC4Init(TIM3, &TIM_OCInitStruct); 
        TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); 



	TIM_Cmd(TIM3, ENABLE); 
}

 /*----------END of USART Settings-----------*/
