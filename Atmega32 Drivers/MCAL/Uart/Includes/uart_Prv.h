#ifndef UART_PRV_H
#define UART_PRV_H


#include "../../../Services/Lib/std_types.h"
#define UBRRH  *((uint8*)0x40)
#define UCSRC  *((uint8*)0x40)
#define UCSRA  *((uint8*)0x2B)
#define UCSRB  *((uint8*)0x2A)
#define UBRRL  *((uint8*)0x29)
#define UDR  *((uint8*)0x2C)

#define BUAD_RATE(BUAD)            ((F_cpu/(16*BUAD))-1)
#define BUAD_RATE_DOUPLY(BUAD)     ((F_cpu/(8*BUAD))-1)

#endif
