#include "app.h"

//volatile bool AdcPingPong = 0;
//volatile bool AdcBufferFull = 0;



/** 
    This file contains the Timer configuration for Timer3 -- Timer 9 (16 bit Timers) .
    Available 32 bit Timers : 
    1: Timer4 & Timer5.
    2: Timer6 & Timer7.
    3: Timer8 & Timer9.  

 Note : Timer 8 is used for generating I2C Clock, so whenever I2C driver is used configure any other Timer.
 */

/** Timer Prescalar Register value which correspond to which prescalar value.
    7 = 1:256 prescale value
    6 = 1:64 prescale value
    5 = 1:32 prescale value
    4 = 1:16 prescale value
    3 = 1:8 prescale value
    2 = 1:4 prescale value
    1 = 1:2 prescale value
    0 = 1:1 prescale value 
 */

/**
 * This function is used to calculate the PR Register value of Timer modules.
 * @param IntFreq, The Timer interrupt frequency that we want to configure.
 * @param PSValue, Current Prescalar value.
 * @return, It will return the PR register value which corresponds to the interrupt frequency that we are given.
 */

UINT32
CalcPeriodReg (double IntFreq, UINT16 PSValue)
{
  double RealValue = 0, Remainder = 0, CountTime = 0;
  UINT32 RoundValue = 0;
  CountTime = (double) TMR_FCY / PSValue;
  RealValue = CountTime / IntFreq;
  RoundValue = RealValue;
  Remainder = RealValue - RoundValue;
  if (Remainder >= 0.5) RoundValue += 1;
  return RoundValue;
}

/**
 * This function is used to configure the Timer3.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer3Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr3Val = 0;
  DISABLE_TIMER3;
  T3CONbits.TCKPS = TIMER3PS; // PreScalar value 1:1
  CLEAR_TIMER3;
  IFS0bits.T3IF = 0;
  IEC0bits.T3IE = InterruptStatus;
  IPC3bits.T3IP = Priority;
  TmrPr3Val = CalcPeriodReg (InterruptFreq, TIMER3PS_VALUE);
  PR3 = TmrPr3Val;
}

/**
 * This function is used to start the timer3.
 */

void
StartTimer3 ()
{
  ENABLE_TIMER3;
}

/**
 * This function is used to stop the timer3.
 */

void
StopTimer3 ()
{
  DISABLE_TIMER3;
}

void (*Tmr3Isr)(void);

/**
 * This function is used to attach local Timer 3 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr3Interrupt (void *(Address))
{
  Tmr3Isr = Address;
}

/**
 * This is the ISR of Timer 3.
 */

void __ISR (_TIMER_3_VECTOR, ipl3AUTO)
Tmr3Handler (void)
{
  IFS0bits.T3IF = 0;
  Tmr3Isr ();
}

/**
 * This function is used to configure the Timer4.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer4Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr4Val = 0;
  DISABLE_TIMER4;
  T4CONbits.TCKPS = TIMER4PS; // PreScalar value 1:1
  CLEAR_TIMER4;
  IFS0bits.T4IF = 0;
  IEC0bits.T4IE = InterruptStatus;
  IPC4bits.T4IP = Priority;
  TmrPr4Val = CalcPeriodReg (InterruptFreq, TIMER4PS_VALUE);
  PR4 = TmrPr4Val;
}

/**
 * This function is used to start the timer4.
 */

void
StartTimer4 ()
{
  ENABLE_TIMER4;
}

/**
 * This function is used to stop the timer4.
 */

void
StopTimer4 ()
{
  DISABLE_TIMER4;
}

void (*Tmr4Isr)(void);

/**
 * This function is used to attach local Timer 4 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr4Interrupt (void *(Address))
{
  Tmr4Isr = Address;
}

/**
 * This is the ISR of Timer 4.
 */

void __ISR (_TIMER_4_VECTOR, ipl1AUTO)
Tmr4Handler (void)
{
  IFS0bits.T4IF = 0;
  Tmr4Isr ();
}

/**
 * This function is used to configure the Timer5.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer5 interrupt priority.
 */

void
Timer5Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr5Val = 0;
  DISABLE_TIMER5;
  T5CONbits.TCKPS = TIMER5PS; // PreScalar value 1:1
  CLEAR_TIMER5;
  IFS0bits.T5IF = 0;
  IEC0bits.T5IE = InterruptStatus;
  IPC6bits.T5IP = Priority;
  TmrPr5Val = CalcPeriodReg (InterruptFreq, TIMER5PS_VALUE);
 
  PR5 = 1330;  // 75187 HZ = 75.1 KHZ
