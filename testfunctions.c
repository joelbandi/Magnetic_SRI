/*
 * testfunctions.c
 * Debugging Functions
 * Created: 5/7/2015 5:26:22 PM
 *  Author: Camacho
 */ 
#include <asf.h>
#include "initializers.h"

void lightshow(void){
	for(int i = 0; i < 10; i++){
		gpio_set_pin_high(LED_GREEN);
		_delay_ms(100);
		gpio_set_pin_low(LED_GREEN);
		_delay_ms(100);
		//gpio_set_pin_high(LED_AMBER);
		_delay_ms(100);
		//gpio_set_pin_low(LED_AMBER);
		_delay_ms(100);
		gpio_set_pin_high(LED_RED);
		_delay_ms(100);
		gpio_set_pin_low(LED_RED);
		_delay_ms(100);
	}  
}


void setLED(char color, int state){
	char selectedLED=0;
	switch (color){
		case 'R':
			selectedLED = LED_RED;
			break;
		
		case 'A':
			//selectedLED = LED_AMBER;
			break;
		
		case'G':
			selectedLED = LED_GREEN;
			break;
	}
	
	if (state){
		gpio_set_pin_high(selectedLED);
	}
	else{
		gpio_set_pin_low(selectedLED);
	}
}

void confirmLED(void){
		gpio_set_pin_high(LED_GREEN);
		_delay_ms(500);
		gpio_set_pin_low(LED_GREEN);
}
