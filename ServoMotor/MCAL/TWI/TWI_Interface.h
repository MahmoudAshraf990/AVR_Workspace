/*
 * TWI_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: mahmo
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

void MI2C_voidMasterInit();

void MI2C_voidStart();

void MI2C_voidWriteData(u8 A_u8Data);

void MI2C_voidWriteAdderess(u8 A_u8Address);

void MI2C_voidSetSlaveAddress(u8 A_u8Address);

u8 MI2C_u8SlaveReading();

void MI2C_voidStop();


#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
