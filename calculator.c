#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "HAL/LCD/LCD_interface.h"

#include "calculator.h"


f64 NUMBERS_NUMBER[10];
char OPERATION[10];

u8 Get_Priority(char operator)
{
    u8 value=0;
    switch (operator)
    {
    case '+':
    case '-':
        value=1;
        break;
    case '*':
    case '/':
        value=2;
    }
    return value;
}

f64 Perform_Operation(f64 operand1, f64 operand2, char operator)
{
    f64 result;

    switch (operator)
    {
    case '+':   result = operand1 + operand2; break;
    case '-':   result = operand1 - operand2; break;
    case '*':   result = operand1 * operand2; break;
    case '/':
        if (operand2 != 0)
        {
            result = operand1 / operand2;
        }
        else
        {
            //("Error: Division by zero")
            return 0;
        }
        break;
    default:
        //("Error: Invalid operator")
        return 0;
    }

    return result;
}



void CALCULATE(char  element)
{
    s8 j=0;
    u8 flag=0;

    static u8 Local_u8NumberIndex=0;
    static s8 Local_u8OperatorIndex=-1;
    f64 Local_f64Result=0;
    static u32 temp=0;

    if(element <= '9' && element >= '0')
    {

        temp = ((element-'0')+ (temp*10)) ;

    }
    else if (element == '#')
    {
        LCD_voidSendCommand(1);
        j=0;
        flag=0;
        Local_u8NumberIndex=0;
        Local_u8OperatorIndex=-1;
        Local_f64Result=0;
        temp=0;
    }
    else if (element == '=')
    {

        //Save the last number
        NUMBERS_NUMBER[Local_u8NumberIndex]= temp;
        if(Get_Priority(OPERATION[Local_u8OperatorIndex]) ==2 && Local_u8OperatorIndex > -1)
        {
            /*do operation between the last two numbers
              and save it in the last index after decreasing it
              operation here */
            u8 Last_u8Index = Local_u8NumberIndex;
            Local_f64Result = Perform_Operation(NUMBERS_NUMBER[Last_u8Index -1] , NUMBERS_NUMBER[Last_u8Index] ,OPERATION[Local_u8OperatorIndex] );

            //don't forget to Local_u8OperatorIndex--
            Local_u8NumberIndex-=1;
            NUMBERS_NUMBER[Local_u8NumberIndex] = Local_f64Result;

            Local_u8NumberIndex++;

            //and assign the new element in place of the last used op
            OPERATION[Local_u8OperatorIndex] = element ;
            Local_u8OperatorIndex--;


        } else{/*DO NOTHING   */}


        //calculate the result
        for (;j <= Local_u8OperatorIndex;j++)
        {
            Local_f64Result = Perform_Operation(NUMBERS_NUMBER[0] , NUMBERS_NUMBER[j+1] ,OPERATION[j] );
            NUMBERS_NUMBER[0] = Local_f64Result;

        }


    }
    else
    {
        //OPERATION[Local_u8OperatorIndex]= element;
        NUMBERS_NUMBER[Local_u8NumberIndex]= temp;
        Local_u8NumberIndex++;
        temp=0;

        if(Get_Priority(OPERATION[Local_u8OperatorIndex]) ==2 & Local_u8OperatorIndex > -1)
        {
            //do operation between the last two numbers
            //and save it in the last index after decreasing it
            /*operation here */
            u8 Last_u8Index = Local_u8NumberIndex-1;
            Local_f64Result = Perform_Operation(NUMBERS_NUMBER[Last_u8Index -1] , NUMBERS_NUMBER[Last_u8Index] ,OPERATION[Local_u8OperatorIndex] );


            //don't forget to Local_u8OperatorIndex--
            Local_u8NumberIndex-=2;

            NUMBERS_NUMBER[Local_u8NumberIndex] = Local_f64Result;


            Local_u8NumberIndex++;
            //Local_u8OperatorIndex--;

            //and assign the new element in place of the last used op
            OPERATION[Local_u8OperatorIndex] = element ;

            flag=1;

        } else{/*DO NOTHING   */}

        if(!flag)
        {
            //now if the element is the biggest
            Local_u8OperatorIndex++;

            //assign the new op in the operation array
            OPERATION[Local_u8OperatorIndex] = element ;
        }
        else
        {
            //now if the element is the biggest
            //Local_u8OperatorIndex++;
            flag=0;
        }

    }

}

