#include "../MCAL/Port/Includes/Port.h"
#include "../MCAL/Dio/Includes/Dio.h"
#include "../HAL/LCD/Includes/LCD.h"
#include "../HAL/KeyPad/Includes/Keypad.h"
#include "util/delay.h"
uint8 operators[1];

uint8 POS1=0,POS2=0;
uint8 flag1=1,flag2=0;
uint8 sign1=0,sign2=0;
sint32 Operand1=0,Operand2=0;
float32 Result1=0.0;

uint8 Key_Checker(uint8 key);
void number_key(uint32 key);
void Operat_key(uint32 key);
void sign_key(uint32 key);
void func_2Operand(uint32 key);

int main(void)
{
	PORT_Init();
	Lcd_Init();
	uint8 Key=0;
	Lcd_VidDisplayString((const pu8)"Welcome    ");
	_delay_ms(500);
	LCD_vidClrDisplay();

	while(1)
	{
		Keypad_enuKeypadGetPressed(&Key);
		if(Key !=0)
		{
			Key_Checker(Key);

		}

	}
}

uint8 Key_Checker(uint8 key)
{
	uint8 ret=0;


	if(key>='0' && key<='9')
	{
		number_key(key);
	}



	else if(key=='*' || key=='/')
	{
		Operat_key(key);
	}

	else if(key=='+' || key=='-')
	{
		sign_key(key);

	}

	if(key=='=')
	{
		if( flag2 ==1 && POS1 !=0 && POS2 !=0)
		{
			Lcd_VidDisplayChracter(key);
			func_2Operand(key);
			if(operators[0] !='/')
			Lcd_VidDisplayNumber(Result1);

		}
	}
	if(key== '#')
	{
		LCD_vidClrDisplay();
		Operand1=0;
		Operand2=0;
		sign1=0;
		sign2=0;
		POS1=0;
		POS2=0;
		flag1=1;
		flag2=0;
		Result1=0;
		operators[0]=0;
		key=0;

	}
	return ret;
}


void number_key(uint32 key)
{
	Lcd_VidDisplayChracter(key);
	key=key - '0';
	if(flag1==1)
	{
		Operand1=(Operand1 * 10)+key;
		POS1++;
	}
	else if(flag2==1)
	{
		Operand2=(Operand2 *10)+key;
		POS2++;
	}

}

void Operat_key(uint32 key)
{
	if(flag1==1 && POS1 !=0)
	{
		Lcd_VidDisplayChracter(key);
		flag1=0;
		flag2=1;
		operators[0]=key;

	}
	else if(flag2==1 && POS2 !=0)
	{

	}

}

void sign_key(uint32 key)
{
	if(flag1==1 && POS1==0)
	{
		Lcd_VidDisplayChracter(key);
		sign1=1;
	}
	else if(flag2==1 && POS2==0)
	{
		Lcd_VidDisplayChracter(key);
		sign2=1;
	}

	if(flag1==1 && POS1 !=0)
	{
		Lcd_VidDisplayChracter(key);
		flag1=0;
		flag2=1;
		operators[0]=key;
	}
	else if(flag2==1 && POS2 !=0)
	{

	}
	}

void func_2Operand(uint32 key)
{
	switch(operators[0])
	{
	case '+':
		if(sign1==0 && sign2==0)
		{
			Result1=Operand1+Operand2;
		}
		else if(sign1==1 && sign2==0)
		{

			if(Operand1>Operand2)
			{
				Result1=Operand1-Operand2;

				Lcd_VidDisplayChracter('-');
			}
			else if(Operand1<Operand2)
			{
				Result1=Operand2-Operand1;
			}
		}
		else if(sign1==0 && sign2==1)
		{

			if(Operand1<Operand2)
			{
				Lcd_VidDisplayChracter('-');
				Result1=Operand2-Operand1;
			}
			else if(Operand1>Operand2)
			{
				Result1=Operand1-Operand2;
			}

		}
		else if(sign1==1 && sign2==1)
		{


			Lcd_VidDisplayChracter('-');
			Result1=Operand1+Operand2;

		}


		break;
	case'-':
		if(sign1==0 && sign2==0)
		{
			if(Operand1<Operand2)
			{
				Lcd_VidDisplayChracter('-');
				Result1=Operand2-Operand1;
			}
			if(Operand1>Operand2)
			{
				Result1=Operand1-Operand2;
			}
		}
		else if(sign1==1 && sign2==0)
		{
			Lcd_VidDisplayChracter('-');
			Result1=Operand1+Operand2;
		}
		else if(sign1==0 && sign2==1)
		{
			Result1=Operand1+Operand2;
		}
		else if(sign1==1 && sign2==1)
		{

			if(Operand1<Operand2)
			{
				Lcd_VidDisplayChracter('-');
				Result1=Operand2-Operand1;
			}
			else if(Operand1>Operand2)
			{
				Result1=Operand1-Operand2;
			}

		}


		break;
	case '*':
		if(sign1==0 && sign2==0)
		{
			Result1=Operand1*Operand2;
		}
		else if(sign1==1 && sign2==0)
		{
			Lcd_VidDisplayChracter('-');
			Result1=Operand1*Operand2;
		}
		else if(sign1==0 && sign2==1)
		{
			Lcd_VidDisplayChracter('-');
			Result1=Operand1*Operand2;
		}
		else if(sign1==1 && sign2==1)
		{
			Result1=Operand1*Operand2;
		}
		break;
	case'/':
		if(sign1==0 && sign2==0)
		{
			Result1=(float32)Operand1/Operand2;
			LCD_VidDisplayFloat(Result1);

		}
		else if(sign1==1 && sign2==0)
		{
			Lcd_VidDisplayChracter('-');
			Result1=(float32)Operand1/Operand2;
			LCD_VidDisplayFloat(Result1);
		}
		else if(sign1==0 && sign2==1)
		{
			Lcd_VidDisplayChracter('-');
			Result1=(float32)Operand1/Operand2;
			LCD_VidDisplayFloat(Result1);

		}
		else if(sign1==1 && sign2==1)
		{
			Result1=(float32)Operand1/Operand2;
			LCD_VidDisplayFloat(Result1);

		}
		break;

	}
}
