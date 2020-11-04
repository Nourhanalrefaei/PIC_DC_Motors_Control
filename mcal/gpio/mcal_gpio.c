/* 
 * File:   mcal_gpio.c
 * Author: DELL
 *
 * Created on November 2, 2020, 8:58 AM
 */

#include "mcal_gpio.h"
#include "pic18f46k20.h"
/* Reference to the Data Direction Control Registers */
uint8_t volatile *tris_register[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
uint8_t volatile *lat_register[]={&LATA,&LATB,&LATC,&LATD,&LATE};
/* Reference to the Port Status Register  */
uint8_t volatile *port_register[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * 
 * @param port_numbers
 * @return 
 */
ret_status gpio_port_default_init(uint8_t port_numbers){
    ret_status ret = R_NOK;
    uint8_t l_counter = ZERO_INIT;
    for(l_counter=ZERO_INIT; l_counter<PORT_MAX_NUMBERS-1; l_counter++){
        /* Write to all (Data Direction Control Registers) -> DIRECTION_INPUT */
        *tris_register[l_counter] = PORT_DIRECTION_INPUT;
    }
    ret = R_OK;
    return ret;
}



/**
 * 
 * @param port
 * @param pin
 * @param direction
 * @return 
 */
ret_status gpio_pin_direction_initialize(port_index port,pin_index pin,direction direction){
    ret_status ret =R_NOK;
    if(pin>PORT_PIN_MAX_NUMBERS-1 || pin<ZERO_INIT){
        return ret;
    }
    else {
         
    switch(direction){
            case DIRECTION_OUTPUT :
                /* Clear the desired bit as indication to be DIRECTION_OUTPUT */
                CLEAR_BIT(*tris_register[port], pin); break;
            case DIRECTION_INPUT : 
                /* Set the desired bit as indication to be DIRECTION_INPUT */
                SET_BIT(*tris_register[port], pin); break;
            default : return R_NOK;
        }
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @param direction
 * @return 
 */
ret_status gpio_pin_get_direction_status(port_index port,pin_index pin,direction *direction){
ret_status ret =R_NOK;
if(pin>PORT_PIN_MAX_NUMBERS-1 || pin<ZERO_INIT){
        return ret;
    }
    else {
         /* Read the direction status of the (pin) -> (DIRECTION_INPUT) or (DIRECTION_OUTPUT) */
        *direction = READ_BIT(*tris_register[port], pin);
        ret = R_OK;
    }
return ret;    
}
/**
 * 
 * @param port
 * @param pin
 * @param logic
 * @return 
 */
ret_status gpio_pin_write_value(port_index port,pin_index pin,pin_logic logic){
   ret_status ret =R_NOK;
if(pin>PORT_PIN_MAX_NUMBERS-1 || pin<ZERO_INIT){
        return ret;
    }
    else {
     switch(logic){
            case PIN_LOW :
                /* Logic High 5v or 3.3v written now on the (pin) */
                CLEAR_BIT(*lat_register[port], pin); break;
            case PIN_HIGH :
                /* Logic Low 0v written now on the (pin) */
                SET_BIT(*lat_register[port], pin); break;
            default : return R_NOK;
        }
        ret = R_OK;
    }
return ret;    
}
/**
 * 
 * @param port
 * @param pin
 * @param logic
 * @return 
 */
ret_status gpio_pin_read_status(port_index port,pin_index pin,pin_logic *logic){
 ret_status ret;
    if(pin > PORT_PIN_MAX_NUMBERS-1 || NULL == logic){
        return R_NOK;
    }
    else{
        /* Read the logic status of the (pin) -> (PIN_LOW) or (PIN_HIGH) */
        *logic = READ_BIT(*port_register[port], pin);
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param pin
 * @return 
 */
ret_status gpio_pin_toggle_value(port_index port,pin_index pin){
ret_status ret =R_NOK;
if(pin>PORT_PIN_MAX_NUMBERS-1 || pin<ZERO_INIT){
        return ret;
    }
    else {
         /* Change the logic on the pin */
        TOGGLE_BIT(*lat_register[port], pin);
        ret = R_OK;
    }
return ret;       
}
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
ret_status gpio_port_direction_initialize(port_index port,direction direction){
    ret_status ret = R_NOK;
    if(port > PORT_MAX_NUMBERS-1){
        return ret;
    }
    else{
        switch(direction){
            case DIRECTION_OUTPUT :
                *tris_register[port] = PORT_DIRECTION_OUTPUT;
                break;
            case DIRECTION_INPUT :
                *tris_register[port] = PORT_DIRECTION_INPUT;
                break;
            default : return ret;
        }
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
ret_status gpio_port_get_direction_status(port_index port,uint8_t *direction){
     ret_status ret = R_NOK;
    if((port > PORT_MAX_NUMBERS-1) || (NULL == direction)){
        return R_NOK;
    }
    else{
        *direction = *tris_register[port];
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param value
 * @return 
 */
ret_status gpio_port_write_value(port_index port,uint8_t value){
    ret_status ret = R_NOK;
    if(port > PORT_MAX_NUMBERS-1){
        return R_NOK;
    }
    else{
        *lat_register[port] = value;
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param value
 * @return 
 */
ret_status gpio_port_read_status(port_index port,uint8_t *value){
    ret_status ret = R_NOK;
    if((port > PORT_MAX_NUMBERS-1) || (NULL == value)){
        return ret;
    }
    else{
        *value = *port_register[port];
        ret = R_OK;
    }
    return ret;
}
/**
 * 
 * @param port
 * @return 
 */
ret_status gpio_port_toggle_value(port_index port){
    ret_status ret = R_NOK;
    if(port > PORT_MAX_NUMBERS-1){
        return ret;
    }
    else{
        TOGGLE_PORT(*lat_register[port]);
        ret = R_OK;
    }
    return ret;
}

