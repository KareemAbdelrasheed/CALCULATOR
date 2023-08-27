/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author: Kareem Abdelrasheed   *********************************/
/*****************************    Layer:  HAL                   *********************************/
/*****************************    SWC:    KEYPAD                *********************************/
/*****************************    Version:1.00                  *********************************/
/************************************************************************************************/
/************************************************************************************************/
#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define ROWS_NUMBER             4
#define COLUMS_NUMBER           4

#define KEYPAD_NO_PRESSED_KEY   0Xff

#define KEYPAD_PORT_COL         GPIO_PORTC

#define KEYPAD_COLUM0_PIN       GPIO_PC4
#define KEYPAD_COLUM1_PIN       GPIO_PC5
#define KEYPAD_COLUM2_PIN       GPIO_PC6
#define KEYPAD_COLUM3_PIN       GPIO_PC7

#define KEYPAD_PORT_ROW         GPIO_PORTA

#define KEYPAD_ROW0_PIN         GPIO_PA4
#define KEYPAD_ROW1_PIN         GPIO_PA5
#define KEYPAD_ROW2_PIN         GPIO_PA6
#define KEYPAD_ROW3_PIN         GPIO_PA7

#if COLUMS_NUMBER == 3
#define KEYPAD_ARR_VALUE                {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}}
#elif COLUMS_NUMBER == 4
#define KEYPAD_ARR_VALUE                {{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'#','0','=','+'}}
#endif

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
