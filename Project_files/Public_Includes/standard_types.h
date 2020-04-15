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
#ifndef STANDARD_TYPES_H_
#define STANDARD_TYPES_H_

/****************************************************************************/
/*                               Standard Types                             */
/****************************************************************************/
/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

/* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;


/****************************************************************************/
/*                               Common Macros                              */
/****************************************************************************/
#define SET_BIT(register,bit) (register|= (1<<bit))
#define CLR_BIT(register,bit) (register&= ~(1<<bit))
	
#define HIGH 1
#define LOW  0


/****************************************************************************/
/*                               Error Types                                */
/****************************************************************************/
typedef enum  {
	Success,
	Fail
} Error;

#endif /*STANDARD_TYPES_H_*/


