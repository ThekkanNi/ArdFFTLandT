/* 
 * File:   Pic32MxDelay.h
 * Author: Asus
 *
 * Created on March 16, 2019, 10:36 AM
 */

#ifndef PIC32MZDELAY_H
#define	PIC32MZSDELAY_H

#include "app.h"

#define         GET_SYS_CLOCK()  (SYS_CLK_FREQ)
#define         US_SCALE         (GET_SYS_CLOCK() / 2000000)
#define         MS_SCALE         (GET_SYS_CLOCK() / 2000)

UINT32 GetCoreTime(void);
void __delay_ms(UINT32 msDelay );
void __delay_us(UINT32 usDelay );

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PIC32MXDELAY_H */

