/*
 * usart.h
 *
 *  Created on: 25.06.2017
 *      Author: nucleus
 */

#ifndef USART_H_
#define USART_H_


#include "mydefinitions.h"
#include <util/setbaud.h>
#include "usart.h"
#include "spi.h"


void usartInit(unsigned int baudrate);
void transmitString(const char string2transmit[]);
void transmitByte(uint8_t byte2transmit);
void printByte(uint8_t byte);
void printBinaryByte(uint8_t byte);
uint8_t receiveByte_blocking(void);


#endif /* USART_H_ */
