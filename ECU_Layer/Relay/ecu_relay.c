/* 
 * File:   ecu_relay.c
 * Author: Seif Essam
 *
 * Created on July 27, 2023, 10:46 AM
 */

#include "ecu_relay.h"

/**
 * @brief Initialize the assigned pin to be OUTPUT and turn the relay OFF or ON.
 * @param _relay pointer to the relay module configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType relay_init(const relay_t * relay_obj){
   Std_ReturnType retVal = E_OK;
   if(NULL == relay_obj){
       retVal = E_NOK;
   }
   else{
       pin_config_t pin_obj = {
           .port = relay_obj->relay_port,
           .pin = relay_obj->relay_pin,
           .direction = OUTPUT,
           .logic = relay_obj->relay_status
       };
       gpio_pin_init(&pin_obj);
   }
   return retVal;
}

/**
 * @brief Turn the relay on
 * @param _relay pointer to the relay module configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType relay_on(const relay_t * relay_obj){

Std_ReturnType retVal = E_OK;
   if(NULL == relay_obj){
       retVal = E_NOK;
   }
   else{
       pin_config_t pin_obj = {
           .port = relay_obj->relay_port,
           .pin = relay_obj->relay_pin,
           .direction = OUTPUT,
           .logic = relay_obj->relay_status
       };
       gpio_pin_wrt_logic(&pin_obj,HIGH);
   }
   return retVal;

}

/**
 * @brief Turn the relay off
 * @param _relay pointer to the relay module configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType relay_off(const relay_t * relay_obj){

Std_ReturnType retVal = E_OK;
   if(NULL == relay_obj){
       retVal = E_NOK;
   }
   else{
       pin_config_t pin_obj = {
           .port = relay_obj->relay_port,
           .pin = relay_obj->relay_pin,
           .direction = OUTPUT,
           .logic = relay_obj->relay_status
       };
       gpio_pin_wrt_logic(&pin_obj,LOW);
   }
   return retVal;

}

