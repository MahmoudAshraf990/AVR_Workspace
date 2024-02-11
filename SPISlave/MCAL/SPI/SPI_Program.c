


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>


void MSPI_voidMasterInit(){

	/*Master Select*/
	SET_BIT(SPCR, 4);

	/*Master Clock sck prescaller 16*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPSR,0);

	/*Spi Enable*/
	SET_BIT(SPCR, 6);
}


void MSPI_voidSlaveInit(){
	/*Slave Select*/
	CLR_BIT(SPCR, 4);
	/*Enable Spi*/
	SET_BIT(SPCR, 6);
}

u8 MSPI_u8Transcieve(u8 A_u8Data){

	/*Transmit Data*/
	SPDR = A_u8Data;

	/*Wait Till Data is Transfered*/
	while(GET_BIT(SPSR,7) == 0);

	/*Access SPDR*/
	return SPDR;
}

