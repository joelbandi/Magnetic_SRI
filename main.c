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
	
	
	/* TODO:
	1. This hub is interfaced to the 8 tiles via the SPI interface !!!
	2. The 8 tiles ports share the same physical address but different ids in the hub and hence are multiplexed and interfaced with SPI interface i.e There is an spi slave
	select line (activate id )in the hub to  get the data from the 8 tiles serially
	3. this data is then sent to the bluetooth module over a TWI(I2C) connection this must be programmed in the hub itself.
	4. The bluetooth module transmits data serially to the android application which then processes data.
	*/
}
