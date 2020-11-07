/* 
 * File:   ecu_dc motor.h
 * Author: DELL
 *
 * Created on November 6, 2020, 1:52 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H
#include "../Relay/ecu_ralay.h"
typedef struct{
    relay_t relay1;
    relay_t relay2;
}dc_motor_t;

ret_status dc_motor_initialize(dc_motor_t *dc_mtor);
ret_status dc_motor_rotate_right(dc_motor_t *dc_mtor);
ret_status dc_motor_rotate_left(dc_motor_t *dc_mtor);
ret_status dc_motor_stop(dc_motor_t *dc_mtor);


#endif	/* ECU_DC_MOTOR_H */

