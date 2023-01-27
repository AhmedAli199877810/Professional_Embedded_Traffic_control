/*
 * dio.h
 *
 * Created: 10/2022 
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/Register/Register.h"

/* select port and pin and define input or output, return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t DIO_init(uint8_t pinNumber , uint8_t portNumber ,uint8_t Direction);

/* select port and pin and define high or low ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t DIO_write(uint8_t pinNumber , uint8_t portNumber ,uint8_t Value);

/* select port and pin and toggle high and low ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t DIO_toggle(uint8_t pinNumber , uint8_t portNumber);

/* select port and pin and read high or low ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t DIO_read(uint8_t pinNumber , uint8_t portNumber,uint8_t *Value);

/*test for APIS ,return Ok(1) or Wrong(0) for error */
EN_FLAG_Error_t Test_Module_dio(uint8_t pinNumber , uint8_t portNumber ,uint8_t *Value1,uint8_t Value,uint8_t Direction);

#endif /* DIO_H_ */