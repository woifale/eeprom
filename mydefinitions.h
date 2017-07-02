/*
 * mydefinitions.h
 *
 *  Created on: 30.06.2017
 *     Author: nucleus
 */

#ifndef MYDEFINITIONS_H_
#define MYDEFINITIONS_H_

#ifndef FOSC
#warning !!!!FOSC_set_in_mydefinitions.h!!!!
#define FOSC 8000000UL
#endif

#ifndef F_CPU
#warning !!!!F_CPU_set_in_mydefinitions.h!!!!
#define F_CPU 8000000UL
#endif

#ifndef BAUD
#warning !!!!BAUD_set_in_mydefinitions.h!!!!
#define BAUD 9600UL
#endif

#ifndef USE_2X
#define USE_2X
#warning !!!!USE_2X!!!!
#endif
#undef USE_2X

#ifndef MYUBRR
#ifndef USE_2X
#define MYUBRR (F_CPU/(16*BAUD))-1
#warning !!!!set_ubrr_16!!!!
#else 
#define MYUBRR (F_CPU/(8*BAUD))-1
#warning !!!!set_ubrr_8!!!!
#endif
#endif


#endif /* MYDEFINITIONS_H_ */
