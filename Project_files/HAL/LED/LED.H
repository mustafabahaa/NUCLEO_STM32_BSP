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

/****************************************************************************/
/*                               Include Files                              */
/****************************************************************************/
#include "MCAL_gpio.h"
/****************************************************************************/
/*                               MACROS                                     */
/****************************************************************************/
#define LED_GPIO GPIOA
#define USER_LED 5
/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/

/**
	* @brief  Init Led structure and configurations
	* @param  void
	* @retval Error
	*/
Error init_led(void);

/**
	* @brief  turn on LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_turn_on(GPIO_TypeDef *GPIOx , uint16_t pin);


/**
	* @brief  turn Off LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_turn_off(GPIO_TypeDef *GPIOx , uint16_t pin);


/**
	* @brief  Toggle LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_toggle(GPIO_TypeDef *GPIOx , uint16_t pin);

/****************************************************************************/
