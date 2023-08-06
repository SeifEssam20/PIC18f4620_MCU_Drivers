/* 
 * File:   ecu_led.c
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 7:13 PM
 */

#include "ecu_led.h"
/**
 * @brief Initialize the assigned pin to be OUTPUT and turn the led OFF or ON.
 * @param led : pointer to the led module configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType led_init(const led_t * led ){
    Std_ReturnType retVal = E_OK;
    if(NULL == led ){
        retVal = E_NOK;
    }
    else{
        pin_config_t pin_obj = {
           .port = led->port_name,
           .pin = led->pin,
           .direction = OUTPUT,
           .logic = led->led_status
        };
        retVal = gpio_pin_init(&pin_obj);
    }
    return retVal;
}

/**
 * @brief Turn the led on
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType led_on(const led_t * led ){
Std_ReturnType retVal = E_OK;
    if(NULL == led ){
        retVal = E_NOK;
    }
    else{
        pin_config_t pin_obj = {
           .port = led->port_name,
           .pin = led->pin,
           .direction = OUTPUT,
           .logic = led->led_status
        };
        retVal = gpio_pin_wrt_logic(&pin_obj,HIGH);
    }
    return retVal;

}

/**
 * @brief Turn the led off
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType led_off(const led_t * led ){
Std_ReturnType retVal = E_OK;
    if(NULL == led){
        retVal = E_NOK;
    }
    else{
        pin_config_t pin_obj = {
           .port = led->port_name,
           .pin = led->pin,
           .direction = OUTPUT,
           .logic = led->led_status
        };
        retVal = gpio_pin_wrt_logic(&pin_obj,LOW);
    }
    return retVal;

}

/**
 * @brief Toggle the led
 * @param led : pointer to the led module configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType led_tgl(const led_t * led ){
Std_ReturnType retVal = E_OK;
    if(NULL == led){
        retVal = E_NOK;
    }
    else{
        pin_config_t pin_obj = {
           .port = led->port_name,
           .pin = led->pin,
           .direction = OUTPUT,
           .logic = led->led_status
        };
        retVal = gpio_pin_tgl_logic(&pin_obj);
    }
    return retVal;



}

