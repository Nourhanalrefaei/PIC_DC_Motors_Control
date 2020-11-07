/* 
 * File:   ecu_ralay.c
 * Author: DELL
 *
 * Created on November 6, 2020, 12:49 PM
 */
#include "ecu_ralay.h"

ret_status relay_initialize(relay_t *relay){
    ret_status ret = R_NOK;
    if((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS-1) || 
            (relay->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_direction_initialize(relay->port_name, relay->pin, DIRECTION_OUTPUT);
        gpio_pin_write_value(relay->port_name, relay->pin, PIN_LOW);
        relay->relay_status = RELAY_OFF;
        ret = R_OK;
    }
    return ret;
}

ret_status relay_turn_on(relay_t *relay){
    ret_status ret = R_NOK;
    if((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS-1) || 
            (relay->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_write_value(relay->port_name, relay->pin, PIN_HIGH);
        relay->relay_status = RELAY_ON;
        ret = R_OK;
    }
    return ret;
}

ret_status relay_turn_off(relay_t *relay){
    ret_status ret = R_NOK;
    if((NULL == relay) || (relay->port_name > PORT_MAX_NUMBERS-1) || 
            (relay->pin > PORT_PIN_MAX_NUMBERS-1)){
        return ret;
    }
    else{
        gpio_pin_write_value(relay->port_name, relay->pin, PIN_LOW);
        relay->relay_status = RELAY_OFF;
        ret = R_OK;
    }
    return ret;
}