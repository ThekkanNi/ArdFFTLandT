#include "app.h" 


/**
 *  DRIVER DETAILS 
 *  UART for 32 bit MicroControllers  
 *  Conifgure 8 bit , 9 bit Uart Tx and  Rx Mode
 *  Configure Address Detection mode  
 *  Example Rx ISR Code Given Below  Line N0 : 734     
 */

/**
 * 
 * @param BaudRate      : Write the needed baud rates here,double precision variable, eg : 9600.
 * @param ptr           : doble poiter variable, contains the expected percentage of error in communicaton.
 * @param brghValue     : char variable, 1 for sellecting high speed mode, 0 for low-speed mode, for any other returns 0.
 * @return              : unsigned long variable, value to be entered in UxBRG register.
 */
UINT32 Set_Baudrate(double BaudRate, double *Ptr, bool BrghValue)
{
    UINT32 BrgHValue = 0;
    char dividerValue = 0;
    float value = 0;
    float dummyValue = 0;
    float calculatedBaud = 0;
    UINT32 longValue = 0;
    UINT16 intValue = 0;
    float reminder = 0;

    if (BrghValue == 1)dividerValue = 4;
    else if (BrghValue == 0)dividerValue = 16;

    value = (float) FCY / BaudRate / dividerValue;
    value = (float) value - 1;
    dummyValue = value;
    intValue = (UINT16) value;
    reminder = (float) value - intValue;
    if (reminder < .5)value = intValue;
    else if (reminder >= .5)value += 1;
    longValue = (unsigned long) value;
    calculatedBaud = FCY / ((longValue + 1) * dividerValue);
    *Ptr = ((calculatedBaud - BaudRate) / BaudRate) * 100;
    if (*Ptr < 0)*Ptr *= -1;
    BrgHValue = (UINT32) value;
    return BrgHValue;
}

/*********************************************   UART 2    ****************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart2tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U2BrgVal = 0;

    U2MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U2MODEbits.IREN = 0; // IrDA is disabled.
    U2MODEbits.RTSMD = 0; // Flow control mode.
    U2MODEbits.UEN = 0; // TX&RX enabled only.
    U2MODEbits.WAKE = 0; // Wake-up disabled.
    U2MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U2MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U2MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U2MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U2MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U2MODEbits.STSEL = 0; // 1 stop bit.

    IFS4bits.U2EIF = 0;
    IFS4bits.U2RXIF = 0;
    IFS4bits.U2TXIF = 0;

    IPC36bits.U2EIP = 0;
    IPC36bits.U2RXIP = Priority;
    IPC36bits.U2TXIP = 0;

    IEC4bits.U2EIE = 0;
    IEC4bits.U2RXIE = RxInterrupt;
    IEC4bits.U2TXIE = 0;

    U2STAbits.UTXISEL = 0;
    U2STAbits.URXISEL = 0;
    U2STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U2STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U2STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U2STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U2STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U2MODEbits.BRGH = BrghValue;
    U2BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U2BRG = U2BrgVal;

    U2MODEbits.ON = 1;
}

void SetU2AddrDetectMode()
{
    U2STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU2AddrDetectMode()
{
    U2STAbits.ADDEN = 0; // Address detect mode is Disabled  
}


void (*Uart2RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU2RxInterrupt(void *(Address))
{
    Uart2RxIsr = Address;
}

/**
 * This is the ISR of UART2.
 */

void __ISR(_UART2_RX_VECTOR, ipl7AUTO)Uart2RxISR(void)
{
    IFS4bits.U2RXIF = 0;
    Uart2RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_RECEIVE);

}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU2Address(BYTE Addr)
{
    U2TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U2STAbits.TRMT);
}

/**************************************************************************************************************************************************/

