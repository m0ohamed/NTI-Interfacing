#ifndef GIE_H
#define GIE_H

#include "../../../Services/Lib/std_types.h"


#define GIE_ENABLE         1
#define GIE_DISABLE        0

typedef enum
{

			GIE_enuOK=0,
			GIE_enuWrongStatus
}GIE_tenuErrorStatus;

void  GIE_enuInit(void);

GIE_tenuErrorStatus GIE_enuSetResetGie(uint8 Copy_u8GieStatus);

#endif
