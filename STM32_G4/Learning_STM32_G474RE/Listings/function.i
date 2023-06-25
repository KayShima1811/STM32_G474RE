# 1 "Function.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 387 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "Function.c" 2
# 1 "./Define_G4.h" 1



void System_Init_170Mhz(void);
void GPIO_Init(void);
void PWM_Init(void);
void NVIC_Init(void);




void EXTI15_10_IRQHandler(void);




void Delay(int time_ms);
void Led_Output(int mode,int led);





typedef volatile unsigned int v_uint32_t;
typedef unsigned int uint32_t;
typedef volatile unsigned short v_uint16_t;
typedef unsigned short uint16_t;
typedef volatile unsigned char v_uint8_t;
typedef unsigned char uint8_t;

typedef volatile int v_int32_t;
typedef int int32_t;
typedef volatile short v_int16_t;
typedef short int16_t;
typedef volatile char v_int8_t;
typedef char int8_t;

enum Status_LED
{
 output_off = 0,
 output_on = 1,
 toggle = 2
};




 extern v_uint32_t user_sw_pressed;
 extern v_int32_t count;
 extern v_int32_t increment;
# 230 "./Define_G4.h"
typedef struct
{
  v_uint32_t CR;
  v_uint32_t ICSCR;
  v_uint32_t CFGR;
  v_uint32_t PLLCFGR;
  uint32_t RESERVED0;

  uint32_t RESERVED1;

  v_uint32_t CIER;
  v_uint32_t CIFR;
  v_uint32_t CICR;
  uint32_t RESERVED2;

  v_uint32_t AHB1RSTR;
  v_uint32_t AHB2RSTR;
  v_uint32_t AHB3RSTR;
  uint32_t RESERVED3;

  v_uint32_t APB1RSTR1;
  v_uint32_t APB1RSTR2;
  v_uint32_t APB2RSTR;
  uint32_t RESERVED4;

  v_uint32_t AHB1ENR;
  v_uint32_t AHB2ENR;
  v_uint32_t AHB3ENR;
  uint32_t RESERVED5;

  v_uint32_t APB1ENR1;
  v_uint32_t APB1ENR2;
  v_uint32_t APB2ENR;
  uint32_t RESERVED6;

  v_uint32_t AHB1SMENR;
  v_uint32_t AHB2SMENR;
  v_uint32_t AHB3SMENR;
  uint32_t RESERVED7;

  v_uint32_t APB1SMENR1;
  v_uint32_t APB1SMENR2;
  v_uint32_t APB2SMENR;
  uint32_t RESERVED8;

  v_uint32_t CCIPR;
  uint32_t RESERVED9;

  v_uint32_t BDCR;
  v_uint32_t CSR;
  v_uint32_t CRRCR;
  v_uint32_t CCIPR2;
}RCC_TypeDef;


typedef struct
{
  v_uint32_t MODE[11];
} GPIO_TypeDef;


typedef struct
{
  v_uint32_t CR1;
  v_uint32_t CR2;
  v_uint32_t CR3;
  v_uint32_t CR4;
  v_uint32_t SR1;
  v_uint32_t SR2;
  v_uint32_t SCR;
    uint32_t RESERVED;
  v_uint32_t PUCRA;
  v_uint32_t PDCRA;
  v_uint32_t PUCRB;
  v_uint32_t PDCRB;
  v_uint32_t PUCRC;
  v_uint32_t PDCRC;
  v_uint32_t PUCRD;
  v_uint32_t PDCRD;
  v_uint32_t PUCRE;
  v_uint32_t PDCRE;
  v_uint32_t PUCRF;
  v_uint32_t PDCRF;
  v_uint32_t PUCRG;
  v_uint32_t PDCRG;
    uint32_t RESERVED1[10];
  v_uint32_t CR5;
} PWR_TypeDef;


typedef struct
{
  v_uint32_t ACR;
  v_uint32_t PDKEYR;
  v_uint32_t KEYR;
  v_uint32_t OPTKEYR;
  v_uint32_t SR;
  v_uint32_t CR;
  v_uint32_t ECCR;
       uint32_t RESERVED1;
  v_uint32_t OPTR;
  v_uint32_t PCROP1SR;
  v_uint32_t PCROP1ER;
  v_uint32_t WRP1AR;
  v_uint32_t WRP1BR;
       uint32_t RESERVED2[4];
  v_uint32_t PCROP2SR;
  v_uint32_t PCROP2ER;
  v_uint32_t WRP2AR;
  v_uint32_t WRP2BR;
       uint32_t RESERVED3[7];
  v_uint32_t SEC1R;
  v_uint32_t SEC2R;
} FLASH_TypeDef;


