/*
 * button.c
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 
#include "button.h"

/* button  initialization*/
EN_FLAG_Error_t button_init(uint8_t buttonPort , uint8_t buttonPin){
	if ( DIO_init(buttonPin,buttonPort,IN) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}
 /*button _Read */
EN_FLAG_Error_t button_read(uint8_t buttonPort , uint8_t buttonPin , uint8_t *value){
	if ( DIO_read(buttonPin,buttonPort,value) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}

	}

/*Test for all Apis*/
EN_FLAG_Error_t Test_Module_button(uint8_t buttonPort , uint8_t buttonPin, uint8_t *value)
{
	if ( button_init(buttonPort ,buttonPin) == 0 || button_read(buttonPort , buttonPin ,value) == 0)
	{
		return WRONG;
	}
	else
	{
		return Ok;
	}	
}
//cases
//Test_Module_button('A',0,&flag_button)== 1 //True
//Test_Module_button('C',0,&flag_button)== 1  //False