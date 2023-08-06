/* 
 * File:   ecu_keypad.c
 * Author: Seif Essam
 *
 * Created on August 2, 2023, 10:53 PM
 */
#include "ecu_keypad.h"

static const uint8 btn_values[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };


/**
 * @brief Initialize the keypad assigned pins
 * @param _keypad_obj pointer to the keypad configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType keypad_init(const keypad_t * keypad_obj){
    Std_ReturnType retVal = E_OK;
    uint8 r_counter = 0,c_counter = 0;
    if(NULL == keypad_obj){
        retVal = E_NOK;
    }
    else{
        for(r_counter = 0;r_counter<KEYPAD_ROWS_NUMBER;r_counter++){
            retVal = gpio_pin_init(&(keypad_obj->keypad_row_pins[r_counter]));
        }
        for(c_counter = 0;c_counter<KEYPAD_COLUMNS_NUMBER;c_counter++){
            retVal = gpio_pin_direction_init(&(keypad_obj->keypad_column_pins[c_counter]));
        }
        
    }
    return retVal;
}

/**
 * @brief Get the value of the button pressed by the user and performing the scanning algorithm
 * @param _keypad_obj pointer to the keypad configurations
 * @param value Value of the button pressed by the user
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
Std_ReturnType keypad_get_val(const keypad_t * keypad_obj, uint8 * val){
    Std_ReturnType retVal = E_OK;
    uint8 r_counter = 0, c_counter = 0, counter = 0;
    uint8 c_logic = 0;
    if((NULL == keypad_obj) || (NULL == val)){
        retVal = E_NOK;
    }
    else{
        for(r_counter = 0;r_counter < KEYPAD_ROWS_NUMBER;r_counter++){
            for(counter = 0;counter < KEYPAD_ROWS_NUMBER;counter++){
                retVal = gpio_pin_wrt_logic(&(keypad_obj->keypad_row_pins[counter]),LOW);
            }
            gpio_pin_wrt_logic(&(keypad_obj->keypad_row_pins[r_counter]),HIGH);
            __delay_ms(25);
            for(c_counter = 0;c_counter < KEYPAD_COLUMNS_NUMBER;c_counter++){
                retVal = gpio_pin_rd_logic(&(keypad_obj->keypad_column_pins[c_counter]),&(c_logic));
                if(HIGH == c_logic){
                    *val = btn_values[r_counter][c_counter];
                }
            }

        }
    }
    return retVal;
}
