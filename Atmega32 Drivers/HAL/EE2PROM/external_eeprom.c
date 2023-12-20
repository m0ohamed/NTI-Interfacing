 /******************************************************************************
 *
 *
 * File Name: external_eeprom.c
 *
 * Description: Source file for the External EEPROM Memory
 *
 *
 *******************************************************************************/
#include "external_eeprom.h"
#include "../../MCAL/I2C/Includes/TWI.h"

void EEPROM_writeByte(uint16 u16addr, uint8 u8data)
{
	/* Send the Start Bit */
	TWI_SendStartCondition();

		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
	TWI_SlaveAddressWrite((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));

		 
    /* Send the required memory location address */
	TWI_SlaveAddressWrite((uint8)(u16addr));

    /* write byte to eeprom */
	TWI_MRSendData(u8data);


    /* Send the Stop Bit */
	TWI_enuStop();
	
}

void EEPROM_readByte(uint16 u16addr, uint8 *u8data)
{
	/* Send the Start Bit */
	TWI_SendStartCondition();

		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
	TWI_SlaveAddressWrite((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));

		
    /* Send the required memory location address */
	TWI_SlaveAddressWrite((uint8)(u16addr));

		
    /* Send the Repeated Start Bit */
	TWI_SendStartCondition();

		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
	TWI_SlaveAddressWrite((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));


    /* Read Byte from Memory without send ACK */
     TWI_ReadByteWithNAck(u8data);


    /* Send the Stop Bit */
     TWI_enuStop();

}
