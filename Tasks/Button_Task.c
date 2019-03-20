/*
 * Button_Task.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */
#include "FreeRTOS.h"
#include "Task.h"
#include "event_groups.h"
#include "Switch_Driver.h"
#include "Button_Task.h"


EventGroupHandle_t Buttons_EventGroup;
EventBits_t uxBits;

volatile uint8_t Button0_FLAG = 0;
volatile uint8_t Button1_FLAG = 0;

volatile static uint8_t debounce_button0 = 0;
volatile static uint8_t debounce_button1 = 0;

//static uint8_t Button0_State = 0;
static uint8_t Button1_State = 0;

/*static uint8_t previous1_State = 0;*/

void Read_Button0_Task(void)
{
    uint8_t Button0_State = 0;
    /*uint8_t previous0_State = 0;*/
    while(1)
    {
        Button0_State = debounce_button0;
        /*if (Button0_State && !previous0_State )*/
        if (Button0_State == 5)
        {
            /* Set bit 0 in xEventGroup. */
              uxBits = xEventGroupSetBits(Buttons_EventGroup ,BIT_0);/* The bits being set. */
        }

        vTaskDelay(25);
    }
}
void Read_Button1_Task(void)
{
    while(1)
    {
        Button1_State = debounce_button1;
        /*if (Button1_State && !previous1_State)*/
        if (Button1_State == 5)
        {
            /* Set bit 4 in xEventGroup. */
              uxBits = xEventGroupSetBits(Buttons_EventGroup ,BIT_4);/* The bits being set. */
        }
        /*previous1_State = Button1_State;*/
        vTaskDelay(25);
    }
}
void debounce_Task(void)
{
    while(1)
    {
        if (Switch1_Read() == 1)
        {
            if(debounce_button1 == 5)

                {
                    debounce_button1 = 5;
                }
            else
                {
                    debounce_button1++;
                }
        }
        else
        {
            if(debounce_button1 == 0)
            {
                debounce_button1 = 0;
            }
            else
            {
                debounce_button1--;
            }
        }
        if (Switch0_Read() == 1)
               {
                   if(debounce_button0 == 5)

                       {
                           debounce_button0 = 5;
                       }
                   else
                       {
                           debounce_button0++;
                       }
               }
               else
               {
                   if(debounce_button0 == 0)
                   {
                       debounce_button0 = 0;
                   }
                   else
                   {
                       debounce_button0--;
                   }
               }
        vTaskDelay(5);
    }
}
void Switch_init_Task(void)
{
    while(1)
    {
        Switch_init();
        vTaskSuspend(NULL);
    }
}