/************************************* UART 1    ***************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart1tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U1BrgVal = 0;

    U1MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U1MODEbits.IREN = 0; // IrDA is disabled.
    U1MODEbits.RTSMD = 0; // Flow control mode.
    U1MODEbits.UEN = 0; // TX&RX enabled only.
    U1MODEbits.WAKE = 0; // Wake-up disabled.
    U1MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U1MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U1MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U1MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U1MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U1MODEbits.STSEL = 0; // 1 stop bit.

    IFS3bits.U1EIF = 0;
    IFS3bits.U1RXIF = 0;
    IFS3bits.U1TXIF = 0;

    IPC28bits.U1EIP = 0;
    IPC28bits.U1RXIP = Priority;
    IPC28bits.U1TXIP = 0;

    IEC3bits.U1EIE = 0;
    IEC3bits.U1RXIE = RxInterrupt;
    IEC3bits.U1TXIE = 0;

    U1STAbits.UTXISEL = 2;
    U1STAbits.URXISEL = 0;
    U1STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U1STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U1STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U1STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U1STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U1MODEbits.BRGH = BrghValue;
    U1BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U1BRG = U1BrgVal;

    U1MODEbits.ON = 1;
}

void SetU1AddrDetectMode()
{
    U1STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU1AddrDetectMode()
{
    U1STAbits.ADDEN = 0; // Address detect mode is Disabled  
}

void (*Uart1RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU1RxInterrupt(void *(Address))
{
    Uart1RxIsr = Address;
}

/**
 * This is the ISR of UART2.
 */

void __ISR(_UART1_RX_VECTOR, ipl1AUTO)Uart1RxISR(void)
{
    IFS3bits.U1RXIF = 0;
    Uart1RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);

}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU1Address(BYTE Addr)
{
    U1TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U1STAbits.TRMT);
}

/*************************************************************************************************************************/


/*************************** UART 3 ******************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart3tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U3BrgVal = 0;

    
    U3MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U3MODEbits.IREN = 0; // IrDA is disabled.
    U3MODEbits.RTSMD = 0; // Flow control mode.
    U3MODEbits.UEN = 0; // TX&RX enabled only.
    U3MODEbits.WAKE = 0; // Wake-up disabled.
    U3MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U3MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U3MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U3MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U3MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U3MODEbits.STSEL = 0; // 1 stop bit.

    IFS4bits.U3EIF = 0;
    IFS4bits.U3RXIF = 0;
    IFS4bits.U3TXIF = 0;

    IPC39bits.U3EIP = 0;
    IPC39bits.U3RXIP = Priority;
    IPC39bits.U3TXIP = 0;


    IEC4bits.U3EIE = 0;
    IEC4bits.U3RXIE = RxInterrupt;
    IEC4bits.U3TXIE = 0;


    U3STAbits.UTXISEL = 0;
    U3STAbits.URXISEL = 0;
    U3STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U3STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U3STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U3STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U3STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U3MODEbits.BRGH = BrghValue;
    U3BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U3BRG = U3BrgVal;

    U3MODEbits.ON = 1;
}

void SetU3AddrDetectMode()
{
    U3STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU3AddrDetectMode()
{
    U3STAbits.ADDEN = 0; // Address detect mode is Disabled  
}

void (*Uart3RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU3RxInterrupt(void *(Address))
{
    Uart3RxIsr = Address;
}

/**
 * This is the ISR of UART2.
 */

void __ISR(_UART3_RX_VECTOR, ipl5AUTO)Uart3RxISR(void)
{
    IFS4bits.U3RXIF = 0;
    Uart3RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_3_RECEIVE);

}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU3Address(BYTE Addr)
{
    U3TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U3STAbits.TRMT);
}

/********************************************************************************************************************/

/*********************************** UART 4 **************************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart4tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U4BrgVal = 0;

    U4MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U4MODEbits.IREN = 0; // IrDA is disabled.
    U4MODEbits.RTSMD = 0; // Flow control mode.
    U4MODEbits.UEN = 0; // TX&RX enabled only.
    U4MODEbits.WAKE = 0; // Wake-up disabled.
    U4MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U4MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U4MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U4MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U4MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U4MODEbits.STSEL = 0; // 1 stop bit.

    IFS5bits.U4EIF = 0;
    IFS5bits.U4RXIF = 0;
    IFS5bits.U4TXIF = 0;

    IPC42bits.U4EIP = 0;
    IPC42bits.U4RXIP = Priority;
    IPC43bits.U4TXIP = 0;


    IEC5bits.U4EIE = 0;
    IEC5bits.U4RXIE = RxInterrupt;
    IEC5bits.U4TXIE = 0;

    U4STAbits.UTXISEL = 0;
    U4STAbits.URXISEL = 0;
    U4STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U4STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U4STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U4STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U4STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U4MODEbits.BRGH = BrghValue;
    U4BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U4BRG = U4BrgVal;

    U4MODEbits.ON = 1;
}

void SetU4AddrDetectMode()
{
    U4STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU4AddrDetectMode()
{
    U4STAbits.ADDEN = 0; // Address detect mode is Disabled  
}

void (*Uart4RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU4RxInterrupt(void *(Address))
{
    Uart4RxIsr = Address;
}

/**
 * This is the ISR of UART2.
 */

