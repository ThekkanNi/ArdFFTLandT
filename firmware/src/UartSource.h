/* 
 * File:   UartSource.h
 * Author: midhu
 *
 * Created on 2 April, 2024, 10:26 AM
 */

#ifndef UARTSOURCE_H
#define	UARTSOURCE_H


/******FUNCTIONS*******/

void U1PutChar(BYTE Char);
bool U1PutString(const char *String);
void U1PutBuff(BYTE *Address, UINT16 Length);

void U2PutChar(BYTE Char);
bool U2PutString(const char *String);
void U2PutBuff(BYTE *Address, UINT16 Length);

void U3PutChar(BYTE Char);
bool U3PutString(const char *String);
void U3PutBuff(BYTE *Address, UINT16 Length);

void U4PutChar(BYTE Char);
bool U4PutString(const char *String);
void U4PutBuff(BYTE *Address, UINT16 Length);

void U5PutChar(BYTE Char);
bool U5PutString(const char *String);
void U5PutBuff(BYTE *Address, UINT16 Length);

void U6PutChar(BYTE Char);
bool U6PutString(const char *String);
void U6PutBuff(BYTE *Address, UINT16 Length);


#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UARTSOURCE_H */

