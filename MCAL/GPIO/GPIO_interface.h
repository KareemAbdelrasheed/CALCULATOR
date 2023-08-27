#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


void GPIO_voidInit(u8 copy_port);
void GPIO_voidInput(u8 copy_port,u8 pin,u8 copy_state);
void GPIO_voidWritePin(u8 copy_port , u8 pin , u8 copy_value);
u8 GPIO_u8Read(u8 copy_port , u8 pin);


#endif
