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
#include "LED.h"
/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/
/**
	* @brief  Init Led structure and configurations
	* @param  void
	* @retval void
	*/
void init_led(void)
{
	/*Create instance of GPIO to assign it to the LED*/
	gpio_pin_conf_t led_pin_conf;
	
  led_pin_conf.pin = USER_LED;
	led_pin_conf.mode = GPIO_PIN_OUTPUT_MODE;
	led_pin_conf.op_type = GPIO_PIN_OUT_PUSHPULL;
	led_pin_conf.speed =  GPIO_PIN_SPEED_MEDIUM;
	led_pin_conf.pull  =  GPIO_PIN_NO_PULL_PUSH;
	
	/*Led is connected by SOC to GPIOD */
	MCAL_gpio_init(LED_GPIO, &led_pin_conf);
}


/**
	* @brief  turn on LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval void
	*/
void led_turn_on(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	MCAL_Gpio_write(LED_GPIO,USER_LED,HIGH);
}



/**
	* @brief  turn Off LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval void
	*/
void led_turn_off(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	MCAL_Gpio_write(LED_GPIO,USER_LED,LOW);
}



/**
	* @brief  Toggle LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval void
	*/
void led_toggle(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	uint8_t* ledStatus ;
	
	MCAL_Gpio_read(LED_GPIO,USER_LED,ledStatus);
	
	if(*ledStatus == HIGH)
	{
		MCAL_Gpio_write(LED_GPIO,USER_LED,LOW);
	}
	else
	{
		MCAL_Gpio_write(LED_GPIO,USER_LED,HIGH);
	}
}

/****************************************************************************/
