#include "../MCAL/Port.h"
#include "../MCAL/Dio.h"
#include "../Services/Platform.h"
#include "../Services/std_types.h"

#include "util/delay.h"

//Global Variables
uint8 Sec1=0,Sec2=0;
uint8 Min1=0,Min2=0;
uint8 Flag=0;
uint8 sw1,sw2,sw3;

//Function to count the Stop watch Time
void Time_Counter(void)
{
	Sec1++;
	if(Sec1==10)
	{
		Sec1=0;
		Sec2++;
	}
	if(Sec2==6)
	{
		Sec2=0;
		Min1++;
	}
	if(Min1==10)
	{
		Min1=0;
		Min2++;
	}
	if(Min2==6)
	{
		Sec1=0;
		Sec2=0;
		Min1=0;
		Min2=0;
	}
}


//Function to count second
void Second_Delay(void)
{
	static uint64 x=0;
	x++;
	_delay_ms(1);
	if(x==25)
	{
		Time_Counter();
		x=0;
	}
}



//Function to check the push buttons
void SW()
{
	Dio_enuReadChannel(PIN26,&sw1);
	Dio_enuReadChannel(PIN27,&sw2);
	Dio_enuReadChannel(PIN10,&sw3);
	if(sw1 ==0)
	{
		Sec1=0;
		Sec2=0;
		Min1=0;
		Min2=0;
	}
	if(sw2==0)
	{
		Flag=1;
	}
	if(sw3==0)
	{
		Flag=0;
	}

}


//Initialization of 7segments pins
void _7Segments_Init(void)
{
	PORT_Init();
	PORT_enuSetDirection(PIN26,PORT_INPUT_Direction);
	PORT_enuSetDirection(PIN27,PORT_INPUT_Direction);
	PORT_enuSetDirection(PIN10,PORT_INPUT_Direction);
	PORT_enuSetPinMode(PIN26,PORT_INPUT_PULLUP);
	PORT_enuSetPinMode(PIN27,PORT_INPUT_PULLUP);
	PORT_enuSetPinMode(PIN10,PORT_INPUT_PULLUP);


}
