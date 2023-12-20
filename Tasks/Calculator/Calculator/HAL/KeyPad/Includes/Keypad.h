#ifndef KEYPAD_H
#define KEYPAD_H

#include "../../../Services/Lib/std_types.h"
#define KEYPAD_PATTERN1       0b00001110
#define KEYPAD_PATTERN2       0b00001101
#define KEYPAD_PATTERN3       0b00001011
#define KEYPAD_PATTERN4       0b00000111

#define KEYPAD_ROWS_PATTERN     0x0F
typedef enum
{

			Keypad_enuOK=0,
			Keypad_enuRowError,
			Keypad_enuColError,
			Keypad_enuPointerError
}Keypad_tenuErrorStatus;

Keypad_tenuErrorStatus Keypad_enuKeypadGetPressed(pu8 Add_pu8Key);

#endif
