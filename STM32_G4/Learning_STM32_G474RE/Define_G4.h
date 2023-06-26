/**
 * ! Init Function Declaration 
*/
void System_Init_170Mhz(void);
void GPIO_Init(void);
void PWM_Init(void);
void NVIC_Init(void);
/*----------------------------------------------------------*/
/**
 * ! ISR Function Declaration  
*/
void EXTI15_10_IRQHandler(void);
/*----------------------------------------------------------*/
/**
 * ! Declaration a Function
*/
void Delay(int time_ms);
void Led_Output(int mode,int led);
/*----------------------------------------------------------*/
/**
 * ! Type Definition 
*/
//TODO: Data Type 
typedef volatile unsigned int                          v_uint32_t;
typedef 		     unsigned int                            uint32_t;
typedef volatile unsigned short                        v_uint16_t;
typedef 		     unsigned short                          uint16_t;
typedef volatile unsigned char                         v_uint8_t;
typedef 		     unsigned char                           uint8_t;

typedef volatile 				  int                          v_int32_t;
typedef 		    				  int                            int32_t;
typedef volatile 				  short                        v_int16_t;
typedef 		      				short                          int16_t;
typedef volatile 				  char                         v_int8_t;
typedef 		     					char                           int8_t;

enum Status_LED 
{
	output_off = 0,
	output_on = 1,
	toggle = 2
};
/*----------------------------------------------------------*/
/**
 * ! Global Variable Extern 
*/
	extern v_uint32_t user_sw_pressed;
	extern v_int32_t count;
	extern v_int32_t increment;
/*----------------------------------------------------------*/
/** @addtogroup 
  * ! Definition Macro other
  * @{
*/
//TODO Name Macro Clock
#define RANGE_1_NORMAL_MODE         (0x1UL << 8UL)
#define PWR_VOS_SHIFT               (0x3UL << 9UL) 
#define VOS_SCALE_RANGE_1           (0x1UL << 9UL)
#define RCC_HSE_ON                  (0x1UL << 16UL)
#define RCC_HSE_READY               (0x1UL << 17UL)
#define RCC_APB1_PWR_ENABLE         (0x1UL << 28UL)
#define RCC_PLL_ON                  (0x1UL << 24UL)
#define RCC_PLL_READY               (0x1UL << 25UL)
#define RCC_PLLR_EN                 (0x1UL << 24UL)
#define RCC_PLLQ_EN                 (0x1UL << 20UL)
#define RCC_PLLP_EN                 (0x1UL << 16UL)
#define FLASH_LATENCY               (0xFUL)
#define FLASH_LATENCY_4WS           (0x4UL)
#define PPRE2_PPRE1_HPRE            (0x3FF0UL)
#define RCC_PLL_CLOCK_SOURCE        (0x3UL)
#define RCC_PLL_USED                (0x3UL << 2UL)
//TODO Name Macro GPIO
#define GPIOA_EN                    (0x1UL)
#define GPIOA_PIN_1                 (0x3UL << 2UL)
#define GPIOA_PIN_1_AF_MODE         (0x8UL)
#define GPIOA_PIN_1_AF1             (0x10UL)
#define GPIOA_PIN_1_HS_OUTPUT       (0x8UL)
#define GPIOA_PIN_5                 (0x3UL << 10UL)
#define GPIOA_PIN_5_AF_MODE         (0x2UL << 10UL)
#define GPIOA_PIN_5_AF1             (0x1UL << 20UL)
#define GPIOA_PIN_5_HS_OUTPUT       (0x2UL << 10UL)
#define GPIOC_EN                    (0x1UL << 2UL)
#define GPIOC_PIN_13                (0x3UL << 10UL)
#define GPIOC_PIN_13_INPUT          (0x3UL << 26UL)    
//TODO Name Macro TIM2
#define RCC_TIM2_EN                 (0x1UL)
#define PSC_DIV_170                 (0xA9UL)
#define ARR_REGISTER                (0xFFFFFFFFUL)
#define ARR_DIV_100                 (0x63UL)
#define TIM2_ARPE_EN                (0x1UL << 7)
#define TIM2_CH1_2_PWM_MODE         (0x6868UL)
#define TIM2_CH1_2_EN               (0x11UL)
#define TIM2_EN                     (0x1UL)
#define TIM2_UIF_EN                 (0x1UL)           
//TODO Variable
#define NONE        NULL
#define true        1
#define false       0
//TODO Value PLL
#define PLLSRC_HSE   3
#define PLL_M        6
#define PLL_N        85
#define PLL_P        2
#define PLL_Q        2
#define PLL_R        2
#define RCC_PLL_CONFIG(__PLLSOURCE__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__,__PLLR__ ) \
                      MODIFY_REG(RCC->PLLCFGR, 																			    \
                      ((0x3UL) | (0xFUL << 4) | (0x7F << 8) |                           \
                      (0x3UL << 21) | (0x3U << 25) | (0x1FU << 27)),                    \
                      ((__PLLSOURCE__) |                                                \
                      (((__PLLM__) - 1U) << 4) |                                        \
                      ((__PLLN__) << 8) |                                               \
                      ((((__PLLQ__) >> 1U) - 1U) << 21) |                               \
                      ((((__PLLR__) >> 1U) - 1U) << 25) |                               \
                      ((__PLLP__) << 27)))
