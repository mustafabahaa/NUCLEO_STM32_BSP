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
#include "Button.h"
/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/
/**
	* @brief  Init Button structure and configurations
	* @param  void
	* @retval Error
	*/
Error init_button(void)
{
	Error E ;
	
	/*Create instance of GPIO to assign it to the LED*/
	gpio_pin_conf_t button_pin_conf;
	
  button_pin_conf.pin = USER_BUTTON;
	button_pin_conf.mode = GPIO_PIN_INPUT_MODE;
	button_pin_conf.op_type = GPIO_PIN_OUT_PUSHPULL;
	button_pin_conf.speed =  GPIO_PIN_SPEED_MEDIUM;
	button_pin_conf.pull  =  GPIO_PIN_NO_PULL_PUSH;
	
	/*Led is connected by SOC to GPIOD */
	E = MCAL_gpio_init(BUTTON_GPIO, &button_pin_conf);
	
	if (E != Success)
	logger_print_error(" GPIO Init Failed \n");
	return E;
}

/**
	* @brief  read Button states
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @param  *states : pointer which holds the button states
	* @retval Error
	*/
Error read_button_states(GPIO_TypeDef *GPIOx , uint16_t pin , uint8_t* states)
{
	Error E;
	E = MCAL_Gpio_read(BUTTON_GPIO,USER_BUTTON,states);
	if (E != Success)
	logger_print_error(" GPIO Read Failed \n");
	return E;  
}

/****************************************************************************/

