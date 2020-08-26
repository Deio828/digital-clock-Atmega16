/*
 * Created: 8/23/2020 3:54:00 PM
 *  Author: Mohamed Mostafa Alsayad
 */ 
#include <avr/io.h>
#include "DIO.h"

typedef unsigned char BYTE;
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0


void pin_mode (char port , BYTE pin , BYTE mode)
{
	switch (port)
	{
		case 'A':
		{
			if (mode == OUTPUT) DDRA |= (1<<pin);
			else if (mode == INPUT) DDRA &= ~(1<<pin);
			break;
		}
		case 'B':
		{
			if (mode == OUTPUT) DDRB |= (1<<pin);
			else if (mode == INPUT) DDRB &= ~(1<<pin);
			break;
		}
		case 'C':
		{
			if (mode == OUTPUT) DDRC |= (1<<pin);
			else if (mode == INPUT) DDRC &= ~(1<<pin);
			break;
		}
		case 'D':
		{
			if (mode == OUTPUT) DDRD |= (1<<pin);
			else if (mode == INPUT) DDRD &= ~(1<<pin);
			break;
		}	
		default:
		{
			break;
		}
	}	
}

void pin_write (char port , BYTE pin ,BYTE value)
{
	switch(port)
	{
		case 'A':
		{
			if(value == HIGH) PORTA |= (1<<pin);
			else if (value == LOW) PORTA &= ~(1<<pin);
			break;
		}
		case 'B':
		{
			if(value == HIGH) PORTB |= (1<<pin);
			else if (value == LOW) PORTB &= ~(1<<pin);
			break;
		}
		case 'C':
		{
			if(value == HIGH) PORTC |= (1<<pin);
			else if (value == LOW) PORTC &= ~(1<<pin);
			break;
		}
		case 'D':
		{
			if(value == HIGH) PORTD |= (1<<pin);
			else if (value == LOW) PORTD &= ~(1<<pin);
			break;
		}
		default:{
			break;
		}						
	}	
}

void port_write (char port , BYTE value){
	switch(port){
		case 'A': PORTA = value;
		case 'B': PORTB = value;
		case 'C': PORTC = value;
		case 'D': PORTD = value;
	}
}

BYTE pin_read (char port , BYTE pin){
	BYTE val;
	switch(port){
		case 'A' : {
			val = PINA;
			val &= (1<<pin);
			val = (val>>pin);
			return val;			
		}
		case 'B' : {
			val = PINB;
			val &= (1<<pin);
			val = (val>>pin);
			return val;
		}
		case 'C' : {
			val = PINC;
			val &= (1<<pin);
			val = (val>>pin);
			return val;
		}
		case 'D' : {
			val = PIND;
			val &= (1<<pin);
			val = (val>>pin);
			return val;
		}						
	}
}

BYTE port_read(char port){
	switch(port){
		case 'A': return PINA;
		case 'B': return PINB;
		case 'C': return PINC;
		case 'D': return PIND;
	}	
}