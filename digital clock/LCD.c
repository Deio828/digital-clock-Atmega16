/*
 * Created: 8/23/2020 8:19:21 PM
 *  Author: Mohamed Mostafa Alsayad
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

#define PM 0
#define AM 1

void LCD_cmd(BYTE cmd){
	port_write('A' , cmd); // write command on data bus
	pin_write('B',5,0); // RS = 0
	pin_write('B',6,0); // RW = 0
	
	pin_write('B',7,1); // E pulse high
	_delay_ms(1);
	pin_write('B',7,0); // E pulse low
	_delay_ms(3);
	
}

void LCD_init (){
	/*
		Always connect D0:D7 to PORTA0:PORTA7
		Always connect RS to PORTB5
		Always connect RW to PORTB6
		Always connect E  to PORTB7 
	*/
	
	pin_mode('A' , 0 , OUTPUT); //D0
	pin_mode('A' , 1 , OUTPUT); //D1
	pin_mode('A' , 2 , OUTPUT); //D2
	pin_mode('A' , 3 , OUTPUT); //D3
	pin_mode('A' , 4 , OUTPUT); //D4
	pin_mode('A' , 5 , OUTPUT); //D5
	pin_mode('A' , 6 , OUTPUT); //D6
	pin_mode('A' , 7 , OUTPUT); //D7
		
	pin_mode('B' , 5 , OUTPUT); //RS instruction\data (0\1)
	pin_mode('B' , 6 , OUTPUT); //R\W (1\0)
	pin_mode('B' , 7 , OUTPUT); //E
	
	_delay_ms(20);
	
	LCD_cmd(0x38); // Enable 8-bit mode
	LCD_cmd(0x0C); // Display ON & Cursor OFF
	LCD_cmd(0x06); // Auto increment cursor 
	LCD_cmd(0x01); // Clear display 
	LCD_cmd(0x80); // cursor at home position 	
}

void LCD_write_char(BYTE data){
	port_write('A' , data); // write command on data bus
	pin_write('B',0,5); // RS = 1
	pin_write('B',1,6); // RW = 0
	
	pin_write('B',7,1); // E pulse high
	_delay_ms(1);
	pin_write('B',7,0); // E pulse low
	_delay_ms(3);	
}

void LCD_write(BYTE* data){
	BYTE i = 0;
	while(data[i] != '\0'){
		LCD_write_char(data[i]);
		i++;
	}
	
}

void LCD_startfrom(BYTE row , BYTE pos){
	if (row != 1 && row!=2) return;
	if (pos>16) return;
	
	if (row == 1) LCD_cmd((pos & 0x0F) | 0x80);
	else if (row == 2) LCD_cmd((pos & 0x0F) | 0xC0);
}
