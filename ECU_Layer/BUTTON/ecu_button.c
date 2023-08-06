/* 
 * File:   ecu_button.c
 * Author: Seif Essam
 *
 * Created on July 26, 2023, 3:20 AM
 */

#include "ecu_button.h"

/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_init(const button_t  * btn){
    Std_ReturnType retVal = E_OK;
    if(NULL == btn){
        retVal = E_NOK;
    }
    else{
        retVal = gpio_pin_direction_init(&(btn->button_obj));
    }
    return retVal;
}

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_rd_state(const button_t * btn, button_state_t * btn_state){
    Std_ReturnType retVal = E_OK;
    logic_t pin_logic_status = LOW; 
        if((NULL == btn) || (NULL ==btn_state)){
            retVal = E_NOK;
        }
        else{
            gpio_pin_rd_logic(&(btn->button_obj),&pin_logic_status);
            if(BUTTON_ACTIVE_LOW == btn->button_connection){
                if(HIGH == pin_logic_status){
                    *btn_state = BUTTON_RELEASED;
                }
                else{
                    *btn_state = BUTTON_PRESSED;
                }
            }
            else if(BUTTON_ACTIVE_HIGH == btn->button_connection){
                if(HIGH == pin_logic_status){
                    *btn_state = BUTTON_PRESSED;
                }
                else{
                    *btn_state = BUTTON_RELEASED;
                }
            }
            else{/*DO NOTHING*/}        
            retVal=E_OK;
        }
    
    
    return retVal;




}

