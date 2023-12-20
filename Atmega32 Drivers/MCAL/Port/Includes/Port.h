/*********************************************************************************************
 * Name                 : Port.h
 * Description          : Port configuration
 * Author               : Mohamed khaled
 * *******************************************************************************************/

//Guard start
#ifndef PORT_H
#define PORT_H
#include "../../../Services/Lib/std_types.h"
#include "Port_Prv.h"

//PinType Definition
typedef  uint8  PortPinType;

/*********************************************************************************************/
							// Configurations Definition//
//Hint : USE IT IN Port_Cfg.h Port.c FILES
/********************************************************************************************/
#define PORT_LOGIC_LOW                    0
#define PORT_LOGIC_HIGH                   1

#define PORT_OUTPUT_HIGH                  2
#define PORT_OUTPUT_LOW			          3
#define PORT_INPUT_FLOATING               4
#define PORT_INPUT_PULLUP                 5
#define PORT_INPUT_Direction              6
#define PORT_OUTPUT_Direction             7


/*********************************************************************************************/
							//Errors check types //
/********************************************************************************************/
typedef enum{
	PORT_enuOK,
	PORT_enuPinError,
	PORT_enuPortError,
	PORT_enuModeError,
	Por_enuDirectionError
}PORT_tenuErrorStatus;

/*********************************************************************************************/
							//Functions Prototypes//
/********************************************************************************************/
/********************************************************************************************
 * Name            : PORT_Init
 * Description     : Function responsible for initializing all Pins with initial configurations
 * Parameters(IN)  : None
 * Parameters(OUT) : None
 *******************************************************************************************/
void PORT_Init(void);

/********************************************************************************************
 * Name            : PORT_enuSetPinMode
 * Description     : Function responsible for setting Pin Mode for a specific pin
 * Parameters(IN)  : 1.Copy_u8PinId   --> channel Number
 *                   2.Copy_u8PinMode --> Mode
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
PORT_tenuErrorStatus PORT_enuSetPinMode(PortPinType Copy_u8PinId,PortPinType Copy_u8PinMode  );


/********************************************************************************************
 * Name            : PORT_enuSetDirection
 * Description     : Function responsible for setting Pin Direction for a specific pin
 * Parameters(IN)  : 1.Copy_u8PinId   --> channel Number
 *                   2.Copy_u8PinDirection --> Direction
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
PORT_tenuErrorStatus PORT_enuSetDirection(PortPinType Copy_u8PinId,PortPinType Copy_u8PinDirection);


//guard end
#endif
