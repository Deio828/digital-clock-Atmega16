/*
 * Created: 8/23/2020 3:35:01 PM
 * Author : Mohamed Mostafa Alsayad
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "schedular.h"

int main(void)
{
	start();
	
	while (1) 
    {
		engine();
	}
    
}

