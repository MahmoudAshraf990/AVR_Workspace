

#include<avr/io.h>
#include<avr/delay.h>
#include "STD_TYPES.h"


int main(){
	/*Intialize A0 as an output*/
	DDRC = 0b11111111;


	u8 SevenSegNumbers[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};


	while(1){

		for(u8 i=0; i<10; i++){
			PORTC = SevenSegNumbers[i];
			_delay_ms(1000);
		}


	};


}


