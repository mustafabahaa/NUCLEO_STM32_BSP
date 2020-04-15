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
#include "Logger.h"
#include "Logger_config.h"
/****************************************************************************/
/*                               Public Functions                           */
/****************************************************************************/

#ifdef WARNING
/**
	* @brief  print messages based on uart , warning only
	* @param  msg  : char array to be printed
	* @retval void 
	*/
void logger_print_warning (char * msg )
{
	
}
#endif  /*WARNING*/


#ifdef ERROR
/**
	* @brief  print messages based on uart , Error only
	* @param  msg  : char array to be printed
	* @retval void 
	*/
void logger_print_error (char * msg )
{
	
}
#endif /*ERROR*/


#ifdef DEBUG
/**
	* @brief  print messages based on uart , debug only
	* @param  msg  : char array to be printed
	* @retval void 
	*/
void logger_print_debug (char * msg )
{
	
}
#endif /*DEBUG*/


#ifdef INFO
/**
	* @brief  print messages based on uart , info only
	* @param  msg  : char array to be printed
	* @retval void 
	*/
void logger_print_info (char * msg )
{
	
}
#endif /*INFO*/

/****************************************************************************/

