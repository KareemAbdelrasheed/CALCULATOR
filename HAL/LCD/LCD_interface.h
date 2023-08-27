/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author: Kareem Abdelrasheed   *********************************/
/*****************************    Layer:  HAL                   *********************************/
/*****************************    SWC:    LCD                   *********************************/
/*****************************    Version:1.00                  *********************************/
/************************************************************************************************/
/************************************************************************************************/

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void delayMs(u32 n);

void LCD_voidSendCommand(u8 copy_u8Command);

void LCD_voidSendData(u8 copy_u8Data);

void LCD_voidInit(void);

void LCD_voidSendString(char* copy_pcharString);

void LCD_voidGoToXY(u8 copy_u8XPos,u8 copy_u8YPos);

void LCD_voidWriteSpecialCh(u8* copy_u8ArrCh,u8 copy_u8ChNo,u8 copy_u8XPos,u8 copy_u8YPos);

void LCD_voidSendNumber(u32 copy_u32Number);

void LCD_voidSendFloat(f64 copy_f64Number);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
