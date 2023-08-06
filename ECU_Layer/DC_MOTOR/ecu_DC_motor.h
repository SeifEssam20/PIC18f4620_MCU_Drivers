/* 
 * File:   ecu_DC_motor.h
 * Author: Seif Essam
 *
 * Created on July 27, 2023, 12:00 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*****************INCLUDES*****************/
#include "ecu_DC_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*****************MACROS*****************/
#define DC_MOTOR_ON                 0x01
#define DC_MOTOR_OFF                0x00

#define DC_MOTOR_PIN1               0x00
#define DC_MOTOR_PIN2               0x01

/*****************MACRO FUNCTIONS*****************/

/*****************DATA TYPES*****************/

typedef struct{
    pin_config_t dc_motor[2];
}dc_motor_t;

/*****************FUNCTIONS*****************/
Std_ReturnType dc_motor_init(const dc_motor_t * motor_obj);
Std_ReturnType dc_motor_move_cw(const dc_motor_t * motor_obj);
Std_ReturnType dc_motor_move_ccw(const dc_motor_t * motor_obj);
Std_ReturnType dc_motor_stop(const dc_motor_t * motor_obj);

#endif	/* ECU_DC_MOTOR_H */

