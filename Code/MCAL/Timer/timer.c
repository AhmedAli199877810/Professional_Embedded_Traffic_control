/*
 * timer.c
 *
 * Created: 10/6/2022 2:12:11 PM
 *  Author: Ahmed
 */ 
#include "timer.h"

uint16_t flag_error ; //flag for error of function
uint16_t over_flow = 0;		//flag for reaching for ending delay of 5 s

/* timer initialization */
EN_FLAG_Error_t timer_init(uint8_t pinNumber){
	while (1)
	{	
	/*normal mode*/
	TCCR0 = 0x00 ; 
	/*initial data  = 4 so (pin 2 = 2^2)*/
	TCNT0 |=(1<<pinNumber) ;	
	if ( pinNumber > 7){break;}
	return Ok ;
	}
	return WRONG ;
		}
	

/* timer start */
EN_FLAG_Error_t timer_start(void){
	flag_error = 0;
	over_flow = 0;
	
	/*set prescaler*/
	TCCR0 |= (1<<2)|(1<<0);	
	
	while(over_flow <=19){

		while ((TIFR & (1<<0)) == 0);
	
		/*clear overflow flag */
		TIFR |= (1<<0);    
		over_flow++;
		flag_error = 1;
	}
	
	/*stop timer*/
	TCCR0 = 0x00 ;
	
	if ( flag_error == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	} 
}

EN_FLAG_Error_t Test_Module_timer(void)
{
	if (timer_init(2) == 0 || timer_start() == 0 )
	{
		return WRONG;
	}
	else
	{
		return Ok;
	}	
}
