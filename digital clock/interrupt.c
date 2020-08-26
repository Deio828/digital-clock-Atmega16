/*
 * Created: 8/24/2020 1:42:48 PM
 *  Author: Mohamed Mostafa Alsayad
 */ 
#include <avr/interrupt.h>
#include "interrupt.h"
#include "LCD.h"
#include "clock.h"
#include "schedular.h"

extern BYTE mode;
extern BYTE HR;
extern BYTE MIN;
extern BYTE SEC;
extern BYTE TIME;
extern BYTE DAY;
extern BYTE MONTH;
extern unsigned int YEAR;

// Mode Bottom
ISR(INT0_vect){
	/*
		* MODE 0 IS RUNNING
		* MODE 1 IS EDITING HOURS
		* MODE 2 IS EDITING MINUITES
		* MODE 3 IS EDITING SECONDS
		* MODE 4 IS EDITING DAYS
		* MODE 5 IS EDITING MONTHS
		* MODE 6 IS EDITING YEARS
	*/
	if(mode == 6) {mode = 0;}
	else {mode++;}
	clock_write(HR , MIN , SEC);
	date_write(DAY , MONTH, YEAR);
	
}

// Increment Bottom
ISR(INT1_vect){
	// increasing hours
	if(mode == 1){ 
		if(HR == 12) {HR = 1;}
		else {HR++;}
		clock_write(HR , MIN , SEC);
	}
	// increasing minuets 
	else if(mode == 2){
		if(MIN == 59) {MIN = 0;}
		else {MIN++;}
		clock_write(HR , MIN , SEC); 
	}
	// increasing seconds
	else if(mode == 3){
		if(SEC == 59) {SEC = 0;}
		else {SEC++;}
		clock_write(HR , MIN , SEC);		
	}
	// increasing days
	else if(mode == 4){
		BYTE max_days;
		if(MONTH==1 ||MONTH==3 ||MONTH==5 ||MONTH==7 ||MONTH==8 ||MONTH==10 ||MONTH==12) max_days = 31;
		else if (MONTH == 2) max_days = 28;
		else max_days = 30;
		
		if(DAY == max_days) {DAY = 1;}
		else {DAY++;}
		date_write(DAY,MONTH,YEAR);		
	}
	// increasing months
	else if(mode==5){
		if(MONTH==12) {MONTH = 1;}
		else {MONTH++;}
		date_write(DAY,MONTH,YEAR);	
	}
	// increasing years
	else if(mode==6){
		YEAR++;
		date_write(DAY,MONTH,YEAR);
	}
	
}

// Decrement Bottom
ISR(INT2_vect){
	// decreasing hours
	if(mode == 1){
		if(HR == 1) {HR = 12;}
		else {HR--;}
		clock_write(HR , MIN , SEC);
	}
	// decreasing minuets
	else if(mode == 2){
		if(MIN == 0) {MIN = 59;}
		else {MIN--;}
		clock_write(HR , MIN , SEC);
	}
	// decreasing hours
	else if(mode == 3){
		if(SEC == 0) {SEC = 59;}
		else {SEC --;}
		clock_write(HR , MIN , SEC);		
	}
	// decreasing days
	else if(mode == 4){
		BYTE max_days;
		if(MONTH==1 ||MONTH==3 ||MONTH==5 ||MONTH==7 ||MONTH==8 ||MONTH==10 ||MONTH==12) max_days = 31;
		else if (MONTH == 2) max_days = 28;
		else max_days = 30;
		
		if(DAY == 1) {DAY = max_days;}
		else {DAY--;}
		date_write(DAY,MONTH,YEAR);
	}
	// decreasing months
	else if(mode==5){
		if(MONTH==1) {MONTH = 12;}
		else {MONTH--;}
		date_write(DAY,MONTH,YEAR);
	}
	// decreasing years
	else if(mode==6){
		YEAR--;
		date_write(DAY,MONTH,YEAR);
	}		
	
}

void interrupt_init(){
	SREG |= (1<<7); // Enable global interrupt 
	// Enable INT0 for rising edge
	MCUCR |= (1<<0);
	MCUCR |= (1<<1);
	MCUCR |= (1<<3);
	MCUCR |= (1<<2);
	MCUCSR|= (1<<6);
	
	GICR |= (1<<5);
	GICR |= (1<<6);
	GICR |= (1<<7);
		
}
