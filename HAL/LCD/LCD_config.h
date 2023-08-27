/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author: Kareem Abdelrasheed   *********************************/
/*****************************    Layer:  HAL                   *********************************/
/*****************************    SWC:    LCD                   *********************************/
/*****************************    Version:1.00                  *********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "../../LIB/tm4c123gh6pm.h"


#define LCD_DATA_PORT_DIRECTION  GPIO_PORTB_DIR_R
#define LCD_CTRL_PORT_DIRECTION  GPIO_PORTE_DIR_R

#define LCD_DATA_PORT_REG  GPIO_PORTB_DATA_R

#define LCD_DATA_PORT   GPIO_PORTB

#define LCD_CTRL_PORT   GPIO_PORTE
#define LCD_RS_PIN		GPIO_PE1
#define LCD_RW_PIN		GPIO_PE2
#define LCD_E_PIN		GPIO_PE3




#endif /* HAL_LCD_LCD_CONFIG_H_ */
