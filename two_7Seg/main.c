/*******************************************************************************************
* ! Title : count up 0 : 9
* ! File Name : main.c
* ! Description : This file has the implementation code for switching on led
* ! Version : V1.0
********************************************************************************************/


#define F_CPU 8000000
#include<avr/io.h>
#include<util/delay.h>

#define zero 0b1111111;
#define one 0b0000110;
#define five 0b1101101;


void main()
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	while(1){
		PORTA = five;
		PORTB = zero;
		_delay_ms(1000);
		PORTA = one;
		PORTB = zero;
		_delay_ms(1000);
	}
}
