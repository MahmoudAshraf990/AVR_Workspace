

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include<avr/delay.h>

int main(){

	MDIO_voidSetPortDirection('D', 0xff);


	while(1){

		MDIO_voidSetPinValue('D', 0, 1);
		MDIO_voidSetPinValue('D', 1, 0);
		MDIO_voidSetPinValue('D', 2, 0);
		MDIO_voidSetPinValue('D', 3, 0);
		_delay_ms(500);


		MDIO_voidSetPinValue('D', 0, 0);
		MDIO_voidSetPinValue('D', 1, 1);
		MDIO_voidSetPinValue('D', 2, 0);
		MDIO_voidSetPinValue('D', 3, 0);
		_delay_ms(500);
		MDIO_voidSetPinValue('D', 0, 0);
		MDIO_voidSetPinValue('D', 1, 0);
		MDIO_voidSetPinValue('D', 2, 1);
		MDIO_voidSetPinValue('D', 3, 0);
		_delay_ms(500);

		MDIO_voidSetPinValue('D', 0, 0);
		MDIO_voidSetPinValue('D', 1, 0);
		MDIO_voidSetPinValue('D', 2, 0);
		MDIO_voidSetPinValue('D', 3, 1);
		_delay_ms(500);

	}
}




