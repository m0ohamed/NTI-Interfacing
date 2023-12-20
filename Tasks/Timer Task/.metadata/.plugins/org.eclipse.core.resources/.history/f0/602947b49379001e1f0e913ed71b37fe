#ifndef EXTI_H
#define EXTI_H


#include "EXTI_Prv.h"

#define EXTI_INT0_DISABLE                        0
#define EXTI_INT0_ENABLE_WITH_LOW_MODE           0xFC
#define EXTI_INT0_ENABLE_WITH_LOGICAL_CHANGE     1
#define EXTI_INT0_ENABLE_WITH_FALLING_EDGE       2
#define EXTI_INT0_ENABLE_WITH_RAISING_EDGE       3


#define EXTI_INT1_DISABLE                        0
#define EXTI_INT1_ENABLE_WITH_LOW_MODE           0xF3
#define EXTI_INT1_ENABLE_WITH_LOGICAL_CHANGE     1
#define EXTI_INT1_ENABLE_WITH_FALLING_EDGE       2
#define EXTI_INT1_ENABLE_WITH_RAISING_EDGE       3


#define EXTI_INT2_DISABLE                        0
#define EXTI_INT2_ENABLE_WITH_FALLING_EDGE       0XBF
#define EXTI_INT2_ENABLE_WITH_RAISING_EDGE       0x40

#define EXTI_INT0                                6
#define EXTI_INT1                                7
#define EXTI_INT2                                5



typedef enum
{

			EXTI_enuOK=0,
			EXTI_enuWrongINT,
			EXTI_enuWrongMode,
			EXTI_NullPtr
}EXTI_tenuErrorStatus;

void EXTI_Init(void);

EXTI_tenuErrorStatus EXTI_Disable(uint8 Copy_u8INTNum);

EXTI_tenuErrorStatus EXTI_Enable(uint8 Copy_u8INTNum,uint8 Copy_u8INTMode);

EXTI_tenuErrorStatus EXTI_CallBack(void(*Func_Ptr)(void),uint8 Copy_u8Index);
#endif
