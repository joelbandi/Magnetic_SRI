/*
 * uart.c
 * UART Functions
 * Created: 5/29/2015 10:08:26 AM
 *  Author: Camacho
 */ 
#include <asf.h>
#include "initializers.h"

void setUpSerial_PORTE(void)
{
	
	// Baud rate selection
	// BSEL = (32000000 / (2^0 * 16*9600) -1 = 207.333 -> BSCALE = 0
	// FBAUD = ( (32000000)/(2^0*16(207+1)) = 9615.384 -> it's alright
	
	USARTE0_BAUDCTRLB = 0; //Just to be sure that BSCALE is 0
	USARTE0_BAUDCTRLA = 0x22; // 207

	//Disable interrupts, just for safety
	USARTE0_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTE0_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	USARTE0_CTRLB = USART_TXEN_bm | USART_CLK2X_bm | USART_RXEN_bm; // And enable high speed mode
}

void sendChar_PORTE(char c)
{
	
	while( !(USARTE0_STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USARTE0_DATA = c;
	
}


void sendString_PORTE(char *text)
{
	while(*text)
	{
		sendChar_PORTE(*text++);
	}
}

void setUpSerial_PORTC(void)
{
	
	// Baud rate selection
	// BSEL = (32000000 / (2^0 * 16*9600) -1 = 207.333 -> BSCALE = 0
	// FBAUD = ( (32000000)/(2^0*16(207+1)) = 9615.384 -> it's alright
	
	USARTC0_BAUDCTRLB = 0; //Just to be sure that BSCALE is 0
	USARTC0_BAUDCTRLA = 0x22; // 207

	//Disable interrupts, just for safety
	USARTC0_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTC0_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	USARTC0_CTRLB = USART_TXEN_bm | USART_CLK2X_bm | USART_RXEN_bm; // And enable high speed mode
}

void sendChar_PORTC(char c)
{
	
	while( !(USARTC0_STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USARTC0_DATA = c;
	
}


void sendString_PORTC(char *text)
{
	while(*text)
	{
		sendChar_PORTC(*text++);
	}
}

void setUpSerial_PORTD(void)
{
	
	// Baud rate selection
	// BSEL = (32000000 / (2^0 * 16*9600) -1 = 207.333 -> BSCALE = 0
	// FBAUD = ( (32000000)/(2^0*16(207+1)) = 9615.384 -> it's alright
	
	USARTD0_BAUDCTRLB = 0; //Just to be sure that BSCALE is 0
	USARTD0_BAUDCTRLA = 0x22; // 207

	//Disable interrupts, just for safety
	USARTD0_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTD0_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	USARTD0_CTRLB = USART_TXEN_bm | USART_CLK2X_bm | USART_RXEN_bm; // And enable high speed mode
}

void sendChar_PORTD(char c)
{
	
	while( !(USARTD0_STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USARTD0_DATA = c;
	
}


void sendString_PORTD(char *text)
{
	while(*text)
	{
		sendChar_PORTD(*text++);
	}
}


void usartPORTC_putc(char c)
{
	// wait for Tx Data Register Empty
	while (!(USARTC0_STATUS & USART_DREIF_bm));

	// output c
	USARTC0_DATA = c;
}

char usartPORTC_getc(void)
{
	// wait for char to be Rx'd
	while (!(USARTC0_STATUS & USART_RXCIF_bm));

	// input and return char
	return USARTC0_DATA;
}

void usartPORTE_putc(char c)
{
	// wait for Tx Data Register Empty
	while (!(USARTE0_STATUS & USART_DREIF_bm));

	// output c
	USARTE0_DATA = c;
}

char usartPORTE_getc(void)
{
	// wait for char to be Rx'd
	while (!(USARTE0_STATUS & USART_RXCIF_bm));

	// input and return char
	return USARTE0_DATA;
}

void usartPORTD_putc(char c)
{
	// wait for Tx Data Register Empty
	while (!(USARTD0_STATUS & USART_DREIF_bm));

	// output c
	USARTD0_DATA = c;
}

char usartPORTD_getc(void)
{
	// wait for char to be Rx'd
	while (!(USARTD0_STATUS & USART_RXCIF_bm));

	// input and return char
	return USARTD0_DATA;
}