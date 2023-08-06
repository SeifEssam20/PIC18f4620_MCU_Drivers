/* 
 * File:   application.c
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 6:27 PM
 */


#include "application.h"
Std_ReturnType ret = E_NOK;
uint8 btnVal = 0;

keypad_t keypad = {
    .keypad_row_pins[0].port = PORTC_index,
    .keypad_row_pins[0].pin = PIN0,
    .keypad_row_pins[0].direction = OUTPUT,
    .keypad_row_pins[0].logic = LOW,
    .keypad_row_pins[1].port = PORTC_index,
    .keypad_row_pins[1].pin = PIN1,
    .keypad_row_pins[1].direction = OUTPUT,
    .keypad_row_pins[1].logic = LOW,
    .keypad_row_pins[2].port = PORTC_index,
    .keypad_row_pins[2].pin = PIN2,
    .keypad_row_pins[2].direction = OUTPUT,
    .keypad_row_pins[2].logic = LOW,
    .keypad_row_pins[3].port = PORTC_index,
    .keypad_row_pins[3].pin = PIN3,
    .keypad_row_pins[3].direction = OUTPUT,
    .keypad_row_pins[3].logic = LOW,
    .keypad_column_pins[0].port = PORTC_index,
    .keypad_column_pins[0].pin = PIN4,
    .keypad_column_pins[0].direction = INPUT,
    .keypad_column_pins[0].logic = LOW,
    .keypad_column_pins[1].port = PORTC_index,
    .keypad_column_pins[1].pin = PIN5,
    .keypad_column_pins[1].direction = INPUT,
    .keypad_column_pins[1].logic = LOW,
    .keypad_column_pins[2].port = PORTC_index,
    .keypad_column_pins[2].pin = PIN6,
    .keypad_column_pins[2].direction = INPUT,
    .keypad_column_pins[2].logic = LOW,
    .keypad_column_pins[3].port = PORTC_index,
    .keypad_column_pins[3].pin = PIN7,
    .keypad_column_pins[3].direction = INPUT,
    .keypad_column_pins[3].logic = LOW
};


void app_init(void);
int main() { 
    app_init();
    while(1){
        ret = keypad_get_val(&(keypad),&(btnVal));
    }
    return (EXIT_SUCCESS);
}

void app_init(void){
   keypad_init(&keypad);
}




