/*********************************************************************************************
 * Name                 : Port.h
 * Description          : Port configuration
 * Author               : Mohamed khaled
 * *******************************************************************************************/

//Guard start
#ifndef DIO_H
#define DIO_H
#include "../Services/std_types.h"


#include "Dio_Cfg.h"
/*********************************************************************************************/
							// Configurations Definition//
/********************************************************************************************/
#define DIO_LOGIC_LOW                    0
#define DIO_LOGIC_HIGH                   1

//PinType Definition
typedef  uint8  DioPinType;


/*********************************************************************************************/
							//Errors check types //
/********************************************************************************************/
typedef enum{

		Dio_enuOK=0,
		Dio_enuPinError,
		Dio_enuPortError,
		DIO_enuDirectionError,
		DIO_enuNullPtr
}Dio_tenuErrorStatus;


/*********************************************************************************************/
							//Functions Prototypes//
/********************************************************************************************/
/********************************************************************************************
 * Name            : Dio_enuWriteChannel
 * Description     : Function responsible for writing high or low for output pins
 * Parameters(IN)  : 1.Copy_u8ChannelId -->channel number
 *                   2.Copy_u8Level     --> High or LOW
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuWriteChannel(DioPinType Copy_u8ChannelId,DioPinType Copy_u8Level);

/********************************************************************************************
 * Name            : Dio_enuReadChannel
 * Description     : Function responsible for reading high or low for input pins
 * Parameters(IN)  : 1.Copy_u8ChannelId        -->channel number
 *                   2.Add_pu8ChannelLevel     --> pointer to address of value carry
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadChannel(DioPinType Copy_u8ChannelId,pu8 Add_pu8ChannelLevel);


/********************************************************************************************
 * Name            : Dio_enuWritePort
 * Description     : Function responsible for writing port
 * Parameters(IN)  : 1.Copy_u8PortlId -->port number
 *                   2.Copy_u8Level     --> High or LOW
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuWritePort(DioPinType Copy_u8PortlId,DioPinType Copy_u8Level);

/********************************************************************************************
 * Name            : Dio_enuReadPort
 * Description     : Function responsible for reading port
 * Parameters(IN)  : 1.Copy_u8PortlId        -->port number
 *                   2.Add_pu8ChannelLevel     --> pointer to address of value carry
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadPort(DioPinType Copy_u8PortlId,pu8 Add_pu8PortLevel);

/********************************************************************************************
 * Name            : Dio_eneFlipChannel
 * Description     : Function responsible for flip pin
 * Parameters(IN)  : 1.Copy_u8ChannelId -->pin number
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_eneFlipChannel(DioPinType Copy_u8ChannelId);


#endif
