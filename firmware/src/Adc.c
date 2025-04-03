
/******************************************************************************/
/**
 * Author : PT
 * Created Date : January 1, 2021, 7:47 PM.
 * Last update :  January 4, 2021, 3:43 PM.
 * Language : C
 */

/**
 * Preconditions:
 * 1. Analog Pins used for this drive should be locked in Harmony Pin Configurations.
 * 1. NO_OF_ADC_CHANNELS_IN_USE in Adc.h should be updated as per user's requirement.
 * 2. ADC Sampling speed required should be specified in ADC_SAMPLING_RATE_IN_SPS in file Adc.h keeping in mind that 
 *    sampling speed should be within the limit 9633 SPS to 666666 SPS.
 * 3. Buffer AdcChannelNoIndex Should be updated with user specifying which channels need to be used.
 * 4. ADC Drive can be configured in two modes with Interrupt Mode or polling mode user should configure this in ADC DRIVER MODE.
 */

/*
 * WARNING :- This ADC Drive only works for Shared ADC Channels so dedicated channels 
 *(AN0, AN1, AN2, AN3, AN4, AN45, AN46, AN47, AN48 , AN49) Cannot be used in this drive.
 * 
 * NOTE
 * This Drive works in Scanning Mode so If the user specifies a sampling speed of 10KSPS and uses 4 channels to read ,
 * effective Sampling Speed of the whole scanning process will be ADC Speed / No of Channels and the readings
 * will be phase shifted by a factor of the sampling speed of the individual channels and their order of priority.
 * (For Example if user wants to take AN8 and AN9 readings and configured for 10KSPS , according to priority AN8 is sampled
 * and converted first then AN9 is sampled and converted next causing the readings be phase shifted by the ADC Sampling 
 * speed).
 * WARNING :-     ADC CHANNLES THAT CAN BE USED BY THIS DRIVE ARE
 *                              AN5
 *                              AN6
 *                              AN7
 *                              AN8
 *                              AN9
 *                              AN10
 *                              AN11
 *                              AN12
 *                              AN13
 *                              AN14
 *                              AN15
 *                              AN16
 *                              AN17
 *                              AN18  
 */

/******************************************************************************/

#include "app.h"

extern volatile bool AdcStatus;                           // GIVES COUNT FOR ADC TIME
extern volatile bool ThresholdDetectFlag;                      // FLAG FOR GENERATING FREQEUNCY
volatile UINT16   AdData;  // varaible added  by nithin during testing




UINT16 AdcEofScanStat;      // Used for End of scan status bit.
UINT16 AdcData[TOTAL_NO_OF_SHARED_ADC_MODULES];      // Used For Storing ADC Data Obtained to this local buffer.
volatile bool AdcDataReadyFlag;     // Flag Indicating End of Scan Status.

volatile uint32_t  *AdcDataRegPoin[TOTAL_NO_OF_SHARED_ADC_MODULES] 
= 
{
    &ADCDATA5
  , &ADCDATA6
  , &ADCDATA7
  , &ADCDATA8
  , &ADCDATA9
  , &ADCDATA10
  , &ADCDATA11
  , &ADCDATA12
  , &ADCDATA13
  , &ADCDATA14
  , &ADCDATA15
  , &ADCDATA16
  , &ADCDATA17
  , &ADCDATA18
};

/**
 * WARNING :- THIS ADC Drive ONLY WORKS FOR SHARED ADC CHANNELS.
 * so CHANNLES THAT CAN BE USED ARE AN5, AN6, AN7, AN8, AN9, AN10, AN11, AN12, AN13, AN14, AN15, AN16, AN17, AN18.
 * NOTE :- USER SHOULD EDIT THIS BUFFER AS PER CHANNELS REQUIREMENT, FOR EG IF USING ONLY 4 CHANNELS THE BUFFER BELOW SHOULD
 * BE EDITED WITH THE BUFFER CONTAINING 4 ELEMENTS(REMAINIG ELEMENTS CAN BE COMMENTED OR REMOVED).
 * USER SHOULD ALSO EDIT THE NO_OF_ADC_CHANNELS_IN_USE DEFINITION IN THE Adc.h WHICH SPECIFIES THE ADC CHANNEL INDEX BUFFER SIZE.
 * AND ADC CHANNEL SPECIFICATION SECTION WHICH SPECIFIES THE CHANNEL NUMBER OF ADC IN USE. 
 */

