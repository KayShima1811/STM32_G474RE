#include "Define_G4.h"

void EXTI15_10_IRQHandler(void)
{
	if(READ_BIT(EXTI->PR1,(0x1UL << 13UL)) != false)
	{
		user_sw_pressed = !user_sw_pressed;
		if(user_sw_pressed == true)
		{
			TIM2->CCR1 = 0;
		}
		SET_BIT(EXTI->PR1,(0x1UL << 13UL));
	}
}
