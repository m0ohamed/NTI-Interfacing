#include "../Includes/Buzzer.h"
#include "../Includes/Buzzer_Cfg.h"
#include "../Includes/Buzzer_Prv.h"
#include "../../../MCAL/Dio/Includes/Dio.h"
void Buzzer_ON(void)
{
	Dio_enuWriteChannel(Buzzer_PIN,DIO_LOGIC_HIGH);
}
void Buzzer_Off(void)
{
	Dio_enuWriteChannel(Buzzer_PIN,DIO_LOGIC_LOW);

}

