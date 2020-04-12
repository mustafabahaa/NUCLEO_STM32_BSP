#ifndef STM_32_F407_H_
#define STM_32_F407_H_

#include "stm32f407xx.h"

#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region                                */
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)

#endif /*STM_32_F407_H_*/