UINT16 AdcChannelNoIndex[NO_OF_ADC_CHANNELS_IN_USE] 
= 
{   ADC_CHANNEL_NO_1
//  , ADC_CHANNEL_NO_2
//  , ADC_CHANNEL_NO_3
//  , ADC_CHANNEL_NO_4
//  , ADC_CHANNEL_NO_5
//  , ADC_CHANNEL_NO_6
//  , ADC_CHANNEL_NO_7
//  , ADC_CHANNEL_NO_8
//  , ADC_CHANNEL_NO_9
//  , ADC_CHANNEL_NO_10
//  , ADC_CHANNEL_NO_11
//  , ADC_CHANNEL_NO_12
//  , ADC_CHANNEL_NO_13
//  , ADC_CHANNEL_NO_14
};

/**
 * This Function initializes the Shared ADC Module in Scanning mode.
 */

void AdcInit()
{
    ADC0CFG = DEVADC0;      // Initialize ADC calibration setting.
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;
    
    ADCCON1 = 0;        // ADC Integer data format , No Scan trigger , ADC Module is turned off, charge pump disabled, continues operation in idle mode, CVD operation is disabled
    ADCCON2 = 0;        // Since we are using Class 1 inputs no setting is required for ADCDIV.   
    
    ADCCON3 = 0;
    
    ADCCON1bits.SELRES = 3;     // Shared ADC Resolution at 12 bits.

    ADCCON1bits.STRGSRC = 1;        // Scan trigger source selected for Global software edge trigger.

    
    
    ADCCON1bits.STRGLVL = 0;        // Scan Trigger is Positive edge sensitive.
    
    ADCCON2bits.SAMC = (UINT16)(1 / (ADC_TAD * ADC_SAMPLING_RATE_IN_SPS) - 15);     // For equation refer ADC PIC32 XL calc.
    ADCCON2bits.ADCDIV = ADC_DEFAULT_DIV_REG_VAL;
     
    ADCANCONbits.WKUPCLKCNT = 15;       // Wake-up Clock Count set to 32,768 clocks.
    
    ADCCON3bits.ADCSEL = 0;     // Analog-to-Digital Clock Source (TCLK) set to PBCLK3.
    ADCCON3bits.CONCLKDIV = 0;      // TQ = TCLK.
    ADCCON3bits.VREFSEL = 0;        // Voltage reference selected in AVDD AVSS.
    
    ADCFLTR1 = 0;       // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    
    ADCCMPCON1 = 0;     // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0;     // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0;
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;
    
    ADCEIEN1 = 0;       // No early interrupt.
    ADCEIEN2 = 0;
    
    ADCIMCON1bits.SIGN5 = 0;        // AN5 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN6 = 0;        // AN6 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN7 = 0;        // AN7 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN8 = 0;        // AN8 is using Unsigned Data Mode.          
    ADCIMCON1bits.SIGN9 = 0;        // AN9 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN10 = 0;        // AN10 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN11 = 0;        // AN11 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN12 = 0;        // AN12 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN13 = 0;        // AN13 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN14 = 0;        // AN14 is using Unsigned Data Mode.
    ADCIMCON1bits.SIGN15 = 0;        // AN15 is using Unsigned Data Mode.
    ADCIMCON2bits.SIGN16 = 0;        // AN16 is using Unsigned Data Mode.
    ADCIMCON2bits.SIGN17 = 0;        // AN17 is using Unsigned Data Mode.
    ADCIMCON2bits.SIGN18 = 0;        // AN18 is using Unsigned Data Mode.
    
    ADCIMCON1bits.DIFF5 = 0;        // AN5 is using Single ended Mode.
    ADCIMCON1bits.DIFF6 = 0;        // AN6 is using Single ended Mode.
    ADCIMCON1bits.DIFF7 = 0;        // AN7 is using Single ended Mode.
    ADCIMCON1bits.DIFF8 = 0;        // AN8 is using Single ended Mode.
    ADCIMCON1bits.DIFF9 = 0;        // AN9 is using Single ended Mode.
    ADCIMCON1bits.DIFF10 = 0;        // AN10 is using Single ended Mode.
    ADCIMCON1bits.DIFF11 = 0;        // AN11 is using Single ended Mode.
    ADCIMCON1bits.DIFF12 = 0;        // AN12 is using Single ended Mode.
    ADCIMCON1bits.DIFF13 = 0;        // AN13 is using Single ended Mode.
    ADCIMCON1bits.DIFF14 = 0;        // AN14 is using Single ended Mode.
    ADCIMCON1bits.DIFF15 = 0;        // AN15 is using Single ended Mode.
    ADCIMCON2bits.DIFF16 = 0;        // AN16 is using Single ended Mode.
    ADCIMCON2bits.DIFF17 = 0;        // AN17 is using Single ended Mode.
    ADCIMCON2bits.DIFF18 = 0;        // AN18 is using Single ended Mode.
    
    ADCTRG2bits.TRGSRC7 = 3;        // Scan Trigger for Conversion for AN7.
    ADCTRG2bits.TRGSRC6 = 3;        // Scan Trigger for Conversion for AN6.
    ADCTRG2bits.TRGSRC5 = 3;        // Scan Trigger for Conversion for AN5.
    ADCTRG3bits.TRGSRC8 = 3;        // Scan Trigger for Conversion for AN8.
    ADCTRG3bits.TRGSRC9 = 3;        // Scan Trigger for Conversion for AN9.
    ADCTRG3bits.TRGSRC10 = 3;        // Scan Trigger for Conversion for AN10.
    ADCTRG3bits.TRGSRC11 = 3;        // Scan Trigger for Conversion for AN11.
    
    ADCCSS1 = 0;
    ADCCSS2 = 0;
    AdcSetChannelForScanReg();      // Sets ADCCSS1 Register for Corresponding channels as specified in the AdcChannelNoIndex Buffer.
    
    
    /** ADC End of scan Interrupt Settings */
    
    ADCCON2bits.EOSIEN = 1;     // End of Scan Interrupt Enabled.
    
#if defined ADC_INTERRUPT_MODE
    IFS6bits.ADCEOSIF = 0;      // End of scan interrupt flag cleared.
    IEC6bits.ADCEOSIE = 1;      // End of Scan Interrupt enabled.
    IPC48bits.ADCEOSIP = 6;     // End of Scan Interrupt Priority at 4.
    IPC48bits.ADCEOSIS = 1;     // End of Scan Interrupt Sub Priority at 4.
#endif
    
    ADCCON1bits.ON = 1;     // ADC Modules are turned on.
    
    while(!ADCCON2bits.BGVRRDY);     // Wait until reference voltage is ready.
    while(ADCCON2bits.REFFLT);      //  Wait if there is a fault with the reference voltage.
    
    ADCANCONbits.ANEN7 = 1;     // Enable the clock to analog bias of Shared ADC Module.
    
    while(!ADCANCONbits.WKRDY7);        // Wait until ADC7 is ready.
    
    ADCCON3bits.DIGEN7 = 1;     // Enabling Shared ADC Module.
}

