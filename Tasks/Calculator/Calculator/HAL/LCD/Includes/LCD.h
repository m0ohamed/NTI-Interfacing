#ifndef LCD_H
#define LCD_H
#include "../../../Services/Lib/std_types.h"

/* LCD Commands */
#define LCD_CLEAR_DISPLAY					0x01
#define LCD_CURSOR_HOME					    0x02
#define LCD_ENTRY_MODE_CURSOR_INCREMENT	    0x06
#define LCD_DISPLAY_ON_CURSOR_ON_NO_BLINK	0x0E
#define LCD_4_BIT_MODE_SELECTION			0x28
#define LCD_8_BIT_MODE_SELECTION			0x38
#define LCD_DISPLAY_SHIFT_LEFT				0x18
#define LCD_DISPLAY_SHIFT_RIGHT			    0x1C
#define LCD_SET_CGRAM_ADDR_CMD				0x40
#define LCD_SET_DDRAM_ADDR_CMD				0x80

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
/* The most common command for LCD. */
#define LCD_4_BIT_1_LINE_SET_COMMAND                   (0X20)
#define LCD_4_BIT_2_LINES_INIT1_COMMAND                (0X33)
#define LCD_4_BIT_2_LINES_INIT2_COMMAND                (0X32)
#define LCD_4_BIT_2_LINES_SET_COMMAND                  (0X28)
#define LCD_8_BIT_1_LINE_SET_COMMAND                   (0X30)
#define LCD_8_BIT_2_LINES_SET_COMMAND                  (0X38)
#define LCD_CLEAR_SCREEN_COMMAND                       (0X01)
#define LCD_RETURN_HOME_COMMAND                        (0X02)
#define LCD_CURSOR_OFF_COMMAND                         (0X0C)


/*********************************************************************/
                         //Functions Prototypes
/*********************************************************************/

void Lcd_Init(void);
void Lcd_VidSendCommand(uint8 Copy_u8Command);
void Lcd_VidDisplayChracter(uint8 Copy_u8Command);
void Lcd_VidGoToXY(uint8 Copy_u8Row,uint8 Copy_u8Column);
void Lcd_VidDisplayString(const pu8 Add_pu8String );
void Lcd_VidDisplayNumber(uint32 Copy_u64Num );
void LCD_vidClrDisplay(void);
void LCD_VidDisplayFloat(float32 Copy_u32Num);

#endif
