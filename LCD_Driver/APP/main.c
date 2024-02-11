

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"


int main(){
	MDIO_voidSetPortDirection('A', 0xff);
	MDIO_voidSetPortDirection('D', 0xff);
	HLCD_voidInit();

	//u8 *Name = "Mahmoud";
	//HLCD_voidSendString(Name);

	//(0,7)
	HLCD_voidGoto(0,7);
	HLCD_voidSendData('M');
	while(1){



	}
}




