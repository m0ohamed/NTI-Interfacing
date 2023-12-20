/*********************************************************************************************
 * Name                 : Port_Cfg.h
 * Description          : Port configuration
 * Author               : Mohamed khaled
 * *******************************************************************************************/


/*********************************************************************************************/
							//File includes//
/********************************************************************************************/
#include "../Includes/Port.h"

#include "../../../Services/Lib/common_macros.h"
#include "../../../Services/Lib/std_types.h"
#include "../Includes/Port_Cfg.h"
#include "../Includes/Port_Prv.h"



/********************************************************************************************
 * Name            : PORT_Init
 * Description     : Function responsible for initializing all Pins with initial configurations
 * Parameters(IN)  : None
 * Parameters(OUT) : None
 *******************************************************************************************/
void PORT_Init(void)
{
//undefine all the configuration and define them as input or output only
#undef PORT_OUTPUT_HIGH
#undef PORT_OUTPUT_LOW
#undef PORT_INPUT_FLOATING
#undef PORT_INPUT_PULLUP


#define  PORT_OUTPUT_HIGH    1
#define  PORT_OUTPUT_LOW     1
#define  PORT_INPUT_FLOATING 0
#define  PORT_INPUT_PULLUP   0


//set the initial direction of all Pins by using ConC function like macro in std_types.h
	DDRA=CONC(PORT_PIN7_CONFIG,PORT_PIN6_CONFIG,PORT_PIN5_CONFIG,PORT_PIN4_CONFIG,PORT_PIN3_CONFIG,PORT_PIN2_CONFIG,PORT_PIN1_CONFIG,PORT_PIN0_CONFIG);
	DDRB=CONC(PORT_PIN15_CONFIG,PORT_PIN14_CONFIG,PORT_PIN13_CONFIG,PORT_PIN12_CONFIG,PORT_PIN11_CONFIG,PORT_PIN10_CONFIG,PORT_PIN9_CONFIG,PORT_PIN8_CONFIG);
	DDRC=CONC(PORT_PIN23_CONFIG,PORT_PIN22_CONFIG,PORT_PIN21_CONFIG,PORT_PIN20_CONFIG,PORT_PIN19_CONFIG,PORT_PIN18_CONFIG,PORT_PIN17_CONFIG,PORT_PIN16_CONFIG);
	DDRD=CONC(PORT_PIN31_CONFIG,PORT_PIN30_CONFIG,PORT_PIN29_CONFIG,PORT_PIN28_CONFIG,PORT_PIN27_CONFIG,PORT_PIN26_CONFIG,PORT_PIN25_CONFIG,PORT_PIN24_CONFIG);

//undefine all the configuration and define them as output high ,output low ,pull up only
#undef PORT_OUTPUT_HIGH
#undef PORT_OUTPUT_LOW
#undef PORT_INPUT_FLOATING
#undef PORT_INPUT_PULLUP

#define PORT_OUTPUT_HIGH                  1
#define PORT_OUTPUT_LOW			          0
#define PORT_INPUT_FLOATING               0
#define PORT_INPUT_PULLUP                 1


//set the initial mode of all Pins by using ConC function like macro in std_types.h
	PORTA=CONC(PORT_PIN7_CONFIG,PORT_PIN6_CONFIG,PORT_PIN5_CONFIG,PORT_PIN4_CONFIG,PORT_PIN3_CONFIG,PORT_PIN2_CONFIG,PORT_PIN1_CONFIG,PORT_PIN0_CONFIG);
	PORTB=CONC(PORT_PIN15_CONFIG,PORT_PIN14_CONFIG,PORT_PIN13_CONFIG,PORT_PIN12_CONFIG,PORT_PIN11_CONFIG,PORT_PIN10_CONFIG,PORT_PIN9_CONFIG,PORT_PIN8_CONFIG);
	PORTC=CONC(PORT_PIN23_CONFIG,PORT_PIN22_CONFIG,PORT_PIN21_CONFIG,PORT_PIN20_CONFIG,PORT_PIN19_CONFIG,PORT_PIN18_CONFIG,PORT_PIN17_CONFIG,PORT_PIN16_CONFIG);
	PORTD=CONC(PORT_PIN31_CONFIG,PORT_PIN30_CONFIG,PORT_PIN29_CONFIG,PORT_PIN28_CONFIG,PORT_PIN27_CONFIG,PORT_PIN26_CONFIG,PORT_PIN25_CONFIG,PORT_PIN24_CONFIG);

//reset the values of configuration to the initial values
#undef PORT_OUTPUT_HIGH
#undef PORT_OUTPUT_LOW
#undef PORT_INPUT_FLOATING
#undef PORT_INPUT_PULLUP

#define PORT_OUTPUT_HIGH                  2
#define PORT_OUTPUT_LOW			          3
#define PORT_INPUT_FLOATING               4
#define PORT_INPUT_PULLUP                 5
}




