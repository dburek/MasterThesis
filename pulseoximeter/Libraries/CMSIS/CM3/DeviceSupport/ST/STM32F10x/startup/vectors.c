/** \file vectors.c
 * \brief STM32 (connectivity line) vector table and __Default_Handler()
 * \details STM32 (connectivity line) vector table and __Default_Handler()
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-07
 */

/******************************************************************************
* chip: STM32F105x / STM32F107x
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

/*------------------------------------------------------------------------*//**
* \brief Default interrupt handler.
* \details Default interrupt handler, used for interrupts that don't have their
* own handler defined.
*//*-------------------------------------------------------------------------*/

static void __Default_Handler(void) __attribute__ ((interrupt));
static void __Default_Handler(void)
{
	while (1);
}

/*
+=============================================================================+
| assign all unhandled interrupts to the default handler
+=============================================================================+
*/

// Non-maskable interrupt (RCC clock security system)
void NMI_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// All class of fault
void HardFault_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Memory management
void MemManage_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Pre-fetch fault, memory access fault
void BusFault_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Undefined instruction or illegal state
void UsageFault_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x1C
void __Reserved_0x1C_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x20
void __Reserved_0x20_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x24
void __Reserved_0x24_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x28
void __Reserved_0x28_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// System service call via SWI instruction
void SVC_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Debug monitor
void DebugMon_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x34
void __Reserved_0x34_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Pendable request for system service
void PendSV_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// System tick timer
void SysTick_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Window watchdog interrupt
void WWDG_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// PVD through EXTI line detection interrupt
void PVD_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Tamper interrupt
void TAMPER_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// RTC global interrupt
void RTC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Flash global interrupt
void FLASH_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// RCC global interrupt
void RCC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line0 interrupt
void EXTI0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line1 interrupt
void EXTI1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line2 interrupt
void EXTI2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line3 interrupt
void EXTI3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line4 interrupt
void EXTI4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel1 global interrupt
void DMA1_Channel1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel2 global interrupt
void DMA1_Channel2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel3 global interrupt
void DMA1_Channel3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel4 global interrupt
void DMA1_Channel4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel5 global interrupt
void DMA1_Channel5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel6 global interrupt
void DMA1_Channel6_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA1 Channel7 global interrupt
void DMA1_Channel7_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// ADC1 and ADC2 global interrupt
void ADC1_2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN1 TX interrupt
void CAN1_TX_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN1 RX0 interrupt
void CAN1_RX0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN1 RX1 interrupt
void CAN1_RX1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN1 SCE interrupt
void CAN1_SCE_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line[9:5] interrupts
void EXTI9_5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM1 break interrupt
void TIM1_BRK_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM1 update interrupt
void TIM1_UP_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM1 trigger and commutation interrupts
void TIM1_TRG_COM_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM1 capture compare interrupt
void TIM1_CC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM2 global interrupt
void TIM2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM3 global interrupt
void TIM3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM4 global interrupt
void TIM4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// I2C1 event interrupt
void I2C1_EV_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// I2C1 error interrupt
void I2C1_ER_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// I2C2 event interrupt
void I2C2_EV_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// I2C2 error interrupt
void I2C2_ER_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// SPI1 global interrupt
void SPI1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// SPI2 global interrupt
void SPI2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// USART1 global interrupt
void USART1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// USART2 global interrupt
void USART2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// USART3 global interrupt
void USART3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// EXTI Line[15:10] interrupts
void EXTI15_10_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// RTC alarm through EXTI line interrupt
void RTCAlarm_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// USB On-The-Go FS Wakeup through EXTI line interrupt
void OTG_FS_WKUP_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xEC
void __Reserved_0xEC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xF0
void __Reserved_0xF0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xF4
void __Reserved_0xF4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xF8
void __Reserved_0xF8_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xFC
void __Reserved_0xFC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x100
void __Reserved_0x100_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x104
void __Reserved_0x104_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM5 global interrupt
void TIM5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// SPI3 global interrupt
void SPI3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// UART4 global interrupt
void UART4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// UART5 global interrupt
void UART5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM6 global interrupt
void TIM6_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// TIM7 global interrupt
void TIM7_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA2 Channel1 global interrupt
void DMA2_Channel1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA2 Channel2 global interrupt
void DMA2_Channel2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA2 Channel3 global interrupt
void DMA2_Channel3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA2 Channel4 global interrupt
void DMA2_Channel4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// DMA2 Channel5 global interrupt
void DMA2_Channel5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Ethernet global interrupt
void ETH_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Ethernet Wakeup through EXTI line interrupt
void ETH_WKUP_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN2 TX interrupt
void CAN2_TX_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN2 RX0 interrupt
void CAN2_RX0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN2 RX1 interrupt
void CAN2_RX1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CAN2 SCE interrupt
void CAN2_SCE_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// USB On The Go FS global interrupt
void OTG_FS_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

/*
+=============================================================================+
| Vector table
+=============================================================================+
*/

extern const char __main_stack_end;			// imported main stack end (from linker script)

void Reset_Handler(void);					// import the address of Reset_Handler()