//TODO Exported macros
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
//TODO Macro other
#define GPIOA                 1
#define GPIOB                 2
#define GPIOC                 3
#define GPIOD                 4
#define GPIOE                 5
#define GPIOF                 6
#define GPIOG                 7
/**
  * @}
  */
/*----------------------------------------------------------*/
/** @addtogroup 
  * !Peripheral Memory Map
  * @{
  */
#define RCC_BASE              (0x40021000UL)

#define GPIOA_BASE            (0x48000000UL)
#define GPIOB_BASE            (0x48000400UL)
#define GPIOC_BASE            (0x48000800UL)
#define GPIOD_BASE            (0x48000C00UL)
#define GPIOE_BASE            (0x48001000UL)
#define GPIOF_BASE            (0x48001400UL)
#define GPIOG_BASE            (0x48001800UL)

#define PWR_BASE              (0x40007000UL)

#define FLASH_R_BASE          (0x40022000UL)
#define SysTick_BASE        	(0xE000E010UL)

#define TIM1_BASE             (0x40012C00UL)
#define TIM2_BASE             (0x40000000UL)
#define TIM3_BASE             (0x40000400UL)
#define TIM4_BASE             (0x40000800UL)
#define TIM5_BASE             (0x40000C00UL)
#define TIM6_BASE             (0x40001000UL)
#define TIM7_BASE             (0x40001400UL)
#define TIM8_BASE             (0x40013400UL)
#define TIM15_BASE            (0x40014000UL)
#define TIM16_BASE            (0x40014400UL)
#define TIM17_BASE            (0x40014800UL)
#define TIM20_BASE            (0x40015000UL)

#define NVIC_BASE             (0xE000E100UL)
#define EXTI_BASE             (0x40010400UL)
#define SYSCFG_BASE           (0x40010000UL)

/**
  * @}
  */
/*----------------------------------------------------------*/
/** @addtogroup 
  * !Peripheral Declaration
  * @{
  */
 #define RCC                 ((RCC_TypeDef *) RCC_BASE)

 #define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
 #define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
 #define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
 #define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
 #define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
 #define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
 #define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)

 #define PWR                 ((PWR_TypeDef *) PWR_BASE)

 #define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

 #define SYST             	 ((SysTick_Type *) SysTick_BASE  )

 #define TIM1                ((TIM_TypeDef *) TIM1_BASE)
 #define TIM2                ((TIM_TypeDef *) TIM2_BASE)
 #define TIM3                ((TIM_TypeDef *) TIM3_BASE)
 #define TIM4                ((TIM_TypeDef *) TIM4_BASE)
 #define TIM5                ((TIM_TypeDef *) TIM5_BASE)
 #define TIM6                ((TIM_TypeDef *) TIM6_BASE)
 #define TIM7                ((TIM_TypeDef *) TIM7_BASE)
 #define TIM8                ((TIM_TypeDef *) TIM8_BASE)
 #define TIM15               ((TIM_TypeDef *) TIM15_BASE)
 #define TIM16               ((TIM_TypeDef *) TIM16_BASE)
 #define TIM17               ((TIM_TypeDef *) TIM17_BASE)
 #define TIM20               ((TIM_TypeDef *) TIM20_BASE)

 #define NVIC                ((NVIC_Type *) NVIC_BASE)

 #define EXTI                ((EXTI_TypeDef *) EXTI_BASE)

 #define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)

