#ifndef UART_H
#define UART_H
#include "../../../Services/Lib/std_types.h"

#define UART_INTERRUPT_ENABLE       1
#define UART_INTERRUPT_DISABLE      0
typedef enum
{
	Parity_Disable,
	Parity_Even=2,
	Parity_Odd
}UART_Parity;


typedef enum
{
	Stop_1,
	Stop_2
}UART_Stop_Bit;


typedef enum
{
	_5_Bit,
	_6_Bit,
	_7_Bit,
	_8_Bit,
	_9_Bit=9
}UART_Chracter_Size;

typedef enum
{
	B_2400=2400,
	B_4800=4800,
	B_9600=9600,
	B_14_4k=14400,
	B_19_2k=19200

}UART_BuadRate;

typedef enum
{
	DSpeed_D,
	DSpeed_E

}UART_DoupleSpeed;

typedef struct
{
	UART_BuadRate Buad_Rate;
	UART_Chracter_Size Data_FramSize;
	UART_Stop_Bit Stop_Num;
	UART_Parity  Parity_Type;
	UART_DoupleSpeed DoubleS;
}UART_ConfiType;

typedef enum
{
	enu_Ok,
	Error_NullPointer
}UART_ErrorStatus;

UART_ErrorStatus UART_Init(const UART_ConfiType* ConfigPtr);
void UART_SendByte(uint8 Data);
void UART_RecieveByte(pu8 Add_pu8Data);
void UART_SendString(pu8 Sstr_Ptr);
void UART_RecieveString(pu8 Rstr_Ptr);
void UART_RecieveCallBack(void (*Ptr_Call)(void));
void UART_SendCallBack(void (*Ptr_Call)(void));


#endif
