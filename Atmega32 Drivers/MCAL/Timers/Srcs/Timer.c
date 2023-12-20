#include "../Includes/Timer.h"
#include "../../../Services/Lib/std_types.h"
#include "../../EXTI/Includes/EXTI.h"
#include "../Includes/Timer_Prv.h"
#include "../Includes/Timer_Cfg.h"
#include "../../../Services/Lib/common_macros.h"

void (*G_Call_1)(void)=Null_ptr;
void (*G_Call_2)(void)=Null_ptr;
void (*G_Call_3)(void)=Null_ptr;
Timer_Config* G_ConfigPtr=Null_ptr;

uint8  T0_Preload=0;
uint8  T2_Preload=0;
uint16 T1_Preload=0;

uint8  T0_CValue=0;
uint8  T2_CValue=0;
uint16 T1_CValue=0;
uint8 numberOfOV=0;
uint8 ICU_Counter=0;
uint8 ICU_G_PeriodTime=0;
uint8 ICU_G_OnTime=0;
uint8 ICU_G_DutyCycle=0;
ErrorStatus Timer_enuTimer_Init(const Timer_Config* ConfigPtr)
{
	uint8 ErrorStatus=enu_OK;
	if(ConfigPtr==Null_ptr)
	{
		ErrorStatus=Error_NullPtr;
	}
	else
	{
		G_ConfigPtr=ConfigPtr;
	}



	//timer0
	if(ConfigPtr->Timer==Timer0)
	{
		Timer0_Init();
	}
	else if(ConfigPtr->Timer==Timer1)
	{

		Timer1_Init();
	}
	else if(ConfigPtr->Timer==Timer2)
	{
		Timer2_Init();
	}
	return ErrorStatus;
}








void Timer0_Init(void)
{
	//timer0 OVF
	if(G_ConfigPtr->Mode==Normal)
	{
		SET_BIT(TCCR0,7);
		CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		TCCR0=(TCCR0 & 0xF8) | (TIMER_PRESCALER);
#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,0);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,0);
#endif

	}


	//Timer0 CTC
	else if(G_ConfigPtr->Mode==CTC)
	{
		SET_BIT(TCCR0,7);
		SET_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR0,4);
			CLEAR_BIT(TCCR0,5);
		}
		else if(G_ConfigPtr->OC==Toggle)
		{
			SET_BIT(TCCR0,4);
			CLEAR_BIT(TCCR0,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR0,5);
			CLEAR_BIT(TCCR0,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR0,5);
			SET_BIT(TCCR0,4);
		}

#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,1);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,1);
#endif
	}

	else if(G_ConfigPtr->Mode==PWM)
	{

		CLEAR_BIT(TCCR0,7);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR0,4);
			CLEAR_BIT(TCCR0,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR0,5);
			CLEAR_BIT(TCCR0,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR0,5);
			SET_BIT(TCCR0,4);
		}
	}
	else if(G_ConfigPtr->Mode==Phase_Correct)
	{

		CLEAR_BIT(TCCR0,7);
		SET_BIT(TCCR0,6);
		CLEAR_BIT(TCCR0,3);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR0,4);
			CLEAR_BIT(TCCR0,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR0,5);
			CLEAR_BIT(TCCR0,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR0,5);
			SET_BIT(TCCR0,4);
		}
	}
}
void Timer1_Init(void)
{
	if(G_ConfigPtr->Mode==Normal)
	{
		SET_BIT(TCCR1A,2);
		SET_BIT(TCCR1A,3);
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,2);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,2);
#endif
	}
	else if(G_ConfigPtr->Mode==CTC)
	{

		SET_BIT(TCCR1A,2);
		SET_BIT(TCCR1A,3);
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==Toggle)
		{
			SET_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		}
#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,4);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,4);
#endif
	}
	else if(G_ConfigPtr->Mode==PWM)
	{

		CLEAR_BIT(TCCR1A,2);
		CLEAR_BIT(TCCR1A,3);
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==Toggle)
		{
			SET_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		}
	}
	else if(G_ConfigPtr->Mode==Phase_Correct)
	{

		CLEAR_BIT(TCCR1A,2);
		CLEAR_BIT(TCCR1A,3);
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}

		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR1A,6);
			CLEAR_BIT(TCCR1A,7);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
		}
	}

}

void Timer2_Init(void)
{
	if(G_ConfigPtr->Mode==Normal)
	{
		SET_BIT(TCCR2,7);
		CLEAR_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,6);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,6);
#endif

	}


	//Timer0 CTC
	else if(G_ConfigPtr->Mode==CTC)
	{

		SET_BIT(TCCR2,7);
		SET_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR2,4);
			CLEAR_BIT(TCCR2,5);
		}
		else if(G_ConfigPtr->OC==Toggle)
		{
			SET_BIT(TCCR2,4);
			CLEAR_BIT(TCCR2,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR2,5);
			CLEAR_BIT(TCCR2,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR2,5);
			SET_BIT(TCCR2,4);
		}
