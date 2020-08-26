/*
 * Created: 8/24/2020 10:41:11 PM
 *  Author: Mohamed Mostafa Alsayad
 */ 
#include "clock.h"
#include "LCD.h"
#define F_CPU 1000000UL
#include <avr/delay.h>

void clock_write(BYTE hr, BYTE min, BYTE sec){
	BYTE hr0,hr1,min0,min1,sec0,sec1;
	
	hr1 = hr%10;
	hr0 = hr/10.0;

	min1 = min%10;
	min0 = min/10.0;

	sec1 = sec%10;
	sec0 = sec/10.0;
	
	hr0+=48;
	hr1+=48;
	min0+=48;
	min1+=48;
	sec0+=48;
	sec1+=48;	
	
	LCD_startfrom(1,1);
	_delay_ms(3);
	LCD_write_char(hr0);
	LCD_write_char(hr1);
	LCD_write_char(':');
	LCD_write_char(min0);
	LCD_write_char(min1);
	LCD_write_char(':');
	LCD_write_char(sec0);
	LCD_write_char(sec1);
	_delay_ms(2);
}

void date_write(BYTE day , BYTE month , unsigned int year){
	BYTE day0,day1,month0,month1,year0,year1,year2,year3;
	
	day1 = day%10;
	day0 = day/10.0;
	
	month1 = month%10;
	month0 = month/10.0;
	
	year0 = year / 1000.0;
	year1 = (year%1000) / 100.0;
	year2 = (year%100) / 10;
	year3 = year%10;
	
	day0+=48;
	day1+=48;
	month0+=48;
	month1+=48;
	year0+=48;
	year1+=48;
	year2+=48;
	year3+=48;
	
	LCD_startfrom(2,1);
	_delay_ms(3);
	LCD_write_char(day0);
	LCD_write_char(day1);
	LCD_write_char('/');
	LCD_write_char(month0);
	LCD_write_char(month1);	
	LCD_write_char('/');
	LCD_write_char(year0);
	LCD_write_char(year1);
	LCD_write_char(year2);
	LCD_write_char(year3);
}
