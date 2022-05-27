/*
 * adc.c
 *
 *  Created on: May 13, 2022
 *      Author: luca
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdlib.h>
#include "adc.h"
#include "usart.h"

void adc_init(){
	ADMUX |= 0b01000000; //Select internal reference voltage and PIN ADC0 for analog input
	ADCSRA |= 0b10101111; //Set ADEN, ADATE, ADIE bits to enable ADC auto trigger and interrupts, bits 0-2 set the prescaler to 128
	sei(); // Lets not forget to enable interrupts =P
	ADCSRA |= 0b01000000; //kick off ADC
}

void outputDigitalData(){
	volatile int val = ADCL | (ADCH << 8);
	char buffer[10];
	usart_sendStringNewLine(itoa(val,buffer,10));
}
