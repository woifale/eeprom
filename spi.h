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
#define DD_SS    DDB2
#define DD_MOSI  DDB3
#define DD_SCK   DDB5

#define SPI_MISO_PORT  PORTB
#define SPI_MISO PORTB4

/* Slave Select aktivieren */
#define SELECT_SLAVE  PORTB &= ~(1 << 2)
/* Slave Select deaktivieren */
#define DESELECT_SLAVE PORTB |= (1 << 2)


void    SPI_initMaster(void);
void    SPI_writeStatReg(uint8_t byte);
void    SPI_writeByte(uint8_t byte);
uint8_t SPI_readByte(void);


#endif   /*endif __SPI_H__ */

