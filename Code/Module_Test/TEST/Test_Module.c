/*
 * Test_Module.c
 *
 * Created: 10/8/2022 1:20:16 PM
 *  Author: Ahmed
 */ 

#include "Test_Module.h"


extern uint8_t flag_button ;


EN_FLAG_Error_t Test_Module(uint8_t pinNumber , uint8_t portNumber ,uint8_t *Value1,uint8_t Value,uint8_t Direction)
{ if ( Test_Module_led(portNumber,pinNumber) == 0)
	{ 
		return WRONG_Led;
	}
	else if(Test_Module_button(portNumber,pinNumber,Value1) == 0)
	{
		return WRONG_Button; 
	}
	else if (Test_Module_dio(pinNumber,portNumber ,Value1,Value,Direction) == 0)
	{ 
	  return WRONG_Dio; 
	}
	else if(Test_Module_timer() == 0)
	{
		   return WRONG_Timer; 
	}
	else if(Test_Module_application() == 0)
	{ 
	  return WRONG_Application; 
	}
	return 1 ;
}
