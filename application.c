/* 
 * File:   application.c
 * Author: DELL
 *
 * Created on November 2, 2020, 8:35 AM
 */

#include "application.h"

button_t btn1={.port_name=PORTD_INDEX,.pin=PIN0,.button_status=BUTTON_NOT_PRESSED};



led_t led_array[led_sequence_number]={
    {.port_name=PORTC_INDEX,.pin=PIN0,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN1,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN2,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN3,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN4,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN5,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN6,.led_status=LED_OFF},
    {.port_name=PORTC_INDEX,.pin=PIN7,.led_status=LED_OFF}
};



int main() {
   uint8_t press_count=ZERO_INIT;
   uint8_t l_led_counter=ZERO_INIT;
   uint8_t btn_status=ZERO_INIT;
   uint8_t seq_len=8;
    button_initialize(&btn1);
    for(l_led_counter=ZERO_INIT;l_led_counter<seq_len;l_led_counter++){
       led_initialize(&led_array[l_led_counter]);
   }
    while(1){
   
   for(l_led_counter=ZERO_INIT;l_led_counter<seq_len;l_led_counter++){
       button_get_status(&btn1,&btn_status);
       if(btn_status==BUTTON_PRESSED){
       for(press_count=ZERO_INIT;press_count<=l_led_counter;press_count++){
               
               led_turn_on(&led_array[l_led_counter]);
               __delay_ms(500);
               led_turn_off(&led_array[l_led_counter]);
               __delay_ms(500);
               
           }
            }else{
           led_turn_off(&led_array[l_led_counter]);
            }
        }
       
    }
    return (EXIT_SUCCESS);
}



