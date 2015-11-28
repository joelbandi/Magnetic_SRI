/*
* systemTiles.c
* Tile Functions
* Created: 5/29/2015 10:05:50 AM
*  Author: Camacho
*/

#include <asf.h>
#include "initializers.h"

struct spi_device spi_device_tile1 = {
	.id = IOPORT_CREATE_PIN(PORTA, 0)
};

struct spi_device spi_device_tile2 = {
	.id = IOPORT_CREATE_PIN(PORTA, 2)
};

struct spi_device spi_device_tile3 = {
	.id = IOPORT_CREATE_PIN(PORTA, 4)
};

struct spi_device spi_device_tile4 = {
	.id = IOPORT_CREATE_PIN(PORTA, 6)
};

struct spi_device spi_device_tile5 = {
	.id = IOPORT_CREATE_PIN(PORTB, 0)
};

struct spi_device spi_device_tile6 = {
	.id = IOPORT_CREATE_PIN(PORTB, 2)
};

struct spi_device spi_device_tile7 = {
	.id = IOPORT_CREATE_PIN(PORTB, 4)
};

struct spi_device spi_device_tile8 = {
	.id = IOPORT_CREATE_PIN(PORTB, 6)
};

struct spi_device spi_device_tile9 = {
	.id = IOPORT_CREATE_PIN(PORTF, 7)
};

struct spi_device *tile_1 = &spi_device_tile1;
struct spi_device *tile_2 = &spi_device_tile2;
struct spi_device *tile_3 = &spi_device_tile3;
struct spi_device *tile_4 = &spi_device_tile4;
struct spi_device *tile_5 = &spi_device_tile5;
struct spi_device *tile_6 = &spi_device_tile6;
struct spi_device *tile_7 = &spi_device_tile7;
struct spi_device *tile_8 = &spi_device_tile8;
struct spi_device *tile_9 = &spi_device_tile9;
struct spi_device *system_tiles[9];

void start_tiles(int tileNumber){
	system_tiles[0] = tile_1;
	system_tiles[1] = tile_2;
	system_tiles[2] = tile_3;
	system_tiles[3] = tile_4;
	system_tiles[4] = tile_5;
	system_tiles[5] = tile_6;
	system_tiles[6] = tile_7;
	system_tiles[7] = tile_8;
	system_tiles[8] = tile_9;
	spi_master_init(&SPIC);
	for(int i = 0; i <tileNumber;i++){
		spi_master_setup_device(&SPIC, system_tiles[i], SPI_MODE_0, 100000, 0);
	}
	spi_enable(&SPIC);
};


void sample100(int tileNumber){
	unsigned char cmd_A[1] = {'1'};
	unsigned char rx_byte;
	
	setLED('G',1);
	for (int i = 0; i<tileNumber; i++){
		spi_select_device(&SPIC, system_tiles[i]);
		_delay_ms(25);
		for(int q=0;q<100;q++){
			//_delay_ms(25);
			spi_write_packet(&SPIC, cmd_A, 1);
			_delay_ms(25);
			sendString_PORTE("T1:");
			while (true){
				spi_write_single(&SPIC,CONFIG_SPI_MASTER_DUMMY); //Dummy write
				_delay_us(200);
				while (!spi_is_rx_full(&SPIC)) {}
				rx_byte = spi_get(&SPIC);
				//sendString_PORTE(rx_byte);
				sendChar_PORTE(rx_byte);
				if (rx_byte==':'){break;}
			}
			sendChar_PORTE('\n');
			sendChar_PORTE('\r');
		}
		spi_deselect_device(&SPIC, system_tiles[i]);
	}
	setLED('G',0);
	
	
}

char readPortE_char(void){
	if((USARTE0_STATUS & USART_RXCIF_bm)){
		return usartPORTE_getc();
	}
	else {
		return 'X';
	}
}