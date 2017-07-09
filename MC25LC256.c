/***********************************/
/** MC25LC256.c                   **/
/** eeprom from microhip tech.    **/
/***********************************/


#include "MC25LC256.h"




void MC25LC256_send16BitAddress(uint16_t address){

}

uint8_t MC25LC256_readStatus(void){

  uint8_t ret;
  
  /* Start instruction */
  SELECT_SLAVE;
  
  /* Send status register read to eeprom */
  SPI_writeByte(MC25LC256_RDSR);

  /* Finish Instruction */
  DESELECT_SLAVE;
  
  /* Read received status */
  ret = SPI_readByte();

  /* shift another round to get results*/
  SELECT_SLAVE;
  SPI_writeByte(0);
  DESELECT_SLAVE;

  ret = SPI_readByte();
  
  return(ret);

}

void MC25LC256_writeEnable(void){

}

uint8_t MC25LC256_readByte(uint16_t address){

  uint8_t address_low;
  uint8_t address_high;
  uint8_t ret;

  address_low = address & 0x00ff;
  address_high = address >> 8;

  /*Start Instruction */
  SELECT_SLAVE;
  
  /* Enable Write */
  SPI_writeByte(MC25LC256_WRDI);

  /*End Instruction */
  DESELECT_SLAVE;

  /* Start Instruction */
  SELECT_SLAVE;
  
  /* Send Read Command to MC25LC256 */
  SPI_writeByte(MC25LC256_READ);

  /* Send Address MSB first */
  SPI_writeByte(address_high);
  SPI_writeByte(address_low);

  /* Shift another round to get results*/
  SPI_writeByte(0);
  
  /* Finish Instruciton */
  DESELECT_SLAVE;
  
  /* Read Byte from SPI */
  ret = SPI_readByte();
  
  return(ret);
}

uint16_t MC25LC256_readWord(uint16_t address){

  uint16_t ret;
  return(ret);
}

void MC25LC256_writeByte(uint16_t address, uint8_t byte){

  uint8_t address_low;
  uint8_t address_high;

  address_low = address & 0x00ff;
  address_high = address >> 8;

  /* Start instruction */
  SELECT_SLAVE;
  
  /* Enable MC25LC256 write operations */
  SPI_writeByte(MC25LC256_WREN);

  /* Finish Instruction */
  DESELECT_SLAVE;

  /* Start Instruction */
  SELECT_SLAVE;
  
  /* Send WriteCommand to MC25LC256 */
  SPI_writeByte(MC25LC256_WRITE);

  /* Send Address MSB first */
  SPI_writeByte(address_high);
  SPI_writeByte(address_low);

  /* Send Data Byte */
  SPI_writeByte(byte);

  /* Finish Instruction */
  DESELECT_SLAVE;
  
}

void MC25LC256_writeWord(uint16_t address, uint8_t bate){

}

void MC25LC256_clearAll(void){

}
