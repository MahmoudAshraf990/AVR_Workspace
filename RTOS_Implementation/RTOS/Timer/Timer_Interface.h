/*
 * Timer_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: mahmo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

void MTimer_voidTimerInit();

u8 MTimer0_u8CompareMatchCallback(void(*A_pvCallback)(void));





#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
