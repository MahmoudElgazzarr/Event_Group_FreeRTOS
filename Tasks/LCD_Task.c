/*
 * LCD_Task.c
 *
 *  Created on: Mar 19, 2019
 *      Author: AVE-LAP-040
 */

#include "LCD.h"
#include "LCD_Task.h"
#include "FreeRTOS.h"
#include "task.h"



void init_LCD_Task()
{
    while(1)
    {
    LCD_init();
    vTaskSuspend(NULL);
    }
}

void LCD_Display_Task()
{
    while(1)
    {
    vTaskDelay(250);
    LCD_displayChar('A');
    vTaskDelay(250);
    LCD_displayChar('B');
    vTaskDelay(250);
    }
}
