/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
 */


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void
APP_Initialize (void)
{
  /* Place the App state machine in its initial state. */
  appData.state = APP_STATE_INIT;


  /* TODO: Initialize your application's state machine and other
   * parameters.
   */
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void
APP_Tasks (void)
{

  /* Check the application's current state. */
  switch (appData.state)
    {
      /* Application's initial state. */
    case APP_STATE_INIT:
      {
        bool appInitialized = true;

        if (appInitialized)
          {

            /*** PIN CONFIG ****/
            TRISBbits.TRISB14 = 1; // AN9, Analog Input, PIN 29.
            ANSELBbits.ANSB14 = 1; // Activating Analog
            TRISBbits.TRISB13 = 0; // MCU LED , PIN 28.
            ANSELBbits.ANSB13 = 0; // Clearing Analog
            TRISBbits.TRISB1 = 0; // Debug RX, PIN 15.
            ANSELBbits.ANSB1 = 0; // Clearing Analog
            /*******************/
            Uart1tInit (0, 0, 921600, 1, 0, 1);
            //            SYS_INT_SourceEnable (INT_SOURCE_USART_1_RECEIVE); // DEBUG UART Receive Enable. 
            __XC_UART = 1; // DEBUG UART 460800
            UINT16 Count = 60;
            while (Count--)
              {
                MCU_LEDToggle ();
                __delay_ms (50);
              }
            printf ("RCON : 0x%x\n\r", RCON);
            printf ("TIME : %s\n\r", __TIME__);
            printf ("DATE : %s\n\r", __DATE__);
            printf ("ARD FFT L&T\n\r");

            AdcInit ();
            __delay_ms (50);

//            Timer5Config (160000, 1, 7);    // 6.25 us     6.25us  * 10000 =  62.5  mS
//            Timer5Config (80000, 1, 7);     // 12.5 us     12.5uS  * 10000 =  125   mS
//            Timer5Config (20000.0, 1, 7);     // 50   us     50.0uS  * 10000 =  500   mS
            Timer5Config (10000.0, 1, 7);   // 100  us     100.0uS * 10000 =  1000  mS

//            TIMER  1:1     (0.01 uS  655.35 uS)
            
            
            while(1)
              {
                
                  
              }

            StartTimer5 ();

            memcpy (LandTDatatoGui.Packet.Header, HEADER, HEADER_SIZE);
            memcpy (LandTDatatoGui.Packet.Footer, FOOTER, FOOTER_SIZE);

            UINT16 AdcSamplesForFFT[2][LT_DATA_ADC_COUNT_SIZE];
            appData.state = APP_STATE_SERVICE_TASKS;
          }

        break;
      }


    case APP_STATE_SERVICE_TASKS:
      {

        if (AdcBufferSend)
          {
            MCU_LEDToggle ();
            Tppindex ^= (AdcPingPong);
            memcpy (&LandTDatatoGui.Packet.Payload.AdcData[0], &AdcSamplesForFFT[Tppindex][0], (LT_DATA_ADC_COUNT_SIZE * 2));
            U1PutBuff (LandTDatatoGui.TxBuffer, LT_DATA_TO_GUI_TX_SIZE); //  
            AdcBufferSend = 0;
          }

        break;
      }


      /* TODO: implement your application state machine.*/

      /* The default state should never be executed. */


    default:
      {

        /* TODO: Handle error in application's state machine. */
        break;
      }


    }
}



/*******************************************************************************
 End of File
 */