/********************************************************************************************
 * Name            : PORT_enuSetPinMode
 * Description     : Function responsible for setting Pin Mode for a specific pin
 * Parameters(IN)  : 1.Copy_u8PinId   --> channel Number
 *                   2.Copy_u8PinMode --> Mode
 * Parameters(OUT) : value of enum type PORT_tenuLOC_u8ErrorStatus
 *******************************************************************************************/
PORT_tenuErrorStatus PORT_enuSetPinMode(PortPinType Copy_u8PinId,PortPinType Copy_u8PinMode  )
{
	//local variable for Error status
	uint8 LOC_u8ErrorStatus=PORT_enuOK;
	//local variables for port and pin indexes
	uint8 PortIndex=0,PinIndex=0;

	//get the port index from the pin id
	PortIndex=(Copy_u8PinId/8);

	//get the pin index from the pin id ---pin index 0---7
	PinIndex=Copy_u8PinId%8;

	//check if pin id invalid
	if(Copy_u8PinId>PORT_NUMBER_OF_PINS)
	{
		LOC_u8ErrorStatus=PORT_enuPinError;
	}

	//check if port id invalid
	if(PortIndex>PORT_NUMBER_OF_PORTS)
	{
		LOC_u8ErrorStatus=PORT_enuPortError;
	}

	//check if the mode invalid
	if(Copy_u8PinMode>5 ||Copy_u8PinMode<2)
	{
		LOC_u8ErrorStatus=PORT_enuModeError;

	}

	//which Port
	switch(PortIndex)
	{
	//if Port A
	case PORT_A:
		//which mode ---PORT_OUTPUT_HIGH---PORT_OUTPUT_LOW----PORT_INPUT_FLOATING----PORT_INPUT_PULLUP
		switch(Copy_u8PinMode)
		{

		case PORT_OUTPUT_HIGH:
			//set output direction
			SET_BIT(DDRA,PinIndex);
			//set high value
			SET_BIT(PORTA,PinIndex);
			break;

		case PORT_OUTPUT_LOW:
			//set output direction
			SET_BIT(DDRA,PinIndex);
			//set LOW value
			CLEAR_BIT(PORTA,PinIndex);
			break;

		case PORT_INPUT_FLOATING:
			//set input direction
			CLEAR_BIT(DDRA,PinIndex);
			//set Low value
			CLEAR_BIT(PORTA,PinIndex);
			break;

		case PORT_INPUT_PULLUP:
			//set input direction
			CLEAR_BIT(DDRA,PinIndex);
			//set pullup
			SET_BIT(PORTA,PinIndex);
			break;
		}
		break;

		//if port B
		case PORT_B:

			//which mode ---PORT_OUTPUT_HIGH---PORT_OUTPUT_LOW----PORT_INPUT_FLOATING----PORT_INPUT_PULLUP
			switch(Copy_u8PinMode)
			{
			case PORT_OUTPUT_HIGH:
				//set output direction
				SET_BIT(DDRB,PinIndex);
				SET_BIT(PORTB,PinIndex);
				break;
			case PORT_OUTPUT_LOW:
				SET_BIT(DDRB,PinIndex);
				CLEAR_BIT(PORTB,PinIndex);
				break;
			case PORT_INPUT_FLOATING:
				CLEAR_BIT(DDRB,PinIndex);
				CLEAR_BIT(PORTB,PinIndex);

				break;
			case PORT_INPUT_PULLUP:
				CLEAR_BIT(DDRB,PinIndex);
				SET_BIT(PORTB,PinIndex);

				break;
			}
			break;

			case PORT_C:
				//which mode ---PORT_OUTPUT_HIGH---PORT_OUTPUT_LOW----PORT_INPUT_FLOATING----PORT_INPUT_PULLUP
				switch(Copy_u8PinMode)
				{
				case PORT_OUTPUT_HIGH:
					//set output direction
					SET_BIT(DDRC,PinIndex);
					SET_BIT(PORTC,PinIndex);
					break;
				case PORT_OUTPUT_LOW:
					SET_BIT(DDRC,PinIndex);
					CLEAR_BIT(PORTC,PinIndex);
					break;
				case PORT_INPUT_FLOATING:
					CLEAR_BIT(DDRC,PinIndex);
					CLEAR_BIT(PORTC,PinIndex);

					break;
				case PORT_INPUT_PULLUP:
					CLEAR_BIT(DDRC,PinIndex);
					SET_BIT(PORTC,PinIndex);

					break;
				}
				break;

				case PORT_D:
					//which mode ---PORT_OUTPUT_HIGH---PORT_OUTPUT_LOW----PORT_INPUT_FLOATING----PORT_INPUT_PULLUP
					switch(Copy_u8PinMode)
					{
					case PORT_OUTPUT_HIGH:
						//set output direction
						SET_BIT(DDRD,PinIndex);
						SET_BIT(PORTD,PinIndex);
						break;
					case PORT_OUTPUT_LOW:
						SET_BIT(DDRD,PinIndex);
						CLEAR_BIT(PORTD,PinIndex);
						break;
					case PORT_INPUT_FLOATING:
						CLEAR_BIT(DDRD,PinIndex);
						CLEAR_BIT(PORTD,PinIndex);

						break;
					case PORT_INPUT_PULLUP:
						CLEAR_BIT(DDRD,PinIndex);
						SET_BIT(PORTD,PinIndex);

						break;
					}
					break;

	}
	//return Error Status
	return LOC_u8ErrorStatus;

}




