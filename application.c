/* 
 * File:   application.c
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 6:27 PM
 */


#include "application.h"

pin_config_t test = {
    .port = PORTA_index,
    .pin = PIN3,
    .direction = OUTPUT,
    .logic = HIGH
};

int main()
{
    gpio_pin_direction_init(&test);
    while(1){
        gpio_pin_wrt_logic(&test,HIGH);
        _delay(2000);
        gpio_pin_wrt_logic(&test,LOW);
        _delay(2000);
    }

    return (EXIT_SUCCESS);
}

