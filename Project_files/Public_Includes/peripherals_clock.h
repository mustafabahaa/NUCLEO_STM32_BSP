/****************************************************************************
Copyright (c) 2020 [Mustafa Bahaa]
*****************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Softwar without restriction,  including without  limitation the rights
to use, copy, modify,  merge,  publish,  distribute,  sublicense, and/or sell
copies  of  the  Software,  and to  permit  persons  to  whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
*****************************************************************************/
#ifndef _PERIPHERALS_CLOCK_H_
#define _PERIPHERALS_CLOCK_H_
/****************************************************************************/
/*                               Include Files                              */
/****************************************************************************/
#include "stm32f407.h"
/****************************************************************************/
/*                               MACROS                                     */
/****************************************************************************/
#define RCC_BASE          (AHB1PERIPH_BASE + 0x3800UL)
#define RCC               ((RCC_TypeDef *) RCC_BASE)
/****************************************************************************/
/*                               Clock Strucure                             */
/****************************************************************************/
typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  */             
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              */             
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            */              
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                */              
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          */            
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          */             
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          */            
           uint32_t RESERVED0;     /*!< Reserved, 0x1C                                               */                              
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,            						   */          
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          */          
           uint32_t RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                          */                           
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          */              
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          */
           uint32_t RESERVED2;     /*!< Reserved, 0x3C                                               */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   */
           uint32_t RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                          */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register  */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register  */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register  */
           uint32_t RESERVED4;     /*!< Reserved, 0x5C                                               */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register  */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register  */
           uint32_t RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                           */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         */
           uint32_t RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           A */
} RCC_TypeDef;

/****************************************************************************/
/*                               GPIO                                       */
/****************************************************************************/
/* GPIO Clock */
#define RCC_GPIO_A_BIT 0
#define RCC_GPIO_B_BIT 1
#define RCC_GPIO_C_BIT 2
#define RCC_GPIO_D_BIT 3
#define RCC_GPIO_E_BIT 4
#define RCC_GPIO_F_BIT 5
#define RCC_GPIO_G_BIT 6
#define RCC_GPIO_H_BIT 7

#define MCAL_RCC_GPIOA_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_A_BIT);
#define MCAL_RCC_GPIOB_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_B_BIT);
#define MCAL_RCC_GPIOC_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_B_BIT);
#define MCAL_RCC_GPIOD_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_D_BIT);
#define MCAL_RCC_GPIOE_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_E_BIT);
#define MCAL_RCC_GPIOF_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_F_BIT);
#define MCAL_RCC_GPIOG_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_G_BIT);
#define MCAL_RCC_GPIOH_CLK_ENABLE()  SET_BIT(RCC->AHB1ENR,RCC_GPIO_H_BIT);


#endif /*_PERIPHERALS_CLOCK_H_*/

