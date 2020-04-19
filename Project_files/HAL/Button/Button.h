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
#ifndef _BUTTON_H_
#define _BUTTON_H_
/****************************************************************************/
/*                               Include Files                              */
/****************************************************************************/
#include "MCAL_gpio.h"
/****************************************************************************/
/*                               MACROS                                     */
/****************************************************************************/
#define BUTTON_GPIO GPIOC
#define USER_BUTTON 13
/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/
/**
	* @brief  Init Button structure and configurations
	* @param  void
	* @retval Error
	*/
Error init_button(void);

/**
	* @brief  read Button states
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @param  *states : pointer which holds the button states
	* @retval Error
	*/
Error read_button_states(GPIO_TypeDef *GPIOx , uint16_t pin , uint8_t* states);
/****************************************************************************/
#endif  /*_BUTTON_H*/

