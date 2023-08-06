/* 
 * File:   ecu_relay.h
 * Author: Seif Essam
 *
 * Created on July 27, 2023, 10:46 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/*****************INCLUDES*****************/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*****************MACROS*****************/
#define RELAY_STATUS_ON         0x01
#define RELAY_STATUS_OFF        0x00

/*****************MACRO FUNCTIONS*****************/


/*****************DATA TYPES*****************/
typedef struct{
    uint8 relay_port    :3;
    uint8 relay_pin     :3;
    uint8 relay_status  :1;
    uint8 reserved_bit  :1;

}relay_t;


/*****************FUNCTIONS*****************/
Std_ReturnType relay_init(const relay_t * relay_obj);
Std_ReturnType relay_on(const relay_t * relay_obj);
Std_ReturnType relay_off(const relay_t * relay_obj);

#endif	/* ECU_RELAY_H */

