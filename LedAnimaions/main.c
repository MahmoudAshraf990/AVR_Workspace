/*******************************************************************************************
* ! Title : Led Animation Program
* ! File Name : main.c
* ! Description : This file has the implementation code for switching on led
* ! Version : V1.0
********************************************************************************************/


#define F_CPU 8000000
#include<avr/io.h>
#include<util/delay.h>



void main(void){
	DDRA = 0b11111111;

	while(1){
		PORTA = 0b01010101;
		_delay_ms(500);
		PORTA = 0b10101010;
		_delay_ms(500);
	}
}

