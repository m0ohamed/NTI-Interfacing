#ifndef TWI_PRV_H
#define TWI_PRV_H
/*
 * I2C_prv.h
 *
 * Created: 10/30/2023 12:14:59 PM
 *  Author: HP
 */
#include "../../../Services/Lib/std_types.h"



#define TWBR_Reg   *((volatile uint8*)0x20)
#define TWSR_Reg   *((volatile uint8*)0x21)
#define TWAR_Reg   *((volatile uint8*)0x22)
#define TWDR_Reg   *((volatile uint8*)0x23)
#define TWCR_Reg   *((volatile uint8*)0x56)








/* TWCR PINS */
#define TWCR_TWINT             7
#define TWCR_TWEA              6
#define TWCR_TWSTA             5
#define TWCR_TWSTO             4
#define TWCR_TWWC              3
#define TWCR_TWEN              2
#define TWCR_TWIE              0

/* TWSR PINS */
#define TWSR_TWPS1             1
#define TWSR_TWPS0             0

/* TWAR PINS */
#define TWAR_TWGCE             0

void TWI_TWBR(uint8 );

/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */


 /* I2C_PRV_H_ */

#endif
