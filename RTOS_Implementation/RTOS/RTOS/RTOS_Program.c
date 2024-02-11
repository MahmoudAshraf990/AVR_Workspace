
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../Timer/Timer_Interface.h"
#include"../GIE/GIE_Interface.h"
#include"RTOS_Interface.h"


Task_t SystemTasks[TASKS_NUMBER] = {{NULL}};


u16 G_u16Counter=0;


void RTOS_voidCreateTask(u8 A_u8Periorty, u16 A_u8Periodicty, void(*A_pvTaskFunc)(void)){

	if(A_u8Periorty < TASKS_NUMBER){
		SystemTasks[A_u8Periorty].Periodicity = A_u8Periodicty;
		SystemTasks[A_u8Periorty].TaskFun = A_pvTaskFunc;
	}
	else{
		/*
		 * Do Nothing
		 * */
	}

}


void RTOS_voidStart(){
	MTimer0_u8CompareMatchCallback(&Scheduler);
	MGIE_voidEnable();
	MTimer_voidTimerInit();
}



void Scheduler(void){

	G_u16Counter++;
	/*Loop On all Tasks */
	for(u8 Local_u8TacksCounter = 0; Local_u8TacksCounter < TASKS_NUMBER; Local_u8TacksCounter++){
		/*Check if The Task Has to be called*/
		if(G_u16Counter % SystemTasks[Local_u8TacksCounter].Periodicity == 0){
			/*Check if the Function Not equal NULL*/
			if(SystemTasks[Local_u8TacksCounter].TaskFun != NULL){
				SystemTasks[Local_u8TacksCounter].TaskFun();
			}
			else {
				/*
				 * Do Nothing
				 * */
			}
		}

	}

}
















