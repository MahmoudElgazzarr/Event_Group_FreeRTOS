/*
 * Button_Task.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */
#include "FreeRTOS.h"
#include "Task.h"
#include "Switch_Driver.h"
#include "Button_Task.h"

volatile uint8_t Button_FLAG = 0;

void Read_Button_Task(void)
{
    while(1)
    {
        if (Switch0_Read() == 1)
        {
            Button_FLAG = 1;
        }
        else
        {
            Button_FLAG = 0;
        }
        vTaskDelay(50);
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
