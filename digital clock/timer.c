/*
 * Created: 8/25/2020 4:55:10 PM
 *  Author: Mohamed Mostafa Alsayad
 */ 

#include "timer.h"
#define F_CPU 1000000ul
#include "DIO.h"
#include <avr/interrupt.h>

extern BYTE flag;
BYTE tick;

ISR(TIMER0_COMP_vect){
	if(tick==100){
		flag = 1;
		tick = 0;
	}
	else{tick++;}
}

void timer_init(){
	tick = 0;
	SREG |= (1<<7);  // Enable global interrupt 
	TIMSK |= (1<<1); // Enable Timer interrupt
	// SET CTC MODE
	TCCR0 &= ~(1<<6);
	TCCR0 |= (1<<3);
	// SET COUNTER CLOCK
	TCCR0 |= (1<<0); 
	TCCR0 &= ~(1<<1);
	TCCR0 |= (1<<2);  
	// SET COMPARING VALUE
	OCR0 = 8;	
}

