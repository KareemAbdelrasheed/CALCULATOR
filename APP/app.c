#include "../LIB/STD_TYPES.h"

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/GPIO_private.h"
#include "../MCAL/EXTI/EXTI.h"


#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/keypad_interface.h"

#include "../calculator.h"


extern f64 NUMBERS_NUMBER[10];

u8 FLAG_KEYPAD_PRESSED=LOW;

char KeyPressed=0xff;

void APP_SysSetUP(void)
{
    LCD_voidInit();
    KEYPAD_voidInit();
    ISR_KEYPAD_PORTA_Init();

}
void APP_SysOn(void)
{
    if(FLAG_KEYPAD_PRESSED)
    {

        KeyPressed = KEYPAD_u8PressedKey();
        if(0xFF != KeyPressed)
        {
            LCD_voidSendData(KeyPressed);
            CALCULATE(KeyPressed);
        }
        if('='== KeyPressed)
        {
            LCD_voidGoToXY(1,0);

            if(NUMBERS_NUMBER[0] >= 0)
            {
                LCD_voidSendFloat(NUMBERS_NUMBER[0]);
            }
            else
            {
                NUMBERS_NUMBER[0] *= -1;
                LCD_voidSendData('-');
                LCD_voidSendFloat(NUMBERS_NUMBER[0]);

            }
        }
        FLAG_KEYPAD_PRESSED=LOW;
    }

}
