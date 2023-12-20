/*********************************************************************************************
 * Name                 : Port_Cfg.h
 * Description          : Port configuration
 * Author               : Mohamed khaled
 * *******************************************************************************************/


/*********************************************************************************************/
							//File includes//
/********************************************************************************************/
#include "../Includes/Dio.h"
#include "../../../Services/Lib/common_macros.h"
#include "../../../Services/Lib/std_types.h"
#include "../Includes/Dio_Cfg.h"
#include "../Includes/Dio_Prv.h"


/********************************************************************************************
 * Name            : Dio_enuWriteChannel
 * Description     : Function responsible for writing high or low for output pins
 * Parameters(IN)  : 1.Copy_u8ChannelId -->channel number
 *                   2.Copy_u8Level     --> High or LOW
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuWriteChannel(DioPinType Copy_u8ChannelId,DioPinType Copy_u8Level)
{
	uint8 ErrorStatus=Dio_enuOK;
	uint8 PortIndex=0,PinIndex=0;
	PortIndex=(Copy_u8ChannelId/8);
	PinIndex=Copy_u8ChannelId%8;
	if(Copy_u8ChannelId>DIO_NUMBER_OF_PINS)
	{
		ErrorStatus=Dio_enuPinError;
	}
	if(PortIndex>DIO_NUMBER_OF_PORTS)
	{
		ErrorStatus=Dio_enuPortError;
	}
	if(Copy_u8Level !=DIO_LOGIC_HIGH ||Copy_u8Level !=DIO_LOGIC_LOW )
	{
		ErrorStatus=DIO_enuDirectionError;
	}
	switch(PortIndex)
	{
	case Dio_PORTA:
		if(GET_BIT(DDRA,PinIndex)==0)
			ErrorStatus=DIO_enuDirectionError;

		else if(Copy_u8Level==DIO_LOGIC_HIGH)
			SET_BIT(PORTA,PinIndex);

		else if(Copy_u8Level==DIO_LOGIC_LOW)
			CLEAR_BIT(PORTA,PinIndex);
		break;
	case Dio_PORTB:
		 if(GET_BIT(DDRB,PinIndex)==0)
			ErrorStatus=DIO_enuDirectionError;
		else if(Copy_u8Level==DIO_LOGIC_HIGH)
			SET_BIT(PORTB,PinIndex);
		else if(Copy_u8Level==DIO_LOGIC_LOW)
			CLEAR_BIT(PORTB,PinIndex);
		break;
	case Dio_PORTC:
		if(GET_BIT(DDRC,PinIndex)==0)
			ErrorStatus=DIO_enuDirectionError;
		else if(Copy_u8Level==DIO_LOGIC_HIGH)
			SET_BIT(PORTC,PinIndex);
		else if(Copy_u8Level==DIO_LOGIC_LOW)
			CLEAR_BIT(PORTC,PinIndex);
		break;
	case Dio_PORTD:
		if(GET_BIT(DDRD,PinIndex)==0)
			ErrorStatus=DIO_enuDirectionError;
		else if(Copy_u8Level==DIO_LOGIC_HIGH)
			SET_BIT(PORTD,PinIndex);
		else if(Copy_u8Level==DIO_LOGIC_LOW)
			CLEAR_BIT(PORTD,PinIndex);
		break;
	}
	return ErrorStatus;
}

/********************************************************************************************
 * Name            : Dio_enuReadChannel
 * Description     : Function responsible for reading high or low for input pins
 * Parameters(IN)  : 1.Copy_u8ChannelId        -->channel number
 *                   2.Add_pu8ChannelLevel     --> pointer to address of value carry
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadChannel(DioPinType Copy_u8ChannelId,pu8 Add_pu8ChannelLevel)
{
	uint8 ErrorStatus=Dio_enuOK;
		uint8 PortIndex=0,PinIndex=0;
		PortIndex=(Copy_u8ChannelId/8);
		PinIndex=Copy_u8ChannelId%8;
		if(Copy_u8ChannelId>DIO_NUMBER_OF_PINS)
		{
			ErrorStatus=Dio_enuPinError;
		}
		if(PortIndex>DIO_NUMBER_OF_PORTS)
		{
			ErrorStatus=Dio_enuPortError;
		}
		if( Add_pu8ChannelLevel ==Null_ptr)
		{
			ErrorStatus=DIO_enuNullPtr;
		}
		switch(PortIndex)
		{
		case Dio_PORTA:
			if(GET_BIT(DDRA,PinIndex)==1)
				ErrorStatus=DIO_enuDirectionError;
			else
			*Add_pu8ChannelLevel=GET_BIT(PINA,PinIndex);

			break;
		case Dio_PORTB:
			if(GET_BIT(DDRB,PinIndex)==1)
				ErrorStatus=DIO_enuDirectionError;
			else
			*Add_pu8ChannelLevel=GET_BIT(PINB,PinIndex);

			break;
		case Dio_PORTC:
			if(GET_BIT(DDRC,PinIndex)==1)
				ErrorStatus=DIO_enuDirectionError;
			else
			*Add_pu8ChannelLevel=GET_BIT(PINC,PinIndex);

			break;
		case Dio_PORTD:
			if(GET_BIT(DDRD,PinIndex)==1)
				ErrorStatus=DIO_enuDirectionError;
			else
			*Add_pu8ChannelLevel=GET_BIT(PIND,PinIndex);

			break;
		}
		return ErrorStatus;

}

/********************************************************************************************
 * Name            : Dio_enuWritePort
 * Description     : Function responsible for writing port
 * Parameters(IN)  : 1.Copy_u8PortlId -->port number
 *                   2.Copy_u8Level     --> High or LOW
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuWritePort(DioPinType Copy_u8PortlId,DioPinType Copy_u8Level)
{
	uint8 ErrorStatus=Dio_enuOK;
	if(Copy_u8PortlId>DIO_NUMBER_OF_PORTS)
			{
				ErrorStatus=Dio_enuPortError;
			}
	switch(Copy_u8PortlId)
			{
			case Dio_PORTA:
				ASSIGN_REG(PORTA,Copy_u8Level);

				break;
			case Dio_PORTB:
				ASSIGN_REG(PORTB,Copy_u8Level);

				break;
			case Dio_PORTC:
				ASSIGN_REG(PORTC,Copy_u8Level);


				break;
			case Dio_PORTD:
				ASSIGN_REG(PORTD,Copy_u8Level);

				break;
			}
			return ErrorStatus;
}


/********************************************************************************************
 * Name            : Dio_enuReadPort
 * Description     : Function responsible for reading port
 * Parameters(IN)  : 1.Copy_u8PortlId        -->port number
 *                   2.Add_pu8ChannelLevel     --> pointer to address of value carry
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_enuReadPort(DioPinType Copy_u8PortlId,pu8 Add_pu8PortLevel)
{
	uint8 ErrorStatus=Dio_enuOK;
		if(Copy_u8PortlId>DIO_NUMBER_OF_PORTS)
				{
					ErrorStatus=Dio_enuPortError;
				}
		if( Add_pu8PortLevel ==Null_ptr)
				{
					ErrorStatus=DIO_enuNullPtr;
				}
		switch(Copy_u8PortlId)
				{
				case Dio_PORTA:
					*Add_pu8PortLevel=PINA;
					break;
				case Dio_PORTB:
					*Add_pu8PortLevel=PINB;

					break;
				case Dio_PORTC:
					*Add_pu8PortLevel=PINC;


					break;
				case Dio_PORTD:
					*Add_pu8PortLevel=PIND;

					break;
				}
				return ErrorStatus;
}


/********************************************************************************************
 * Name            : Dio_eneFlipChannel
 * Description     : Function responsible for flip pin
 * Parameters(IN)  : 1.Copy_u8ChannelId -->pin number
 * Parameters(OUT) : value of enum type PORT_tenuErrorStatus
 *******************************************************************************************/
Dio_tenuErrorStatus Dio_eneFlipChannel(DioPinType Copy_u8ChannelId)
{
	uint8 ErrorStatus=Dio_enuOK;
			uint8 PortIndex=0,PinIndex=0;
			PortIndex=(Copy_u8ChannelId/8);
			PinIndex=Copy_u8ChannelId%8;
			if(Copy_u8ChannelId>DIO_NUMBER_OF_PINS)
			{
				ErrorStatus=Dio_enuPinError;
			}
			if(PortIndex>DIO_NUMBER_OF_PORTS)
			{
				ErrorStatus=Dio_enuPortError;
			}
			switch(PortIndex)
					{
					case Dio_PORTA:
						TOGGLE_BIT(DDRA,PinIndex);

						break;
					case Dio_PORTB:
						TOGGLE_BIT(DDRB,PinIndex);

						break;
					case Dio_PORTC:
						TOGGLE_BIT(DDRC,PinIndex);

						break;
					case Dio_PORTD:
						TOGGLE_BIT(DDRD,PinIndex);

						break;
					}
					return ErrorStatus;
}
