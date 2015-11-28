/*
 * initializers.c
 * Initialization Functions
 * Created: 5/7/2015 4:34:35 PM
 *  Author: Camacho
 */ 
#include <asf.h>
#include "initializers.h"

void setUp32MhzInternalOsc(void)
{
// Configure clock to 32MHz
OSC.CTRL |= OSC_RC32MEN_bm | OSC_RC32KEN_bm;  /* Enable the internal 32MHz & 32KHz oscillators */
while(!(OSC.STATUS & OSC_RC32KRDY_bm));       /* Wait for 32Khz oscillator to stabilize */
while(!(OSC.STATUS & OSC_RC32MRDY_bm));       /* Wait for 32MHz oscillator to stabilize */
DFLLRC32M.CTRL = DFLL_ENABLE_bm ;             /* Enable DFLL - defaults to calibrate against internal 32Khz clock */
CCP = CCP_IOREG_gc;                           /* Disable register security for clock update */
CLK.CTRL = CLK_SCLKSEL_RC32M_gc;              /* Switch to 32MHz clock */
OSC.CTRL &= ~OSC_RC2MEN_bm;                   /* Disable 2Mhz oscillator */
	
}

void setupIOpins(void){
	//LED PINS
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 0), IOPORT_DIR_OUTPUT);
	//ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 4), IOPORT_DIR_OUTPUT); HUB SlaveSelect 
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 4), IOPORT_DIR_OUTPUT);
	//BLUETOOTH HARDWARE WAKE PINS
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 1), IOPORT_DIR_OUTPUT);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 1), IOPORT_DIR_OUTPUT);
	//USART PORT E
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTE, 3), IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTE, 2), IOPORT_DIR_INPUT);	
	//USART PORT C
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 3), IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTC, 2), IOPORT_DIR_INPUT);	
	//USART PORT D
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT);	
	//USB PORT D
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 7), IOPORT_DIR_OUTPUT);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 6), IOPORT_DIR_INPUT);
	//SPI SYSTEM
    ioport_configure_port_pin(&PORTA, PIN0_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 1 Mag Slave Select
    ioport_configure_port_pin(&PORTA, PIN2_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 2 Mag Slave Select
	ioport_configure_port_pin(&PORTA, PIN4_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 3 Mag Slave Select
    ioport_configure_port_pin(&PORTA, PIN6_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 4 Mag Slave Select
    ioport_configure_port_pin(&PORTB, PIN0_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 5 Mag Slave Select
    ioport_configure_port_pin(&PORTB, PIN2_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 6 Mag Slave Select
    ioport_configure_port_pin(&PORTB, PIN4_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 7 Mag Slave Select
    ioport_configure_port_pin(&PORTB, PIN6_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 8 Mag Slave Select
    ioport_configure_port_pin(&PORTB, PIN7_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);//TILE 9 Mag Slave Select	
	
    ioport_configure_port_pin(&PORTC, PIN4_bm, IOPORT_PULL_UP | IOPORT_DIR_INPUT);
    ioport_configure_port_pin(&PORTC, PIN5_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);
    ioport_configure_port_pin(&PORTC, PIN6_bm, IOPORT_DIR_INPUT);
    ioport_configure_port_pin(&PORTC, PIN7_bm, IOPORT_INIT_HIGH | IOPORT_DIR_OUTPUT);

}

