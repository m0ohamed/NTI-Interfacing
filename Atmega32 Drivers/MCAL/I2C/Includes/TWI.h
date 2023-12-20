#ifndef TWI_H
#define TWI_H
#define TWI_INTERRUPT_E           1
#define TWI_INTERRUPT_D           0



typedef enum
{
	Rate_100Kh,
	Rate_400Kh

}TWI_DataRate;

typedef enum
{
	ACK_Disable,
	ACK_Enable
}TWI_ACKEnable;

typedef enum
{
	Prescaler_1,
	Prescaler_4,
	Prescaler_16,
	Prescaler_64

}TWI_Prescaler;



typedef struct
{
	uint8 Address;
	TWI_DataRate Data_Rate;
	TWI_ACKEnable   ACK;
	TWI_Prescaler  Prescaler;
}TWI_COnfigType;
typedef enum
{
	TWI_enuOK,
	TWI_NullPointer,
	TWI_Start_Error,
	TWI_AddressACK,
	TWI_RDataACK,
	TWI_SDataACK
}TWI_ErrorStatus;


TWI_ErrorStatus TWI_enuInit(TWI_COnfigType* Config_Ptr);
TWI_ErrorStatus TWI_SendStartCondition(void);
TWI_ErrorStatus TWI_SlaveAddressRead(uint8 Add);
TWI_ErrorStatus TWI_SlaveAddressWrite(uint8 Add);
TWI_ErrorStatus TWI_ReadByteWithAck(pu8 Add_RevievedData);
TWI_ErrorStatus TWI_ReadByteWithNAck(pu8 Add_RevievedData);
TWI_ErrorStatus TWI_MRSendData(uint8 Data);
void TWI_enuStop();
void TWI_Status(pu8 Add_pu8Status);


#endif
