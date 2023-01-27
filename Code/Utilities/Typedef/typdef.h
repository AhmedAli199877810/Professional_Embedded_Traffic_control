/*
 * typdef.h
 *
 * Created: 10/7/2022 6:37:53 PM
 *  Author: Ahmed
 */ 


#ifndef TYPDEF_H_
#define TYPDEF_H_

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

/* refer to ok or not for each function */
typedef enum EN_FLAG_FUNCTION
{	WRONG, Ok ,WRONG_Timer,WRONG_Dio ,WRONG_Led,WRONG_Button,WRONG_Application }EN_FLAG_Error_t;



/* define pins for interrupt registers*/
#define INT0    6
#define ISC01   1
#define ISC00   0

/* define used ports */
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'

/* input or output */
#define OUT 1
#define IN 0

/* button state */
#define HIGH 1
#define LOW 0

#endif /* TYPDEF_H_ */