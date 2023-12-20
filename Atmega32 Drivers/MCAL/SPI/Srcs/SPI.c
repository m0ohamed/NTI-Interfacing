#include "../Includes/SPI.h"
#include "../Includes/SPI_Cfg.h"
#include "../Includes/SPI_Prv.h"
#include "../../../Services/Lib/common_macros.h"
#include "../../../Services/Lib/std_types.h"
#include "../../Port/Includes/Port.h"
#include "util/delay.h"

void (_G_Ptr)(void)=Null_ptr;

SPI_ErrorStatus SPI_enuInit(SPI_ConfigType* ConfigPtr)
{
	uint8 ErrorStatus=SPI_enuOk;
	if(ConfigPtr==Null_ptr)
	{
		ErrorStatus=SPI_enuNullPointer;
	}

#if(SPI_MODE==SPI_INTERRUPT_E)
	SET_BIT(SPCR,SPIE);
#elif(SPI_MODE==SPI_INTERRUPT_D)
	CLEAR_BIT(SPCR,SPIE);
#endif



#if(SPI_DOUPLE==SPI_DOUPLE_S_D)
	SPCR |=(SPCR & 0xFC)|(ConfigPtr->Clock);
	CLEAR_BIT(SPSR,SPI2X);
#elif(SPI_DOUPLE==SPI_DOUPLE_S_E)
	SPCR =(SPCR & 0xFC)|(ConfigPtr->Clock);
	SET_BIT(SPSR,SPI2X);
#endif

	if(ConfigPtr->MODe==SPI_Slave)
	{
		SPI_SlaveInit(ConfigPtr);
	}
	else if(ConfigPtr->MODe==SPI_Master)
	{
		SPI_MasterInit(ConfigPtr);
	}

	return ErrorStatus;
}

void SPI_MasterInit(SPI_ConfigType* MConfig)
{
	PORT_enuSetDirection(SPI_MOSI,PORT_OUTPUT_Direction);
	PORT_enuSetDirection(SPI_MISO,PORT_INPUT_Direction);
	PORT_enuSetDirection(SPI_SCK,PORT_OUTPUT_Direction);
	PORT_enuSetDirection(SPI_SS,PORT_OUTPUT_Direction);

	SET_BIT(SPCR,MSTR);
	SPCR |= ((MConfig->Order)<<5) ;
	CLEAR_BIT(SPCR,CPOL);
	CLEAR_BIT(SPCR,CPHA);
	SPCR |=(SPCR & 0xFC)|(MConfig->Clock);
	SET_BIT(SPCR,SPE);

}

void SPI_SlaveInit(SPI_ConfigType* SConfig)
{
	PORT_enuSetDirection(SPI_MOSI,PORT_INPUT_Direction);
	PORT_enuSetDirection(SPI_MISO,PORT_OUTPUT_Direction);
	PORT_enuSetDirection(SPI_SCK,PORT_INPUT_Direction);
	PORT_enuSetDirection(SPI_SS,PORT_INPUT_Direction);
	SET_BIT(SPCR,SPE);
	CLEAR_BIT(SPCR,MSTR);
	SPCR |= ((SConfig->Order)<<5) ;
	CLEAR_BIT(SPCR,CPHA);
	CLEAR_BIT(SPCR,CPOL);
	SPCR |=(SPCR & 0xFC)|(SConfig->Clock);
}

void SPI_SendRecieveByte(uint8 Data,pu8 Add_pu8Data)
{
	SPDR=Data;
	while(BIT_IS_CLEAR(SPSR,SPIF));
	*Add_pu8Data=SPDR;
}
void SPI_SendString(uint8 *Data)
{
	uint8 Iterator=0;
	uint8 recievedData=0;
	while(Data[Iterator] !=0)
	{
		SPI_SendRecieveByte(Data[Iterator],&recievedData);
		Iterator++;
	}
}

void SPI_RecieveString(uint8 *Data)
{
	uint8 Iterator = 0;

	/* Receive the first byte */
	  SPI_SendRecieveByte(SPI_DEFAULT_DATA_VALUE,&Data[Iterator]);

	/* Receive the whole string until the '#' */
	while(Data[Iterator] != '#')
	{
		Iterator++;
		SPI_SendRecieveByte(SPI_DEFAULT_DATA_VALUE,&Data[Iterator]);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Data[Iterator] = '\0';
}

void SPI_CallBack(void (*Func_Call)(void))
{
	if(Func_Call !=Null_ptr)
		_G_Ptr=Func_Call;
}

