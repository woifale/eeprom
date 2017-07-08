/***********************************/
/** spi.c                         **/
/** Version 1.0                   **/
/** Author: nucleus               **/
/***********************************/

#include "spi.h"



/* Set SPI in master mode */
void SPI_initMaster(void){

  /* Set MOSI and SCK output, SS output, all others input */
  DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DD_SS);

  /* Pull up resistor for MISO */
  //SPI_MISO_PORT |= (1<<SPI_MISO);
  
  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
  transmitString("Init SPI...->");
  printBinaryByte(SPCR);
  transmitByte('\n');
  
}


void SPI_writeStatReg(uint8_t byte){

}


void SPI_writeByte(uint8_t byte){
  
  /* Start transmission */
  SPDR = byte;

  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF)));
  
}


uint8_t SPI_readByte(void){

  uint8_t byte;

  /* Read Byte from SPI shift register */
  byte = SPDR;

  return(byte);
}
