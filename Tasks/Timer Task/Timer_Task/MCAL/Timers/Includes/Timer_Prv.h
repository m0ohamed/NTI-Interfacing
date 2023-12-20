#ifndef TIME_PRV_H
#define TIME_PRV_H
#include "Timer.h"

#define  TCCR0      *((volatile uint8*)0x53)
#define  TCNT0      *((volatile uint8*)0x52)
#define  OCR0       *((volatile uint8*)0x5C)
#define  ICR1H      *((volatile uint8*)0x4F)
#define  ICR1L      *((volatile uint8*)0x47)

#define  TCCR1A     *((volatile uint8*)0x4F)
#define  TCCR1B     *((volatile uint8*)0x4E)
#define  TCNT1      *((volatile uint16*)0x4C)
#define  OCR1A      *((volatile uint16*)0x4A)

#define  OCR1BH     *((volatile uint8*)0x49)
#define  OCR1BL     *((volatile uint8*)0x48)
#define  TCCR2      *((volatile uint8*)0x45)
#define  TCNT2      *((volatile uint8*)0x44)
#define  OCR2       *((volatile uint8*)0x43)
#define  TIMSK      *((volatile uint8*)0x59)


void Timer0_Init(void);
void Timer1_Init(void);
void Timer2_Init(void);

#endif
