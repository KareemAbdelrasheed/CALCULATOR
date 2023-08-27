#include "LIB/STD_TYPES.h"
#include "LIB/tm4c123gh6pm.h"

#include "EXTI.h"

extern u8 FLAG_KEYPAD_PRESSED;

void ISR_KEYPAD_PORTA(void)
{
    //clear flags
    GPIO_PORTA_ICR_R |= 0xF0;

    FLAG_KEYPAD_PRESSED=1;
}


void ISR_KEYPAD_PORTA_Init(void)
{

    /*Enable PORTA Interrupt */
    NVIC_EN0_R |= (1<<0);

    /*Enable mask interrupt for selected pins */
    GPIO_PORTA_IM_R |= 0xF0;

    /*(By default) sense edged & falling */

}

