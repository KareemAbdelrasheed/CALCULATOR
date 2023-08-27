/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author: Kareem Abdelrasheed   *********************************/
/*****************************    Layer:  HAL                   *********************************/
/*****************************    SWC:    LCD                   *********************************/
/*****************************    Version:1.00                  *********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/GPIO/GPIO_private.h"



#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

#define MS_CLK16 4000
//delay in ms
void delayMs(u32 n)
{
    u32 i=0 , j=0;
    for ( i=0 ; i<n ; i++)
        for ( j=0 ; j<16000 ; j++);

//    /*Disable PORTA Interrupt */
//    NVIC_EN0_R=0;
//    int i,j ;
//
//    for(i=0 ; i < n ; i++)
//        for(j=0 ; j < MS_CLK16 ; j++ );
//
////
//    /*Enable PORTA Interrupt */
//    NVIC_EN0_R |= (1<<0);
}

void LCD_voidSendCommand(u8 copy_u8Command)
{
	//set RS_PIN as low for command
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
	//set RW_PIN as low for write
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	//send command bits
	//DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command);
	LCD_DATA_PORT_REG = copy_u8Command ;
	//set E_PIN 1 for 2ms to enable
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	delayMs(2);
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_E_PIN,LOW);
}

void LCD_voidSendData(u8 copy_u8Data)
{
	//set RS_PIN as high for data
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
	//set RW_PIN as low for write
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
	//send data bits
	//DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Data);
	LCD_DATA_PORT_REG = copy_u8Data ;
	//set E_PIN 1 for 2ms to enable (enable pulse)
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_E_PIN,HIGH);
	delayMs(2);
	GPIO_voidWritePin(LCD_CTRL_PORT,LCD_E_PIN,LOW);

}


void LCD_voidInit(void)
{
    GPIO_voidInit(LCD_DATA_PORT);
    GPIO_voidInit(LCD_CTRL_PORT);

    //allow changes for pins needed
    GPIO_PORTB_CR_R = 0xFF;
    GPIO_PORTE_CR_R = 0x0F;

    //direction
    LCD_DATA_PORT_DIRECTION =0xFF;
    LCD_CTRL_PORT_DIRECTION =0xFF;

    //enable
    GPIO_PORTB_DEN_R = 0xFF;
    GPIO_PORTE_DEN_R = 0x0F;

    //wait for more than 30 ms to init
	delayMs(40);

	//function set command 2 lines and font size bits (0011NFxx)
	LCD_voidSendCommand(0b00111100);

	//wait for more than 40 mc
	//delayMs(0.5); can cancel it and depend on set command function

	//function set command display & blink cursor     (00001DCB)
	LCD_voidSendCommand(0b00001100);

	//wait for more than 40mc
	//delayMs(0.5); can cancel it and depend on set command function

	//function set command to clear dispaly
	LCD_voidSendCommand(0b00000001);

}

void LCD_voidSendString(char* copy_pcharString)
{
	u8 Local_u8Counter=0;

	while(copy_pcharString[Local_u8Counter] != NULL_CH)
	{
		LCD_voidSendData(copy_pcharString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_voidGoToXY(u8 copy_u8XPos,u8 copy_u8YPos)
{
	u8 Local_u8Address;
	if(copy_u8XPos==FIRST_LINE)
	{
		Local_u8Address= copy_u8YPos;
	}
	else if(copy_u8XPos==SECOND_LINE)
	{
		Local_u8Address= copy_u8YPos+(0x40);
	}

	//send command to set the address (0b1address)=(ob10000000+address)
	LCD_voidSendCommand(Local_u8Address+128);

}

void LCD_voidWriteSpecialCh(u8* copy_pu8ArrCh,u8 copy_u8ChNo,u8 copy_u8XPos,u8 copy_u8YPos)
{
	u8 i=0;
	//calculate the CGRAM Address cuz each block is 8 bytes
	u8 Local_u8CGRAMAddress=(copy_u8ChNo*8);

	//send CGRAM address to LCD with set bit6 and clear bit7
	LCD_voidSendCommand(Local_u8CGRAMAddress+64);

	//write data on CGRAM
	for(i=0;i<8;i++)
	{
		LCD_voidSendData(copy_pu8ArrCh[i]);
	}

	//go back to DDRAM to display the ch
	LCD_voidGoToXY(copy_u8XPos , copy_u8YPos);

	//display on LCD
	LCD_voidSendData(copy_u8ChNo);

}

void LCD_voidSendNumber(u32 copy_u32Number)
{
    u32 local_u32Number_1 = 1;
    if (copy_u32Number == 0)
    {
        LCD_voidSendData('0');
    }
    while (copy_u32Number != 0)
    {
        local_u32Number_1 = ((local_u32Number_1 * 10) + (copy_u32Number % 10));
        copy_u32Number = copy_u32Number / 10;
    }
    while (local_u32Number_1 != 1)
    {
        LCD_voidSendData((local_u32Number_1 % 10) + 48);

        local_u32Number_1 = local_u32Number_1 / 10;
    }

}
void LCD_voidSendFloat(f64 copy_f64Number)
{
    u16 local_u16floatingPart=0;

    LCD_voidSendNumber((u32)copy_f64Number);
    LCD_voidSendData('.');
    local_u16floatingPart= ((f64)copy_f64Number - (u32)copy_f64Number)*100;
    LCD_voidSendNumber(local_u16floatingPart);

}