#if(Timer_INTERRUPT==DISABLE_INTERRUPT)
		CLEAR_BIT(TIMSK,7);
#elif(Timer_INTERRUPT==ENABLE_INTERRUPT)
		SET_BIT(TIMSK,7);
#endif

	}
	else if(G_ConfigPtr->Mode==PWM)
	{

		CLEAR_BIT(TCCR2,7);
		SET_BIT(TCCR2,6);
		SET_BIT(TCCR2,3);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR2,4);
			CLEAR_BIT(TCCR2,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR2,5);
			CLEAR_BIT(TCCR2,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR2,5);
			SET_BIT(TCCR2,4);
		}
	}
	else if(G_ConfigPtr->Mode==Phase_Correct)
	{

		CLEAR_BIT(TCCR2,7);
		SET_BIT(TCCR2,6);
		CLEAR_BIT(TCCR2,3);
		if(G_ConfigPtr->OC==Disconnect)
		{
			CLEAR_BIT(TCCR2,4);
			CLEAR_BIT(TCCR2,5);
		}
		else if(G_ConfigPtr->OC==Clear)
		{
			SET_BIT(TCCR2,5);
			CLEAR_BIT(TCCR2,4);
		}
		else if(G_ConfigPtr->OC==set)
		{
			SET_BIT(TCCR2,5);
			SET_BIT(TCCR2,4);
		}
	}
}

void Timer_DeInit(Timer_Type Timer)
{
	switch(Timer)
	{
	case Timer0:
		TCCR0=0;
		break;
	case Timer1:
		TCCR1B=0;
		break;
	case Timer2:
		TCCR2=0;
		break;
	}
}

void Timer0_CallBack(void (*GPT0_Ptr)(void))
{
	if(GPT0_Ptr==Null_ptr)
	{
		//do nothing
	}
	else
	{
		G_Call_1=GPT0_Ptr;
	}
}
void Timer1_CallBack(void (*GPT1_Ptr)(void))
{
	if(GPT1_Ptr==Null_ptr)
	{
		//do nothing
	}
	else
	{
		G_Call_2=GPT1_Ptr;
	}
}
void Timer2_CallBack(void (*GPT2_Ptr)(void))
{
	if(GPT2_Ptr==Null_ptr)
	{
		//do nothing
	}
	else
	{
		G_Call_3=GPT2_Ptr;
	}
}


void Timer_Start(void)
{
	if(G_ConfigPtr->Timer==Timer0)
	{
		TCNT0=G_ConfigPtr->preload;
		OCR0=G_ConfigPtr->Compare_value;
		TCCR0 =(TCCR0 & 0xF8) | (TIMER_PRESCALER & 0x07);
	}
	else if(G_ConfigPtr->Timer==Timer1)
	{
		TCNT1=G_ConfigPtr->preload;
		OCR1A=G_ConfigPtr->Compare_value;
		TCCR1B=(TCCR1B & 0xF8) | (TIMER_PRESCALER & 0x07);


	}
	else if(G_ConfigPtr->Timer==Timer2)
	{
		TCNT2=G_ConfigPtr->preload;
		OCR2=G_ConfigPtr->Compare_value;
		TCCR2 =(TCCR2 & 0xF8) | (TIMER_PRESCALER & 0x07);

	}
}


void ICU_ResetTimer(void)
{
	if(G_ConfigPtr->Timer==Timer0)
	{
		TCNT0=0;
	}
	else if(G_ConfigPtr->Timer==Timer1)
	{
		TCNT1=0;

	}
	else if(G_ConfigPtr->Timer==Timer2)
	{
		TCNT2=0;
	}
}

void ICU_VidSWEnable(void)
{
	Timer_Config Config={0,0,Timer1,Normal,prescaler_1024,Disconnect};
	Timer_enuTimer_Init(&Config);
	EXTI_CallBack(ICU_CalculateDuty,EXTI_INT0_IRQ);
	EXTI_Enable(EXTI_INT0,EXTI_INT0_ENABLE_WITH_RAISING_EDGE);

}

void ICU_CalculateDuty(void)
{
	ICU_Counter++;
	if(ICU_Counter==1)
	{
		ICU_ResetTimer();
		Timer_Start();
	}
	if(ICU_Counter==2)
	{
		ICU_G_PeriodTime=TCNT1;
		EXTI_Enable(EXTI_INT0,EXTI_INT0_ENABLE_WITH_FALLING_EDGE);
		ICU_ResetTimer();
		Timer_Start();
	}
	if(ICU_Counter==3)
	{
		ICU_G_OnTime=TCNT1;
		ICU_Counter=0;
		EXTI_Disable(EXTI_INT0);
		Timer_DeInit(Timer2);
		ICU_G_DutyCycle=(ICU_G_OnTime/ICU_G_PeriodTime)*100;
	}


}


