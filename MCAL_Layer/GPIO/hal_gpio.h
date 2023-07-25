/* 
 * File:   hal_gpio.h
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 6:48 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/*****************INCLUDES*****************/

#include "../mcal_std_types.h"
#include "../proc/pic18f4620.h"
#include "../device_cfg.h"
#include "hal_gpio_cfg.h"

/*****************MACROS*****************/

#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5

/*****************MACRO FUNCTIONS*****************/
#define HWREG8(X)        (*((volatile uint8 *)(X)))

#define SET_BIT(REG, BIT_POSN)          (REG |= (BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)        (REG &= ~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)       (REG ^= (BIT_MASK<<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)          ((REG >> BIT_POSN) & BIT_MASK)

/*****************DATA TYPES*****************/

typedef enum{
    LOW
   ,HIGH
    
}logic_t;

typedef enum{
    OUTPUT
   ,INPUT
    
}direction_t;

typedef enum{
    PIN0
   ,PIN1
   ,PIN2
   ,PIN3
   ,PIN4
   ,PIN5
   ,PIN6
   ,PIN7         
}pin_index_t;

typedef enum{
    PORTA_index
   ,PORTB_index
   ,PORTC_index
   ,PORTD_index
   ,PORTE_index
           
}port_index_t;

typedef struct {
    uint8 port        :3;
    uint8 pin         :3;
    uint8 direction   :1;
    uint8 logic       :1;
}pin_config_t;

/*****************FUNCTIONS*****************/

Std_ReturnType gpio_pin_direction_init(const pin_config_t *pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config, direction_t *direction_status);
Std_ReturnType gpio_pin_wrt_logic(const pin_config_t *pin_config, logic_t logic);
Std_ReturnType gpio_pin_rd_logic(const pin_config_t *pin_config, logic_t *logic);
Std_ReturnType gpio_pin_tgl_logic(const pin_config_t *pin_config);
Std_ReturnType gpio_pin_init(const pin_config_t *pin_config);

Std_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_wrt_logic(port_index_t port, uint8 logic);
Std_ReturnType gpio_port_rd_logic(port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_tgl_logic(port_index_t port);

#endif	/* HAL_GPIO_H */

