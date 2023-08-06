/* 
 * File:   ecu_DC_motor.c
 * Author: Seif Essam
 *
 * Created on July 27, 2023, 12:00 PM
 */
#include "ecu_DC_motor.h"


/**
 * @brief Initialize the assigned pins to be OUTPUT and turn the motor OFF or ON.
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_init(const dc_motor_t * motor_obj){
    Std_ReturnType retVal = E_OK;
    if(NULL == motor_obj){
        retVal = E_NOK;
    }
    else{
        gpio_pin_init(&(motor_obj->dc_motor[DC_MOTOR_PIN1]));
        gpio_pin_init(&(motor_obj->dc_motor[DC_MOTOR_PIN2]));
    }
    return retVal;
}

/**
 * @brief Move the motor to the right direction
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_move_cw(const dc_motor_t * motor_obj){
    Std_ReturnType retVal = E_OK;
    if(NULL == motor_obj){
        retVal = E_NOK;
    }
    else{
        gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN1]),HIGH);
        gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN2]),LOW);
    }
    return retVal;


}

/**
 * @brief Move the motor to the left direction
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_move_ccw(const dc_motor_t * motor_obj){

    Std_ReturnType retVal = E_OK;
    if(NULL == motor_obj){
        retVal = E_NOK;
    }
    else{
       gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN1]),LOW);
       gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN2]),HIGH);
    }
    return retVal;




}

/**
 * @brief stop the motor movement
 * @param _dc_motor pointer to the motor configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType dc_motor_stop(const dc_motor_t * motor_obj){
    Std_ReturnType retVal = E_OK;
    if(NULL == motor_obj){
        retVal = E_NOK;
    }
    else{
       gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN1]),LOW);
       gpio_pin_wrt_logic(&(motor_obj->dc_motor[DC_MOTOR_PIN2]),LOW);
    }
    return retVal;





}