/*
 * bluetooth.c
 * Bluetooth Functions for RN4020 BLE Transceiver
 * Created: 5/29/2015 10:29:21 AM
 *  Author: Camacho
 */ 
#include <asf.h>
#include "initializers.h"

void setupBluetooth(void){
	setUpSerial_PORTC();
	setUpSerial_PORTD();
	if(gpio_pin_is_high(DIP1)){
		sendString_PORTC("SF,2\n");
		_delay_ms(4000);
		sendString_PORTC("R,1\n");
		_delay_ms(4000);
		sendString_PORTD("SF,2\n");
		_delay_ms(4000);
		sendString_PORTD("R,1\n");
		_delay_ms(4000);
	}
	if(gpio_pin_is_high(DIP2)){
		setLED('A', 1);
		sendString_PORTC("SR,32000000\n");
		_delay_ms(4000);
		sendString_PORTC("R,1\n");
		_delay_ms(4000);
		sendString_PORTC("SN,RSIMASTER\n");
		_delay_ms(4000);
		sendString_PORTC("A\n");
		setLED('A', 0);
		confirmLED();
		setLED('A', 1);
		sendString_PORTD("SR,32000000\n");
		_delay_ms(4000);
		sendString_PORTD("R,1\n");
		_delay_ms(4000);
		sendString_PORTD("SN,RSISLAVE\n");
		_delay_ms(4000);
		sendString_PORTD("A\n");
		setLED('A', 0);
		confirmLED();
	}
	gpio_set_pin_high(CMD_BTA);
	gpio_set_pin_high(CMD_BTB);
}
