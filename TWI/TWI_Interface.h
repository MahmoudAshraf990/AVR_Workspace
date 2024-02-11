/*
 * TWI_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: mahmo
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_


typedef enum{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAdderssWithWriteErr,
	SlaveAdderssWithReadErr,
	MasterWriteByteErr,
	MasterReadDataByteErr,
	SlaveAddressRecievedErr,
	SlaveDataRecievedErr
}TWI_ErrStatus;

void MTWI_voidMasterInit();


void MTWI_voidSlaveInit(u8 A_u8SalveAddress);

TWI_ErrStatus MTWI_SendStartCondition();
TWI_ErrStatus MTWI_SendRepeatedStartCondition();

TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress);

TWI_ErrStatus MTWI_SendSlaveAdderssWithRead(u8 A_u8SalveAddress);

TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data);

TWI_ErrStatus MTWI_MasterReadDataByte(u8 *A_pu8RecievedData);

TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData);

void MTWI_voidSendStopCondition();

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
