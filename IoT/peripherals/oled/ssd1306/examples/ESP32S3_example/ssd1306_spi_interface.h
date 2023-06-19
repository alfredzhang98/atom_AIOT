#ifndef __SSD1306_SPI_INTERFACE__H
#define __SSD1306_SPI_INTERFACE__H			  	 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TODO: the board libs
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#define OLED_CMD 0
#define OLED_DATA 1

extern void oledSpiInit(void);
extern void writeByteCMD(unsigned char dat);
extern void writeByteDATA(unsigned char dat);
extern void oledSpiReset(void);
extern void delay_ms(unsigned int ms);

#endif