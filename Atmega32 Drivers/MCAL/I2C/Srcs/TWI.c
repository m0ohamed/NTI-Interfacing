#include "../Includes/TWI.h"
#include "../Includes/TWI_Cfg.h"
#include "../Includes/TWI_Prv.h"


TWI_ErrorStatus TWI_enuInit(TWI_COnfigType* Config_Ptr)
{
	uint8 ErrorStatus=TWI_enuOK;
	if(Config_Ptr==Null_ptr)
	{
		ErrorStatus=TWI_NullPointer;
	}

	TWCR_Reg |=(TWCR_Reg & 0xBF) | ((Config_Ptr->ACK)<<TWCR_TWEA);
	TWSR_Reg =(TWSR_Reg & 0xFC)  |  ((Config_Ptr->Prescaler)<<TWSR_TWPS0);
	TWAR_Reg = ((Config_Ptr->Address));
	TWI_TWBR(Config_Ptr->Data_Rate);

	return ErrorStatus;
}

void TWI_TWBR(uint8 DataRate)
{
	TWBR_Reg=(F_CPUC /(DataRate*2))-8;
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWCR_Reg |= (1<<TWCR_TWINT)|(1<<TWCR_TWSTA) |(1<<TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_START))
	{
		ErrorStatus=TWI_Start_Error;
	}
	return ErrorStatus;

}

TWI_ErrorStatus TWI_SlaveAddressRead(uint8 Add)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;

	TWDR_Reg = ((Add<<1) |0x01);
	TWCR_Reg |= (1<<TWCR_TWINT) |(1<<TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_MT_SLA_R_ACK))
	{
		ErrorStatus=TWI_AddressACK;
	}
	else
	{
		TWCR_Reg &=~(1<<TWCR_TWEA);
	}

	return ErrorStatus;

}

TWI_ErrorStatus TWI_SlaveAddressWrite(uint8 Add)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWDR_Reg =((Add<<1) & 0xFE );
	TWCR_Reg = (1<<TWCR_TWINT) |(1<<TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_MT_SLA_W_ACK))
	{
		ErrorStatus=TWI_AddressACK;
	}
	else
	{
		TWCR_Reg &=~(1<<TWCR_TWEA);
	}
	return ErrorStatus;

}

TWI_ErrorStatus TWI_ReadByteWithAck(pu8 Add_RevievedData)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWCR_Reg |= (1 << TWCR_TWINT) | (1 << TWCR_TWEN) | (1 << TWCR_TWEA);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_MR_DATA_ACK))
	{
		ErrorStatus=TWI_RDataACK;
	}
	else
	{
		*Add_RevievedData=TWDR_Reg;


	}
	return ErrorStatus;
}

TWI_ErrorStatus TWI_ReadByteWithNAck(pu8 Add_RevievedData)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWCR_Reg |= (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_MR_DATA_NACK))
	{
		ErrorStatus=TWI_RDataACK;
	}
	else
	{
		*Add_RevievedData=TWDR_Reg;


	}
	return ErrorStatus;
}

void TWI_Status(pu8 Add_pu8Status)
{
	*Add_pu8Status=((TWSR_Reg & 0xF8));
}



TWI_ErrorStatus TWI_MRSendData(uint8 Data)
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWDR_Reg=Data;
	TWCR_Reg |= (1 << TWCR_TWINT) | (1 << TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));
	TWI_Status(&Status);
	if(!(Status==TWI_MT_DATA_ACK))
	{
		ErrorStatus=TWI_SDataACK;
	}

	return ErrorStatus;

}

void TWI_enuStop()
{
	uint8 ErrorStatus=TWI_enuOK;
	uint8 Status;
	TWCR_Reg |= (1<<TWCR_TWINT)|(1<<TWCR_TWSTO) |(1<<TWCR_TWEN);
	while (!(TWCR_Reg & (1<<TWCR_TWINT)));


}

