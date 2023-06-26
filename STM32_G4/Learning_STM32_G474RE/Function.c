#include "Define_G4.h"

void Signal_Pin_Output(int mode,int port,int value)
{
	switch (port)
	{
	case 1:
		
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
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
