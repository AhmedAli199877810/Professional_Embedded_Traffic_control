/*
 * led.c
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 

#include "led.h"

uint16_t flag[12] = {0};		//flag for changing between two modes 
extern uint16_t over_flow ;		//flag for reaching for ending delay of 5 s
extern uint16_t flag_error;		// flag for error of function


/* led initialization*/
EN_FLAG_Error_t led_init(uint8_t ledport, uint8_t ledpin){
	if (DIO_init(ledpin,ledport,OUT) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}

/* led on without flag*/
EN_FLAG_Error_t led_on(uint8_t ledport, uint8_t ledpin){
		if (DIO_write(ledpin,ledport,HIGH) == 1)
		{
			return Ok ;
		}
		else
		{
			return WRONG ;
		}

}


/* led on with flag*/
EN_FLAG_Error_t led_on_flag(uint8_t ledport, uint8_t ledpin){
	flag[ledpin] = ledpin+1;
	if(DIO_write(ledpin,ledport,HIGH) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}


/* led off with flag*/
EN_FLAG_Error_t led_off(uint8_t ledport, uint8_t ledpin){
	flag[ledpin] = 0;
	if(DIO_write(ledpin,ledport,LOW) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}		
}


/* led toggle*/
EN_FLAG_Error_t led_toggle(uint8_t ledport, uint8_t ledpin)
{
	if (DIO_toggle(ledpin,ledport) == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}

/* led toggle for 5s*/

EN_FLAG_Error_t timer_led_togle(uint8_t ledport, uint8_t ledpin){
	uint16_t c [15] = {0};			//using for store state of function
	flag_error = 0;	
	flag[ledpin] = 1+ledpin;
	over_flow = 0;
	TCCR0 |= (1<<2)|(1<<0);	//set prescaler
	while(over_flow <=19){
		c[0] = led_toggle(ledport,ledpin);
		while ((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);    //clear overflow flag
		over_flow++;
		flag_error = 1;
	}
	led_off(ledport,ledpin);
	TCCR0 = 0x00 ; //stop timer
	if ( flag_error == 1 && c[0] == 1 )
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}

/* special led toggle for 5s */

EN_FLAG_Error_t timer_double_led_toggle(void)
{	uint16_t c [15] = {0};			//using for store state of function
	flag_error = 0;
	over_flow = 0;
	TCCR0 |= (1<<2)|(1<<0);	//set prescaler
	while(over_flow <=19)
	{
		c[0] = led_toggle('A',1);
		c[1] = led_toggle('B',1);
		while ((TIFR & (1<<0)) == 0);
		TIFR |= (1<<0);    //clear overflow flag
		over_flow++;
		flag_error = 1;
	}
	led_off('A',1);led_off('B',1);
	TCCR0 = 0x00 ; //stop timer
	
	if( flag_error == 1 && c[0] == 1 && c[1] == 1  )
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
}

/* Test for all ApIS */
EN_FLAG_Error_t Test_Module_led(uint8_t ledport, uint8_t ledpin)
{
	if (led_on(ledport,ledpin) == 0 || led_on_flag(ledport,ledpin) == 0 || 
		led_toggle(ledport,ledpin) == 0 || led_init(ledport,ledpin) == 0 ||
		led_off(ledport,ledpin) == 0 || timer_led_togle(ledport,ledpin) == 0  || 
		timer_double_led_toggle() == 0 )
	{
		return WRONG;
	}
	else
	{
		return Ok;
	}
}

//cases
//Test_Module_led('A',0)== 1 //True
//Test_Module_led('C',0)== 1  //False