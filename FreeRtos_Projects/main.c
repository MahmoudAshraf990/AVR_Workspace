

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"

/*2 Basic Files */

#include"FreeRTOS.h"
#include"task.h"



void LED1(void *pv){
	while(1){
		MDIO_voidSetPinValue('A' ,1, !MDIO_u8GetPinValue('A', 1));
		vTaskDelay(1000);
	}
}

void LED2(void *pv){
	while(1){
		MDIO_voidSetPinValue('A' ,2, !MDIO_u8GetPinValue('A', 2));
		vTaskDelay(2000);
	}
}

void LED3(void *pv){
	while(1){
		MDIO_voidSetPinValue('A' ,3, !MDIO_u8GetPinValue('A', 3));
		vTaskDelay(3000);
	}
}


int main(){

	/*Set Directions*/
	MDIO_voidSetPortDirection('A', 0xff);

	/*Create Tasks*/
	xTaskCreate(&LED1, NULL, 200, NULL, 0, NULL);
	xTaskCreate(&LED2, NULL, 200, NULL, 1, NULL);
	xTaskCreate(&LED3, NULL, 200, NULL, 2, NULL);

	/*Start FreeRtos(Scheduler)*/

	vTaskStartScheduler();

	while(1){

	}

}








