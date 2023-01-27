/*
 * Application.c
 *
 * Created: 10/6/2022 4:44:33 PM
 *  Author: Ahmed
 */ 	
#include "Application.h"

/* array of flags to set stages and modes*/
/*flag for changing between two modes*/
extern uint16_t flag[12]; 

extern uint16_t over_flow ; //flag for reaching for ending delay of 5 s

extern uint16_t flag_error; // flag for error of function


uint8_t flag_button = 0; // flag for reading of state of pin


/* initialization function*/
EN_FLAG_Error_t application_init(void){
	uint16_t c [15] = {0};			//using for store state of function
	/*1. set LED pins to in output */		
	c[0] = led_init('A',0);
	c[1] = led_init('A',1);
	c[2] = led_init('A',2);
	c[3] = led_init('B',0);
	c[4] = led_init('B',1);
	c[5] = led_init('B',2);
	/*2. set direction for button pin to in input */
	c[6] = button_init('D',2); 
	/*3. Enable global interrupts - setting bit 7 in the status register to 1 */
	sei();
    /*4. choose the external interrupt sense - sense on rising edge */
	MCUCR |= (1<<ISC00)|(1<<ISC01);
	/*4. Enable External interrupt 0 */
	GICR |= (1<<INT0);
	/*5. set settings of mode and initial data = 4 so pitNumber (2) high for timer0 */	
	timer_init(2);
	if (c[0] == 0 ||c[1] == 0 ||c[2] == 0 ||c[3] == 0 ||c[4] == 0 ||c[5] == 0 ||c[6] == 0 )
	{
		return WRONG;
	} 
	else
	{
		return Ok;
	}
	
	}

/*start function*/
EN_FLAG_Error_t application_start(void){	
	while(1){
	uint16_t c [15] = {0};			//using for store state of function

	/* stage 1 in normal mode  green on */ 
		if (flag[5] == 0 && flag[11] == 0)
		{	/* turn on car green led  and return flag[0] = 1 */
			c[0] = led_on_flag('A',0); 
			/* turn on timer0 for 5s with prescaler 1024 */
			c[11] = timer_start();      
			flag[5] = 1; flag[6]= 1;flag[0] = 0;	
		if (c[0] == 0 || c[11] == 0 ){return WRONG;}

		}

	
		/* stage 2 in normal mode  yellow on */
		else if (flag[6] == 1 && flag[3] == 0)
		{	/* turn off car green led and return flag[0] = 0*/
			c[1] = led_off('A',0);
			/* toggle car yellow led for 5s with prescaler 1024 then turn off*/
			/* return flag[1] = 2 */			  
			c[2] = timer_led_togle('A',1);	
			flag[7] = 1; flag[6]= 0;
			if (c[1] == 0 || c[2] == 0 ){return WRONG;}
		}
	
		/* stage 3 in normal mode  red on */
		else if (flag[7] == 1 && flag[4] == 0)
		{	/* turn off pedestrian red led if turn on and return flag[2] = 0 */
			c[10] = led_off('B',2);
			/* turn on car red led  and return flag[2] = 3 */
			c[4] = led_on_flag('A',2); 
			/* turn on timer0 for 5s with prescaler 1024 */
			c[11] = timer_start();
			flag[7] = 0; flag[8] = 1;flag[2] = 0;
			if (c[10] == 0 || c[4] == 0 ||c[11] == 0){return WRONG;}
		}
	
	
		/* case 1 in pedestrian mode  */
		else if (flag[9] == 1)
		{	/* turn on timer0 for 5s with prescaler 1024 */
			c[11] = timer_start();
			/* turn off car red led if turn on and return flag[2] = 0*/
			c[5] = led_off('A',2);
			/* toggle car yellow led and pedestrian yellow led for 5s with prescaler 1024 then turn off for all*/
			c[12] = timer_double_led_toggle();
			/* turn off pedestrian green led if turn on and return flag[0] = 0*/
			c[7] = led_off('B',0);
			/* turn on pedestrian red led  and without return */
			c[9] = led_on('B',2);
			flag[5] = 0; flag[9] = 0; flag[8] = 0;
			if (c[11] == 0 || c[5] == 0 ||c[12] == 0 || c[7] == 0 ||c[9] == 0){return WRONG;}
		}

		/* stage 4 in normal mode yellow on */
		else if (flag[8] == 1)
		{	/* turn off car red led if turn on and return flag[2] = 0*/
			c[5] = led_off('A',2);
			/* turn off pedestrian green led if turn on and return flag[0] = 0*/
			c[7] = led_off('B',0);
			/* toggle car yellow led for 5s with prescaler 1024 then turn off*/
			/* return flag[1] = 2 */
			c[2] = timer_led_togle('A',1);//2
			flag[5] = 0; flag[8]= 0; 
			if (c[2] == 0 || c[5] == 0 ||c[7] == 0 ){return WRONG;}
		}	
	

		/* case 2 in pedestrian mode  */
		else if (flag[10] == 1)
		{																													
			/* turn off car green led if turn on and return flag[0] = 0*/
			c[1] = led_off('A',0);
			/* toggle car yellow led and pedestrian yellow led for 5s with prescaler 1024 then turn off for all*/
			c[12] = timer_double_led_toggle();
			/* turn off pedestrian red led if turn on and return flag[2] = 0*/
			c[10] = led_off('B',2);
			/* turn on car red led  and without return */
			c[13] = led_on('A',2);
			/* turn on pedestrian green led  and without return */
			c[14] = led_on('B',0);
			/* turn on timer0 for 5s with prescaler 1024 */
			c[11] = timer_start();
			/* turn off car red led if turn on and return flag[2] = 0*/
			c[5] = led_off('A',2);
			/* toggle car yellow led and pedestrian yellow led for 5s with prescaler 1024 then turn off for all*/
			c[12] = timer_double_led_toggle();
			/* turn off pedestrian green led if turn on and return flag[0] = 0*/
			c[7] = led_off('B',0);
			/* turn on pedestrian red led  and without return */
			c[14] = led_on('B',2);
			flag[5] = 0; flag[10] = 0;flag[3] = 0; flag[4] = 0; flag[11] = 0; 	
			if (c[1] == 0 || c[5] == 0 ||c[7] == 0 || c[10] == 0 ||c[11] == 0 ||c[12] == 0 ||c[13] == 0 ||c[14] == 0 ){return WRONG;}
		}
	}

	}
	
	
	
