/*
 * IncFile1.h
 *
 * Created: 5/7/2015 4:41:00 PM
 *  Author: Camacho
 */ 


#ifndef INITIALIZERS_H
#define INITIALIZERS_H

#ifndef F_CPU
#define F_CPU 32000000UL // 32 MHz clock speed
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


//#define LED_AMBER IOPORT_CREATE_PIN(PORTC, 4)
#define LED_GREEN IOPORT_CREATE_PIN(PORTD, 4)
#define LED_RED IOPORT_CREATE_PIN(PORTC, 0)

#define BTA_HW_WAKE IOPORT_CREATE_PIN(PORTC, 1)
#define BTB_HW_WAKE IOPORT_CREATE_PIN(PORTD, 1)

	//DIP SWITCH SETUP
#define DIP1              IOPORT_CREATE_PIN(PORTF, 1)
#define DIP2              IOPORT_CREATE_PIN(PORTF, 2)
#define DIP3              IOPORT_CREATE_PIN(PORTF, 3)
#define DIP4              IOPORT_CREATE_PIN(PORTF, 4)
#define DIP5              IOPORT_CREATE_PIN(PORTF, 5)

#define CMD_BTA           IOPORT_CREATE_PIN(PORTE, 4)
#define CMD_BTB           IOPORT_CREATE_PIN(PORTE, 5)

void lightshow(void);
void confirmLED(void);
void setLED(char color, int state);

void setUp32MhzInternalOsc(void);
void setupIOpins(void);
void setupBluetooth(void);
void setUpSerial_PORTE(void);
void sendString_PORTE(char *text);
void sendChar_PORTE(char c);

void setUpSerial_PORTC(void);
void sendString_PORTC(char *text);
void sendChar_PORTC(char c);

void setUpSerial_PORTD(void);
void sendString_PORTD(char *text);
void sendChar_PORTD(char c);

void usartPORTC_putc(char c);
char usartPORTC_getc(void);

void usartPORTE_putc(char c);
char usartPORTE_getc(void);
char readPortE_char(void);

void usartPORTD_putc(char c);
char usartPORTD_getc(void);

void spi_init_module1(void);
void spi_init_module9(void);

void start_tiles(int);
void sample100(int);

extern struct spi_device spi_device_tile1;
extern struct spi_device spi_device_tile2;
extern struct spi_device spi_device_tile3;
extern struct spi_device spi_device_tile4;
extern struct spi_device spi_device_tile5;
extern struct spi_device spi_device_tile6;
extern struct spi_device spi_device_tile7;
extern struct spi_device spi_device_tile8;
extern struct spi_device spi_device_tile9;

extern struct spi_device *tile_1;
extern struct spi_device *tile_2;
extern struct spi_device *tile_3;
extern struct spi_device *tile_4;
extern struct spi_device *tile_5;
extern struct spi_device *tile_6;
extern struct spi_device *tile_7;
extern struct spi_device *tile_8;
extern struct spi_device *tile_9;

extern struct spi_device *system_tiles[9];

#endif /* INCFILE1_H_ */



