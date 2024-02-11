


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"TWI_Interface.h"


void MI2C_voidMasterInit(){
	TWBR = 10;
	TWSR = 0;
}

void MI2C_voidStart(){

	TWCR = (1<<7)|(1<<2)|(1<<5);

	// Wait Till flag raised
	while(GET_BIT(TWCR, 7) == 0);

	//Wait till starting transmitted
	while((TWSR & 0xf8) != 0x08);

}

void MI2C_voidWriteData(u8 A_u8Data){

	TWDR = A_u8Data;
	TWCR = (1<<7)|(1<<2);

	// Wait Till flag raised
	while(GET_BIT(TWCR, 7) == 0);

	//Wait Till data has been transmitted
	while((TWSR & 0xf8) != 0x28);
}

void MI2C_voidWriteAdderess(u8 A_u8Address){

	TWDR = A_u8Address;
	TWCR = (1<<7)|(1<<2);

	// Wait Till flag raised
	while(GET_BIT(TWCR, 7) == 0);

	//Wait Till data has been transmitted
	while((TWSR & 0xf8) != 0x18);

}

void MI2C_voidSetSlaveAddress(u8 A_u8Address){
	TWAR = A_u8Address;
}

u8 MI2C_u8SlaveReading(){
	TWCR = (1<<7)|(1<<2)|(1<<6);
	// Wait Till flag raised
	while(GET_BIT(TWCR, 7) == 0);
	while((TWSR & 0xf8) != 0x60);


	TWCR = (1<<7)|(1<<2)|(1<<6);
	// Wait Till flag raised
	while(GET_BIT(TWCR, 7) == 0);
	while((TWSR & 0xf8) != 0x80);

	return TWDR;

}

void MI2C_voidStop(){
	TWCR = (1<<7)|(1<<2)|(1<<4);
}




