#ifndef SPI_H
#define SPI_H
#include "../../../Services/Lib/std_types.h"
#define SPI_INTERRUPT_E      1
#define SPI_INTERRUPT_D      0


#define SPI_DOUPLE_S_E       1
#define SPI_DOUPLE_S_D       0

#define SPI_DEFAULT_DATA_VALUE    0xFF
typedef enum
{
	SPI_Slave,
	SPI_Master
}SPI_MsterSlave;

typedef enum
{
	SPI_MSB,
	SPI_LSB
}SPI_DataOrder;

typedef enum
{
	fosc_4,
	fosc_16,
	fosc_64,
	fosc_128,
	fosc_2_x2=0,
	fosc_8_x2,
	fosc_32_x2,
	fosc_64_x2
}SPI_CLock;


typedef struct
{
	SPI_MsterSlave MODe;
	SPI_DataOrder Order;
	SPI_CLock Clock;
}SPI_ConfigType;

typedef enum
{
	SPI_enuOk,
	SPI_enuNullPointer

}SPI_ErrorStatus;


SPI_ErrorStatus SPI_enuInit(SPI_ConfigType* ConfigPtr);
void SPI_SendRecieveByte(uint8 Data,pu8 Add_pu8Data);
void SPI_SendString(uint8 *Data);
void SPI_RecieveString(uint8 *Data);
void SPI_CallBack(void (*Func_Call)(void));
#endif
