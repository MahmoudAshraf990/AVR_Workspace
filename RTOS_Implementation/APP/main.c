

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include<avr/delay.h>
#include"../RTOS/RTOS/RTOS_Interface.h"

void toggleA1(void){
	MDIO_voidSetPinValue('A', 1, !MDIO_u8GetPinValue('A', 1));
}

void toggleA2(void){
	MDIO_voidSetPinValue('A', 2, !MDIO_u8GetPinValue('A', 2));
}

void toggleA3(void){
	MDIO_voidSetPinValue('A', 3, !MDIO_u8GetPinValue('A', 3));
}


int main(){
	MDIO_voidSetPinDirection('A', 1, 1);
	MDIO_voidSetPinDirection('A', 2, 1);
	MDIO_voidSetPinDirection('A', 3, 1);

	/*
	 * create 3 Tasks
	 * Task1 toggle led every 1s
	 * Task2 toggle led every 2s
	 * Task3 toggle led every 3s
	 * */

	RTOS_voidCreateTask(0,1000, &toggleA1);
	RTOS_voidCreateTask(1,2000, &toggleA2);
	RTOS_voidCreateTask(2,3000, &toggleA3);

	RTOS_voidStart();


	while(1){



	}
}





