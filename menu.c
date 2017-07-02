/***********************************/
/** menu.c                        **/
/** Version 1.0                   **/
/** Author: nucleus               **/
/***********************************/


#include "menu.h"


void MainMenu(void){

  char choice;

  transmitString("========================\n");
  transmitString("Main Menu\n");
  transmitString("========================\n");
  transmitString("Please choose an action:\n");
  transmitString("------------------------\n");
  transmitString("  1. SPI Menu\n");
  transmitString("  2. EEPROM Menu\n");
  transmitString("------------------------\n");
  transmitString("Your choice: ");

  /* Blocking Bytereceive */
  choice = receiveByte_blocking();

  switch(choice){
  case('1'):
    transmitString("1\n");
    transmitByte('\n');
    SPIMenu();
    break;
  case('2'):
    transmitString("2\n");
    transmitByte('\n');
    EEPROMMenu();
    break;
  default:
    transmitByte(choice);
    transmitString(" Choice not supported.\n");
    transmitByte('\n');
  }
  
}

void SPIMenu(void){
  char choice;
  bool leave = false;

  while(leave == false){
  
    transmitString("========================\n");
    transmitString("SPI Menu\n");
    transmitString("========================\n");
    transmitString("Please choose an action:\n");
    transmitString("------------------------\n");
    transmitString("  1. Print ControlReg\n");
    transmitString("  2. Print StatusReg\n");
    transmitString("  3. Print SPI-DD\n");
    transmitString("  0. Exit\n");
    transmitString("------------------------\n");
    transmitString("Your choice: ");

    /* Blocking Bytereceive */
    choice = receiveByte_blocking();

    switch(choice){
    case('0'):
      transmitString("0\n");
      leave = true;
      break;
    case('1'):
      transmitString("1\n");
      transmitString("SPI Control Register: ");
      printBinaryByte(SPCR);
      transmitByte('\n');
      narrate_SPCR();
      transmitByte('\n');
      break;
    case('2'):
      transmitString("2\n");
      transmitString("SPI Status Register: ");
      printBinaryByte(SPSR);
      transmitByte('\n');
      narrate_SPSR();
      transmitByte('\n');
      break;
    case('3'):
      transmitString("3\n");
      transmitString("SPI Data Direction: ");
      printBinaryByte(DDR_SPI);
      transmitByte('\n');
      break;
    default:
      transmitByte(choice);
      transmitString(" Choice not supported.\n");
      transmitByte('\n');
    } /*End switch */

    if(leave == true) break;

  } /*End while leave == false */
}

void EEPROMMenu(void){
  char choice;
  bool leave = false;

  while(leave == false){
  
    transmitString("========================\n");
    transmitString("EEPROM Menu\n");
    transmitString("========================\n");
    transmitString("Please choose an action:\n");
    transmitString("------------------------\n");
    transmitString("  0. Exit\n");
    transmitString("------------------------\n");
    transmitString("Your choice: ");

    /* Blocking Bytereceive */
    choice = receiveByte_blocking();

    switch(choice){
    case('0'):
      transmitString("0\n");
      leave = true;
      break;
    default:
      transmitByte(choice);
      transmitString(" Choice not supported.\n");
      transmitByte('\n');
    } /*End switch */

    if(leave == true) break;

  } /*End while leave == false */

}

void narrate_SPCR(void){

  transmitString("Bit7 - SPIE0:  SPI0 Interrupt Enable => ");
  if(bit_is_set(SPCR, SPIE)){
    transmitByte('1');
    transmitString(" => Enabled\n");
  }
  else{
    transmitByte('0');
    transmitString(" => Disabled\n");
  }

  transmitString("Bit6 - SPE0 :  SPIO Enable           => ");
  if(bit_is_set(SPCR, SPE)){
    transmitByte('1');
    transmitString(" => Enabled\n");
  }
  else{
    transmitByte('0');
    transmitString(" => Disabled\n");
  }

  transmitString("Bit5 - DORD0:  Data0 Order           => ");
  if(bit_is_set(SPCR, DORD)){
    transmitByte('1');
    transmitString(" => LSB transmit first\n");
  }
  else{
    transmitByte('0');
    transmitString(" => MSB transmit first\n");
  }

  transmitString("Bit4 - MSTR0:  Master/Slave Select   => ");
  if(bit_is_set(SPCR, MSTR)){
    transmitByte('1');
    transmitString(" => Master\n");
  }
  else{
    transmitByte('0');
    transmitString(" => Slave\n");
  }
  transmitString("Bit3 - CPOL0:  Clock0 Polarity       => ");
  if(bit_is_set(SPCR, CPOL)){
    transmitByte('1');
    transmitString(" => SCK high when idle\n");
  }
  else{
    transmitByte('0');
    transmitString(" => SCK low when idle\n");
  }
  transmitString("Bit2 - CPHA0:  Clock0 Phase          => ");
  if(bit_is_set(SPCR, CPHA)){
    transmitByte('1');
    transmitString(" => Data sample at leading edge of SCK\n");
  }
  else{
    transmitByte('0');
    transmitString(" => Data sample at trailing edge of SCK\n");
  }
  transmitString("Bit1 - SPR01:  SPI0 Clock Rate Select     => ");
  if((SPCR & 0x03 == 0) && bit_is_set(SPSR, SPI2X))
    transmitString("FOSC/2\n");
  if((SPCR & 0x03 == 1) && bit_is_set(SPSR, SPI2X))
    transmitString("FOSC/8\n");
  if((SPCR & 0x03 == 2) && bit_is_set(SPSR, SPI2X))
    transmitString("FOSC/32\n");
  if((SPCR & 0x03 == 3) && bit_is_set(SPSR, SPI2X))
    transmitString("FOSC/64\n");
  if((SPCR & 0x03 == 0) && !(bit_is_set(SPSR, SPI2X)))
    transmitString("FOSC/4\n");
  if((SPCR & 0x03 == 1) && !(bit_is_set(SPSR, SPI2X)))
    transmitString("FOSC/16\n");
  if((SPCR & 0x03 == 2) && !(bit_is_set(SPSR, SPI2X)))
    transmitString("FOSC/64\n");
  if((SPCR & 0x03 == 3) && (!bit_is_set(SPSR, SPI2X)))
    transmitString("FOSC/128\n");

  if(SPCR & 0x03 == 0) transmitString("HALLELUJA");
  
}

void narrate_SPSR(void){

  transmitString("Bit7 - SPIF0:  SPI Interrupt Flag    => ");
  if(bit_is_set(SPSR, SPIF)){
    transmitByte('1');
    transmitString(" => Serial transfer complete\n");
  }
  else{
    transmitByte('0');
    transmitString(" => Waiting for Serial transfer complete\n");
  }

  transmitString("Bit6 - WCOL0:  Write Collison Flag   => ");
  if(bit_is_set(SPSR, WCOL)){
    transmitByte('1');
    transmitString(" => Write Collision detected\n");
  }
  else{
    transmitByte('0');
    transmitString(" => No Write Collision detected\n");
  }

  transmitString("Bit0 - SPI2X0: Double SPI Spped Bit  => ");
  if(bit_is_set(SPSR, SPI2X)){
    transmitByte('1');
    transmitString(" => SCK speed doubled\n");
  }
  else{
    transmitByte('0');
    transmitString(" => normal Speed\n");
  }

}


