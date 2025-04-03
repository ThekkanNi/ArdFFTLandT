

#include "Pic32MzDelay.h"

/**************************************************************************************************************
 This particular file contains following functions,
  
 
 * __delay_ms(UINT32 Delay) - For generating the specified amount of time in multiples of 1 mS.
 * __delay_us(UINT32 Delay) - For generating the specified amount of time in multiples of 1 uS.
 * UINT32 GetCoreTime()     - Gives back the Core timer count, which is system clock / 2, in 
 *                            case of PIC32MZ1024EFK064.
 
 * 
 ***************************************************************************************************************/

/**
 * Function used for getting core timer value, each clock represents 2 system clocks
 * eg :
 * 
        UINT32 StartTime = 0, StopTime = 0;
        StartTime = GetCoreTime();
        __delay_ms(1);
        StopTime = GetCoreTime();
        printf("%lu\n\r", (StopTime - StartTime) * 2);
 * (StopTime - StartTime) is multiplied with 2, because each core timer clock represents 2 system clocks
 * So the output will be 96000, which is equal to 96000 / System clock, = 1mS
 * Caution : This function should not be used for measuring times below 1 uS.
 * @return Core timer count.
 */

UINT32 GetCoreTime()
{
    volatile UINT32 timer;
    // get the count reg
    asm volatile("mfc0   %0, $9" : "=r"(timer));
    return(timer);
}

/**
 * Function used for generating mS range delays.
 * @param msDelay, Delay time needed in mS.
 */

void __delay_ms(UINT32 msDelay )
{
    register unsigned int waitCntms = msDelay * MS_SCALE;
    register unsigned int startCntms = GetCoreTime();
    while( GetCoreTime() - startCntms < waitCntms );
}

/**
 * Function used for generating uS range delays.
 * @param usDelay, Delay time needed in uS.
 */
 
void __delay_us(UINT32 usDelay )
{
    register unsigned int waitCnt = usDelay * US_SCALE;
    register unsigned int startCnt = GetCoreTime();
    while( GetCoreTime() - startCnt < waitCnt );
}
