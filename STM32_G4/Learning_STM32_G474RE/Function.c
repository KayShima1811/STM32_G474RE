#include "Define_G4.h"

void Signal_Pin_Output(int Mode,int Port,int Pin, uint32_t Value)
{
	GPIO_TypeDef* GPIOx = 0;
	switch (Port)
	{
	case GPIO_PORT_A:
		GPIOx = GPIOA;
		break;
	case GPIO_PORT_B:
		GPIOx = GPIOB;
		break;
	case GPIO_PORT_C:
		GPIOx = GPIOC;
		break;
	case GPIO_PORT_D:
		GPIOx = GPIOD;
		break;
	case GPIO_PORT_E:
		GPIOx = GPIOE;
		break;
	case GPIO_PORT_F:
		GPIOx = GPIOF;
		break;
	case GPIO_PORT_G:
		GPIOx = GPIOG;
		break;
	default:
		break;
	}
	switch (Mode)
	{
	case MODE_WRITE:
		if(Value)
		{
			SET_BIT(GPIOx->MODE[ODR],1UL << Pin);
		}
		else
		{
			CLEAR_BIT(GPIOx->MODE[ODR], 1UL << Pin);
		}
		break;
	case MODE_READ:
		READ_BIT(GPIOx->MODE[ODR],1 << Pin);
		break;
	case MODE_TOGGLE:
		TOGGLE_BIT(GPIOx->MODE[ODR],1 << Pin);
		break;
	default:
		break;
	}
}

void Delay(int time_ms) 
{
	int delay_count = (170 * time_ms) / 1000;
	
	SYST->LOAD |= 0xF423FUL; 					//Set register reload value = 999.999

	SYST->VAL = 0x0UL;								//Clear register current value = 0

	SYST->CTRL |= 0x5UL; 							//Enable SystemTick and chose clock source = processor clock

  	for (int i = 0; i < delay_count; i++) 
	{
		while (!(SYST->CTRL & (1 << 16))); // busy-wait until SYSTICK exception occurs
  	}

  	SYST->CTRL = 0x0UL;
}