/* changing modes function */	
EN_FLAG_Error_t pedestrian_start(void)
{	
	uint16_t c [15] = {0};			//using for store state of function
	int i = 0;
	c[0] = button_read('D',2,&flag_button);
	c[1] = 1;c[2] = 1;over_flow = 1 ;	
	while(flag_button == 1 )
	{
		c[0] = button_read('D',2,&flag_button);
		i++;
		if ( i > 3000) //2200
		{
			return 10;
		}
	}
	
	
	/* interrupt for case 1 in pedestrian mode  */
	if (flag[2] == 3 )
	{	
		/* turn on pedestrian green led  and without return */
		c[1] = led_on('B',0);
		/* to stop timer immediately*/
		over_flow = 20 ;
		flag[9] = 1;
		c[2] = 1;	
	}
	
	/* interrupt for case 2 in pedestrian mode  */
	else if (flag[0] ==1 || flag[1]==2)
	{	
		/* turn on pedestrian red led  and without return */
		c[2] = led_on('B',2);
		/* to stop timer immediately*/
		over_flow = 20 ;
		flag[10] = 1;
		flag[3] = 1;
		flag[4] = 1;
		flag[11] = 1;
		c[1] = 1;	
	}

if (c[0] == 0 || c[1] == 0 ||c[2] == 0 )
	{
		return WRONG;
	} 
	else
	{
		/* to stop interrupt and complete code*/
		return over_flow;
	}

	}



/* function to call interrupt */
ISR(EXT_INT_0){
	pedestrian_start();
}


/*test for APIS*/
EN_FLAG_Error_t Test_Module_application(void)
{
	if(application_init() == 0 || pedestrian_start() == 0 )
	{
				return WRONG;
	}
	else	
	{
		if (application_start()  != 0)
		{
			return Ok;
		}
		else{return WRONG;}
				
	}
	
}

