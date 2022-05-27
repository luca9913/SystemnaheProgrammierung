/*
 * main.c
 *
 *  Created on: May 13, 2022
 *      Author: luca
 */

#include "adc.h"
#include "usart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(){
	usart_Init();
	adc_init();
	usart_sendStringNewLine("Go...");
}

ISR(ADC_vect){
	outputDigitalData();
}
