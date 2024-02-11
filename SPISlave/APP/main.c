

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
	 * Spi As A Slave
	 * */
	//SS
	MDIO_voidSetPinDirection('B',4,0);

	//MOSI Pin
	MDIO_voidSetPinDirection('B',5,0);
	//MISO PIN
	MDIO_voidSetPinDirection('B',6,1);
	//SCk
	MDIO_voidSetPinDirection('B', 7, 0);

	//PIN A1 output
	MDIO_voidSetPinDirection('A', 1, 1);

	MSPI_voidSlaveInit();
	u8 Data;

	while(1){
		Data = MSPI_u8Transcieve(10);
		if(Data == '2')
			MDIO_voidSetPinValue('A', 1,1);
		_delay_ms(100);
	}
}





