#include "../Includes/ADC_Prv.h"
#include "../../../Services/Lib/std_types.h"
extern   void(*G_Ptr)(uint16 );
static uint16 x=0;
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	x=(ADC & 0x0FFF);
	(*G_Ptr)(x);
}
