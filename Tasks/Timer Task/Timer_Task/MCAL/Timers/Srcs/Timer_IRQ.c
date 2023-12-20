#include "../Includes/Timer.h"

extern void (*G_Call_1)(void);
extern void (*G_Call_2)(void);
extern void (*G_Call_3)(void);


void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	(*G_Call_3)();
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	(*G_Call_3)();
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	(*G_Call_2)();
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	(*G_Call_2)();
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	(*G_Call_1)();
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	(*G_Call_1)();
}
