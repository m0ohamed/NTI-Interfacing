#include "../Includes/WDT.h"

#include "../Includes/WDT_Prv.h"
#include "../../../Services/Lib/common_macros.h"
void WDT_VidInit(void)
{
	WDTCR=0;
}

void WDT_VidEnable(WDT_Prescaler WDT_SleepTime)
{
	WDTCR =(WDTCR & 0xF8) | (WDT_SleepTime & 0x07);
	SET_BIT(WDTCR,3);
}

void WDT_VidDisable(void)
{
	WDTCR |=(1<<3) | (1<<4);
	WDTCR =0;
}
