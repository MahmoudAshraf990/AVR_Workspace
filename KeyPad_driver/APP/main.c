

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"


int main(){

	MDIO_voidSetPortDirection('D', 0b00001111);
	MDIO_voidSetPortValue('D', 0xff);

	MDIO_voidSetPortDirection('A', 0xff);


	u8 SevenSegNumbers[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};

	u8 L_u8Key;
	while(1){
		L_u8Key = HKPD_u8GetPressedKey();
		switch(L_u8Key){
			case '0': MDIO_voidSetPortValue('A', SevenSegNumbers[0]); break;

			case '1': MDIO_voidSetPortValue('A', SevenSegNumbers[1]); break;

			case '2': MDIO_voidSetPortValue('A', SevenSegNumbers[2]); break;

			case '3': MDIO_voidSetPortValue('A', SevenSegNumbers[3]); break;

			case '4':MDIO_voidSetPortValue('A', SevenSegNumbers[4]); break;

			case '5':MDIO_voidSetPortValue('A', SevenSegNumbers[5]); break;

			case '6':MDIO_voidSetPortValue('A', SevenSegNumbers[6]); break;

			case '7':MDIO_voidSetPortValue('A', SevenSegNumbers[7]); break;

			case '8':MDIO_voidSetPortValue('A', SevenSegNumbers[8]); break;

			case '9':MDIO_voidSetPortValue('A', SevenSegNumbers[9]); break;


		}


	}
}




