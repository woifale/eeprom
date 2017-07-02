/***********************************/
/** spi.c                         **/
/** Version 1.0                   **/
/** Author: nucleus               **/
/***********************************/

#include "spi.h"



/* Set SPI in master mode */
void initSPI_Master(void){

  /* Set MOSI and SCK output, SS output, all others input */
DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DDB2);

  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
  transmitString("Init SPI...->");
  printBinaryByte(SPCR);
  transmitByte('\n');
  
}


void writeSPI_StatReg(uint8_t byte){

}


void SPI_tradeByte(uint8_t byte){

}
