#ifndef ADC_H
#define ADC_H
#include "../../../Services/Lib/std_types.h"


typedef enum{
	AREF,
	AVCC,
	Internal_Ref=3
}ADC_VoltageReference;


typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_Channel;

typedef enum
{
	Prescaler_2_0,
	Prescaler_2_1,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128
}ADC_Prescaler;

#define ADC_INTERRUPT_ENABL   1
#define ADC_INTERRUPT_DISABLE 0

#define ADC_START_CONVERSION    6
#define ADC_START_ENABLE        7
#define ADC_ADJUST_ENBLE        1
#define ADC_ADJUST_DISABLE      0
#define ADC_AUTO_TRIGGER_ENABLE     1
#define ADC_AUTO_TRIGGER_DISABLE    0


typedef struct
{
	ADC_VoltageReference Voltage;
	ADC_Channel Channel;
	ADC_Prescaler        Prescaler;
}ADC_ConfigType;

typedef enum
{
	ADC_enuOK,
	ADC_enuNullPtr,
	ADC_enuWrongChannel
}ADC_enuErrorStatus;

ADC_enuErrorStatus ADC_Init(const ADC_ConfigType* Config_Ptr);
void ADC_StartConcersion();
void ADC_Disable(void);
ADC_enuErrorStatus ADC_enuReadChannel(ADC_Channel Copy_u8Channel );
void ADC_CallBack(void(*ADC_CallPtr)(uint16));
#endif
