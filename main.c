/**
* MAIN PROGRAM FOR RSI DETECTOR
*/

#include <asf.h>
#include "initializers.h"
char d;
char c;

int main (void)
{
	
	setUp32MhzInternalOsc();
	setupIOpins();
	setUpSerial_PORTE();//Debugging UART
	setupBluetooth();
	
	int tilecount = 1;
	start_tiles(tilecount);
	
	//Debugging|Test Mode
	while(gpio_pin_is_high(DIP4)){
		char mode = readPortE_char();
		switch(mode){
			case '1':
				sample100(tilecount);
				break;
			default: break;
		}
		
	}
	
	//BlueTooth Test Mode
	while(gpio_pin_is_high(DIP3)){
		
		while((USARTD0_STATUS & USART_RXCIF_bm)){
			c = usartPORTD_getc();
			sendChar_PORTE(c);
		}
		
		while((USARTE0_STATUS & USART_RXCIF_bm)){
			d = usartPORTE_getc();
			sendChar_PORTD(d);
		}
	}
	
	
}
