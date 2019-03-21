
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
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
          the event group.  Clear the bits before exiting. */
          uxBits = xEventGroupWaitBits(
                    Buttons_EventGroup,   /* The event group being tested. */
                    BIT_0 | BIT_4, /* The bits within the event group to wait for. */
                    pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
                    pdFALSE,       /* Don't wait for both bits, either bit will do. */
                    10 );/* Wait a maximum of 10ms for either bit to be set. */
    if( (( uxBits & ( BIT_0 )) == ( BIT_0 )) && ((uxBits & ( BIT_4 )) != ( BIT_4 )) )
    {
        led1_on();
    }
    else if ((( uxBits & ( BIT_0 )) != ( BIT_0 )) && (( uxBits & ( BIT_4 )) == ( BIT_4 )))
    {
        led2_on();
    }
    else
    {
        led1_off();
        led2_off();
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
