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
#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_
/****************************************************************************/
/*                               Include Files                              */
/****************************************************************************/
#include "stm32f407.h"
#include "peripherals_clock.h"
#include "Logger.h"
/****************************************************************************/
/*                                GPIO Configurations                       */
/****************************************************************************/
#define GPIO_PIN_INPUT_MODE      0x00
#define GPIO_PIN_OUTPUT_MODE     0x01
#define GPIO_PIN_ALTERNATE_MODE  0x02

#define GPIO_PIN_OUT_PUSHPULL     0x00
#define GPIO_PIN_OUT_OPEN_DRAIN   0x01

#define GPIO_PIN_SPEED_LOW         0x00
#define GPIO_PIN_SPEED_MEDIUM      0x01
#define GPIO_PIN_SPEED_HIGH        0x02
#define GPIO_PIN_SPEED_VERY_HIGH   0x03

#define GPIO_PIN_NO_PULL_PUSH   0x00
#define GPIO_PIN_PULL_UP        0x01
#define GPIO_PIN_PULL_DOWN      0x02

/****************************************************************************/
/*                         GPIOx Base Addresses                             */
/****************************************************************************/
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL) 
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000UL)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)


/****************************************************************************/
/*                         GPIOx Clock Gating                               */
/****************************************************************************/

#define GPIOA_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,0);
#define GPIOB_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,1);
#define GPIOC_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,2);
#define GPIOD_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,3);
#define GPIOE_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,4);
#define GPIOF_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,5);
#define GPIOG_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,6);
#define GPIOH_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,7);
#define GPIOI_CLOCK_ENABLE() SET_BIT(RCC->AHB1ENR,8);

/****************************************************************************/
/*                         GPIO Module Structures and enums                 */
/****************************************************************************/

typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


typedef struct
{
	uint32_t pin;            /*Specifies the GPIO pins to be configured */
	uint32_t mode;           /*Specifies the operating mode for the selected pins */										
	uint32_t op_type;        /*Specifies the output type for the selected pins*/
	uint32_t pull;           /*Specifies the Pull-up or Pull-Down activation for the selected pins */				
	uint32_t speed;          /* Specifies the speed for the selected pins */					 
	uint32_t alternate;      /*Specifies the alternate function value */                
}gpio_pin_conf_t;



/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/


/**
	* @brief  Init GPIO Port Clock
	* @param  GPIOx   : GPIO Base Address
  * @retval Error   :	Status of function
	*/
Error MCAL_gpio_init(GPIO_TypeDef *GPIOx, gpio_pin_conf_t *gpio_pin_conf);

/**
	* @brief  Configure GIPO alternate functions 
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  pupd    : alternate function value according to datasheet
  * @retval Error   :	Status of function
	*/
Error MCAL_Gpio_set_alt_function
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t alt_fun_value);


/**
	* @brief  Read GPIO Current States high or low
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  pinNo   : Value to be returned
  * @retval Error   :	Status of function
	*/
Error MCAL_Gpio_read(GPIO_TypeDef *GPIOx, uint16_t pinNo , uint8_t *returnValue);



/**
	* @brief  Write GPIO high or low
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
  * @retval Error   :	Status of function
	*/
Error MCAL_Gpio_write(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint8_t value);


#endif /*MCAL_GPIO_H_*/
/****************************************************************************/



