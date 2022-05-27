/*
 * usart.c
 *
 *  Created on: May 13, 2022
 *      Author: luca
 */


#include "usart.h"

void usart_Init() {

	/*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;

	UCSR0B |= (1 << TXEN0);      // Enable transmitter
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp
	sei();  // Lets not forget to enable interrupts =P
}
