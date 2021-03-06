#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"



#define FirstLine 0
#define SecondLine 1
#define FirstLineADD  0x80
#define SecondLineADD 0xC0

void LCD_init(void);
void LCD_sendCommand(uint8_t cmd);
void LCD_displayChar(uint8_t c);
void LCD_displayString(uint8_t* kalam);
void LCD_clear();
void LCD_gotoRowColumn(uint8_t ROW,uint8_t COL);
void LCD_AllowSpecialCharacters(void);

#define BYTE 8
#define BYTE_minus1 7
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7


#define NUMBER4_ToShiftToUpperBits 4


#endif /* LCD_H_ */
