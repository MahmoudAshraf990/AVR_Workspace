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
#define two 0b1011011;
#define three 0b1001111;
#define four 0b1100110;
#define five 0b1101101;
#define six 0b1111101;
#define seven 0b0000111;
#define eight 0b1111111;
#define nine 0b1101111;

void main(void){
	DDRA = 0xFF;
	//char number = '0';
	while(1){
		PORTA = zero;
		_delay_ms(500);
		PORTA = one;
		_delay_ms(500);
		PORTA = two;
		_delay_ms(500);
		PORTA = three;
		_delay_ms(500);
		PORTA = four;
		_delay_ms(500);
		PORTA = five;
		_delay_ms(500);
		PORTA = six;
		_delay_ms(500);
		PORTA = seven;
		_delay_ms(500);
		PORTA = eight;
		_delay_ms(500);
		PORTA = nine;
		_delay_ms(500);

	}



}

