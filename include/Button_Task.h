/*
 * Button_Task.h
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */

#ifndef INCLUDE_BUTTON_TASK_H_
#define INCLUDE_BUTTON_TASK_H_

#include "queue.h"
extern volatile uint8_t Button0_FLAG;
extern volatile uint8_t Button1_FLAG;
extern QueueHandle_t xQueue1;
void Read_Button0_Task(void);
void Read_Button1_Task(void);
void Switch_init_Task(void);

#endif /* INCLUDE_BUTTON_TASK_H_ */
