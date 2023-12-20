
#include "../Includes/lm35_sensor.h"
#include "../Includes/lm35_Cfg.h"

#include <util/delay.h>
#include "../../../MCAL/ADC/Includes/ADC.h"


void LM35_getTemperature(uint16 data,pu16 Add_pu16Value)
{


	*Add_pu16Value = (uint8)(((uint32)data*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

}

