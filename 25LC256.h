/***********************************/
/** 25LC256.h                     **/
/** eeprom from microhip tech.    **/
/***********************************/

#ifndef __25LC256_H__
#define __25LC256_H__

#include <avr/io.h>

void EEPROM_send16BitAddress(uint16_t address);
uint8_t EEPROM_readStatus(void);
void EEPROM_writeEnable(void);
uint8_t EEPROM_readByte(uint16_t address);
uint16_t EEPROM_readWord(uint16_t address);
void EEPROM_writeByte(uint16_t address, uint8_t byte);
void EEPROM_writeWord(uint16_t address, uint8_t bate);
void EEPROM_clearAll(void);


#endif /*  endif  __25LC256_H__  */