//  PR5 = TmrPr5Val;
}

/**
 * This function is used to start the timer5.
 */

void
StartTimer5 ()
{
  ENABLE_TIMER5;
}

/**
 * This function is used to stop the timer5.
 */

void
StopTimer5 ()
{
  DISABLE_TIMER5;
}

void (*Tmr5Isr)(void);

/**
 * This function is used to attach local Timer 5 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr5Interrupt (void *(Address))
{
  Tmr5Isr = Address;
}

/**
 * This is the ISR of Timer 5.
 */

UINT16 AdcCount = 0;

void __ISR (_TIMER_5_VECTOR, ipl7AUTO)
Tmr5Handler (void)
{
  
  
  LATFbits.LATF4 = ~ LATFbits.LATF4;   
  
  
//  MCU_LEDToggle ();
//  printf ("%0.3f\n\r", (ADCDATA9 * PIC32_ADC_RESOLUTION));
//  AdcSamplesForFFT[AdcPingPong][AdcCount] = (ADCDATA9 * PIC32_ADC_RESOLUTION);
  
#ifdef TEST    
  AdcSamplesForFFT[AdcPingPong][AdcCount] = (ADCDATA9);
  AdcCount++;
  if (AdcCount >= LT_DATA_ADC_COUNT_SIZE)
    {
      AdcCount = 0;
      AdcPingPong ^= 1;
      AdcBufferSend = 1;
    }
#endif    
  
  
  ADCCON3bits.GSWTRG = 1;
  IFS0bits.T5IF = 0;
  
  
}

/**
 * This function is used to configure the Timer6.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer6Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr6Val = 0;
  DISABLE_TIMER6;
  T6CONbits.TCKPS = TIMER6PS; // PreScalar value 1:1
  CLEAR_TIMER6;
  IFS0bits.T6IF = 0;
  IEC0bits.T6IE = InterruptStatus;
  IPC7bits.T6IP = Priority;
  TmrPr6Val = CalcPeriodReg (InterruptFreq, TIMER6PS_VALUE);
  PR6 = TmrPr6Val;
}

/**
 * This function is used to start the timer6.
 */

void
StartTimer6 ()
{
  ENABLE_TIMER6;
}

/**
 * This function is used to stop the timer6.
 */

void
StopTimer6 ()
{
  DISABLE_TIMER6;
}

void (*Tmr6Isr)(void);

/**
 * This function is used to attach local Timer 6 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr6Interrupt (void *(Address))
{
  Tmr6Isr = Address;
}

/**
 * This is the ISR of Timer 6.
 */

void __ISR (_TIMER_6_VECTOR, ipl1AUTO)
Tmr6Handler (void)
{
  IFS0bits.T6IF = 0;
  Tmr6Isr ();
}

/**
 * This function is used to configure the Timer7.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer7Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr7Val = 0;
  DISABLE_TIMER7;
  T7CONbits.TCKPS = TIMER7PS; // PreScalar value 1:1
  CLEAR_TIMER7;
  IFS1bits.T7IF = 0;
  IEC1bits.T7IE = InterruptStatus;
  IPC8bits.T7IP = Priority;
  TmrPr7Val = CalcPeriodReg (InterruptFreq, TIMER7PS_VALUE);
  PR7 = TmrPr7Val;
}

/**
 * This function is used to start the timer6.
 */

void
StartTimer7 ()
{
  ENABLE_TIMER7;
}

/**
 * This function is used to stop the timer6.
 */

void
StopTimer7 ()
{
  DISABLE_TIMER7;
}

void (*Tmr7Isr)(void);

/**
 * This function is used to attach local Timer 6 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr7Interrupt (void *(Address))
{
  Tmr7Isr = Address;
}

/**
 * This is the ISR of Timer 6.
 */

void __ISR (_TIMER_7_VECTOR, ipl1AUTO)
Tmr7Handler (void)
{
  IFS1bits.T7IF = 0;
  Tmr7Isr ();
}

/**
 * This function is used to configure the Timer8.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer8Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr8Val = 0;
  DISABLE_TIMER8;
  T8CONbits.TCKPS = TIMER8PS; // PreScalar value 1:1
  CLEAR_TIMER7;
  IFS1bits.T8IF = 0;
  IEC1bits.T8IE = InterruptStatus;
  IPC9bits.T8IP = Priority;
  TmrPr8Val = CalcPeriodReg (InterruptFreq, TIMER8PS_VALUE);
  PR8 = TmrPr8Val;
}

/**
 * This function is used to start the timer6.
 */

