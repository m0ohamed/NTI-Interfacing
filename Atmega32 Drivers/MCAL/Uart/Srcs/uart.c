#include "../Includes/uart.h"
#include "../Includes/uart_Cfg.h"
#include "../Includes/uart_Prv.h"
#include "../../../Services/Lib/common_macros.h"
void (_G_Ptr)(void)=Null_ptr;
void (_G1_Ptr)(void)=Null_ptr;

UART_ErrorStatus UART_Init(const UART_ConfiType* ConfigPtr)
{
	uint8 ErrorStatus=enu_Ok;
	if(ConfigPtr==Null_ptr)
	{
		ErrorStatus=Error_NullPointer;
	}


	UCSRC =(1<<7)| (UCSRC & 0xBE);
	UCSRC |=(1<<7)| ((UCSRC & 0xF7) |((ConfigPtr->Stop_Num)<<3));
	UCSRC |=(1<<7)|((UCSRC & 0xF9)|((ConfigPtr->Data_FramSize)<<1));
	if((ConfigPtr->Data_FramSize)==_9_Bit)
	{
		UCSRB |=(1<<2);
	}
	UCSRC |=(1<<7)|((UCSRC & 0xCF) | ((ConfigPtr->Parity_Type)<<4));
	if(ConfigPtr->DoubleS==DSpeed_E){
		SET_BIT(UCSRA,1);
		UBRRL=BUAD_RATE_DOUPLY(ConfigPtr->Buad_Rate);
		UBRRH=(UBRRH & (~(1<<7)))|((BUAD_RATE_DOUPLY(ConfigPtr->Buad_Rate))>>8);

	}
	else if(ConfigPtr->DoubleS==DSpeed_E)
	{
		CLEAR_BIT(UCSRA,1);
		UBRRL=BUAD_RATE(ConfigPtr->Buad_Rate);
		UBRRH=(UBRRH & (~(1<<7)))|((BUAD_RATE(ConfigPtr->Buad_Rate))>>8);
	}
#if(UART_MODE==UART_INTERRUPT_ENABLE)
	UCSRB |=0xE0;
#elif(UART_MODE==UART_INTERRUPT_DISABLE)
	UCSRB &=~(0xE0);

#endif

	UCSRB = (1<<4) | (1<<3);

	return ErrorStatus;
}


void UART_SendByte(uint8 Data)
{

#if(UART_MODE==UART_INTERRUPT_DISABLE)
	while(BIT_IS_CLEAR(UCSRA,5)){}


	UDR = Data;
#elif(UART_MODE==UART_INTERRUPT_ENABLE)

#endif

}
void UART_RecieveByte(pu8 Add_pu8Data)
{
#if(UART_MODE==UART_INTERRUPT_DISABLE)
	while(BIT_IS_CLEAR(UCSRA,7)){}
	*Add_pu8Data=UDR;
#elif(UART_MODE==UART_INTERRUPT_ENABLE)

#endif

}

void UART_SendString(pu8 Sstr_Ptr)
{
	uint8 Iterator = 0;
#if(UART_MODE==UART_INTERRUPT_DISABLE)

	while(Sstr_Ptr[Iterator] != '\0')
	{
		UART_SendByte(Sstr_Ptr[Iterator]);
		Iterator++;
	}
	UART_SendByte('\0');
#elif(UART_MODE==UART_INTERRUPT_ENABLE)

#endif

}

void UART_RecieveString(pu8 Rstr_Ptr)
{
	uint8 Iterator = 0;
#if(UART_MODE==UART_INTERRUPT_DISABLE)

	while(Rstr_Ptr[Iterator] != '\0')
	{
		UART_RecieveByte(&Rstr_Ptr[Iterator]);
		Iterator++;
	}
	Rstr_Ptr[Iterator]='\0';
#elif(UART_MODE==UART_INTERRUPT_ENABLE)
#endif

}

void UART_RecieveCallBack(void (*Ptr_Call)(void))
{
	if(Ptr_Call !=Null_ptr)
	_G_Ptr=Ptr_Call;
}
void UART_SendCallBack(void (*Ptr_Call)(void))
{
	if(Ptr_Call !=Null_ptr)
		_G1_Ptr=Ptr_Call;
}
