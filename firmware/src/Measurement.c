/* 
 * File:   Measurement.c
 * Author: Kartha.
 *
 * Created on July 30, 2019, 6:30 PM
 */

#include "app.h"

float CoffArray[4][5] = { {TEMP0_COFF_A_0, TEMP0_COFF_A_1, TEMP0_COFF_A_2, TEMP0_COFF_A_3, TEMP0_COFF_A_4}
                         ,{TEMP1_COFF_A_0, TEMP1_COFF_A_1, TEMP1_COFF_A_2, TEMP1_COFF_A_3, TEMP1_COFF_A_4}
                         ,{TEMP2_COFF_A_0, TEMP2_COFF_A_1, TEMP2_COFF_A_2, TEMP2_COFF_A_3, TEMP2_COFF_A_4}
                         ,{PRESSURE_COFF_A_0, PRESSURE_COFF_A_1, PRESSURE_COFF_A_2, PRESSURE_COFF_A_3, PRESSURE_COFF_A_4}
                        };
UINT16 AdcVal[NO_OF_ADC_CHANNELS_IN_USE];       // Only one temperature channel need to be measured.

float TempArray[10];
float VolatgeArray[10];


/**
 * Here resistance is measured using potential divider 
 * @param Voltage is the voltage read from ADC in volts
 * @return return resistance in ohms
 */

float GetResistance(float Voltage)
{
    float Resistance;
    Voltage  = PIC32_VREFF / Voltage;
    Voltage = Voltage - 1.0;
    Resistance = POTENTIAL_DIVIDER_R1 / Voltage;
    return Resistance;
}

/**
 * This function is used to get the resistance of the resistor connected in the potential divider.
 * Caution this function will only works when the supply to the potential divider and ADC VREFF is same.
 * @param AdcValue, Row ADC reading.
 * @return, resistance value.
 */

float GetRfromADCValue(UINT16 AdcValue)
{
   return (AdcValue * POTENTIAL_DIVIDER_R1) / (ADC_EOB - AdcValue);     // 4095 is ADC resolution.;
}

/**
 * converts data into natural logarithm
 * @param data
 * @return log data
 */

float Ln(float data)
{
    return (log10(data) * 2.302585092994045);
}

/**
 * converts resistance into temperature with standard thermistor coefficients
 * @param Resistance
 * @return Temperature in degree C
 * Note : Here resistance to temperature coefficients will be same for all sensors, for a relative temp measurement
 * this is enough.
 */

float GetTemperature(float Resistance, BYTE Channel)
{
    float lnValue = 0;    
    float lnSquareValue = 0; 
    float lnCubeValue = 0; 
    float Temp = 0;
    lnValue = Ln(Resistance);
    lnSquareValue = lnValue * lnValue;
    lnCubeValue = lnSquareValue * lnValue;
    Temp = CoffArray[Channel][0] + (CoffArray[Channel][1] * lnValue) + (CoffArray[Channel][2] * lnSquareValue) + (CoffArray[Channel][3] * lnCubeValue);
    Temp = 1 / Temp;
    Temp -= 273.15;
    return Temp;
}

/**
 * This function is used to collect the ADC channels data.
 */

void CollectAdcChData()
{
    GetAdcDataNonBlock(AdcVal, NO_OF_ADC_CHANNELS_IN_USE);
    AdcStart();
}

/**
 * Function used for getting temperature readings from a thermistor connected to AN16.
 * @return Temperature in degrees.
 */

float GetTemp(BYTE Channel)
{
    static float PreviousTemp = 0;
//    if(GetAdcDataNonBlock(AdcVal, NO_OF_ADC_CHANNELS_IN_USE))
//    {
//        AdcStart();
//        printf("%d\t", AdcVal[Channel]);
//        PreviousTemp = GetTemperature(GetRfromADCValue(AdcVal[Channel]), Channel);
//    }
//    printf("%d\t%d\n\r", AdcVal[0], AdcVal[1]);
    PreviousTemp = GetTemperature(GetRfromADCValue(AdcVal[Channel]), Channel);
//    printf("%f\n\r",PreviousTemp);
    return PreviousTemp;
}

/**
 * This function is used to get the analog pressure sensor reading.
 * @return, It will return analog pressure sensor value.
 */

float GetAnalgVoltage()
{
    static float PrevVal = 0;
//    GetAdcDataNonBlock(AdcVal, NO_OF_ADC_CHANNELS_IN_USE);
//    AdcStart();
    PrevVal = (AdcVal[INPUT_VOLTAGE] * PIC32_ADC_RESOLUTION) * ATTENUATION;
    return PrevVal;
}

/**
 * 
 * @return 
 */

float TemperatureAnalysis(float *MaxTemp, float *MinTemp, float *AvgTemp)
{
    static float SumTemp;
    static BYTE Index = 0;
    CollectAdcChData();
    TempArray[Index] = GetTemp(TEMP_1);
    Index++;
    if (Index >= 10) 
    {
        *MinTemp = TempArray[0];
        *MaxTemp = TempArray[0];
        SumTemp = 0;
        for (Index = 0; Index < 10; Index++) 
        {
            if (TempArray[Index] < *MinTemp)
            {
                *MinTemp = TempArray[Index];
            }
            if (TempArray[Index] > *MaxTemp) 
            {
                *MaxTemp = TempArray[Index];
            }
            SumTemp += TempArray[Index];
        }
        Index = 0;
    }
    *AvgTemp = (float) SumTemp / 10;
}


/**
 *  
 * @param MaxVolt
 * @param MinVolt
 * @param AvgVolt
 * @return 
 */
float VoltageAnalysis(float *MaxVolt, float *MinVolt, float *AvgVolt)
{
    static float SumVolt;
    static BYTE Index = 0;
    CollectAdcChData();
    VolatgeArray[Index] = GetAnalgVoltage();
    Index++;
    if (Index >= 3) 
    {
        *MinVolt = VolatgeArray[0];
        *MaxVolt = VolatgeArray[0];
        SumVolt = 0;
        for (Index = 0; Index < 3; Index++) 
        {
            if (VolatgeArray[Index] < *MinVolt)
            {
                *MinVolt = VolatgeArray[Index];
            }
            if (VolatgeArray[Index] > *MaxVolt) 
            {
                *MaxVolt = VolatgeArray[Index];
            }
            SumVolt += VolatgeArray[Index];
        }
        Index = 0;
    }
    *AvgVolt = (float) SumVolt / 3;
}