/*
 * Register.h
 *
 * Created: 10/2022 
  *  Author: Ahmed
 */ 

/**************************************************************/
/*                 All microcontroller registers              */
/**************************************************************/
#ifndef REGISTER_H_
#define REGISTER_H_
#include "../Typedef/typdef.h"
/**************************************************************/
/*DIO Registers                                               */
/**************************************************************/
//PORTA Registers
#define PORTA *((volatile uint8_t*) (0x3B))//8-bit registers
#define DDRA *((volatile uint8_t*)(0x3A)) //8-bit registers
#define PINA *((volatile uint8_t*)(0x39)) //8-bit registers
//PORTB Registers
#define PORTB *((volatile uint8_t*) (0x38)) //8-bit registers
#define DDRB *((volatile uint8_t*)(0x37))  //8-bit registers
#define PINB *((volatile uint8_t*)(0x36))  //8-bit registers
//PORTD Registers
#define PORTD *((volatile uint8_t*) (0x32)) //8-bit registers
#define DDRD *((volatile uint8_t*)(0x31))  //8-bit registers  
#define PIND *((volatile uint8_t*)(0x30))  //8-bit registers

/**************************************************************/
/*Timer0 Registers                                            */
/**************************************************************/
#define TCCR0 *((volatile uint8_t*) (0x53))  //8-bit registers
#define TCNT0 *((volatile uint8_t*) (0x52))  //8-bit registers
#define TIFR *((volatile uint8_t*) (0x58))  //8-bit registers

/**************************************************************/
/*External Interrupt registers                                */
/**************************************************************/
#define MCUCR *((volatile uint8_t*) (0x55))  //8-bit registers
#define MCUCSR *((volatile uint8_t*) (0x54)) //8-bit registers
#define GICR *((volatile uint8_t*) (0x5B))  //8-bit registers
#define GIFR *((volatile uint8_t*) (0x5A))  //8-bit registers



#endif /* REGISTER_H_ */