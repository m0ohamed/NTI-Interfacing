#ifndef SPI_PRV_H
#define SPI_PRV_H
#include "../../../Services/Lib/std_types.h"
/* SPI */
/* SPI Control Register */
#define SPCR       *((volatile uint8*)0x2D)
/* SPI Status Register */
#define SPSR       *((volatile uint8*)0x2E)
/* SPI I/O Data Register */
#define SPDR       *((volatile uint8*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1

void SPI_MasterInit(SPI_ConfigType* MConfig);
void SPI_SlaveInit(SPI_ConfigType* SConfig);
#endif
