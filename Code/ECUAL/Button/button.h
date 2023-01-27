/*
 * button.h
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_driver/dio.h"
#include "../../MCAL/Interrupt/INT.h"

/* button initialization , return Ok(1) or Wrong(0) for error*/
EN_FLAG_Error_t button_init(uint8_t buttonPort , uint8_t buttonPin);

/* read state of button,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t button_read(uint8_t buttonPort , uint8_t buttonPin,uint8_t *value);

/*test for APIS ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t Test_Module_button(uint8_t buttonPort , uint8_t buttonPin, uint8_t *value);

#endif /* BUTTON_H_ */