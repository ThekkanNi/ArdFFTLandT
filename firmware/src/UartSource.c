
#include "app.h"


/************ UART 1 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U1PutChar(BYTE Char)
{
    U1TXREG = Char;
    while (!U1STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U1PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U1PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U1PutBuff(BYTE *Address, UINT16 Length)
{
    while (Length--)
    {
        U1PutChar(*Address++);
    }
}


/************ UART 2 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U2PutChar(BYTE Char)
{
    U2TXREG = Char;
    while (!U2STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U2PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U2PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U2PutBuff(BYTE *Address, UINT16 Length)
{
    while (Length--)
    {
        U2PutChar(*Address++);
    }
}

/************ UART 3 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U3PutChar(BYTE Char)
{
    U3TXREG = Char;
    while (!U3STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U3PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U3PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U3PutBuff(BYTE *Address, UINT16 Length)
{

    while (Length--)
    {
        U3PutChar(*Address++);
    }
}

/************ UART 4 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U4PutChar(BYTE Char)
{
    U4TXREG = Char;
    while (!U4STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U4PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U4PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U4PutBuff(BYTE *Address, UINT16 Length)
{
    while (Length--)
    {
        U4PutChar(*Address++);
    }
}

/************ UART 5 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U5PutChar(BYTE Char)
{
    U5TXREG = Char;
    while (!U5STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U5PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U5PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U5PutBuff(BYTE *Address, UINT16 Length)
{
    while (Length--)
    {
        U5PutChar(*Address++);
    }
}

/************ UART 6 *********************/

/**
 * 
 * @param a : Byte variable, transmit the variable passed.
 */
void U6PutChar(BYTE Char)
{
    U6TXREG = Char;
    while (!U6STAbits.TRMT);
}

/**
 * 
 * @param string  : Char array, transmit the entire array, Null terminator is necessary.
 * @return        : Bool variable, return 0 if string is invalid, 1 if transmit ok.
 */
bool U6PutString(const char *String)
{
    if (String == NULL)return (0);
    while (*String != '\0')
    {
        U6PutChar(*String++);
    }
    return (1);
}

/**
 * Function to transmit a buffer having size Length through UART 1 Module
 * @param Address : Starting address of the Buffer to be transmitted
 * @param Length : No of bytes of data to be transmitted
 */
void U6PutBuff(BYTE *Address, UINT16 Length)
{
    while (Length--)
    {
        U6PutChar(*Address++);
    }
}
