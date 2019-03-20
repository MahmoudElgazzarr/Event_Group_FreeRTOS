/*
 * Button_Task.h
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */

#ifndef INCLUDE_BUTTON_TASK_H_
#define INCLUDE_BUTTON_TASK_H_

#include "event_groups.h"

#define BIT_0   ( 1 << 0 )
#define BIT_4   ( 1 << 4 )

extern volatile uint8_t Button0_FLAG;
extern volatile uint8_t Button1_FLAG;
EventGroupHandle_t Buttons_EventGroup;
extern EventBits_t uxBits;

void Read_Button0_Task(void);
void Read_Button1_Task(void);
void Switch_init_Task(void);
void debounce_Task(void);

#endif /* INCLUDE_BUTTON_TASK_H_ */
