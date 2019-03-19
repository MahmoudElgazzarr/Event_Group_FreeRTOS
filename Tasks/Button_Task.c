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
volatile static uint8_t debounce_button1 = 0;

QueueHandle_t LED_Queue;
QueueHandle_t LCD_Queue;
void Read_Button0_Task(void)
{
    while(1)
    {
        if (Switch0_Read() == 1)
        {
            Button0_FLAG = 1;
            xQueueSend( LED_Queue ,&Button0_FLAG,5);
            xQueueSend( LCD_Queue ,&Button0_FLAG,5);
        }
        else
        {
            Button0_FLAG = 3;
            xQueueSend( LED_Queue ,&Button0_FLAG,5);
            xQueueSend( LCD_Queue ,&Button1_FLAG , 5);
        }
        vTaskDelay(20);
    }
}
void Read_Button1_Task(void)
{
    while(1)
    {
        if (Switch1_Read() == 1)
        {
            Button1_FLAG = 2;
            xQueueSend( LED_Queue ,&Button1_FLAG , 5);
            xQueueSend( LCD_Queue ,&Button1_FLAG , 5);
        }
        else
        {
            Button1_FLAG = 4;
            xQueueSend( LED_Queue ,&Button1_FLAG,5);
            xQueueSend( LCD_Queue ,&Button1_FLAG , 5);
        }
        vTaskDelay(20);
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
        vTaskDelay(20);
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
