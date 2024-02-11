

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include<avr/interrupt.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"

int main(){

	MDIO_voidSetPinDirection('D', 2, 0);
	MDIO_voidSetPinDirection('A', 0, 1);

	/*Activate Pull up res*/
	MDIO_voidSetPinValue('D', 2,1);

	/*Global Interrupt Enable*/
	MGIE_voidEnable();


	/*INT0 && Falling Edge*/
	MEXTI_voidSenseControl(0, 2);

	MEXTI_voidEnable(0);

	while(1){


	}
}


ISR(INT0_vect){

	if(MDIO_u8GetPinValue('A', 0) == 0){
		MDIO_voidSetPinValue('A', 0, 1);

	}else{
		MDIO_voidSetPinValue('A', 0, 0);
	}
}





