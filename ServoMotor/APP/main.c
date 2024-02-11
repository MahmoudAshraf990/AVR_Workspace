

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
#include"../MCAL/TWI/TWI_Interface.h"

int main(){

	/*Set Pin D5 As an output*/
	MDIO_voidSetPinDirection('D', 5, 1);

	MTimer1_voidInit();
	/*period time 20000*/
	MTimer1_voidSetICR1(20000);

	/*Go to +60 Deg*/
	MTimer1_voidSetCompareMatchValue(1833);

	while(1){



	}
}





