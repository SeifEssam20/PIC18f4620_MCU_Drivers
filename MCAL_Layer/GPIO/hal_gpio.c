/* 
 * File:   hal_gpio.c
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 6:27 PM
 */

#include "hal_gpio.h"

/* Reference to the Data Direction Control Registers */
volatile uint8 * tris_regs[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
volatile uint8 * port_regs[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
/* Reference to the Port Status Register  */
volatile uint8 * lat_regs[]  = {&LATA, &LATB, &LATC, &LATD, &LATE};

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief Initialize the direction of a specific pin @ref direction_t
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_direction_init(const pin_config_t * pin_config){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{
    switch(pin_config -> direction )
    {
        case(OUTPUT):
            CLEAR_BIT(*tris_regs[pin_config->port],pin_config->pin);
            break;
        case(INPUT):
            SET_BIT(*tris_regs[pin_config->port],pin_config->pin);
            break;
        default :
            retVal = E_NOK;
            break;       
    }
    }
    return retVal;
}
#endif


#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_wrt_logic(const pin_config_t *pin_config, logic_t logic){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{  
        switch(logic){
            case(LOW)  :
                CLEAR_BIT(*lat_regs[pin_config->port],pin_config->pin);
                break;
            case(HIGH) :
                SET_BIT(*lat_regs[pin_config->port],pin_config->pin);
                break;
            default:
                retVal = E_NOK;
        }   
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin_config, direction_t *direction_status){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (NULL == direction_status ) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{
        *direction_status = READ_BIT(*lat_regs[pin_config->port],pin_config->pin);
        retVal = E_OK;
    }


    return retVal;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_rd_logic(const pin_config_t *pin_config, logic_t *logic){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (NULL == logic ) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{
        *logic = READ_BIT(*port_regs[pin_config->port],pin_config->pin);
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_tgl_logic(const pin_config_t *pin_config){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{
        TOGGLE_BIT(*lat_regs[pin_config->port],pin_config->pin);
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_pin_init(const pin_config_t *pin_config){
    Std_ReturnType retVal = E_OK;
    if((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)){
        retVal = E_NOK;
    }
    else{
       retVal = gpio_pin_direction_init(pin_config);
       retVal = gpio_pin_wrt_logic(pin_config,pin_config->logic);
        
    }
    return retVal;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction){
    Std_ReturnType retVal = E_OK;
    if( port > PORT_PIN_MAX_NUMBER - 1){
        retVal = E_NOK;
    }
    else{
        *tris_regs[port] = direction;
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){
    Std_ReturnType retVal = E_OK;
    if(( port > PORT_PIN_MAX_NUMBER - 1) || (NULL == direction_status)){
        retVal = E_NOK;
    }
    else{
        *direction_status = *tris_regs[port];
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_wrt_logic(port_index_t port, uint8 logic){
    Std_ReturnType retVal = E_OK;
    if(port > PORT_PIN_MAX_NUMBER - 1){
        retVal = E_NOK;
    }
    else{
        *lat_regs[port] = logic;
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_rd_logic(port_index_t port, uint8 *logic){
    Std_ReturnType retVal = E_OK;
    if((port > PORT_PIN_MAX_NUMBER - 1) || (NULL == logic)){
        retVal = E_NOK;
    }
    else{
        *logic = *lat_regs[port];
        retVal = E_OK;
    }
    return retVal;
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * 
 * @param port
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_tgl_logic(port_index_t port){
    Std_ReturnType retVal = E_OK;
    if(port > PORT_PIN_MAX_NUMBER - 1){
        retVal = E_NOK;
    }
    else{
        
        retVal = E_OK;
    }
    return retVal;
}
#endif



