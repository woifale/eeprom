/******************************************/
/** eeprom                               **/
/** Verison 1.0                          **/
/** Author: nucleus                      **/
/** Reff: According to examples in book  **/
/** "make: avr programmin"               **/
/******************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "mydefinitions.h"
#include "usart.h"
#include "spi.h"
#include "MC25LC256.h"
#include "menu.h"


void main (void) {

  usartInit(MYUBRR);
  transmitString("EEprom.c Version 1.0\n");

  SPI_initMaster();

  while(1){

    MainMenu();
    
  }
}