/********************************************************************************************
 * Name            : PORT_enuSetDirection
 * Description     : Function responsible for setting Pin Direction for a specific pin
 * Parameters(IN)  : 1.Copy_u8PinId   --> channel Number
 *                   2.Copy_u8PinDirection --> Direction
 * Parameters(OUT) : value of enum type PORT_tenuLOC_u8ErrorStatus
 *******************************************************************************************/

PORT_tenuErrorStatus PORT_enuSetDirection(PortPinType Copy_u8PinId,PortPinType Copy_u8PinDirection)
{
	//local variable for Error status
	uint8 LOC_u8ErrorStatus=PORT_enuOK;

	uint8 PortIndex=0,PinIndex=0;

	PortIndex=(Copy_u8PinId/8);

	PinIndex=Copy_u8PinId%8;


	if(Copy_u8PinId>PORT_NUMBER_OF_PINS)
	{
		LOC_u8ErrorStatus=PORT_enuPinError;
	}

	if(PortIndex>PORT_NUMBER_OF_PORTS)
	{
		LOC_u8ErrorStatus=PORT_enuPortError;
	}

	if((Copy_u8PinDirection != PORT_INPUT_Direction) ||(Copy_u8PinDirection != PORT_OUTPUT_Direction))
	{
		LOC_u8ErrorStatus=Por_enuDirectionError;

	}


	switch(PortIndex)
	{

	case PORT_A:

		switch(Copy_u8PinDirection)
		{
		case PORT_INPUT_Direction:
			CLEAR_BIT(DDRA,PinIndex);
			break;
		case PORT_OUTPUT_Direction:
			SET_BIT(PORTA,PinIndex);
			break;
		}
		break;

		case PORT_B:

			switch(Copy_u8PinDirection)
			{
			case PORT_INPUT_Direction:
				CLEAR_BIT(DDRB,PinIndex);
				break;
			case PORT_OUTPUT_Direction:
				SET_BIT(PORTB,PinIndex);
				break;
			}

			break;

			case PORT_C:

				switch(Copy_u8PinDirection)
				{
				case PORT_INPUT_Direction:
					CLEAR_BIT(DDRC,PinIndex);
					break;
				case PORT_OUTPUT_Direction:
					SET_BIT(PORTC,PinIndex);
					break;
				}
				break;

				case PORT_D:

					switch(Copy_u8PinDirection)
					{
					case PORT_INPUT_Direction:
						CLEAR_BIT(DDRD,PinIndex);
						break;
					case PORT_OUTPUT_Direction:
						SET_BIT(PORTD,PinIndex);
						break;
					}
					break;

	}

	return LOC_u8ErrorStatus;
}


