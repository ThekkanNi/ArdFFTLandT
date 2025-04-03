#include "app.h"


BYTE LT_RxBuff[100];
UINT16 LT_RxIndex = 0;
volatile bool LT_RxFlagReady = 0;
BYTE LT_PreambleBuffer[4];




void LandTDataSend(BYTE *Data, UINT16 Length)
{
    U1PutBuff(Data, Length);
}

/**
 * This function is the used for getting the RxData from the UART connected to LORA Device.
 */

void GetLandTRxData()
{
    LT_RxBuff[LT_RxIndex] = U1RXREG;
    if (LT_RxIndex < HEADER_SIZE)
    {
        if (LT_RxBuff[LT_RxIndex] == LT_PreambleBuffer[LT_RxIndex])
        {
            LT_RxIndex++;
        }
        else
        {
            LT_RxIndex = 0;
        }
    }
    else
    {
        if (LT_RxIndex >= (LT_DATA_TO_GUI_TX_SIZE - 1))
        {
            LT_RxIndex = 0;
            SetLTRxdataReady(1);
        }
        else
        {
            LT_RxIndex++;
        }
    }
}

bool GetLandTRxdataReady()
{
    return LT_RxFlagReady;
}

void SetLandTRxdataReady(bool Flag)
{
    LT_RxFlagReady = Flag;
}

void LandTPreambleInit()
{
    memcpy(LT_PreambleBuffer, HEADER, HEADER_SIZE);
}

void GetLandTDataPacketBuffer(BYTE *Data, UINT16 Length)
{
    memcpy(Data, LT_RxBuff, Length);
    memset(LT_RxBuff, 0, Length);
}




