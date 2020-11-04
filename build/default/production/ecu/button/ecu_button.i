# 1 "ecu/button/ecu_button.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v5.45/packs/Microchip/PIC18F-K_DFP/1.4.87/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ecu/button/ecu_button.c" 2







# 1 "ecu/button/ecu_button.h" 1
# 10 "ecu/button/ecu_button.h"
# 1 "ecu/button/../../mcal/gpio/mcal_gpio.h" 1
# 10 "ecu/button/../../mcal/gpio/mcal_gpio.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stddef.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stddef.h" 2 3
# 19 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stddef.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 132 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ptrdiff_t;
# 168 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 19 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stddef.h" 2 3
# 10 "ecu/button/../../mcal/gpio/mcal_gpio.h" 2

# 1 "ecu/button/../../mcal/gpio/../../std_types.h" 1
# 11 "ecu/button/../../mcal/gpio/../../std_types.h"
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
# 11 "ecu/button/../../mcal/gpio/mcal_gpio.h" 2
# 32 "ecu/button/../../mcal/gpio/mcal_gpio.h"
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
# 10 "ecu/button/ecu_button.h" 2

typedef enum{
    BUTTON_NOT_PRESSED,
    BUTTON_PRESSED
}button_status;

typedef struct{
    uint8_t port_name : 4;
    uint8_t pin : 3;
    uint8_t button_status : 1;
}button_t;


ret_status button_initialize(button_t *btn);
ret_status button_get_status(button_t *btn, button_status *btn_status);
# 8 "ecu/button/ecu_button.c" 2






ret_status button_initialize(button_t *btn){
    ret_status ret = R_NOK;
    if((((void*)0) == btn) || (btn->port_name > 5U -1) ||
            (btn->pin > 8U -1)){
        return ret;
    }
    else{
        gpio_pin_direction_initialize(btn->port_name, btn->pin, DIRECTION_INPUT);
        ret = R_OK;
    }
    return ret;
}






ret_status button_get_status(button_t *btn, button_status *btn_status){
    ret_status ret = R_NOK;
    if((((void*)0) == btn) || (btn->port_name > 5U -1) ||
            (btn->pin > 8U -1)){
        return ret;
    }
    else{
        gpio_pin_read_status(btn->port_name, btn->pin, btn_status);
        btn->button_status = *btn_status;
        ret = R_OK;
    }
    return ret;
}
