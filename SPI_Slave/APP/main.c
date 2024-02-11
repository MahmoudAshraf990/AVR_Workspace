

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"
#include<avr/delay.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include"../MCAL/Timer/Timer_Interface.h"
#include<avr/interrupt.h>
#include"../MCAL/UART/UART_Interface.h"
#include"../MCAL/SPI/SPI_Interface.h"


int main(){

	/*SS Pin*/
	MDIO_voidSetPinDirection('B', 4,0);

	/*MOSI Pin*/
	MDIO_voidSetPinDirection('B', 5,0);
	/*MISO Pin*/
	MDIO_voidSetPinDirection('B', 6,1);
	/*SCK Pin*/
	MDIO_voidSetPinDirection('B', 7,0);

	/*A1 Output*/
	MDIO_voidSetPinDirection('A', 1, 1);
	/*Init Master Mode*/
	MSPI_voidSlaveInit();

	u8 data;
	while(1){
		data = MSPI_u8Transceieve(0);
		if(data == '1')
			MDIO_voidSetPinValue('A', 1, 1);
		_delay_ms(10);
	}
}





