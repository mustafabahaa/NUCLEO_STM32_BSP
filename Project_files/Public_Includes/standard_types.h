#ifndef STANDARD_TYPES_H_
#define STANDARD_TYPES_H_

/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

/* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

#define SET_BIT(register,bit) (register|= (1<<bit))
#define CLR_BIT(register,bit) (register&= ~(1<<bit))
	
#define HIGH 1
#define LOW  0

#endif /*STANDARD_TYPES_H_*/


