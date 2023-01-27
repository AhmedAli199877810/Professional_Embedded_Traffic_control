/*
 * Application.h
 *
 * Created: 10/6/2022 4:44:47 PM
 *  Author: Ahmed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../../ECUAL/LED/led.h"
#include "../../ECUAL/Button/button.h"

/* set all settings for system , return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t application_init(void);
/*set normal mode and pedestrian mode , return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t application_start(void);

/*set transfer between modes and stop timer, return overflow*/
EN_FLAG_Error_t pedestrian_start(void);

/*test for APIS ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t Test_Module_application(void);


#endif /* APPLICATION_H_ */