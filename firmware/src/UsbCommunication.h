/* 
 * File:   UsbCommunication.h
 * Author: aravi
 *
 * Created on February 1, 2025, 11:24 AM
 */

#ifndef USBCOMMUNICATION_H
#define	USBCOMMUNICATION_H



/*

#define     NUMBER_OF_FLOAT            55 
#define     NUMBER_OF_DOUBLE           0
#define     NUMBER_OF_BYTE             0
#define     NUMBER_OF_UINT16           0
#define     NUMBER_OF_INT16            0
#define     NUMBER_OF_UINT32           0
#define     NUMBER_OF_INT32            0



#define     DEV_ID                           1

#define     HEADER                          "ATW#"
#define     FOOTER                          "R&D#"
#define     HEADER_SIZE                     (4)
#define     FOOTER_SIZE                     (4)
#define     CHECKSUM_SIZE                   (2)
#define     TOTAL_OVERHEAD                  (HEADER_SIZE + FOOTER_SIZE + CHECKSUM_SIZE)

#define     ACK_DATA_CRC_SIZE_DATA          ( (NUMBER_OF_FLOAT * sizeof(float)) + (NUMBER_OF_DOUBLE * sizeof(double)) + (NUMBER_OF_BYTE * sizeof(BYTE)) + (NUMBER_OF_UINT16 * sizeof(UINT16)) + (NUMBER_OF_INT16 * sizeof(INT16)) + (NUMBER_OF_UINT32 * sizeof(INT32)) + (NUMBER_OF_INT32 * sizeof(UINT32))  )          
#define     ACK_DATA_CRC_SIZE_RESERVED      ( 1472 -  ACK_DATA_CRC_SIZE_DATA - TOTAL_OVERHEAD - 8)          
#define     ACK_DATA_CRC_SIZE               ( ACK_DATA_CRC_SIZE_DATA + ACK_DATA_CRC_SIZE_RESERVED)
#define     ACK_DATA_ID_SIZE                ( ACK_DATA_CRC_SIZE + 8)                 
#define     ACK_DATA_SIZE                   ( TOTAL_OVERHEAD + ACK_DATA_ID_SIZE)          



typedef struct
{
    FloatVect AccData __attribute((packed));              //  3
    FloatVect GyroData __attribute((packed));             //  3
    FloatVect Mag __attribute((packed));                  //  3
    Quaternions QuaternionData __attribute((packed));     //  4
    float YawData __attribute((packed));                  //  1
    float PitchData __attribute((packed));                //  1
    float RollData __attribute((packed));                 //  1
    FloatVect MadData __attribute((packed));              //  3
}AHRS_DATA_PACKET;


typedef union 
{
    BYTE TxBuffer[ACK_DATA_SIZE] __attribute__((coherent));
    struct
    {
        BYTE Header[HEADER_SIZE];                                             // 4
        union 
        {
            BYTE CrcBuffer[ACK_DATA_ID_SIZE];
            struct
            {
                UINT16 Fam_ID __attribute((packed));                          // 2
                UINT16 Dev_Code __attribute((packed));                          // 2
                UINT32 Dev_ID __attribute((packed));                          // 4
                union
                {
                    BYTE PayloadBuffer[ACK_DATA_CRC_SIZE];
                    struct
                    {
                        
                        AHRS_DATA_PACKET AhrsDataPacket;                     
                        BYTE ReservedBuff[ACK_DATA_CRC_SIZE_RESERVED] ;                              // 1396
                    };
                }PAYLOAD;
            };
        }ID_SEC;
        UINT16 CheckSum __attribute((packed));                                // 2
        BYTE Footer[FOOTER_SIZE];                                             // 4
    }PACKET;
}UI_TX_PACKET;


*/

typedef union
{
    BYTE Data[8] __attribute__((coherent));
    struct
    {
    BYTE Header[4];
    BYTE Footer[4];
    }Payload;
      
}DMACHECK;




void UartDmaInit() ;
void SetSourceAddress(void *Address, UINT16 Size);
void StartUartDma0();
void StopUartDma0();



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* USBCOMMUNICATION_H */

