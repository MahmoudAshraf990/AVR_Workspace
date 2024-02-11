/*
 * RTOS_Interface.h
 *
 *  Created on: Sep 3, 2023
 *      Author: mahmo
 */

#ifndef RTOS_RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_RTOS_INTERFACE_H_


#define TASKS_NUMBER       4



typedef struct {
	u16  Periodicity;
	void(*TaskFun)(void);
}Task_t;


void RTOS_voidCreateTask(u8 A_u8Periorty, u16 A_u8Periodicty, void(*A_pvTaskFunc)(void));


void RTOS_voidStart();



void Scheduler(void);




#endif /* RTOS_RTOS_RTOS_INTERFACE_H_ */
