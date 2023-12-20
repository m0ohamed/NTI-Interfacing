#include "../MCAL/Port.h"
#include "../MCAL/Dio.h"
#include "../Services/Platform.h"
#include "../Services/std_types.h"
#include "../MCAL/GIE.h"
#include "../HAL/EXTI.h"
#include "util/delay.h"
#include "avr/interrupt.h"
uint8 Sec1=0,Sec2=0;
uint8 Min1=0,Min2=0;
uint8 Flag=0;

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


void ResetFunction(void)
{
	Sec1=0;
	Sec2=0;
	Min1=0;
	Min2=0;
}
void ResumeFunction(void)
{
	Flag=1;
}

void StopFunction(void)
{
	Flag=0;
}



void _7Segments_Init(void)
{
	PORT_Init();
	GIE_enuInit();
	EXTI_Init();


}
