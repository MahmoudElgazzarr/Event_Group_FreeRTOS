



#include <FreeRTOS.h>
#include <stdint.h>
#include "task.h"
#include "LEDS.h"
#include "led_task.h"
#include "Button_Task.h"

void LED_Task()
{
    while(1)
    {
    if( Button0_FLAG == 1)
    {
        led1_on();
    }
    else if (Button1_FLAG == 1)
    {
        led2_on();
    }
    else
    {
        led1_off();
    }
    vTaskDelay(50);
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
