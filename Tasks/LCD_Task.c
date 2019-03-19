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
#include "Button_Task.h"


static uint8_t *Kalam1 = "Button 1 :";
static uint8_t *Kalam2 = "Button 2 :";

void init_LCD_Task()
{
    while(1)
    {
    LCD_init();
    LCD_gotoRowColumn(FirstLine ,0);
    LCD_displayString(Kalam1);
    LCD_gotoRowColumn(SecondLine ,0);
    LCD_displayString(Kalam2);
    vTaskSuspend(NULL);
    }
}

void LCD_Display_Task()
{
    static uint8_t count1=0;
    static uint8_t count2=0;
    static uint8_t Value_Received_Button;
    while(1)
    {
    xQueueReceive( LCD_Queue, &Value_Received_Button, 0 );
    if ( Value_Received_Button ==  1)
    {
    count1++;
    if (count1 == 9)
      {
          count2 = 0;
      }
    LCD_clear();
    LCD_gotoRowColumn(FirstLine ,0);
    LCD_displayString(Kalam1);
    LCD_gotoRowColumn(SecondLine ,0);
    LCD_displayString(Kalam2);
    LCD_gotoRowColumn(FirstLine , 11);
    LCD_displayChar(count1 + '0');
    LCD_gotoRowColumn(SecondLine , 11);
    LCD_displayChar(count2 + '0');
    }

    if(Value_Received_Button ==  2)
    {
    count2++;
    if (count2 == 9)
          {
              count2 = 0;
          }
    LCD_clear();
    LCD_gotoRowColumn(FirstLine ,0);
    LCD_displayString(Kalam1);
    LCD_gotoRowColumn(SecondLine ,0);
    LCD_displayString(Kalam2);
    LCD_gotoRowColumn(FirstLine , 11);
    LCD_displayChar(count1 + '0');
    LCD_gotoRowColumn(SecondLine , 11);
    LCD_displayChar(count2 + '0');
    }
    vTaskDelay(5);
    }
}
