/* 
 * File:   ecu_button.h
 * Author: Seif Essam
 *
 * Created on July 26, 2023, 3:20 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H


/****************INCLUDES*****************/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_button_cfg.h"

/*****************MACROS*****************/

/*****************MACRO FUNCTIONS*****************/

/*****************DATA TYPES*****************/
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PRESSED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}button_active_t;

typedef struct{
    pin_config_t button_obj;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/*****************FUNCTIONS*****************/
Std_ReturnType button_init(const button_t  * btn);
Std_ReturnType button_rd_state(const button_t * btn, button_state_t * btn_state);




#endif	/* ECU_BUTTON_H */

