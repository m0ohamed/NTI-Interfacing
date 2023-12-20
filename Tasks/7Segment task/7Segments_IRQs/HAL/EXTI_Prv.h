#ifndef EXTI_PRV_H
#define EXTI_PRV_H

#include "../Services/std_types.h"


#define  SREG              *((volatile uint8*)0x5F)
#define  MCUCR             *((volatile uint8*)0x55)
#define  GICR              *((volatile uint8*)0x5B)
#define  GIFR              *((volatile uint8*)0x5A)
#define MCUCSR             *((volatile uint8*)0x54)

void(*EXTIINT_Ptr[3])(void);
#define EXTI_INT0_IRQ     0
#define EXTI_INT1_IRQ     1
#define EXTI_INT2_IRQ     2


#endif
