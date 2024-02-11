/***************************************************************************************/
/* Author      !  Mahmoud Ashraf													   */
/* Layer       ! APP																   */
/* Description ! TWI Driver  													       */
/* Release Date! 17/7/2020                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include<avr/delay.h>
#include"TWI_Interface.h"



void MTWI_voidMasterInit(){
	//Set CLock freq to 400KbPS
	TWBR = 2;

	//Clear The 2bit of TWPS
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);

	//TWI Enable
	SET_BIT(TWCR, 2);

}


void MTWI_voidSlaveInit(u8 A_u8SalveAddress){
	/**Intialize slave address*/
	TWAR = (A_u8SalveAddress<<1);

	//TWI Enable
	SET_BIT(TWCR, 2);
}

TWI_ErrStatus MTWI_SendStartCondition(){
	TWI_ErrStatus Loca_ErrorStatus = NoError;
	/*Send Start condition On Bus*/
	SET_BIT(TWCR, 5);
	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);
	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);
	/*Check For Status Reg*/
	if((TWSR & 0xF8) != 0x08){
		Loca_ErrorStatus = StartConditionErr;
	}
	return Loca_ErrorStatus;
}
TWI_ErrStatus MTWI_SendRepeatedStartCondition(){

	TWI_ErrStatus Loca_ErrorStatus = NoError;
	/*Send Start condition On Bus*/
	SET_BIT(TWCR, 5);
	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);
	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);
	/*Check For Status Reg*/
	if((TWSR & 0xF8) != 0x10){
		Loca_ErrorStatus = RepeatedStartErr;
	}
	return Loca_ErrorStatus;
}

TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress){
	TWI_ErrStatus Loca_ErrorStatus = NoError;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR, 5);
	/*Set The Slave Address in the 7 MSB In data Reg*/
	TWDR = A_u8SalveAddress<<1;
	/*ClR Bit for Write req*/
	CLR_BIT(TWDR, 0);

	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Set TWI Enable*/
	SET_BIT(TWCR, 2);

	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);
	/*Check For Status Reg*/

	if((TWSR & 0xF8) != 0x18){
		Loca_ErrorStatus = SlaveAdderssWithWriteErr;
	}

	return Loca_ErrorStatus;
}

TWI_ErrStatus MTWI_SendSlaveAdderssWithRead(u8 A_u8SalveAddress){
	TWI_ErrStatus Loca_ErrorStatus = NoError;

	/*Clear the start condition bit*/
	 CLR_BIT(TWCR, 5);

	 /*Set The Slave Address in the 7 MSB In data Reg*/
	TWDR = A_u8SalveAddress<<1;
	/*SET Bit 0 for Read req*/
	SET_BIT(TWDR, 0);

	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);


	/*Check For the operation Status Reg*/
	if((TWSR & 0xF8) != 0x40){
		Loca_ErrorStatus = SlaveAdderssWithReadErr;
	}

	return Loca_ErrorStatus;
}

TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data){
	TWI_ErrStatus Loca_ErrorStatus = NoError;

	/*Write The Data */
	TWDR = A_u8Data;

	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);


	/*Set TWI Enable*/
	SET_BIT(TWCR, 2);


	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);


	/*Check For the operation Status Reg*/

	if((TWSR & 0xF8) != 0x28){
		Loca_ErrorStatus = MasterWriteByteErr;
	}

	return Loca_ErrorStatus;
}

TWI_ErrStatus MTWI_MasterReadDataByte(u8 *A_pu8RecievedData){
	TWI_ErrStatus Loca_ErrorStatus = NoError;

	/*Enable Master generating ACK bit */
	SET_BIT(TWCR, 6);

	/*Clear The interrupt Flag to start the slave sending data operation*/
	SET_BIT(TWCR, 7);

	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);


	/*Check For the operation Status Reg*/
	if((TWSR & 0xF8) != 0x50){
		Loca_ErrorStatus = MasterReadDataByteErr;
	}
	else {
		/*Read The RecievedData*/
		*A_pu8RecievedData = TWDR;
	}
	return Loca_ErrorStatus;
}


void MTWI_voidSetSlaveAddress(u8 A_u8Address)
{
	TWAR=A_u8Address;
}


TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData)
{
	TWI_ErrStatus Loca_ErrorStatus = NoError;

	/*Enable Master generating ACK bit */
	SET_BIT(TWCR, 6);

	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0XF8) != 0x60){ // 0x60 The slave add is recieved with write req
		Loca_ErrorStatus = SlaveAddressRecievedErr;
	}

	/*Enable Master generating ACK bit */
	SET_BIT(TWCR, 6);

	/*Clear The interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait till wht interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0XF8) != 0x80){ // 0x80 means that a byte  is recieved
		Loca_ErrorStatus = SlaveDataRecievedErr;
	}
	else{
		*A_pu8RecievedData = TWDR;
	}

	return Loca_ErrorStatus ;
}


void MTWI_voidSendStopCondition(){

	/*Generate Stop Condition On the bus */
	SET_BIT(TWCR, 4);
	/*Clear The interrupt Flag to start the slave sending data operation*/
	SET_BIT(TWCR, 7);

}

