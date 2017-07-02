#include <avr/io.h>
#include "usart.h"


void usartInit(unsigned int baudrate) {

    //Set baud rate
	//UBRR0H = (MYUBRR >> 8);
	//UBRR0L = MYUBRR
    UBRR0H = (unsigned char) (baudrate>>8);
    UBRR0L = (unsigned char) baudrate;
	//UBRR0H = UBRRH_VALUE;
	//UBRR0L = UBRRL_VALUE;
#if USE_2X
    UCSR0A |= (1 << U2X0);
#else
    UCSR0A &= ~(1 << U2X0);
#endif

    //Enable receiver and transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

    //Set frame format 8N1
    // UCSZ0 - number of data bits
    //      5 bit       000;
    //      6 bit       001,
    //      7 bit       010,
    //      8 bit       011,
    //      reserved    100,
    //      reserved    101,
    //      reserved    110,
    //      9 bit       111;

    // UPMN0 - parity mode
    //      disabled    00,
    //      reserved    01,
    //      even        10,
    //      odd         11;

    // USBS0 - number of stop bits
    //      1 bit       0,
    //      2 bits      1;

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
    //UCSR0C |= (1<<URSEL) | (1<<UCSZ01) | (1<<UCSZ00);

    //UCSR0C = (3<<UCSZ00) | (0<<UPM00) | (0<<USBS0);

    //Set USART mode
    // UMSEL0 - USART mode
    //      asynchronous    00,
    //      synchronous     01,
    //      reserved        10,
    //      master SPI      11;


//    UCSR0C |= (0<<UMSEL00);

}

void transmitByte(uint8_t byte2transmit) {

    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = byte2transmit;
}


void transmitString(const char string2transmit[]) {

    // Loop characterwise throuhg string

    uint8_t i = 0;
    while (string2transmit[i]) {
        //Schreibe Zeichen in USART
        transmitByte(string2transmit[i]);
        i++;
    }

}

void printByte(uint8_t byte) {

  // Convert a Byte to a stirng of decimal text, sends it
  transmitByte('0'+ (byte/100));         /* hundrets */
  transmitByte('0'+ (byte/10) % 10);     /* tens     */
transmitByte('0' + (byte % 10));         /* ones     */
}

void printBinaryByte(uint8_t byte) {

  // Convert a Byte to a string of zeros and ones and send is as text
  uint8_t bit;

  for(bit=7;bit<255;bit--) {
    if (bit_is_set(byte,bit))
      transmitByte('1');
    else transmitByte('0');
  }
}

uint8_t receiveByte_blocking(void) {

  loop_until_bit_is_set(UCSR0A, RXC0);
  return(UDR0);
  
}
