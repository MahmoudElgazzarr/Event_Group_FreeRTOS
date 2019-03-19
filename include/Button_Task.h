/*
 * Button_Task.h
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-040
 */

#ifndef INCLUDE_BUTTON_TASK_H_
#define INCLUDE_BUTTON_TASK_H_

extern volatile uint8_t Button_FLAG;
void Read_Button_Task(void);
void Switch_init_Task(void);

#endif /* INCLUDE_BUTTON_TASK_H_ */
