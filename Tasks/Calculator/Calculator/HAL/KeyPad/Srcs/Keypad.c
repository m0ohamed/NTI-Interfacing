#include "../Includes/Keypad.h"

#include "util/delay.h"

#include "../../../MCAL/Dio/Includes/Dio.h"
#include "../../../Services/Lib/common_macros.h"
#include "../../../Services/Lib/Platform.h"
#include "../../../Services/Lib/std_types.h"
#include "../Includes/Keypad_Cfg.h"
#include "../Includes/Keypad_Prv.h"


 void Keypad_VidWritePins(uint8 LOC_u8Pattern)
{
	Dio_enuWriteChannel(KEYPAD_ROW1,GET_BIT(LOC_u8Pattern,0));
	Dio_enuWriteChannel(KEYPAD_ROW2,GET_BIT(LOC_u8Pattern,1));
	Dio_enuWriteChannel(KEYPAD_ROW3,GET_BIT(LOC_u8Pattern,2));
	Dio_enuWriteChannel(KEYPAD_ROW4,GET_BIT(LOC_u8Pattern,3));
}

 void Keypad_VidReadPins(pu8 Add_LOC_u8PinsReading)
{
	uint8 LOC_u8Temp=0x00;
	*Add_LOC_u8PinsReading=0x00;
	uint8 LOC_u8ErrorStatus=Keypad_enuOK;
	if(Add_LOC_u8PinsReading==Null_ptr)
	{
		LOC_u8ErrorStatus=Keypad_enuPointerError;

	}
#if(KEYPAD_TYPE==KEYPAD_4x4)
	Dio_enuReadChannel(KEYPAD_COL1,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<0;
	Dio_enuReadChannel(KEYPAD_COL2,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<1;
	Dio_enuReadChannel(KEYPAD_COL3,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<2;
	Dio_enuReadChannel(KEYPAD_COL4,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<3;
#elif(KEYPAD_TYPE==KEYPAD_4x3)
	Dio_enuReadChannel(KEYPAD_COL1,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<0;
	Dio_enuReadChannel(KEYPAD_COL2,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<1;
	Dio_enuReadChannel(KEYPAD_COL3,&LOC_u8Temp);
	*Add_LOC_u8PinsReading |=LOC_u8Temp<<2;
#endif
}



Keypad_tenuErrorStatus Keypad_enuKeypadGetPressed(pu8 Add_pu8Key)
{
	uint8 LOC_u8ErrorStatus=Keypad_enuOK;
	uint8 LOC_u8Iterator=0;
	uint8 LOC_u8ColPattern=0;
	*Add_pu8Key=0;
	if(Add_pu8Key==Null_ptr)
	{
		LOC_u8ErrorStatus=Keypad_enuPointerError;

	}

	for(LOC_u8Iterator=0;LOC_u8Iterator<KEYPAD_NUMBER_OF_ROWS;LOC_u8Iterator++)
	{
		Keypad_VidWritePins(TGLWithOUTASSIGN(KEYPAD_ROWS_PATTERN,LOC_u8Iterator));
		Keypad_VidReadPins(&LOC_u8ColPattern);
		switch(LOC_u8ColPattern)
		{
		case KEYPAD_PATTERN1:
			*Add_pu8Key=Symbols[(LOC_u8Iterator*KEYPAD_NUMBER_OF_ROWS)+0];
			break;
		case KEYPAD_PATTERN2:
			*Add_pu8Key=Symbols[(LOC_u8Iterator*KEYPAD_NUMBER_OF_ROWS)+1];

					break;
		case KEYPAD_PATTERN3:
			*Add_pu8Key=Symbols[(LOC_u8Iterator*KEYPAD_NUMBER_OF_ROWS)+2];

			break;
		case KEYPAD_PATTERN4:
			*Add_pu8Key=Symbols[(LOC_u8Iterator*KEYPAD_NUMBER_OF_ROWS)+3];

			break;

		}
		if(*Add_pu8Key !=0)
			break;
	}
_delay_ms(200);
	return LOC_u8ErrorStatus;
}
