
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>

#include"SPI_Interface.h"

void MSPI_voidMasterInit(){
	/*Master Intialization*/
	SET_BIT(SPCR, 4);

	/*Master SCk with PS 16*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPSR, 0);
	/*SPi Enable*/
	SET_BIT(SPCR, 6);
}

void MSPI_voidSlaveInit(){

	/*slave Select*/
	CLR_BIT(SPCR, 4);

	/*SPI Enable*/
	SET_BIT(SPCR, 6);

}


u8 MSPI_u8Transceieve(u8 A_u8Data){

	/*Send Data */
	SPDR = A_u8Data;

	/*Wait Till Transfer is complete*/
	while(GET_BIT(SPSR, 7) == 0);

	return SPDR;


}




