# Magnetic_SRI
Firmware for ATXMEGA Chip.
TO DO:
/* TODO:
	1. This hub is interfaced to the 8 tiles via the SPI interface !!!
	2. The 8 tiles ports share the same physical address but different ids in the hub and hence are multiplexed and interfaced with SPI interface i.e There is an spi slave
	select line (activate id )in the hub to  get the data from the 8 tiles serially
	3. this data is then sent to the bluetooth module over a TWI(I2C) connection this must be programmed in the hub itself.
	4. The bluetooth module transmits data serially to the android application which then processes data.
