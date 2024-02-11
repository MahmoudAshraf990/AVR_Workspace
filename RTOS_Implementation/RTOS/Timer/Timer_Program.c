

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include"Timer_Interface.h"

#define NoErr     0
#define Err       0xff



void(*G_TIM0_CTC_Callback)(void);



void MTimer_voidTimerInit(){
		/*CTC Mode*/
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		/*SET CTC Interrupt Enable*/
		SET_BIT(TIMSK,1);


		/*Set Compare Match Value to 125*/
		OCR0 = 125;

		/*Prescaller 64*/
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);

}

void MTimer_voidSetCompareMatchValue(u8 A_u8CompValue){
		OCR0 = A_u8CompValue;
}


u8 MTimer0_u8CompareMatchCallback(void(*A_pvCallback)(void)){

	u8 Local_u8ErrorState =NoErr;

	if(A_pvCallback != NULL){
		G_TIM0_CTC_Callback = A_pvCallback;
	}
	else{
		Local_u8ErrorState = Err;
	}

	return Local_u8ErrorState;

}





ISR(TIMER0_COMP_vect){

	if(G_TIM0_CTC_Callback != NULL){
		G_TIM0_CTC_Callback();
	}
	else{
		/*
		 * Do nothing
		 * */
	}

}



