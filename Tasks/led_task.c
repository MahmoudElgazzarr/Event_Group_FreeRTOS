
#include <FreeRTOS.h>
#include <stdint.h>
#include "task.h"
#include "LEDS.h"
#include "led_task.h"
#include "Button_Task.h"

void LED_Task()
{
    static uint8_t ulValReceived;
    while(1)
    {
      xQueueReceive( LED_Queue, &ulValReceived, 5 );
    if( (ulValReceived == 2) || (ulValReceived == 1) )
    {
        led1_on();
    }
    else
    {
        led1_off();
    }
    vTaskDelay(10);
    }
}
void LEDS_Task_init()
{
    while(1)
    {
    LEDS_PORT_init();
    led1_init();
    led2_init();
    led3_init();
    vTaskSuspend(NULL);
    }
}
