/***********************************/
/** spi.h                         **/
/** Version 1.0                   **/
/** Author: nucleus               **/
/***********************************/

#ifndef __SPI_H__
#define __SPI_H__

#include <avr/io.h>


#define DDRB3 3
#define DDRB5 5
    
#define DDR_SPI  DDRB
#define DD_MOSI  DDRB3
#define DD_SCK   DDRB5


void initSPI_Master(void);
void writeSPI_StatReg(uint8_t byte);
void SPI_tradeByte(uint8_t byte);


#endif   /*endif __SPI_H__ */

