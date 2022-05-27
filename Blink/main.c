/*
 * Blink.c
 *
 * Created: 4/19/2022 1:12:39 PM
 * Author : luca9
 */ 

#define F_CPU 16000000UL /*CPU frequency 16MHz*/
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Data direction register (determines In-/Output)
	DDRB |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3);
	//DDRB = 0b00000111; /* 0 = Eingang; 1 = Ausgang*/
	PORTB |= 1 << PORTB5; /*Shift bit by 5 to the left to activate pin 5 of PortB*/
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= 1 << PORTB5;
		_delay_ms(1000);
		PORTB=0; //turn all pins of PortB off
		_delay_ms(2000);
    }
}

