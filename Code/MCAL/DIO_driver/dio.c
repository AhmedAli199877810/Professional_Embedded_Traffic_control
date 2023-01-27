/*
 * dio.c
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 
#include "dio.h"

uint16_t flag_error = 0 ; // flag for error of function


/* to initialize pin */
EN_FLAG_Error_t DIO_init(uint8_t pinNumber , uint8_t portNumber ,uint8_t Direction){
	flag_error = 0;
	switch(portNumber){
		case PORT_A:			//PORTA
			if(Direction == OUT)
			{
				DDRA |= (1<<pinNumber);
			}
			else if(Direction == IN)
			{
				DDRA &= ~(1<<pinNumber);
			}
		flag_error = 1;
		break;
		case PORT_B:			//PORTB
			if(Direction == OUT)
			{
				DDRB |= (1<<pinNumber);
			}
			else if(Direction == IN)
			{
				DDRB &= ~(1<<pinNumber);
			}
		
		flag_error = 1;
		break;		
		case PORT_D:			//PORTD
		if(Direction == OUT)
		{
			DDRD |= (1<<pinNumber);
		}
		else if(Direction == IN)
		{
			DDRD &= ~(1<<pinNumber);
		}
		
		flag_error = 1;
		break;
	}
	if ( flag_error == 1)
	{
		return Ok ;
	} 
	else
	{
		return WRONG ;
	}
	
}

/* to make pin to be toggle */
EN_FLAG_Error_t DIO_toggle(uint8_t pinNumber , uint8_t portNumber){
	flag_error = 0;
	switch(portNumber){
		case PORT_A:		//PORTA
			PORTA ^= (1<<pinNumber);
		flag_error = 1;
		break;
		case PORT_B:		//PORTB
			PORTB ^= (1<<pinNumber);
		
		flag_error = 1;
		break;		
		case PORT_D:		//PORTD
		PORTD ^= (1<<pinNumber);
		
		flag_error = 1;
		break;	
	}
	if ( flag_error == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
	
}

/*to write on pin */
EN_FLAG_Error_t DIO_write(uint8_t pinNumber , uint8_t portNumber ,uint8_t Value)
{	flag_error = 0;
	switch(portNumber)
	{
		case PORT_A:		//PORTA
		if(Value == HIGH)
		{
			PORTA |= (1<<pinNumber);
		}
		else if(Value == LOW)
		{
			PORTA &= ~(1<<pinNumber);
		}
		flag_error = 1;
		break;
		case PORT_B:		//PORTB
		if(Value == HIGH)
		{
			PORTB |= (1<<pinNumber);
		}
		else if(Value == LOW)
		{
			PORTB &= ~(1<<pinNumber);
		}
		flag_error = 1;
		break;
		case PORT_D:		//PORTD
		if(Value == HIGH)
		{
			PORTD |= (1<<pinNumber);
		}
		else if(Value == LOW)
		{
			PORTD &= ~(1<<pinNumber);
		}
		flag_error = 1;
		break;
		
	}
	if ( flag_error == 1)
	{
		return Ok ;
	}
	else
	{
		return WRONG ;
	}
	
}

/* to read pin*/ 
EN_FLAG_Error_t DIO_read(uint8_t pinNumber , uint8_t portNumber ,uint8_t *Value){
	flag_error = 0;
	switch(portNumber){
		case PORT_A:		//PORTA
			*Value = (PINA &(1<<pinNumber))>>pinNumber;
		flag_error = 1;
		break;
		case PORT_B:		//PORTB
			*Value = (PINB &(1<<pinNumber))>>pinNumber;
		flag_error = 1;
		break;
		case PORT_D:		//PORTD
		*Value = (PIND &(1<<pinNumber))>>pinNumber;
		flag_error = 1;
		break;
		}
		if ( flag_error == 1)
		{
			return Ok ;
		}
		else
		{
			return WRONG ;
		}
		
}


/*test for APIS */

EN_FLAG_Error_t Test_Module_dio(uint8_t pinNumber , uint8_t portNumber ,uint8_t *Value1,uint8_t Value,uint8_t Direction)
{
	if (DIO_init(pinNumber , portNumber , Direction) == 0 || DIO_write(pinNumber ,portNumber,Value) == 0 || 
	DIO_toggle(pinNumber , portNumber) == 0 || DIO_read(pinNumber , portNumber, Value1) == 0 )
	{
		return WRONG;
	}
	else
	{
		return Ok;
	}
	
	
}

//cases
//Test_Module_dio(0,'A',&flag_button,HIGH,OUT) == 1  true
//Test_Module_dio(0,'C',&flag_button,HIGH,OUT) == 1  false