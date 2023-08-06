/* 
 * File:   ecu_led.h
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 7:13 PM
 */


#ifndef ECU_LED_H
#define	ECU_LED_H

/*****************INCLUDES*****************/

#include "../LED/../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/*****************MACROS*****************/
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5


/*****************MACRO FUNCTIONS*****************/


/*****************DATA TYPES*****************/
typedef enum{
    LED_OFF,
    LED_ON
}led_status;

typedef struct{
    uint8 port_name    :3;
    uint8 pin          :3;
    uint8 led_status   :1;
    uint8 reserved_bit :1;
}led_t;


/*****************FUNCTIONS*****************/
Std_ReturnType led_init(const led_t * led );
Std_ReturnType led_on(const led_t * led );
Std_ReturnType led_off(const led_t * led );
Std_ReturnType led_tgl(const led_t * led );




#endif	/* ECU_LED_H */

