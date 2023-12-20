#ifndef ADC_PRV_H
#define ADC_PRV_H



#define ADMUX    *((volatile uint8*)0x27)

#define ADCSRA    *((volatile uint8*)0x26)

#define ADC    *((volatile uint16*)0x24)
#define	ADCH    *((volatile uint8*)0x25)
#define ADCL    *((volatile uint8*)0x24)

#endif
