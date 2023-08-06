/* 
 * File:   ecu_7_seg.c
 * Author: Seif Essam
 *
 * Created on July 30, 2023, 6:30 PM
 */

#include "ecu_7_seg.h"

/**
 * This Interface to make the needed GPIO and segment initialization
 * @param seg pointer to the segment configurations 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType se7en_seg_init(const seg_t * seg_obj){
    Std_ReturnType retVal = E_OK;
    if((NULL == seg_obj)){
        retVal = E_NOK;
    }
    else{
        retVal = gpio_pin_init(&(seg_obj->seg_pins[SEGMENT_PIN0]));
        retVal = gpio_pin_init(&(seg_obj->seg_pins[SEGMENT_PIN1]));
        retVal = gpio_pin_init(&(seg_obj->seg_pins[SEGMENT_PIN2]));
        retVal = gpio_pin_init(&(seg_obj->seg_pins[SEGMENT_PIN3]));
    }
    return retVal;
}

/**
 * Write a number to the segment 0 ~ 9
 * @param seg pointer to the segment configurations 
 * @param number the needed number to show
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType se7en_seg_wrt_num(const seg_t * seg_obj, uint8 num){
    Std_ReturnType retVal = E_OK;
    if((NULL == seg_obj) || (num > 9)){
        retVal = E_NOK;
    }
    else{
        retVal = gpio_pin_wrt_logic(&(seg_obj->seg_pins[SEGMENT_PIN0]),(num & 0x01));
        retVal = gpio_pin_wrt_logic(&(seg_obj->seg_pins[SEGMENT_PIN1]),((num >> 1) & 0x01));
        retVal = gpio_pin_wrt_logic(&(seg_obj->seg_pins[SEGMENT_PIN2]),((num >> 2) & 0x01));
        retVal = gpio_pin_wrt_logic(&(seg_obj->seg_pins[SEGMENT_PIN3]),((num >> 3) & 0x01));
    }
    return retVal;
}