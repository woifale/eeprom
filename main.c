/******************************************/
/** eeprom                               **/
/** Verison 1.0                          **/
/** Author: nucleus                      **/
/** Reff: According to examples in book  **/
/** make: avr programming                **/
/******************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "mydefinitions.h"
#include "usart.h"
#include "spi.h"
#include "25LC256.h"
#include "menu.h"


void main (void) {

  usartInit(MYUBRR);
  transmitString("EEprom.c Version 1.0\n");

  initSPI_Master();

  while(1){

    MainMenu();
    
  }
}
