#include "Define_G4.h"
/*----------------------------------------------------------*/
/**
 * ! Variable definition 
*/
	//TODO: Global Variable
	v_uint32_t user_sw_pressed = false;
	v_int32_t count = 0;
	v_int32_t increment = 0;
	//TODO: Local Variable
/*----------------------------------------------------------*/
int main(void)
{
	System_Init_170Mhz();
	GPIO_Init();
	PWM_Init();
	NVIC_Init();
	for(;;)
	{
		if(user_sw_pressed == false)
		{
			if(count == 100){
				increment = -1;
			}
			else if(count == 0){
				increment = 1;
			}
			count += increment;
			TIM2->CCR1 = (v_uint32_t)count;
			Delay(15);
		}
	}
}
