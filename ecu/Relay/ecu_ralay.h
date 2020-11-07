/* 
 * File:   ecu_ralay.h
 * Author: DELL
 *
 * Created on November 6, 2020, 12:39 PM
 */

#ifndef ECU_RALAY_H
#define	ECU_RALAY_H
#include "../../mcal/gpio/mcal_gpio.h"
typedef enum{
    RELAY_OFF,
    RELAY_ON
}relay_status;

typedef struct{
    uint8_t port_name : 4;
    uint8_t pin : 3; 
    uint8_t relay_status : 1;
}relay_t;

ret_status relay_initialize(relay_t *relay);
ret_status relay_turn_on(relay_t *relay);
ret_status relay_turn_off(relay_t *relay);

#endif	/* ECU_RALAY_H */

