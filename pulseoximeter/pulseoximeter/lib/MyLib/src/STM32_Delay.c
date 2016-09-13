/*
 * 		@file STM32_Delay.c
 * 		@date 25-01-2012
 * 		@author Damian Burek
 * 		@brief The file contains simple Delay function
 *
 */

#include "STM32_Delay.h"

void Delay(void){
	int cnt=0;
	for(cnt=0;cnt<0xFFF;cnt++);
}
