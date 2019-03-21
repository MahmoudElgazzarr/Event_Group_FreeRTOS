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


static uint8_t *Kalam1 = "Button 0 Pressed :";
static uint8_t *Kalam2 = "Button 1 Pressed :";
static uint8_t *Kalam3 = "Welcome";
static uint8_t *Kalam4 = "Two Button Pressed";
static uint8_t *Kalam5 = "No Button Pressed";

void init_LCD_Task()
{
    while(1)
    {
    LCD_init();
    LCD_gotoRowColumn(FirstLine ,0);
    LCD_displayString(Kalam3);
    vTaskSuspend(NULL);
    }
}

void LCD_Display_Task()
{
    /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
              the event group.  Clear the bits before exiting. */
              uxBits = xEventGroupWaitBits(
                        Buttons_EventGroup,   /* The event group being tested. */
                        BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                        pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                        pdFALSE,       /* Don't wait for both bits, either bit will do. */
                        10 );/* Wait a maximum of 10ms for either bit to be set. */
    while(1)
    {
    if ((( uxBits & ( BIT_0 )) == ( BIT_0 )) && ((uxBits & ( BIT_4 )) != ( BIT_4 )))
    {
    LCD_clear();
    LCD_gotoRowColumn(FirstLine ,0);
    LCD_displayString(Kalam1);
    }

    else if((( uxBits & ( BIT_0 )) != ( BIT_0 )) && (( uxBits & ( BIT_4 )) == ( BIT_4 )))
    {
    LCD_clear();
    LCD_gotoRowColumn(SecondLine ,0);
    LCD_displayString(Kalam2);
    }
    else if((( uxBits & ( BIT_0 )) == ( BIT_0 )) && ((uxBits & ( BIT_4 )) == ( BIT_4 )))
    {
        LCD_clear();
        LCD_gotoRowColumn(FirstLine ,0);
        LCD_displayString(Kalam4);
    }
    else
    {
        LCD_clear();
        LCD_gotoRowColumn(FirstLine ,0);
        LCD_displayString(Kalam5);
    }
    vTaskDelay(30);
    }
}