void
StartTimer8 ()
{
  ENABLE_TIMER8;
}

/**
 * This function is used to stop the timer6.
 */

void
StopTimer8 ()
{
  DISABLE_TIMER8;
}

void (*Tmr8Isr)(void);

/**
 * This function is used to attach local Timer 6 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr8Interrupt (void *(Address))
{
  Tmr8Isr = Address;
}

/**
 * This is the ISR of Timer 6.
 */

void __ISR (_TIMER_8_VECTOR, ipl1AUTO)
Tmr8Handler (void)
{
  IFS1bits.T8IF = 0;
  Tmr8Isr ();
}

/**
 * This function is used to configure the Timer9.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer9Config (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT16 TmrPr9Val = 0;
  DISABLE_TIMER9;
  T9CONbits.TCKPS = TIMER9PS; // PreScalar value 1:1
  CLEAR_TIMER9;
  IFS1bits.T9IF = 0;
  IEC1bits.T9IE = InterruptStatus;
  IPC10bits.T9IP = Priority;
  TmrPr9Val = CalcPeriodReg (InterruptFreq, TIMER9PS_VALUE);
  PR9 = TmrPr9Val;
}

/**
 * This function is used to start the timer6.
 */

void
StartTimer9 ()
{
  ENABLE_TIMER9;
}

/**
 * This function is used to stop the timer6.
 */

void
StopTimer9 ()
{
  DISABLE_TIMER9;
}

void (*Tmr9Isr)(void);

/**
 * This function is used to attach local Timer 6 ISR function.
 * @param address : Function pointer variable, give address of the local ISR here. 
 */

void
AttachTmr9Interrupt (void *(Address))
{
  Tmr9Isr = Address;
}

/**
 * This is the ISR of Timer 6.
 */

void __ISR (_TIMER_9_VECTOR, ipl1AUTO)
Tmr9Handler (void)
{
  IFS1bits.T9IF = 0;
  Tmr9Isr ();
}

/**
 * This function is used to configure the 32 bit Timer4.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer4_5_32BitConfig (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT32 TmrPr4Val = 0;
  DISABLE_TIMER4;
  T4CONbits.TCKPS = TIMER4PS; // PreScalar value 1:1
  T5CONbits.SIDL = 0; //clear SIDL of timer5 for run in idle mode
  T4CONbits.T32 = 1; //32 bit ON
  CLEAR_TIMER4;
  //set the interrupt function of Timer 5s
  IFS0bits.T5IF = 0;
  IEC0bits.T5IE = InterruptStatus;
  IPC6bits.T5IP = Priority;
  TmrPr4Val = CalcPeriodReg (InterruptFreq, TIMER4PS_VALUE);
  PR4 = TmrPr4Val;
}

/**
 * This function is used to configure the 32 bit Timer6.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer6_7_32BitConfig (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT32 TmrPr6Val = 0;
  DISABLE_TIMER6;
  T6CONbits.TCKPS = TIMER6PS; // PreScalar value 1:1
  T7CONbits.SIDL = 0; //clear SIDL of timer5 for run in idle mode
  T6CONbits.T32 = 1; //32 bit ON
  CLEAR_TIMER6;
  //set the interrupt function of Timer 7
  IFS1bits.T7IF = 0;
  IEC1bits.T7IE = InterruptStatus;
  IPC8bits.T7IP = Priority;
  TmrPr6Val = CalcPeriodReg (InterruptFreq, TIMER6PS_VALUE);
  PR6 = TmrPr6Val;
}

/**
 * This function is used to configure the 32 bit Timer8.
 * @param InterruptFreq, The interrupt frequency of timer.
 * @param InterruptStatus, 1 to enable interrupt, 0 to disable interrupt.
 * @param Priority, To setup the Timer3 interrupt priority.
 */

void
Timer8_9_32BitConfig (double InterruptFreq, bool InterruptStatus, BYTE Priority)
{
  UINT32 TmrPr8Val = 0;
  DISABLE_TIMER8;
  T8CONbits.TCKPS = TIMER6PS; // PreScalar value 1:1
  T9CONbits.SIDL = 0; //clear SIDL of timer5 for run in idle mode
  T8CONbits.T32 = 1; //32 bit ON
  CLEAR_TIMER8;
  //set the interrupt function of Timer 7
  IFS1bits.T9IF = 0;
  IEC1bits.T9IE = InterruptStatus;
  IPC10bits.T9IP = Priority;
  TmrPr8Val = CalcPeriodReg (InterruptFreq, TIMER8PS_VALUE);
  PR8 = TmrPr8Val;
}