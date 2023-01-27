/*
 * IncFile1.h
 *
 * Created: 10/6/2022 2:11:31 PM
 *  Author: Ahmed
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../../Utilities/Register/register.h"

/* set setting of timer0 ,return Ok(1) or Wrong(0) for error , (2) = 2^2 = 4*/
EN_FLAG_Error_t timer_init(uint8_t pinNumber);

/* set starting timer0 ,ending and overcome , return Ok(1) or Wrong(0) for error */
/* FOR 5S*/
EN_FLAG_Error_t timer_start(void);

/*test for APIS mreturn Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t Test_Module_timer(void);


#endif /* INCFILE1_H_ */