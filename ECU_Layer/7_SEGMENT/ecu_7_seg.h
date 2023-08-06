/* 
 * File:   ecu_7_seg.h
 * Author: Seif Essam
 *
 * Created on July 30, 2023, 6:30 PM
 */

#ifndef ECU_7_SEG_H
#define	ECU_7_SEG_H


/*****************INCLUDES*****************/
#include "ecu_7_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*****************MACROS*****************/
#define SEGMENT_PIN0        0
#define SEGMENT_PIN1        1
#define SEGMENT_PIN2        2
#define SEGMENT_PIN3        3


/*****************MACRO FUNCTIONS*****************/


/*****************DATA TYPES*****************/
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}seg_type_t;

typedef struct{
    pin_config_t seg_pins[4];
    seg_type_t seg_type;

}seg_t;

/*****************FUNCTIONS*****************/
Std_ReturnType se7en_seg_init(const seg_t * seg_obj);
Std_ReturnType se7en_seg_wrt_num(const seg_t * seg_obj, uint8 num);


#endif	/* ECU_7_SEG_H */

