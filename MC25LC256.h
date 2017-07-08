/***********************************/
/** MC25LC256.h                   **/
/** eeprom from microhip tech.    **/
/***********************************/

#ifndef __MC25LC256_H__
#define __MC25LC256_H__

#include <avr/io.h>
#include "spi.h"


/* Commands for MC25LC256 */
#define MC25LC256_READ   0b00000011
#define MC25LC256_WRITE  0b00000010
#define MC25LC256_WRDI   0b00000100
#define MC25LC256_WREN   0b00000110
#define MC25LC256_RDSR   0b00000101
#define MC25LC256_WRSR   0b00000001

/* Functions to operate with MC25LC256 */
void     MC25LC256_send16BitAddress(uint16_t address);
uint8_t  MC25LC256_readStatus(void);
void     MC25LC256_writeEnable(void);
uint8_t  MC25LC256_readByte(uint16_t address);
uint16_t MC25LC256_readWord(uint16_t address);
void     MC25LC256_writeByte(uint16_t address, uint8_t byte);
void     MC25LC256_writeWord(uint16_t address, uint8_t bate);
void     MC25LC256_clearAll(void);


#endif /*  endif  __MC25LC256_H__  */
