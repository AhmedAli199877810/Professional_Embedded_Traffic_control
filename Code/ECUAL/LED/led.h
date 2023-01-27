/*
 * led.h
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 

 
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_driver/dio.h"
#include "../../MCAL/Timer/timer.h"

/* led initialization ,return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t led_init(uint8_t ledport, uint8_t ledpin);

/* led on without flag ,nreturn Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t led_on(uint8_t ledport, uint8_t ledpin);

/* led on with flag ,return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t led_on_flag(uint8_t ledport, uint8_t ledpin);

/* led off with flag ,flag[] = 0, return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t led_off(uint8_t ledport, uint8_t ledpin);

/* led toggle ,return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t led_toggle(uint8_t ledport, uint8_t ledpin);

/* led toggle for 5s ,return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t timer_led_togle(uint8_t ledport, uint8_t ledpin);

/* special led toggle for 5s ,return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t timer_double_led_toggle(void);

/*test for APIS ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t Test_Module_led(uint8_t ledport, uint8_t ledpin);

#endif /* LED_H_ */