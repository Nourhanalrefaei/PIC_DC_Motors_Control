/* 
 * File:   application.c
 * Author: DELL
 *
 * Created on November 2, 2020, 8:35 AM
 */

#include "application.h"
#include "ecu/Relay/ecu_ralay.h"
#include "ecu/dc_motor/ecu_dc motor.h"

dc_motor_t motor1;
dc_motor_t motor2;
dc_motor_t motor3;
dc_motor_t motor4;
button_t btn[4] ={{.port_name=PORTD_INDEX,.pin=PIN0,.button_status=BUTTON_NOT_PRESSED},
                  {.port_name=PORTD_INDEX,.pin=PIN1,.button_status=BUTTON_NOT_PRESSED},
                  {.port_name=PORTD_INDEX,.pin=PIN2,.button_status=BUTTON_NOT_PRESSED},
                  {.port_name=PORTD_INDEX,.pin=PIN3,.button_status=BUTTON_NOT_PRESSED}};
uint8_t btn_status[4]={0,0,0,0};
uint8_t i=ZERO_INIT;

void robot_move_forward(void);
void robot_move_backward(void);
void robot_move_right(void);
void robot_move_left(void);
void robot_stop(void);

int main() {
   
    motor1.relay1.port_name=PORTC_INDEX;
    motor1.relay1.pin=PIN0;
    motor1.relay1.relay_status=RELAY_OFF;
    motor1.relay2.port_name=PORTC_INDEX;
    motor1.relay2.pin=PIN1;
    motor1.relay2.relay_status=RELAY_OFF;
    dc_motor_initialize(&motor1);
    
    motor2.relay1.port_name=PORTC_INDEX;
    motor2.relay1.pin=PIN2;
    motor2.relay1.relay_status=RELAY_OFF;
    motor2.relay2.port_name=PORTC_INDEX;
    motor2.relay2.pin=PIN3;
    motor2.relay2.relay_status=RELAY_OFF;
    dc_motor_initialize(&motor2);
    
    motor3.relay1.port_name=PORTC_INDEX;
    motor3.relay1.pin=PIN4;
    motor3.relay1.relay_status=RELAY_OFF;
    motor3.relay2.port_name=PORTC_INDEX;
    motor3.relay2.pin=PIN5;
    motor3.relay2.relay_status=RELAY_OFF;
    dc_motor_initialize(&motor3);
    
    motor4.relay1.port_name=PORTC_INDEX;
    motor4.relay1.pin=PIN6;
    motor4.relay1.relay_status=RELAY_OFF;
    motor4.relay2.port_name=PORTC_INDEX;
    motor4.relay2.pin=PIN7;
    motor4.relay2.relay_status=RELAY_OFF;
    dc_motor_initialize(&motor4);
    for(i=ZERO_INIT;i<4;i++){
        button_initialize(&btn[i]);
    }
   while(1){
       for(i=ZERO_INIT;i<4;i++){
        button_get_status(&btn[i],&btn_status[i]);
    }
       
       if(btn_status[0]==BUTTON_PRESSED && btn_status[1]==BUTTON_NOT_PRESSED&& btn_status[2]==BUTTON_NOT_PRESSED&& btn_status[3]==BUTTON_NOT_PRESSED){
           robot_move_forward();
       }else if(btn_status[0]==BUTTON_NOT_PRESSED && btn_status[1]==BUTTON_PRESSED &&btn_status[2]==BUTTON_NOT_PRESSED && btn_status[3]==BUTTON_NOT_PRESSED){
          robot_move_backward(); 
       }else if(btn_status[0]==BUTTON_NOT_PRESSED && btn_status[1]==BUTTON_NOT_PRESSED &&btn_status[2]==BUTTON_PRESSED && btn_status[3]==BUTTON_NOT_PRESSED){
           robot_move_right();
       }else if(btn_status[0]==BUTTON_NOT_PRESSED && btn_status[1]==BUTTON_NOT_PRESSED &&btn_status[2]==BUTTON_NOT_PRESSED && btn_status[3]==BUTTON_PRESSED){
           robot_move_left();
       }
       else{
          robot_stop(); 
       }
       
   }
    return (EXIT_SUCCESS);
}

void robot_move_forward(void){
    dc_motor_rotate_right(&motor1);
    dc_motor_rotate_right(&motor2);
    dc_motor_rotate_right(&motor3);
    dc_motor_rotate_right(&motor4);
}
void robot_move_backward(void){
    dc_motor_rotate_left(&motor1);
    dc_motor_rotate_left(&motor2);
    dc_motor_rotate_left(&motor3);
    dc_motor_rotate_left(&motor4);
}
void robot_move_right(void){
    dc_motor_stop(&motor1);
    dc_motor_rotate_right(&motor2);
    dc_motor_rotate_right(&motor3);
    dc_motor_stop(&motor4);
}
void robot_move_left(void){
    dc_motor_rotate_left(&motor1);
    dc_motor_stop(&motor2);
    dc_motor_stop(&motor3);
    dc_motor_rotate_left(&motor4);
}
void robot_stop(void){
    dc_motor_stop(&motor1);
    dc_motor_stop(&motor2);
    dc_motor_stop(&motor3);
    dc_motor_stop(&motor4);
    __delay_ms(100);
}

