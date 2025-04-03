/* 
 * File:   UartFile.h
 * Author: midhu
 *
 * Created on 29 June, 2024, 10:52 AM
 */

#ifndef UARTFILE_H
#define	UARTFILE_H



#define     FCY_UART                        (SYS_CLK_BUS_PERIPHERAL_2)      // Since this clock is used by PMP, I2C, SPIand USART, it should be


UINT32 Set_Baudrate(double BaudRate, double *Ptr, bool BrghValue);


void Uart1tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU1RxInterrupt(void *(Address));
void SendU1Address(BYTE Addr);
void SetU1AddrDetectMode();
void ClearU1AddrDetectMode(); 


void Uart2tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU2RxInterrupt(void *(Address));
void SendU2Address(BYTE Addr);
void SetU2AddrDetectMode();
void ClearU2AddrDetectMode(); 



void Uart3tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU3RxInterrupt(void *(Address));
void SendU3Address(BYTE Addr);
void SetU3AddrDetectMode();
void ClearU3AddrDetectMode(); 


void Uart4tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU4RxInterrupt(void *(Address));
void SendU4Address(BYTE Addr);
void SetU4AddrDetectMode();
void ClearU4AddrDetectMode(); 


void Uart5tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU5RxInterrupt(void *(Address));
void SendU5Address(BYTE Addr);
void SetU5AddrDetectMode();
void ClearU5AddrDetectMode(); 


void Uart6tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority);
void AttachU6RxInterrupt(void *(Address));
void SendU6Address(BYTE Addr);
void SetU6AddrDetectMode();
void ClearU6AddrDetectMode(); 




#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UARTFILE_H */

