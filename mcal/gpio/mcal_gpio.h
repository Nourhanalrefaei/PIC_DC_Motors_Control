/* 
 * File:   mcal_gpio.h
 * Author: DELL
 *
 * Created on November 2, 2020, 8:58 AM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H
#include <stddef.h>
#include "../../std_types.h"

/* Section: Macro Declarations */
#define PORT_PIN_MAX_NUMBERS 8U
#define PORT_MAX_NUMBERS 5U
#define PORT_DIRECTION_INPUT        0xFFU
#define PORT_DIRECTION_OUTPUT       0x00U
#define PIN_MASK_VALUE              1U
#define PORT_MASK_VALUE             0XFF

/* Section: Macro Functions Declarations */
#define CLEAR_BIT(REGISTER,BIT_POS)  (REGISTER &= ~(PIN_MASK_VALUE << BIT_POS))
#define SET_BIT(REGISTER,BIT_POS)    (REGISTER |= (PIN_MASK_VALUE << BIT_POS))
#define TOGGLE_BIT(REGISTER,BIT_POS) (REGISTER ^= (PIN_MASK_VALUE << BIT_POS))
#define READ_BIT(REGISTER,BIT_POS)   ((REGISTER >> BIT_POS) & PIN_MASK_VALUE)

#define CLEAR_PORT(REGISTER)    (REGISTER &= ~PORT_MASK_VALUE)
#define SET_PORT(REGISTER)      (REGISTER |= PORT_MASK_VALUE)
#define TOGGLE_PORT(REGISTER)   (REGISTER ^= PORT_MASK_VALUE)


typedef enum{
    R_NOK ,
    R_OK
}ret_status;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index;

typedef enum{
    DIRECTION_OUTPUT,
    DIRECTION_INPUT,       
}direction;

typedef enum{
    PIN_LOW,
    PIN_HIGH
}pin_logic;

typedef enum{
  PORTA_INDEX,
  PORTB_INDEX,
  PORTC_INDEX,
  PORTD_INDEX,
  PORTE_INDEX 
}port_index;

ret_status gpio_port_default_init(uint8_t port_numbers);
ret_status gpio_pin_direction_initialize(port_index port,pin_index pin,direction direction);
ret_status gpio_pin_get_direction_status(port_index port,pin_index pin,direction *direction);
ret_status gpio_pin_write_value(port_index port,pin_index pin,pin_logic logic);
ret_status gpio_pin_read_status(port_index port,pin_index pin,pin_logic *logic);
ret_status gpio_pin_toggle_value(port_index port,pin_index pin);

ret_status gpio_port_direction_initialize(port_index port,direction direction);
ret_status gpio_port_get_direction_status(port_index port,uint8_t *direction);
ret_status gpio_port_write_value(port_index port,uint8_t value);
ret_status gpio_port_read_status(port_index port,uint8_t *value);
ret_status gpio_port_toggle_value(port_index port);
 

#endif	/* MCAL_GPIO_H */