void __ISR(_UART4_RX_VECTOR, ipl6AUTO)Uart4RxISR(void)
{
    IFS5bits.U4RXIF = 0;
    Uart4RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_4_RECEIVE);

}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU4Address(BYTE Addr)
{
    U4TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U4STAbits.TRMT);
}


/******************************************************************************************/


/*************************************** UART 5 **********************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart5tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U5BrgVal = 0;

    U5MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U5MODEbits.IREN = 0; // IrDA is disabled.
    U5MODEbits.RTSMD = 0; // Flow control mode.
    U5MODEbits.UEN = 0; // TX&RX enabled only.
    U5MODEbits.WAKE = 0; // Wake-up disabled.
    U5MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U5MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U5MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U5MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U5MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U5MODEbits.STSEL = 0; // 1 stop bit.

    IFS5bits.U5EIF = 0;
    IFS5bits.U5RXIF = 0;
    IFS5bits.U5TXIF = 0;

    IPC44bits.U5EIP = 0;
    IPC45bits.U5RXIP = Priority;
    IPC45bits.U5TXIP = 0;


    IEC5bits.U5EIE = 0;
    IEC5bits.U5RXIE = RxInterrupt;
    IEC5bits.U5TXIE = 0;

    U5STAbits.UTXISEL = 0;
    U5STAbits.URXISEL = 0;
    U5STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U5STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U5STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U5STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U5STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U5MODEbits.BRGH = BrghValue;
    U5BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U5BRG = U5BrgVal;

    U5MODEbits.ON = 1;
}

void SetU5AddrDetectMode()
{
    U5STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU5AddrDetectMode()
{
    U5STAbits.ADDEN = 0; // Address detect mode is Disabled  
}

void (*Uart5RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU5RxInterrupt(void *(Address))
{
    Uart5RxIsr = Address;
}

/**
 * This is the ISR of UART5.
 */

void __ISR(_UART5_RX_VECTOR, ipl3AUTO)Uart5RxISR(void)
{
    IFS5bits.U5RXIF = 0;
    Uart5RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_5_RECEIVE);

}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU5Address(BYTE Addr)
{
    U5TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U5STAbits.TRMT);
}

/***************************************************************************************/


/**********************************  UART  6  *************************************************************/

/**
 * This function is used to configure the UART2 Module.
 * @param BaudRate, Baud rate of communication.
 * @param BrghValue, 1 for selecting high speed mode, 0 for low-speed mode
 * @param RxInterrupt, For enabling RX interrupt, 1 for enable and 0 for disable.
 * @param Priority, The interrupt priority of the RX interrupt. Do not exceed 7.
 */

