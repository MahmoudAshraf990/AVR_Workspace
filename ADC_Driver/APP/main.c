

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"
#include<avr/delay.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
int main(){

	MDIO_voidSetPortDirection('A', 0b11110111);
	MDIO_voidSetPortDirection('D', 0xff);

	HLCD_voidInit();
	MADC_voidInit(0);

	u8 L_u8Reading, x, tmp;
	f32 AnalogVal, temprature;
	u8 numbers[5];
	u8 *STR = "Temprature: ";
	while(1){
		s8 i = 0;
		L_u8Reading = MADC_u8GetChannelReading(3);
		AnalogVal = ((L_u8Reading * 5000.0)/(256.0));
		temprature = AnalogVal/10;

		HLCD_voidSendCommand(0x01);
		HLCD_voidSendString(STR);
		x = (u8)temprature;

		while(x != 0){
			tmp = x%10;
			numbers[i] = (tmp+'0');
			x /= 10;
			i++;
		}
		i--;
		for(; i>=0; i--){
			HLCD_voidSendData(numbers[i]);
			_delay_ms(10);
		}

		_delay_ms(1000);

	}
}





