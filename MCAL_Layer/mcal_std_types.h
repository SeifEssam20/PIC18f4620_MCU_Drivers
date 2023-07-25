/* 
 * File:   mcal_std_types.h
 * Author: Seif Essam
 *
 * Created on July 24, 2023, 6:38 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H





/*****************INCLUDES*****************/

#include "compiler.h"
#include "std_libs.h"


/*****************MACROS*****************/

#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK            (Std_ReturnType)0x01;
#define E_NOK           (Std_ReturnType)0x00;

#define BIT_MASK        (uint8)0x01

/*****************MACRO FUNCTIONS*****************/

/*****************DATA TYPES*****************/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef uint8 Std_ReturnType;





/*****************FUNCTIONS*****************/

#endif	/* MCAL_STD_TYPES_H */

