/* 
 * File:   GuiCommunicationFile.h
 * Author: asus
 *
 * Created on 2 April, 2025, 1:34 PM
 */

#ifndef GUICOMMUNICATIONFILE_H
#define	GUICOMMUNICATIONFILE_H



/******************************* COMMON /*******************************/

#define     DEV_ID                           1     
#define     HEADER                          "ATW#"
#define     FOOTER                          "R&D#"
#define     HEADER_SIZE                     (4)
#define     FOOTER_SIZE                     (4)
#define     CHECKSUM_SIZE                   (2)
#define     TOTAL_OVERHEAD                  (HEADER_SIZE + FOOTER_SIZE + CHECKSUM_SIZE)




/******************************* AHRS DATA TO GUI /*******************************/

//#define     LT_DATA_ADC_COUNT_SIZE        (10000)
//#define     LT_DATA_TO_GUI_CRC_SIZE       (4 + (LT_DATA_ADC_COUNT_SIZE * 2))            // 4 + (10000 * 2) = 20004
//#define     LT_DATA_TO_GUI_TX_SIZE        (TOTAL_OVERHEAD + LT_DATA_TO_GUI_CRC_SIZE)    // (20004 + 10)    = 20014


// 40014 *** 

#define     LT_DATA_ADC_COUNT_SIZE        (20000)
#define     LT_DATA_TO_GUI_CRC_SIZE       (4 + (LT_DATA_ADC_COUNT_SIZE * 2))            //  4 + (20000 * 2) = 40004
#define     LT_DATA_TO_GUI_TX_SIZE        (TOTAL_OVERHEAD + LT_DATA_TO_GUI_CRC_SIZE)    // (40004 + 10)    =  40014


typedef union
{
    BYTE TxBuffer[LT_DATA_TO_GUI_TX_SIZE];     //  40014
    struct
    {
        BYTE Header[HEADER_SIZE];
        union
        {
            BYTE CrcBuffer[LT_DATA_TO_GUI_CRC_SIZE]; // 40004
            struct
            {
                UINT32 FrameNumb                           __attribute__ ((packed)); 
                UINT16  AdcData[LT_DATA_ADC_COUNT_SIZE]    __attribute__ ((packed));      // It contains ADC measurement of the device about 20000 no.
            };
        }Payload;
        UINT16 CheckSum __attribute__((packed));
        BYTE Footer[FOOTER_SIZE];
    }Packet;
}LT_DATA_TO_GUI;



void LandTDataSend(BYTE *Data, UINT16 Length);
void GetLandTRxData();
bool GetLandTRxdataReady();
void SetLandTRxdataReady(bool Flag);
void LandTPreambleInit();
void GetLandTDataPacketBuffer(BYTE *Data, UINT16 Length);








#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GUICOMMUNICATIONFILE_H */

