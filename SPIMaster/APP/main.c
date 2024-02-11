

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
#include "../MCAL/SPI/SPI_Interface.h"


int main(){

	/*
	 * Spi As A Master
	 * */
	//SS
	MDIO_voidSetPinDirection('B',4,0);
	MDIO_voidSetPinValue('B', 4, 1);
	//MOSI Pin
	MDIO_voidSetPinDirection('B',5,1);
	//MISO PIN
	MDIO_voidSetPinDirection('B',6,0);
	//SCk
	MDIO_voidSetPinDirection('B', 7, 1);

	MSPI_voidMasterInit();


	while(1){
		MSPI_u8Transcieve('2');
		_delay_ms(100);
	}
}





