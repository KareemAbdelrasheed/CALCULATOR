#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/tm4c123gh6pm.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"



void GPIO_voidInit(u8 copy_port)
{
    switch (copy_port){
    case GPIO_PORTA:
        //enable clk
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTA);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTA));
        //unlock port
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        break;
    case GPIO_PORTB:
        //enable
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTB);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTB));
        //unlock port
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        break;
    case GPIO_PORTC:
        //enable
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTC);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTC));
        //unlock port
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        break;
    case GPIO_PORTD:
        //enable
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTD);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTD));
        //unlock port
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        break;
    case GPIO_PORTE:
        //enable
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTE);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTE));
        //unlock port
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        break;
    case GPIO_PORTF:
        //enable
        SET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTF);
        //wait till finish
        while(0==GET_BIT(SYSCTL_RCGCGPIO_R,GPIO_PORTF));
        //unlock port
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        break;
    }
}
void GPIO_voidInput(u8 copy_port,u8 pin,u8 copy_state)
{
    if(copy_state==PULL_UP)
    {
        switch(copy_port){
        case GPIO_PORTA:
            //allow changes
            SET_BIT(GPIO_PORTA_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTA_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTA_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTA_PUR_R,pin);
            break;
        case GPIO_PORTB:
            //allow changes
            SET_BIT(GPIO_PORTB_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTB_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTB_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTB_PUR_R,pin);
            break;
        case GPIO_PORTC:
            //allow changes
            SET_BIT(GPIO_PORTC_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTC_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTC_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTC_PUR_R,pin);
            break;
        case GPIO_PORTD:
            //allow changes
            SET_BIT(GPIO_PORTD_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTD_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTD_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTD_PUR_R,pin);
            break;
        case GPIO_PORTE:
            //allow changes
            SET_BIT(GPIO_PORTE_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTE_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTE_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTE_PUR_R,pin);
            break;
        case GPIO_PORTF:
            //allow changes
            SET_BIT(GPIO_PORTF_CR_R,pin);
            //set direction as input
            CLEAR_BIT(GPIO_PORTF_DIR_R,pin);
            //enable
            SET_BIT(GPIO_PORTF_DEN_R,pin);
            //set as pull up
            SET_BIT(GPIO_PORTF_PUR_R,pin);
            break;
        }

    }
    //pull-down
    else
    {

    }
}
void GPIO_voidWritePin(u8 copy_port,u8 pin,u8 copy_value)
{
    switch(copy_port){
    case GPIO_PORTA:
        //allow changes
        SET_BIT(GPIO_PORTA_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTA_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTA_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTA_DATA_R, pin);
        GPIO_PORTA_DATA_R |= copy_value<<pin;
        break;
    case GPIO_PORTB:
        //allow changes
        SET_BIT(GPIO_PORTB_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTB_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTB_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTB_DATA_R, pin);
        GPIO_PORTB_DATA_R |= copy_value<<pin;
        break;
    case GPIO_PORTC:
        //allow changes
        SET_BIT(GPIO_PORTC_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTC_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTC_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTC_DATA_R, pin);
        GPIO_PORTC_DATA_R |= copy_value<<pin;
        break;
    case GPIO_PORTD:
        //allow changes
        SET_BIT(GPIO_PORTD_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTD_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTD_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTD_DATA_R, pin);
        GPIO_PORTD_DATA_R |= copy_value<<pin;
        break;
    case GPIO_PORTE:
        //allow changes
        SET_BIT(GPIO_PORTE_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTE_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTE_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTE_DATA_R, pin);
        GPIO_PORTE_DATA_R |= copy_value<<pin;
        break;
    case GPIO_PORTF:
        //allow changes
        SET_BIT(GPIO_PORTF_CR_R,pin);
        //set direction as output
        SET_BIT(GPIO_PORTF_DIR_R,pin);
        //enable
        SET_BIT(GPIO_PORTF_DEN_R,pin);
        //set value
        CLEAR_BIT(GPIO_PORTF_DATA_R, pin);
        GPIO_PORTF_DATA_R |= copy_value<<pin;

        break;
    }
}

u8 GPIO_u8Read(u8 copy_port , u8 pin)
{
    u8 Local_u8value=0;
    switch(copy_port){
    case GPIO_PORTA:
        Local_u8value = GET_BIT(GPIO_PORTA_DATA_R,pin);
        break;
    case GPIO_PORTB:
        Local_u8value = GET_BIT(GPIO_PORTB_DATA_R,pin);
        break;
    case GPIO_PORTC:
        Local_u8value =  GET_BIT(GPIO_PORTC_DATA_R,pin);
        break;
    case GPIO_PORTD:
        Local_u8value = GET_BIT(GPIO_PORTD_DATA_R,pin);
        break;
    case GPIO_PORTE:
        Local_u8value =  GET_BIT(GPIO_PORTE_DATA_R,pin);
        break;
    case GPIO_PORTF:
        Local_u8value =  GET_BIT(GPIO_PORTF_DATA_R,pin);
        break;
    }
    return Local_u8value;
}

