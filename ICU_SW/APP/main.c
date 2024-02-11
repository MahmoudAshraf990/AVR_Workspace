

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"
#include<avr/delay.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include"../MCAL/Timer/Timer_Interface.h"
#include<avr/interrupt.h>

u8 G_u8Counter, OnTicks, OffTicks;

int main(){

	MDIO_voidSetPinDirection('B', 3, 1);
	MDIO_voidSetPinDirection('D', 2,0);

	/*LCD Configrations*/
	MDIO_voidSetPortDirection('C', 0xff);
	MDIO_voidSetPortDirection('A',0xff);

	MTimer_voidTimerInit(2);
	MTimer_voidSetPreloadValue(2, 64);

	MEXTI_voidSenseControl(0, 3);

	MTimer_voidStart();
	MTimer1_voidInit();

	/*LCD Init*/
	HLCD_voidInit();
	/* Enable Interrupts */
	MEXTI_voidEnable(0);
	MGIE_voidEnable();

	while(1){

		while(OnTicks == 0 && OffTicks == 0);

		HLCD_voidGoto(0,0);
		HLCD_voidSendString("OnTicks = ");
		HLCD_voidDisplayNumber(OnTicks);
		HLCD_voidGoto(1,0);
		HLCD_voidSendString("OffTicks = ");
		HLCD_voidDisplayNumber(OffTicks);
		while(OnTicks && OffTicks);


	}
}


ISR(INT0_vect){
	G_u8Counter++;
	if(G_u8Counter == 1){
		/*SET Timer1 = 0*/
		MTimer1_voidSetTimer1Value(0);
		/*Detect Falling Edge*/
		MEXTI_voidSenseControl(0, 2);
	}
	else if(G_u8Counter == 2){
		OnTicks = MTimer1_u16ReadTimer1Value();

		MTimer1_voidSetTimer1Value(0);
		/*Detect Rising edge*/
		MEXTI_voidSenseControl(0, 3);
	}
	else if(G_u8Counter == 3){
		OffTicks =  MTimer1_u16ReadTimer1Value();

		/*Disable INT0*/
		MEXTI_voidDisable(0);

	}

}




