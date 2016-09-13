/**
 *  @file main.c
 *  @date 16-01-2012
 *  @author: Damian Burek
 *  @brief The file contains Main function
 */

#include "stm32f10x.h"
#include "STM32_CoreInit.h"
#include "STM32_PeriphInit.h"

/* STM32 Library */
#include "stm32f10x_gpio.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"

struct LEDparams {
	uint16_t Pin;
	uint16_t Delay;	
} LedParameters1, LedParameters2, LedParameters3;

void LedToggle ( void *pvParameters ) 
{
	while ( 1 ) {
		GPIO_SetBits (GPIOD, ((struct LEDparams *) pvParameters)->Pin);
	        vTaskDelay(( portTickType) (((struct LEDparams *) pvParameters)->Delay) );	
		GPIO_ResetBits (GPIOD, ((struct LEDparams *) pvParameters)->Pin);
		vTaskDelay(( portTickType) (((struct LEDparams *) pvParameters)->Delay) );	
	}
}

void Send ( void )
{
	static uint16_t Data = 0x0000;
	while ( 1 ) {
		// Start the conversion 
		ADC_SoftwareStartConvCmd ( ADC1, ENABLE ); 
		// Wait until conversion completion 
		while ( ADC_GetFlagStatus ( ADC1, ADC_FLAG_EOC ) == RESET ); 
		// Get the conversion value
		Data = ADC_GetConversionValue ( ADC1 );
		
		while ( USART_GetFlagStatus( USART1, USART_FLAG_TXE) != SET );
			USART_SendData( USART1, (uint8_t) (Data & 0x00FF) );

		while ( USART_GetFlagStatus( USART1, USART_FLAG_TXE) != SET );
			USART_SendData( USART1, (uint8_t) ((Data >> 8) & 0x00FF) );
	
	vTaskDelay(( portTickType) 5 );	
	}
}

/*--------------------MAIN function------------------------------------------------*/
int main(void) {

/*-------------Core and Peripherals basic settings initialization------------------*/
	STM32_CoreInit();
	STM32_PeriphInit();

/*-----------------Infinite Loop---------------------------------------------------*/

	LedParameters1.Pin = GPIO_Pin_2; 
	LedParameters1.Delay = 50;
	
	LedParameters2.Pin =  GPIO_Pin_4; 
	LedParameters2.Delay = 25;
		
	LedParameters3.Pin =  GPIO_Pin_7; 
	LedParameters3.Delay = 75;
 
	xTaskCreate( LedToggle, ( signed portCHAR * ) "LED1", configMINIMAL_STACK_SIZE, (struct LEDparams *) &LedParameters1, 1, NULL );
	xTaskCreate( LedToggle, ( signed portCHAR * ) "LED2", configMINIMAL_STACK_SIZE, (struct LEDparams *) &LedParameters2, 1, NULL );
	xTaskCreate( LedToggle, ( signed portCHAR * ) "LED3", configMINIMAL_STACK_SIZE, (struct LEDparams *) &LedParameters3, 1, NULL );

	xTaskCreate( Send, ( signed portCHAR * ) "USART", configMINIMAL_STACK_SIZE, (struct LEDparams *) NULL, 1, NULL );


	vTaskStartScheduler();
	
       	while(1) {
		
	}
}
/*------------------END of MAIN function-------------------------------------------*/