void Uart6tInit(bool Bit9Mode, bool AdrDetectEnable, double BaudRate, bool BrghValue, bool RxInterrupt, char Priority)
{
    double error = 0;
    UINT32 U6BrgVal = 0;

    U6MODEbits.SIDL = 0; // Continue operation in Idle mode.
    U6MODEbits.IREN = 0; // IrDA is disabled.
    U6MODEbits.RTSMD = 0; // Flow control mode.
    U6MODEbits.UEN = 0; // TX&RX enabled only.
    U6MODEbits.WAKE = 0; // Wake-up disabled.
    U6MODEbits.LPBACK = 0; // Loopback mode is disabled.
    U6MODEbits.ABAUD = 0; // Automatic baud rate is disabled.
    U6MODEbits.RXINV = 0; // RX Idle state is 1.
    if (Bit9Mode == 1)
    {
        U6MODEbits.PDSEL = 3; // 9-bit data, no parity.
    }
    else
    {
        U6MODEbits.PDSEL = 0; // 8-bit data, no parity.
    }
    U6MODEbits.STSEL = 0; // 1 stop bit.

    IFS5bits.U6EIF = 0;
    IFS5bits.U6RXIF = 0;
    IFS5bits.U6TXIF = 0;

    IPC47bits.U6EIP = 0;
    IPC47bits.U6RXIP = Priority;
    IPC47bits.U6TXIP = 0;


    IEC5bits.U6EIE = 0;
    IEC5bits.U6RXIE = RxInterrupt;
    IEC5bits.U6TXIE = 0;

    U6STAbits.UTXISEL = 0;
    U6STAbits.URXISEL = 0;
    U6STAbits.UTXINV = 0; // Transmitter idle state is 1.

    if (AdrDetectEnable == 1)
    {
        U6STAbits.ADDEN = 1; // Address detect mode is enabled.
    }
    else
    {
        U6STAbits.ADDEN = 0; // Address detect mode is disabled.
    }
    U6STAbits.UTXEN = 1; // UART2 transmitter is enabled.
    U6STAbits.URXEN = 1; // UART2 Receiver is enabled.

    U6MODEbits.BRGH = BrghValue;
    U6BrgVal = Set_Baudrate(BaudRate, &error, BrghValue);
    U6BRG = U6BrgVal;

    U6MODEbits.ON = 1;
}

void SetU6AddrDetectMode()
{
    U6STAbits.ADDEN = 1; // Address detect mode is enabled.
}

void ClearU6AddrDetectMode()
{
    U6STAbits.ADDEN = 0; // Address detect mode is Disabled  
}

void (*Uart6RxIsr)(void);

/**
 * This function is used to attach local UART2 RX ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void AttachU6RxInterrupt(void *(Address))
{
    Uart6RxIsr = Address;
}

/**
 * This is the ISR of UART5.
 */

void __ISR(_UART6_RX_VECTOR, ipl7AUTO)Uart6RxISR(void)
{
    IFS5bits.U6RXIF = 0;
    Uart6RxIsr();
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_6_RECEIVE);
}

/**
 * This function is used to send the address.
 * @param Addr
 */

void SendU6Address(BYTE Addr)
{
    U6TXREG = 0x0100 | Addr; // We should send the 9bit address to the slave device by setting the 9th bit as 1, then only the slave device will accept the data from the Master onwards.
    while (!U6STAbits.TRMT);
}

/*************************************************************************************/

/****************************************************************************************************************************/
/********* EXAMPLE FOR RX ISR   ******/

/*
 
BYTE U3RxLocalISR()
{
    MCU_LED = ~MCU_LED;
    static BYTE DevAddress = 0;
    if (U3STAbits.ADDEN)
    {
        DevAddress = U3RXREG;
        if (DevAddress == DEV_ADDR)
        {
            U1TXREG = 'O';
            U1TXREG = 'K';
            //            U3STAbits.ADDEN = 0;
            ClearU3AddrDetectMode();
        }
        else
        {

            U1TXREG = 'E';
            U1TXREG = 'R';
            U1TXREG = 'R';
            U1TXREG = 'O';
            U1TXREG = 'R';
            U1TXREG = '\n';
            U1TXREG = '\r';
            return 0;
        }
    }
    else
    {
        UartRxBuffer[RxBufferIndex] = U3RXREG;
        if (RxBufferIndex < HEADER_SIZE)
        {
            if (UartRxBuffer[RxBufferIndex] == PreambleBuffer[RxBufferIndex])
            {
                RxBufferIndex++;
            }
            else
            {
                RxBufferIndex = 0;
            }
        }
        else
        {
            HeaderMatch = 1;
            if (RxBufferIndex >= (TOTAL_BUFFER_SIZE - 1))
            {
                ExBufferReadyStatus = 1;
                RxBufferIndex = 0;
                //                U3STAbits.ADDEN = 1;
                SetU3AddrDetectMode();

            }
            else
            {
                RxBufferIndex++;
            }
        }
    }
}
 
 
 */