#include "../Includes/EXTI_Prv.h"

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTIINT_Ptr[EXTI_INT0_IRQ]();
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTIINT_Ptr[EXTI_INT1_IRQ]();
}


void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTIINT_Ptr[EXTI_INT2_IRQ]();
}

