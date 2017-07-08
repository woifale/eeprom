/***********************************/
/** menu.h                        **/
/** Version 1.0                   **/
/** Author: nucleus               **/
/***********************************/


#ifndef __MENU_H__
#define __MENU_H__

#include <stdbool.h>
#include <avr/io.h>
#include "usart.h"
#include "MC25LC256.h"


void MainMenu(void);
void SPIMenu(void);
void EEPROMMenu(void);

void narrate_SPCR(void);
void narrate_SPSR(void);

#endif /* __MENU_H__ */