void (* const vectors[])(void) __attribute__ ((section(".vectors"))) = {
		(void (*)(void))&__main_stack_end,	// Main stack end address
		Reset_Handler,						// Reset
		NMI_Handler,						// Non-maskable interrupt (RCC clock security system)
		HardFault_Handler,					// All class of fault
		MemManage_Handler,					// Memory management
		BusFault_Handler,					// Pre-fetch fault, memory access fault
		UsageFault_Handler,					// Undefined instruction or illegal state
		__Reserved_0x1C_Handler,			// Reserved 0x1C
		__Reserved_0x20_Handler,			// Reserved 0x20
		__Reserved_0x24_Handler,			// Reserved 0x24
		__Reserved_0x28_Handler,			// Reserved 0x28
		SVC_Handler,						// System service call via SWI instruction
		DebugMon_Handler,					// Debug monitor
		__Reserved_0x34_Handler,			// Reserved 0x34
		PendSV_Handler,						// Pendable request for system service
		SysTick_Handler,					// System tick timer
		WWDG_IRQHandler,					// Window watchdog interrupt
		PVD_IRQHandler,						// PVD through EXTI line detection interrupt
		TAMPER_IRQHandler,					// Tamper interrupt
		RTC_IRQHandler,						// RTC global interrupt
		FLASH_IRQHandler,					// Flash global interrupt
		RCC_IRQHandler,						// RCC global interrupt
		EXTI0_IRQHandler,					// EXTI Line0 interrupt
		EXTI1_IRQHandler,					// EXTI Line1 interrupt
		EXTI2_IRQHandler,					// EXTI Line2 interrupt
		EXTI3_IRQHandler,					// EXTI Line3 interrupt
		EXTI4_IRQHandler,					// EXTI Line4 interrupt
		DMA1_Channel1_IRQHandler,			// DMA1 Channel1 global interrupt
		DMA1_Channel2_IRQHandler,			// DMA1 Channel2 global interrupt
		DMA1_Channel3_IRQHandler,			// DMA1 Channel3 global interrupt
		DMA1_Channel4_IRQHandler,			// DMA1 Channel4 global interrupt
		DMA1_Channel5_IRQHandler,			// DMA1 Channel5 global interrupt
		DMA1_Channel6_IRQHandler,			// DMA1 Channel6 global interrupt
		DMA1_Channel7_IRQHandler,			// DMA1 Channel7 global interrupt
		ADC1_2_IRQHandler,					// ADC1 and ADC2 global interrupt
		CAN1_TX_IRQHandler,					// CAN1 TX interrupt
		CAN1_RX0_IRQHandler,				// CAN1 RX0 interrupt
		CAN1_RX1_IRQHandler,				// CAN1 RX1 interrupt
		CAN1_SCE_IRQHandler,				// CAN1 SCE interrupt
		EXTI9_5_IRQHandler,					// EXTI Line[9:5] interrupts
		TIM1_BRK_IRQHandler,				// TIM1 break interrupt
		TIM1_UP_IRQHandler,					// TIM1 update interrupt
		TIM1_TRG_COM_IRQHandler,			// TIM1 trigger and commutation interrupts
		TIM1_CC_IRQHandler,					// TIM1 capture compare interrupt
		TIM2_IRQHandler,					// TIM2 global interrupt
		TIM3_IRQHandler,					// TIM3 global interrupt
		TIM4_IRQHandler,					// TIM4 global interrupt
		I2C1_EV_IRQHandler,					// I2C1 event interrupt
		I2C1_ER_IRQHandler,					// I2C1 error interrupt
		I2C2_EV_IRQHandler,					// I2C2 event interrupt
		I2C2_ER_IRQHandler,					// I2C2 error interrupt
		SPI1_IRQHandler,					// SPI1 global interrupt
		SPI2_IRQHandler,					// SPI2 global interrupt
		USART1_IRQHandler,					// USART1 global interrupt
		USART2_IRQHandler,					// USART2 global interrupt
		USART3_IRQHandler,					// USART3 global interrupt
		EXTI15_10_IRQHandler,				// EXTI Line[15:10] interrupts
		RTCAlarm_IRQHandler,				// RTC alarm through EXTI line interrupt
		OTG_FS_WKUP_IRQHandler,				// USB On-The-Go FS Wakeup through EXTI line interrupt
		__Reserved_0xEC_IRQHandler,			// Reserved 0xEC
		__Reserved_0xF0_IRQHandler,			// Reserved 0xF0
		__Reserved_0xF4_IRQHandler,			// Reserved 0xF4
		__Reserved_0xF8_IRQHandler,			// Reserved 0xF8
		__Reserved_0xFC_IRQHandler,			// Reserved 0xFC
		__Reserved_0x100_IRQHandler,		// Reserved 0x100
		__Reserved_0x104_IRQHandler,		// Reserved 0x104
		TIM5_IRQHandler,					// TIM5 global interrupt
		SPI3_IRQHandler,					// SPI3 global interrupt
		UART4_IRQHandler,					// UART4 global interrupt
		UART5_IRQHandler,					// UART5 global interrupt
		TIM6_IRQHandler,					// TIM6 global interrupt
		TIM7_IRQHandler,					// TIM7 global interrupt
		DMA2_Channel1_IRQHandler,			// DMA2 Channel1 global interrupt
		DMA2_Channel2_IRQHandler,			// DMA2 Channel2 global interrupt
		DMA2_Channel3_IRQHandler,			// DMA2 Channel3 global interrupt
		DMA2_Channel4_IRQHandler,	 		// DMA2 Channel4 global interrupt
		DMA2_Channel5_IRQHandler, 			// DMA2 Channel5 global interrupt
		ETH_IRQHandler,						// Ethernet global interrupt
		ETH_WKUP_IRQHandler,				// Ethernet Wakeup through EXTI line interrupt
		CAN2_TX_IRQHandler,					// CAN2 TX interrupt
		CAN2_RX0_IRQHandler,				// CAN2 RX0 interrupt
		CAN2_RX1_IRQHandler,				// CAN2 RX1 interrupt
		CAN2_SCE_IRQHandler,				// CAN2 SCE interrupt
		OTG_FS_IRQHandler					// USB On The Go FS global interrupt
};

/******************************************************************************
* END OF FILE
******************************************************************************/
