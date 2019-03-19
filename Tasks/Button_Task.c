/*
 * Button_Task.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */
#include "FreeRTOS.h"
#include "Task.h"
#include "queue.h"
#include "Switch_Driver.h"
#include "Button_Task.h"


volatile uint8_t Button0_FLAG = 0;
volatile uint8_t Button1_FLAG = 0;
QueueHandle_t xQueue1;

void Read_Button0_Task(void)
{
    while(1)
    {
        if (Switch0_Read() == 1)
        {
            Button0_FLAG = 1;
            xQueueSendToBack( xQueue1,&Button0_FLAG,5);
        }
        else
        {
            Button0_FLAG = 0;
            xQueueSendToBack( xQueue1,&Button0_FLAG,5);
        }
        vTaskDelay(50);
    }
}
void Read_Button1_Task(void)
{
    while(1)
    {
        if (Switch1_Read() == 1)
        {
            Button1_FLAG = 1;
            //xQueueSend( xQueue1,&Button1_FLAG,5);
        }
        else
        {
            Button1_FLAG = 0;
            //xQueueSendToBack( xQueue1,&Button1_FLAG,5);
        }
        vTaskDelay(50);
    }
}
void Switch_init_Task(void)
{
    while(1)
    {
        Switch_init();
        xQueue1 = xQueueCreate( 2 , sizeof( uint8_t) );
        vTaskSuspend(NULL);
    }
}
