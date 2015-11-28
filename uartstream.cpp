/*
 * uartstream.cpp
 *
 * Created: 5/7/2015 11:46:02 PM
 *  Author: Camacho
 */ 
static int uart_putchar(char c, FILE *stream);

extern "C"{
	FILE * uart_str;
}


void getBTinfo(void){
	char str [80];
	int i;
	printf ("Enter your family name: ");
	scanf ("%79s",str);	
	
	
	
	
}