/**
  * @}
  */
/*----------------------------------------------------------*/
/** @addtogroup 
  * !Peripheral Registers Structures
  * @{
  */   
//TODO GPIO Index Offsets
#define MODER      0
#define OTYPER     1
#define OSPEEDR    2
#define PUPDR      3
#define IDR        4
#define ODR        5
#define BSRR       6
#define LCKR       7
#define AFR_L      8
#define AFR_H      9
#define BRR        10
//?----------------------------------------------------------
//TODO RCC Offset Register
typedef struct
{
  v_uint32_t CR;          
  v_uint32_t ICSCR;       
  v_uint32_t CFGR;        
  v_uint32_t PLLCFGR;     
  uint32_t      RESERVED0;

  uint32_t      RESERVED1;

  v_uint32_t CIER;        
  v_uint32_t CIFR;        
  v_uint32_t CICR;        
  uint32_t      RESERVED2;

  v_uint32_t AHB1RSTR;    
  v_uint32_t AHB2RSTR;    
  v_uint32_t AHB3RSTR;    
  uint32_t      RESERVED3;

  v_uint32_t APB1RSTR1;   
  v_uint32_t APB1RSTR2;   
  v_uint32_t APB2RSTR;    
  uint32_t      RESERVED4;

  v_uint32_t AHB1ENR;     
  v_uint32_t AHB2ENR;     
  v_uint32_t AHB3ENR;     
  uint32_t      RESERVED5;

  v_uint32_t APB1ENR1;    
  v_uint32_t APB1ENR2;    
  v_uint32_t APB2ENR;     
  uint32_t      RESERVED6;

  v_uint32_t AHB1SMENR;   
  v_uint32_t AHB2SMENR;   
  v_uint32_t AHB3SMENR;   
  uint32_t      RESERVED7;

  v_uint32_t APB1SMENR1;  
  v_uint32_t APB1SMENR2;  
  v_uint32_t APB2SMENR;   
  uint32_t      RESERVED8;

  v_uint32_t CCIPR;       
  uint32_t      RESERVED9;

  v_uint32_t BDCR;        
  v_uint32_t CSR;         
  v_uint32_t CRRCR;       
  v_uint32_t CCIPR2;      
}RCC_TypeDef;
//?----------------------------------------------------------
//TODO GPIO Offset Register
typedef struct
{
  v_uint32_t MODE[11];
} GPIO_TypeDef;
//?----------------------------------------------------------
//TODO PWR Offset Register
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
//?----------------------------------------------------------
//TODO FLASH Offset Register
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
//?----------------------------------------------------------
//TODO: SystemTick Offset
typedef struct
{
  v_uint32_t CTRL;                   
  v_uint32_t LOAD;                   
  v_uint32_t VAL;                    
  v_uint32_t CALIB;                  
} SysTick_Type;
//?----------------------------------------------------------
//TODO: Timer Offset
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
//?----------------------------------------------------------
//TODO: NVIC Offset
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
  v_uint8_t  IP[240U];               
        uint32_t RESERVED5[644U];
  v_uint32_t STIR;               
}  NVIC_Type;
//?----------------------------------------------------------
//TODO:  SYSCFG Offset
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
//?----------------------------------------------------------
//TODO:  EXTI Offset
typedef struct
{
  v_uint32_t IMR1;        
  v_uint32_t EMR1;        
  v_uint32_t RTSR1;       
  v_uint32_t FTSR1;       
  v_uint32_t SWIER1;      
  v_uint32_t PR1;         
    uint32_t      RESERVED1;   
    uint32_t      RESERVED2;   
  v_uint32_t IMR2;        
  v_uint32_t EMR2;        
  v_uint32_t RTSR2;       
  v_uint32_t FTSR2;       
  v_uint32_t SWIER2;      
  v_uint32_t PR2;         
} EXTI_TypeDef;
/**
  * @}
  */
/*----------------------------------------------------------*/
