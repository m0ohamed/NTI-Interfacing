#include "7Segments.h"
int main(void)
{
	_7Segments_Init();
	EXTI_CallBack(ResetFunction,EXTI_INT0_IRQ);
	EXTI_CallBack(ResumeFunction,EXTI_INT1_IRQ);
	EXTI_CallBack(StopFunction,EXTI_INT2_IRQ);

	while(1)
	{
		Dio_enuWritePort(P_PORTA,0x01);
		Dio_enuWritePort(P_PORTC,Sec1);
		_delay_ms(1);
		Dio_enuWritePort(P_PORTA,0x02);
		Dio_enuWritePort(P_PORTC,Sec2);
		_delay_ms(1);
		Dio_enuWritePort(P_PORTA,0x04);
		Dio_enuWritePort(P_PORTC,Min1);
		_delay_ms(1);
		Dio_enuWritePort(P_PORTA,0x08);
		Dio_enuWritePort(P_PORTC,Min2);
		_delay_ms(1);

		if(Flag==0)
		{
			Second_Delay();
	    }
	}
}
