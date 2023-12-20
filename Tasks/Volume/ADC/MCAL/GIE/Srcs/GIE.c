#include "../Includes/GIE.h"
#include "../../../Services/Lib/common_macros.h"
#include "../Includes/GIE_Cfg.h"
#include "../Includes/GIE_Prv.h"

void  GIE_enuInit(void)
{
#if(GIE_MODE==GIE_ENABLE)
	SET_BIT(SREG,GIE_BIT);
#elif(GIE_MODE==GIE_DISABLE)
	CLEAR_BIT(SREG,GIE_BIT);
#endif
}



GIE_tenuErrorStatus GIE_enuSetResetGie(uint8 Copy_u8GieStatus)
{
	uint8 ErrorStatus=GIE_enuOK;
	switch(Copy_u8GieStatus)
	{
	case GIE_ENABLE:
		SET_BIT(SREG,GIE_BIT);
		break;
	case GIE_DISABLE:
		CLEAR_BIT(SREG,GIE_BIT);
		break;
default:
	ErrorStatus=GIE_enuWrongStatus;
	break;
	}
	return ErrorStatus;
}

