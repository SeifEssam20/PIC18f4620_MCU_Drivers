/* 
 * File:   ecu_keypad.h
 * Author: Seif Essam
 *
 * Created on August 2, 2023, 10:53 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/*****************INCLUDES*****************/
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*****************MACROS*****************/
#define KEYPAD_ROWS_NUMBER              4
#define KEYPAD_COLUMNS_NUMBER           4


/*****************MACRO FUNCTIONS*****************/


/*****************DATA TYPES*****************/
typedef struct{
    pin_config_t keypad_row_pins[KEYPAD_ROWS_NUMBER];
    pin_config_t keypad_column_pins[KEYPAD_COLUMNS_NUMBER];
}keypad_t;

/*****************FUNCTIONS*****************/
Std_ReturnType keypad_init(const keypad_t * keypad_obj);
Std_ReturnType keypad_get_val(const keypad_t * keypad_obj, uint8 * val);


#endif	/* ECU_KEYPAD_H */

