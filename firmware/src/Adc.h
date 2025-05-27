/* 
 * File:   Adc.h
 * Author: PT.
 *
 * Created on December 18, 2020, 12:39 PM
 */

#ifndef ADC_H
#define	ADC_H






/** ADC DRIVER MODE */

//#define     ADC_INTERRUPT_MODE
#define     ADC_POLLING_MODE

/** ADC USER CONFIGURABLE DEFINITIONS */

#define     NO_OF_ADC_CHANNELS_IN_USE       1       // MAXIMUM NO CHANNELS SHOULD NOT EXCEED 14 (MAX NO OF SHARED ADC CHANNELS IN PIC32)
//#define     ADC_SAMPLING_RATE_IN_SPS        280000       // WARINING :- ADC SAMLING RATE ENTERED HERE SHOULD BE WITHIN THE LIMIT
//#define     ADC_SAMPLING_RATE_IN_SPS        291000       // WARINING :- ADC SAMLING RATE ENTERED HERE SHOULD BE WITHIN THE LIMIT
#define     ADC_SAMPLING_RATE_IN_SPS        750000       // WARINING :- ADC SAMLING RATE ENTERED HERE SHOULD BE WITHIN THE LIMIT
//#define     ADC_SAMPLING_RATE_IN_SPS        100000       // WARINING :- ADC SAMLING RATE ENTERED HERE SHOULD BE WITHIN THE LIMIT
                                                        // 9633 SPS to 666666 SPS.(Cause apart from SAMC register value all
                                                        // ADC configure Parameters are set to a predefined value).
                                                        // The Scanning Frequency of ADC Then will be 
                                                        // Scanning Frequency = (ADC_SAMPLING_RATE_IN_SPS) / (NO_OF_ADC_CHANNELS_IN_USE)

/** ADC CHANNEL SPECIFICATION SECTION */

/**
 * NOTE :- USER SHOULD EDIT THIS AS PER THE CHANNEL REQUIREMENT , BEOFRE EDITING THIS NO_OF_ADC_CHANNELS_IN_USE SHOULD BE EDITED
 * AS PER REQUIREMENT.IF USER DEFINED CHANNEL NUMBER IS 5 THEN 5 CHANNEL NAME SHOULD BE SPECIFIED BELOW REMAINING CHANNELS CAN BE
 * COMMENTED SINCE IT WILL NOT USE BY THE DRIVE.
 * ADC CHANNELS THAT CAN BE USED HERE ARE AN5, AN6, AN7, AN8, AN9, AN10, AN11, AN12, AN13, AN14, AN15, AN16, AN17, AN18.
 */

#define     ADC_CHANNEL_NO_1                  9 
//#define     ADC_CHANNEL_NO_2                8 
//#define     ADC_CHANNEL_NO_3                48
//#define     ADC_CHANNEL_NO_4                2
//#define     ADC_CHANNEL_NO_5                8
//#define     ADC_CHANNEL_NO_6                9
//#define     ADC_CHANNEL_NO_7                5
//#define     ADC_CHANNEL_NO_8                12
//#define     ADC_CHANNEL_NO_9                13
//#define     ADC_CHANNEL_NO_10               14
//#define     ADC_CHANNEL_NO_11               16
//#define     ADC_CHANNEL_NO_12               18
//#define     ADC_CHANNEL_NO_13               7
//#define     ADC_CHANNEL_NO_14               10

/** ADC DAEFAULT PARAMETERS */

#define     TOTAL_NO_OF_SHARED_ADC_MODULES  14      // There is 14 Shared ADC Channels in 64 Pin PIC32MZ1024EFK064 MCU.

/** ADC CONSTANT PARAMETERS */

#define     ADC_DEFAULT_DIV_REG_VAL         5
#define     ADC_TCLK3                       (1 / (float)SYS_CLK_BUS_PERIPHERAL_3)
#define     ADC_TAD                         (ADC_TCLK3 * ADC_DEFAULT_DIV_REG_VAL * 2)   // TAD = ADCDIV * 2 * (1 / PBCLK3).

/** FUNCTIONS */

void AdcInit();
void AdcStart();
void AdcStop();
void AdcSetChannelForScanReg();
void SetAdcInterDataReadyStat(bool Status);
bool GetAdcInterDataReadyStat();
bool GetAdcDataNonBlock(UINT16 *DataBuffer, BYTE NoOfChannels);
void GetAdcDataBlocking(UINT16 *DataBuffer, BYTE NoOfChannels);
bool GetAdcInterrStatAndData(UINT16 *DataBuffer, BYTE NoOfChannels);
bool GetAdcScanStatAndData(UINT16 *DataBuffer, BYTE NoOfChannels);
void FillAdcLocalBuffer();
void PrintADc1(void);
void PrintADc2(void);
void UpdateDmaAdcDataToDac();


/** END */














#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

