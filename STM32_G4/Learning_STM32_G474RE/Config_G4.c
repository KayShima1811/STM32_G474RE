#include "Define_G4.h"

void System_Init_170Mhz(void)
{
	/* Configure the main internal regulator output voltage */
	CLEAR_BIT(PWR->CR5, RANGE_1_NORMAL_MODE);
	MODIFY_REG(PWR->CR1, PWR_VOS_SHIFT, VOS_SCALE_RANGE_1);
	/* HSE Configuration */
	SET_BIT(RCC->CR,RCC_HSE_ON);
	while(!READ_BIT(RCC->CR,RCC_HSE_READY));
	SET_BIT(RCC->APB1ENR1,RCC_APB1_PWR_ENABLE);
	/* PLL Configuration */
	CLEAR_BIT(RCC->CR, RCC_PLL_ON);
	CLEAR_BIT(RCC->PLLCFGR, (RCC_PLLR_EN | RCC_PLLQ_EN | RCC_PLLP_EN));
	RCC_PLL_CONFIG(PLLSRC_HSE,PLL_M,PLL_N,PLL_P,PLL_Q,PLL_R);
	SET_BIT(RCC->PLLCFGR,RCC_PLLR_EN);
	SET_BIT(RCC->CR, RCC_PLL_ON);
	while (READ_BIT(RCC->CR, RCC_PLL_READY) == 0U);
	/* FLASH Configuration */
	MODIFY_REG(FLASH->ACR, FLASH_LATENCY, FLASH_LATENCY_4WS);
	/* AHB,APB1,APB2 Configuration */
	/* AHB,APB1,APB2 div 1*/
	CLEAR_BIT(RCC->CFGR, PPRE2_PPRE1_HPRE);
	/* Select the Clock Source for PLL */
	SET_BIT(RCC->CFGR, RCC_PLL_CLOCK_SOURCE);
	while(READ_BIT(RCC->CFGR, RCC_PLL_USED) == 0);
}

void GPIO_Init(void)
{
	/* Enable AHB2 GPIOA */
    SET_BIT(RCC->AHB2ENR,GPIOA_EN);

	/* Chose GPIOA Pin 5 PWM Mode Output CH1 */
	MODIFY_REG(GPIOA->MODE[MODER],GPIOA_PIN_5,GPIOA_PIN_5_AF_MODE);
	SET_BIT(GPIOA->MODE[AFR_L],(GPIOA_PIN_5_AF1));
	SET_BIT(GPIOA->MODE[OSPEEDR],(GPIOA_PIN_5_HS_OUTPUT));

	/* Chose GPIOA Pin 1 Alternate Function (PWM) CH2 */ 
	MODIFY_REG(GPIOA->MODE[MODER],GPIOA_PIN_1,GPIOA_PIN_1_AF_MODE);
	SET_BIT(GPIOA->MODE[AFR_L],(GPIOA_PIN_1_AF1));
	SET_BIT(GPIOA->MODE[OSPEEDR],(GPIOA_PIN_1_HS_OUTPUT));

	/* Enable AHB2 GPIOC */
	SET_BIT(RCC->AHB2ENR,GPIOC_EN);
	/* Chose GPIOC Pin 13 Input */
	CLEAR_BIT(GPIOC->MODE[MODER],GPIOC_PIN_13_INPUT);
}
void PWM_Init(void)
{
	/* Enable Clock APB1 TIM2 */
	SET_BIT(RCC->APB1ENR1,RCC_TIM2_EN);
	/* Div clock source 170-1 */
	SET_BIT(TIM2->PSC,PSC_DIV_170);
	/* ARR 100-1 */
	MODIFY_REG(TIM2->ARR,ARR_REGISTER,ARR_DIV_100);
	/* Enable ARPE */
	SET_BIT(TIM2->CR1,TIM2_ARPE_EN);
	/* Chose Output PWM Mode  */
	SET_BIT(TIM2->CCMR1,(TIM2_CH1_2_PWM_MODE));
	/* Enable PWM CH1 */
	SET_BIT(TIM2->CCER,TIM2_CH1_2_EN);
	/* Enable Timer2*/
	SET_BIT(TIM2->CR1,TIM2_EN);
	/* Enable UIF */
	SET_BIT(TIM2->EGR,TIM2_UIF_EN);
}
void NVIC_Init(void)
{
	SET_BIT(NVIC->ISER[1],(0x1UL << 8UL));

	SET_BIT(RCC->APB2ENR,(0x1UL));

	SET_BIT(SYSCFG->EXTICR[3],(0x2UL << 4UL));

	SET_BIT(EXTI->RTSR1,(0x1UL << 13UL));

	SET_BIT(EXTI->IMR1,(0x1UL << 13UL));

}
void Delay(int time_ms) 
{
	/**
	@brief 	//!Configure SystemTick Timer
	* Enable SystemTick
	* Chose Clock Source is Processor Clock: 1
	* Enable SystemTick Interrupt
	* Set register reload value
	*/
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

void Led_Output(int mode,int led)
{
	switch (mode)
	{
	case 0://OFF LED OUT
		GPIOA->MODE[ODR] |= (1<<led);
		break;
	
	case 1://ON LED OUT
		GPIOA->MODE[ODR] &= ~(1u << led);
		break;

	case 2://TOGGLE LED OUT
		GPIOA->MODE[ODR] ^= (1u << led);
		break;
	}
}

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