typedef struct
{
  v_uint32_t CTRL;
  v_uint32_t LOAD;
  v_uint32_t VAL;
  v_uint32_t CALIB;
} SysTick_Type;


typedef struct
{
  v_uint32_t CR1;
  v_uint32_t CR2;
  v_uint32_t SMCR;
  v_uint32_t DIER;
  v_uint32_t SR;
  v_uint32_t EGR;
  v_uint32_t CCMR1;
  v_uint32_t CCMR2;
  v_uint32_t CCER;
  v_uint32_t CNT;
  v_uint32_t PSC;
  v_uint32_t ARR;
  v_uint32_t RCR;
  v_uint32_t CCR1;
  v_uint32_t CCR2;
  v_uint32_t CCR3;
  v_uint32_t CCR4;
  v_uint32_t BDTR;
  v_uint32_t CCR5;
  v_uint32_t CCR6;
  v_uint32_t CCMR3;
  v_uint32_t DTR2;
  v_uint32_t ECR;
  v_uint32_t TISEL;
  v_uint32_t AF1;
  v_uint32_t AF2;
  v_uint32_t OR ;
      v_uint32_t RESERVED0[220];
  v_uint32_t DCR;
  v_uint32_t DMAR;
} TIM_TypeDef;


typedef struct
{
  v_uint32_t ISER[8U];
        v_uint32_t RESERVED0[24U];
  v_uint32_t ICER[8U];
        uint32_t RESERVED1[24U];
  v_uint32_t ISPR[8U];
        uint32_t RESERVED2[24U];
  v_uint32_t ICPR[8U];
        uint32_t RESERVED3[24U];
  v_uint32_t IABR[8U];
        uint32_t RESERVED4[56U];
  v_uint8_t IP[240U];
        uint32_t RESERVED5[644U];
  v_uint32_t STIR;
} NVIC_Type;


typedef struct
{
  v_uint32_t MEMRMP;
  v_uint32_t CFGR1;
  v_uint32_t EXTICR[4];
  v_uint32_t SCSR;
  v_uint32_t CFGR2;
  v_uint32_t SWPR;
  v_uint32_t SKR;
} SYSCFG_TypeDef;


typedef struct
{
  v_uint32_t IMR1;
  v_uint32_t EMR1;
  v_uint32_t RTSR1;
  v_uint32_t FTSR1;
  v_uint32_t SWIER1;
  v_uint32_t PR1;
    uint32_t RESERVED1;
    uint32_t RESERVED2;
  v_uint32_t IMR2;
  v_uint32_t EMR2;
  v_uint32_t RTSR2;
  v_uint32_t FTSR2;
  v_uint32_t SWIER2;
  v_uint32_t PR2;
} EXTI_TypeDef;
# 2 "Function.c" 2

void Led_Output(int mode,int led)
{
 switch (mode)
 {
 case 0:
  ((GPIO_TypeDef *) (0x48000000UL))->MODE[5] |= (1<<led);
  break;

 case 1:
  ((GPIO_TypeDef *) (0x48000000UL))->MODE[5] &= ~(1u << led);
  break;

 case 2:
  ((GPIO_TypeDef *) (0x48000000UL))->MODE[5] ^= (1u << led);
  break;
 }
}

void Delay(int time_ms)
{
 int delay_count = (170 * time_ms) / 1000;

 ((SysTick_Type *) (0xE000E010UL) )->LOAD |= 0xF423FUL;

 ((SysTick_Type *) (0xE000E010UL) )->VAL = 0x0UL;

 ((SysTick_Type *) (0xE000E010UL) )->CTRL |= 0x5UL;

   for (int i = 0; i < delay_count; i++)
 {
  while (!(((SysTick_Type *) (0xE000E010UL) )->CTRL & (1 << 16)));
   }

   ((SysTick_Type *) (0xE000E010UL) )->CTRL = 0x0UL;
}