#ifdef ADC_INTERRUPT_MODE

/**
 * This Function is used to get ADC Data , for the specified no of channels in a non blocking manner.
 * @param DataBuffer , Pointer to the buffer to which ADC data obtained to be stored.
 * @param NoOfChannels , No of channels in use.
 * @return 1 ADC Data Buffer will be valid , 0 if ADC Data Buffer not valid.
 * WARNING :- BEFORE USING THIS FUNCTION ADC SHOULD BE STARTED USING THE FUNCTION AdcStart() AND THE DATA BUFFER PASSED IS VALID
 * IF FUNCTION RETURNED VALUE 1.
 */

bool GetAdcDataNonBlock(UINT16 *DataBuffer, BYTE NoOfChannels)
{
    if(GetAdcInterrStatAndData(DataBuffer, NoOfChannels))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * This Function is used to get ADC Data , for the specified no of channels in a blocking manner.
 * @param DataBuffer , Pointer to the buffer to which ADC data obtained to be stored.
 * @param NoOfChannels , No of channels in use.
 */

void GetAdcDataBlocking(UINT16 *DataBuffer, BYTE NoOfChannels)
{
    AdcStart();
    while(!GetAdcInterrStatAndData(DataBuffer, NoOfChannels));
}

#endif

#ifdef  ADC_POLLING_MODE

/**
 * This Function is used to get ADC Data , for the specified no of channels in a non blocking manner.
 * @param DataBuffer , Pointer to the buffer to which ADC data obtained to be stored.
 * @param NoOfChannels , No of channels in use.
 * @return 1 ADC Data Buffer will be valid , 0 if ADC Data Buffer not valid.
 * WARNING :- BEFORE USING THIS FUNCTION ADC SHOULD BE STARTED USING THE FUNCTION AdcStart() AND THE DATA BUFFER PASSED IS VALID
 * IF FUNCTION RETURNED VALUE 1.
 */

bool GetAdcDataNonBlock(UINT16 *DataBuffer, BYTE NoOfChannels) 
{
    if(GetAdcScanStatAndData(DataBuffer, NoOfChannels))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * This Function is used to get ADC Data , for the specified no of channels in a blocking manner.
 * @param DataBuffer , Pointer to the buffer to which ADC data obtained to be stored.
 * @param NoOfChannels , No of channels in use.
 */

void GetAdcDataBlocking(UINT16 *DataBuffer, BYTE NoOfChannels)
{
    AdcStart();
    while(!GetAdcScanStatAndData(DataBuffer, NoOfChannels));
}

#endif

#ifdef  ADC_INTERRUPT_MODE

/**
 * This is the ISR for ADC End of scan interrupt.
 */


UINT16 AdcCount = 0;

void __ISR(_ADC_EOS_VECTOR, ipl6AUTO)ADCEosHandler(void)
{   
//     MCU_LED = ~MCU_LED;
    AdcSamplesForFFT[AdcPingPong][AdcCount] = ADCDATA11;
    AdcCount++;
//    (ThresholdDetectFlag > 0) ?  TimerCount++ : (TimerCount = 0) ;
   
    if(AdcCount >= NO_OF_FFT_SAMPLES)
    {
        AdcCount = 0;
        AdcPingPong ^= 1;
        AdcBufferFull = 1;  
    }
    else
    {
         AdcEofScanStat = ADCCON2bits.EOSRDY;      // For Clearing End of scan interrupt status bit read.
         IFS6bits.ADCEOSIF = 0;                    // ADC End of scan interrupt flag cleared.
         ADCCON3bits.GSWTRG = 1;                      // Global Software edge trigger.
    }
    
                
}

#endif

/**
 * This Function is used to start the ADC Conversions.
 */



/**
 * This Function is used for setting the defined channels for scanning.
 * For More info refer ADC FRM Page number 32.
 */

void AdcSetChannelForScanReg()
{
    BYTE Index = 0;
    UINT32 ADCSS1Reg = 0;
    for(Index = 0; Index < NO_OF_ADC_CHANNELS_IN_USE; Index++)
    {
        ADCSS1Reg |= (UINT32)(1 << AdcChannelNoIndex[Index]);
    }
    ADCCSS1 = ADCSS1Reg;        // Scanning register is updated.
}

/**
 * This Function is used to set ADC Interrupt Mode Data ready flag status.
 * @param Status , Status of the flag to be set.
 */

void SetAdcInterDataReadyStat(bool Status)
{
    AdcDataReadyFlag = Status;
}

/**
 * This Function is used to get the ADC Interrupt Mode Data ready flag status.
 * @return AdcDataReadyFlag value.
 */

bool GetAdcInterDataReadyStat()
{
    return AdcDataReadyFlag;
}

/**
 * This Function is used to get ADC interrupt status and ADC Data.
 * @param DataBuffer , Pointer to the buffer to which ADC Data obtained to be stored.
 * @param NoOfChannels , No of ADC Channels in use.
 * @return 1 ADC Interrupt occurred is complete data can be fetched, 0 ADC Interrupt not occurred ADC data not ready. 
 */

bool GetAdcInterrStatAndData(UINT16 *DataBuffer, BYTE NoOfChannels)
{
    BYTE Index = 0;
    BYTE ChannelIndex = 0;
    if(GetAdcInterDataReadyStat())
    {
        SetAdcInterDataReadyStat(0);
        for(Index = 0; Index < NoOfChannels; Index++)
        {
            ChannelIndex = AdcChannelNoIndex[Index] - 5;        // -5 Since Shared ADC Channel starts from 5 so AdcData[0] holds AN5 data and so on.
            DataBuffer[Index] = AdcData[ChannelIndex];
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * This Function is used to get ADC Scanning status and ADC Data.
 * @param DataBuffer , Pointer to the buffer to which ADC Data obtained to be stored.
 * @param NoOfChannels , No of ADC Channels in use.
 * @return 1 scanning is complete data can be fetched, 0 scanning not completed ADC data not ready. 
 */

bool GetAdcScanStatAndData(UINT16 *DataBuffer, BYTE NoOfChannels)
{
    BYTE Index = 0;
    BYTE ChannelIndex = 0;
    BYTE EndOfScanStat = 0;
    EndOfScanStat = ADCCON2bits.EOSRDY;     // End of Scan ready status bit.
    if(EndOfScanStat)
    {
        FillAdcLocalBuffer();       // Reading Configured ADC Channel's data to ADC Local Buffer.
        for(Index = 0; Index < NoOfChannels; Index++)
        {
            ChannelIndex = AdcChannelNoIndex[Index] - 5;        // -5 Since Shared ADC Channel starts from 5 so AdcData[0] holds AN5 data and so on.
            DataBuffer[Index] = AdcData[ChannelIndex];
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * This Function is used to fill the ADC Local Buffer for every configured ADC Channels.
 */

void FillAdcLocalBuffer()
{
    BYTE Index = 0;
    BYTE ChannelIndex = 0;
    for(Index = 0; Index < NO_OF_ADC_CHANNELS_IN_USE; Index++)
    {
        ChannelIndex = AdcChannelNoIndex[Index] - 5;        // -5 Since Shared ADC Channel starts from 5 so AdcData[0] holds AN5 data and so on.
        AdcData[ChannelIndex] = *AdcDataRegPoin[ChannelIndex];
    }
}




