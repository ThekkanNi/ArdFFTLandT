/* 
 * File:   Measurement.h
 * Author: Kartha.
 *
 * Created on July 30, 2019, 6:31 PM
 */

#ifndef MEASUREMENT_H
#define	MEASUREMENT_H

/** Board depending parameters */

#define     PIC32_ADC_RESOLUTION          8.0586080586e-4         // 3.3 / 4095, this may vary from board to board.
#define     PIC32_VREFF                   3.3
#define     POTENTIAL_DIVIDER_R1          10000.0
#define     ADC_EOB                       4095.0
#define     PRESSURE_GAIN_FACTOR          0.02014652        // The adc result is actually sampled from the output of an opamp, with a 
                                                            // gain = 14. So we need to divide the value by 14 in order to convert to 
                                                            // volts we have to multiply the result with 3.3/4095 And since the max out at
                                                            // max pressure is 0.2 volts at 70 bar we can convert the voltage to bar my 
                                                            // multiplying the voltage with 70/0.2 for the equation become like this 
                                                            // Pressure = ADC value* ((3.3*70)/(4095*14*0.2))
                                                            // Pressure = 0.02014652 * ADC value

#define     ATTENUATION                     1

// Multiplying with STRAIN_ADC_GAIN_FACTOR is because, the voltage is coming from a potential divider with some attenuation around 0.5.  
#define     STRAIN_ADC_GAIN_FACTOR          1.998   

#define     TEMP0_COFF_A_0                    1.2286184e-3        /* random coefficients */
#define     TEMP0_COFF_A_1                    1.9635006e-4
#define     TEMP0_COFF_A_2                    4.4736099e-6
#define     TEMP0_COFF_A_3                    -8.0735756e-8
#define     TEMP0_COFF_A_4                    0
#define     TEMP1_COFF_A_0                    1.2286184e-3        /* random coefficients */
#define     TEMP1_COFF_A_1                    1.9635006e-4
#define     TEMP1_COFF_A_2                    4.4736099e-6
#define     TEMP1_COFF_A_3                    -8.0735756e-8
#define     TEMP1_COFF_A_4                    0
#define     TEMP2_COFF_A_0                    1.2286184e-3        /* random coefficients */
#define     TEMP2_COFF_A_1                    1.9635006e-4
#define     TEMP2_COFF_A_2                    4.4736099e-6
#define     TEMP2_COFF_A_3                    -8.0735756e-8
#define     TEMP2_COFF_A_4                    0
#define     PRESSURE_COFF_A_0                 1.2286184e-3        /* random coefficients */
#define     PRESSURE_COFF_A_1                 1.9635006e-4
#define     PRESSURE_COFF_A_2                 4.4736099e-6
#define     PRESSURE_COFF_A_3                 -8.0735756e-8
#define     PRESSURE_COFF_A_4                 0

#define     TEMP_1                          0
#define     INPUT_VOLTAGE                   1

/*** TEMP DATA & VOLTAGE DATA  STRUCTURES */
typedef struct
{
    float MaxTemp;
    float MinTemp;
    float AverageTemp;
}TEMP_DATA;

typedef struct
{
    float MaxVoltage;
    float MinVoltage;
    float AverageVoltage;
}VOLT_DATA;

/** Functions */

float GetResistance(float Voltage);
float GetRfromADCValue(UINT16 AdcValue);
float GetTemperature(float Resistance, BYTE Channel);
float GetTemp(BYTE Channel);
//float GetAnalgPressure();
float GetAnalgVoltage();
//void UpdateEnvCoeff(SETT_PACKET *SettPacket);
void CollectAdcChData();
float TemperatureAnalysis(float *MaxTemp, float *MinTemp, float *AvgTemp);
float VoltageAnalysis(float *MaxVolt, float *MinVolt, float *AvgVolt);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MEASUREMENT_H */

