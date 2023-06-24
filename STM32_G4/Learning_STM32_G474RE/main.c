#include "Define_G4.h"
/*----------------------------------------------------------*/
/**
 * ! Variable definition 
*/
	v_uint32_t user_sw_pressed = false;
	static v_int32_t count = 0;
	static v_int32_t increment = 0;
	static v_uint32_t	flag_cycle = false;
/*----------------------------------------------------------*/
int main(void)
{
	System_Init_170Mhz();
	GPIO_Init();
	PWM_Init();
	NVIC_Init();
	for(;;)
	{
		if(user_sw_pressed == true)
		{
			count = 0;
			increment = 0;
		}
		if(user_sw_pressed == false)
		{
			if(count >= 0)
			{
				if(count == 100){
					increment = -1;
					flag_cycle = true;
				}
				else if(count == 0){
					increment = 1;
				}
				count += increment;
			}
			TIM2->CCR1 = (v_uint32_t)count;
			Delay(20);
			if(flag_cycle == true)
			{
				Delay(5000);
				flag_cycle = false;
			}
			}
		}
	}
