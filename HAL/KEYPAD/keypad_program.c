/************************************************************************************************/
/************************************************************************************************/
/*****************************    Author: Kareem Abdelrasheed   *********************************/
/*****************************    Layer:  HAL                   *********************************/
/*****************************    SWC:    KEYPAD                *********************************/
/*****************************    Version:1.00                  *********************************/
/************************************************************************************************/
/************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/GPIO/GPIO_private.h"

#include "keypad_config.h"
#include "keypad_interface.h"

void KEYPAD_voidInit(void)
{
       GPIO_voidInit(GPIO_PORTA);
       GPIO_voidInit(GPIO_PORTC);

       //allow changes for pins needed
       GPIO_PORTA_CR_R = 0xF0;
       //PORTC
       GPIO_PORTC_CR_R = 0xF0;

       //direction
       GPIO_PORTA_DIR_R =0x00;
       //PORTC
       GPIO_PORTC_DIR_R =0xF0;


       //RESISTORS
       GPIO_PORTA_PUR_R = 0xF0;


       //enable
       GPIO_PORTA_DEN_R = 0xF0;
       //PORTC
       GPIO_PORTC_DEN_R = 0xF0;

}


u8 KEYPAD_u8PressedKey(void)
{
	u8 Local_u8PressedKey=KEYPAD_NO_PRESSED_KEY;
	u8 Local_u8ColumIndex,Local_u8RowIndex,Local_u8PinState;
	static u8 Local_u8KEYPADArr[ROWS_NUMBER][COLUMS_NUMBER]=KEYPAD_ARR_VALUE;

    GPIO_voidWritePin(GPIO_PORTC, 4 , HIGH);
    GPIO_voidWritePin(GPIO_PORTC, 5 , HIGH);
    GPIO_voidWritePin(GPIO_PORTC, 6 , HIGH);
    GPIO_voidWritePin(GPIO_PORTC, 7 , HIGH);


	#if COLUMS_NUMBER==4
	static u8 Local_u8ColumsArr[COLUMS_NUMBER]={KEYPAD_COLUM0_PIN,KEYPAD_COLUM1_PIN,KEYPAD_COLUM2_PIN,KEYPAD_COLUM3_PIN};
	#elif COLUMS_NUMBER==3
	static u8 Local_u8ColumsArr[COLUMS_NUMBER]={KEYPAD_COLUM0_PIN,KEYPAD_COLUM1_PIN,KEYPAD_COLUM2_PIN};
	#endif

	static u8 Local_u8RowsArr[ROWS_NUMBER]={KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	for(Local_u8ColumIndex = 0 ; Local_u8ColumIndex < COLUMS_NUMBER ; Local_u8ColumIndex++)
	{
	    //activate one low
		GPIO_voidWritePin(KEYPAD_PORT_COL,Local_u8ColumsArr[Local_u8ColumIndex],LOW);

		//check if any raw pressed
		for(Local_u8RowIndex=0;Local_u8RowIndex<ROWS_NUMBER;Local_u8RowIndex++)
		{

		    Local_u8PinState = GPIO_u8Read(KEYPAD_PORT_ROW , Local_u8RowsArr[Local_u8RowIndex] );
			if(LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KEYPADArr[Local_u8RowIndex][Local_u8ColumIndex];
				while(LOW==Local_u8PinState)
				{
		            Local_u8PinState = GPIO_u8Read(KEYPAD_PORT_ROW , Local_u8RowsArr[Local_u8RowIndex] );

				}
		        //GPIO_voidWritePin(KEYPAD_PORT_COL,Local_u8ColumsArr[Local_u8ColumIndex],HIGH);
				//return Local_u8PressedKey;
			}

		}

		GPIO_voidWritePin(KEYPAD_PORT_COL,Local_u8ColumsArr[Local_u8ColumIndex],HIGH);
	}


	GPIO_voidWritePin(GPIO_PORTC, 4 , LOW);
	GPIO_voidWritePin(GPIO_PORTC, 5 , LOW);
	GPIO_voidWritePin(GPIO_PORTC, 6 , LOW);
	GPIO_voidWritePin(GPIO_PORTC, 7 , LOW);

	return Local_u8PressedKey;
}
