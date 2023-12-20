#ifndef LCD_CFG_H
#define LCD_CFG_H

#include "../../../Services/Lib/Platform.h"
#define LCD_FOUR_BIT_MODE      0
#define LCD_EIGHT_BIT_MODE     1

#define LCD_DATA_MODE   LCD_FOUR_BIT_MODE


#define LCD_RS_PORT_NUM     PORTA
#define LCD_RS_PIN_NUM      PIN16


#define LCD_E_PORT_NUM      PORTA
#define LCD_E_PIN_NUM       PIN17

#define LCD_RW_PORT_NUM      PORTA
#define LCD_RW_PIN_NUM       PIN0

#if(LCD_DATA_MODE==LCD_FOUR_BIT_MODE)
#define LCD_DATA_PIN4    PIN18
#define LCD_DATA_PIN5    PIN19
#define LCD_DATA_PIN6    PIN20
#define LCD_DATA_PIN7    PIN21
#endif
#if(LCD_DATA_MODE==LCD_EIGHT_BIT_MODE)
#define LCD_DATA_PIN0    PIN0
#define LCD_DATA_PIN1    PIN0
#define LCD_DATA_PIN2    PIN0
#define LCD_DATA_PIN3    PIN0
#define LCD_DATA_PIN4    PIN0
#define LCD_DATA_PIN5    PIN0
#define LCD_DATA_PIN6    PIN0
#define LCD_DATA_PIN7    PIN0
#endif



#endif
