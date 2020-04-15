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
	* @retval Error
	*/
Error init_led(void)
{
	Error E = Success;
	
	/*Create instance of GPIO to assign it to the LED*/
	gpio_pin_conf_t led_pin_conf;
	
  led_pin_conf.pin = USER_LED;
	led_pin_conf.mode = GPIO_PIN_OUTPUT_MODE;
	led_pin_conf.op_type = GPIO_PIN_OUT_PUSHPULL;
	led_pin_conf.speed =  GPIO_PIN_SPEED_MEDIUM;
	led_pin_conf.pull  =  GPIO_PIN_NO_PULL_PUSH;
	
	/*Led is connected by SOC to GPIOD */
	E = MCAL_gpio_init(LED_GPIO, &led_pin_conf);
	
	if (E != Success)
	logger_print_error(" GPIO Init Failed \n");
	
	return E;
}


/**
	* @brief  turn on LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_turn_on(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	Error E = Success;
	
	E = MCAL_Gpio_write(LED_GPIO,USER_LED,HIGH);
	
	if (E != Success)
	logger_print_error(" GPIO Write Failed \n");
	
	return E;
}



/**
	* @brief  turn Off LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_turn_off(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	Error E = Success;
	
	E = MCAL_Gpio_write(LED_GPIO,USER_LED,LOW);
	
	if (E != Success)
	logger_print_error(" GPIO Write Failed \n");
		
	return E;
}



/**
	* @brief  Toggle LED
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @retval Error
	*/
Error led_toggle(GPIO_TypeDef *GPIOx , uint16_t pin)
{
	Error E = Success;
	
	uint8_t* ledStatus ;
	
	E = MCAL_Gpio_read(LED_GPIO,USER_LED,ledStatus);
	
	if (E != Success)
	logger_print_error(" GPIO Read Failed \n");
	
	if(*ledStatus == HIGH)
	{
		E = MCAL_Gpio_write(LED_GPIO,USER_LED,LOW);
		
		if (E != Success)
	  logger_print_error(" GPIO Write Failed \n");
	}
	else
	{
		E = MCAL_Gpio_write(LED_GPIO,USER_LED,HIGH);
		if (E != Success)
		logger_print_error(" GPIO Write Failed \n");
		
	}
	return E;
}

/****************************************************************************/
