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
/*                                    Macros                                */
/****************************************************************************/
#define ALT_FUNCTION_LOW_REGISTER_LIMIT 7 
/****************************************************************************/
/*                               Static Functions                           */
/****************************************************************************/
/**
	* @brief  Configure GPIO Pin Mode 
	* @param  GPIOx : GPIO Base Address
	* @param  pinNo : pin Number to be Configured
	* @param  mode  : mode of configurations
	* @retval void
	*/
static void MCAL_Gpio_configre_pin_mode
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t mode)
{
		GPIOx->MODER |= (mode << (2*pinNo));
}


/**
	* @brief  Configure GPIO pin output type
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  op_type : output type
	* @retval void
	*/
static void MCAL_Gpio_configure_pin_output_type
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t op_type)
{
	GPIOx->OTYPER |= (op_type << pinNo);
}


/**
	* @brief  Configure GPIO configure pin speed (in MHZ)
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  speed   : Speed according to datasheet
	* @retval void
	*/
static void MCAL_Gpio_configure_pin_speed
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t speed)
{
	GPIOx->OSPEEDR |= (speed << (2*pinNo));
}

/**
	* @brief  Configure GPIO configure pin pull down , up
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  pupd    : pull down or pull up configurations
	* @retval void
	*/
static void MCAL_Gpio_configure_pin_pupd 
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t pupd)
{
	GPIOx->PUPDR |= (pupd << (2 * pinNo));
}


/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/
/**
	* @brief  Init GPIO Port Clock
	* @param  GPIOx   : GPIO Base Address
	* @retval void
	*/

Error MCAL_gpio_init(GPIO_TypeDef *GPIOx, gpio_pin_conf_t *gpio_pin_conf)
{
	Error E = Success ; 
	
	if      (GPIOx == GPIOA){MCAL_RCC_GPIOA_CLK_ENABLE();}
	else if (GPIOx == GPIOB){MCAL_RCC_GPIOB_CLK_ENABLE();}
	else if (GPIOx == GPIOC){MCAL_RCC_GPIOC_CLK_ENABLE();}
	else if (GPIOx == GPIOD){MCAL_RCC_GPIOD_CLK_ENABLE();}
	else if (GPIOx == GPIOE){MCAL_RCC_GPIOE_CLK_ENABLE();}
	else if (GPIOx == GPIOF){MCAL_RCC_GPIOF_CLK_ENABLE();}
	else if (GPIOx == GPIOG){MCAL_RCC_GPIOG_CLK_ENABLE();}
	else if (GPIOx == GPIOH){MCAL_RCC_GPIOH_CLK_ENABLE();}
	else 
	{
	  E = Fail;
		logger_print_error("Port not found \n");
	};
		
	MCAL_Gpio_configre_pin_mode(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->mode);
	MCAL_Gpio_configure_pin_speed(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->speed);
	MCAL_Gpio_configure_pin_output_type(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->op_type);
	MCAL_Gpio_configure_pin_pupd(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->pull);
		
	return E;
}


/**
	* @brief  Configure GIPO alternate functions 
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
	* @param  pupd    : alternate function value according to datasheet
	* @retval void
	*/
Error MCAL_Gpio_set_alt_function
	(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint32_t alt_fun_value)
{
	Error E = Success;
	
	/*differnet handling for HSB Register and LSB */
	if (pinNo <= ALT_FUNCTION_LOW_REGISTER_LIMIT )
	{
		GPIOx->AFR[0] |= (alt_fun_value << ((pinNo) * 4 ));
	}
	else
	{
		GPIOx->AFR[1] |= (alt_fun_value << ((pinNo % 8) * 4 ));
	}
	return E;
}


/**
	* @brief  Read GPIO Current States high or low
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
  * @retval uint8_t : the value of returnted GPIO states
	*/
Error MCAL_Gpio_read(GPIO_TypeDef *GPIOx, uint16_t pinNo , uint8_t* returnValue)
{
	Error E = Success;

	*returnValue = (uint8_t)((GPIOx->IDR >> pinNo) & 0x00000001);
	
	if (*returnValue != HIGH || *returnValue != LOW) 
	{
		E = Fail;
		logger_print_error("GPIO Read Failed \n");
	}
	return E;
}



/**
	* @brief  Write GPIO high or low
	* @param  GPIOx   : GPIO Base Address
	* @param  pinNo   : pin Number to be Configured
  * @retval uint8_t : the value to be written
	*/
Error MCAL_Gpio_write(GPIO_TypeDef *GPIOx , uint16_t pinNo , uint8_t value)
{
	Error E = Success;
	
	if (value != HIGH || value != LOW) 
	{
		E = Fail;
		logger_print_warning("GPIO not intetned value \n");
	}
	if (value)
	{
		SET_BIT(GPIOx->ODR,pinNo);
	}
	else
	{
		CLR_BIT(GPIOx->ODR,pinNo);
	}
	return E;
}


/****************************************************************************/



