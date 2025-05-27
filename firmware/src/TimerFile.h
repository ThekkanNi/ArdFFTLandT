/* 
 * File:   TimerFile.h
 * Author: aravindpp
 *
 * Created on 18 May, 2021, 12:55 PM
 */

#ifndef TIMERFILE_H
#define	TIMERFILE_H

#define         TMR_FCY                     SYS_CLK_BUS_PERIPHERAL_3

/** Configurations */
#define         TIMER3PS                    7
#define         TIMER3PS_VALUE              256
#define         DISABLE_TIMER3              T3CONbits.ON = 0 
#define         ENABLE_TIMER3               T3CONbits.ON = 1 
#define         CLEAR_TIMER3                TMR3 = 0

#define         TIMER4PS                    7
#define         TIMER4PS_VALUE              256
#define         DISABLE_TIMER4              T4CONbits.ON = 0 
#define         ENABLE_TIMER4               T4CONbits.ON = 1 
#define         CLEAR_TIMER4                TMR4 = 0


/*
    7 = 1:256 prescale value
    6 = 1:64 prescale value
    5 = 1:32 prescale value
    4 = 1:16 prescale value
    3 = 1:8 prescale value
    2 = 1:4 prescale value
    1 = 1:2 prescale value
    0 = 1:1 prescale value 
*/

#define         TIMER5PS                    0
#define         TIMER5PS_VALUE              1
#define         DISABLE_TIMER5              T5CONbits.ON = 0 
#define         ENABLE_TIMER5               T5CONbits.ON = 1 
#define         CLEAR_TIMER5                TMR5 = 0 


#define         TIMER6PS                    7
#define         TIMER6PS_VALUE              256
#define         DISABLE_TIMER6              T6CONbits.ON = 0 
#define         ENABLE_TIMER6               T6CONbits.ON = 1 
#define         CLEAR_TIMER6                TMR6 = 0

#define         TIMER7PS                    7
#define         TIMER7PS_VALUE              256
#define         DISABLE_TIMER7              T7CONbits.ON = 0 
#define         ENABLE_TIMER7               T7CONbits.ON = 1 
#define         CLEAR_TIMER7                TMR7 = 0

#define         TIMER8PS                    7
#define         TIMER8PS_VALUE              256
#define         DISABLE_TIMER8              T8CONbits.ON = 0 
#define         ENABLE_TIMER8               T8CONbits.ON = 1 
#define         CLEAR_TIMER8                TMR8 = 0

#define         TIMER9PS                    7
#define         TIMER9PS_VALUE              256
#define         DISABLE_TIMER9              T9CONbits.ON = 0 
#define         ENABLE_TIMER9               T9CONbits.ON = 1 
#define         CLEAR_TIMER9                TMR9 = 0

/** Functions */

UINT32 CalcPeriodReg(double IntFreq, UINT16 PSValue);
void Timer3Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer3();
void StopTimer3();
bool SetTimer3IntFreq(UINT32 IntFrequency);
void AttachTmr3Interrupt(void *(Address));

void Timer4Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer4();
void StopTimer4();
bool SetTimer4IntFreq(UINT32 IntFrequency);
void AttachTmr4Interrupt(void *(Address));

void Timer5Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer5();
void StopTimer5();
bool SetTimer5IntFreq(UINT32 IntFrequency);
void AttachTmr5Interrupt(void *(Address));

void Timer6Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer6();
void StopTimer6();
bool SetTimer6IntFreq(UINT32 IntFrequency);
void AttachTmr6Interrupt(void *(Address));

void Timer7Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer7();
void StopTimer7();
bool SetTimer7IntFreq(UINT32 IntFrequency);
void AttachTmr7Interrupt(void *(Address));

void Timer8Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer8();
void StopTimer8();
bool SetTimer8IntFreq(UINT32 IntFrequency);
void AttachTmr8Interrupt(void *(Address));

void Timer9Config(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void StartTimer9();
void StopTimer9();
bool SetTimer9IntFreq(UINT32 IntFrequency);
void AttachTmr9Interrupt(void *(Address));

void Timer4_5_32BitConfig(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void Timer6_7_32BitConfig(double InterruptFreq, bool InterruptStatus, BYTE Priority);
void Timer8_9_32BitConfig(double InterruptFreq, bool InterruptStatus, BYTE Priority);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMERFILE_H */

