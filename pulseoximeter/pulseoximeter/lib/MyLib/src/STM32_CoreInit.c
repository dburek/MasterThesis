/**
 * 		@file STM32_Init.c
 * 		@date 25-01-2012
 * 		@author Damian Burek
 * 		@brief The file contains basic system initialization function
 */

#include "STM32_CoreInit.h"
#include "stm32f10x_rcc.h"

/**
 *	@brief Basic system configuration: Core
 *	@param  None
 *	@retval None
 */

void STM32_CoreInit(void)
{

	/* Setting system clock speed */
	STM32_ClockInit();
}



/**
 * @brief  Basic Clock Settings
 * @note   External crystal = 25MHz
 * @param  None
 * @retval None
 */
void STM32_ClockInit(void)
{
	/* Reset to default */
	RCC_DeInit();

	/* HSE Clock enable (25MHz) */
	RCC_HSEConfig(RCC_HSE_ON);

	/* Waiting for HSE Start Up, Clock Security System (CSS) enabled automatically */
	if(RCC_WaitForHSEStartUp()==SUCCESS){

		/* PLL settings (25MHz*4) */
		RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_4);
		/* PREDIV1 settings (25MHz*4/2 = 50MHz) */
		RCC_PREDIV1Config(RCC_PREDIV1_Source_HSE, RCC_PREDIV1_Div2);
		/* PLL1 ON */
		RCC_PLLCmd(ENABLE);

		/* Waiting for PLL Start Up */
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);

		/* AHB settings (50MHZ) */
		RCC_HCLKConfig(RCC_SYSCLK_Div2);
		/* APB1 settings (25MHz) */
		RCC_PCLK1Config(RCC_HCLK_Div2);
		/* APB2 settings (50MHz) */
		RCC_PCLK2Config(RCC_HCLK_Div1);

		/* System Clock switching to PLLCLK = 50MHz */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		/* Waiting for System Clock switching */
		while(RCC_GetSYSCLKSource()!=0x08);
	}
	else
	{
	/* HSE Start Up Error Procedure */

	}

/* If HSE failed SYSCLK=HSI (8MHz) */

}
/*----------END of Clock Settings----------*/
