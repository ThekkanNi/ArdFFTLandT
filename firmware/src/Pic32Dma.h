/* 
 * File:   Pic32Dma.h
 * Author: aravi
 *
 * Created on February 4, 2025, 12:04 PM
 */

#ifndef PIC32DMA_H
#define	PIC32DMA_H




/* 
 * File:   SpiDmaDriver.h
 * Author: Aravind Ts
 *
 * Created on June 25, 2024, 6:42 PM
 */

#ifndef SPIDMADRIVER_H
#define	SPIDMADRIVER_H


/* 
 * This is Peripheral to memory DMA driver
 * Enable each channel given below to activate DMA respective channel
 *    DmaChannel_(Channel Number)_Array_Data_Type  this represent what type of data type the memory is
 * 1 for BYTE
 * 2 for INT16
 * 3 for UINT16
 * 4 for INT32
 * 5 for UINT32
 
 * This driver also support DMA ping Pong AKA DMA Chaining
 * 4 Drivers are available for DMA Chaining
 */

/********************* CHANNEL DEFINITIONS (VALUES NESCARY FOR EACH CHANEL FUNCTIONSC *******************/

/********************* SINGLE CHANNEL DMA *************************************/

#define DmaChannel_0     
//#define DmaChannel_1 
//#define DmaChannel_2
//#define DmaChannel_3
//#define DmaChannel_4
//#define DmaChannel_5
//#define DmaChannel_6
//#define DmaChannel_7

/********************* DMA CHAINING *******************************************/

//#define Chain_Dma_0_And_1
//#define Chain_Dma_2_And_3
//#define Chain_Dma_4_And_5
//#define Chain_Dma_6_And_7

/********************* MEMORY TO MEMORY ***************************************/

//#define MemtoMemDma_Channel_0
//#define MemtoMemDma_Channel_1
//#define MemtoMemDma_Channel_2
//#define MemtoMemDma_Channel_3

/*             MEMMORY TO PERIPHERAL DMA           */

#define MemToPeripheralCh0
//#define MemToPeripheralCh1
//#define MemToPeripheralCh2
//#define MemToPeripheralCh3
//#define MemToPeripheralCh4
//#define MemToPeripheralCh5
//#define MemToPeripheralCh6
//#define MemToPeripheralCh7



/******************* END OF CHANNEL DEFINITIONS *******************************/


/************* ALL FUNTIONS NESSCARY VALUES ***********************************/
#ifdef DmaChannel_0

#define DmaChannel_0_Array_Data_Type         3
#define DmaChannel_0_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_0_Interupt_PRIORITY      5
#define DMA_CHANNEL_0_Interupt_Sub_PRIORITY  3
#define DmaChannel_0_DataBuffer              &ADCDATA10
#define Dma0RunContinously                   1
#define Dma0InterruptFunction                1
#endif

#ifdef DmaChannel_1

#define DmaChannel_1_Array_Data_Type         3
#define DmaChannel_1_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_1_Interupt_PRIORITY      5
#define DMA_CHANNEL_1_Interupt_Sub_PRIORITY  3
#define DmaChannel_1_DataBuffer              &ADCDATA10
#define Dma1RunContinously                   1
#define Dma1InterruptFunction                1

#endif

#ifdef DmaChannel_2

#define DmaChannel_2_Array_Data_Type         3
#define DmaChannel_2_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_2_Interupt_PRIORITY      5
#define DMA_CHANNEL_2_Interupt_Sub_PRIORITY  3
#define DmaChannel_2_DataBuffer              &ADCDATA10
#define Dma2RunContinously                   1
#define Dma2InterruptFunction                1

#endif

#ifdef DmaChannel_3

#define DmaChannel_3_Array_Data_Type         3
#define DmaChannel_3_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_3_Interupt_PRIORITY      5
#define DMA_CHANNEL_3_Interupt_Sub_PRIORITY  3
#define DmaChannel_3_DataBuffer              &ADCDATA10
#define Dma3RunContinously                   1
#define Dma3InterruptFunction                1

#endif

#ifdef DmaChannel_4

#define DmaChannel_4_Array_Data_Type         3
#define DmaChannel_4_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_4_Interupt_PRIORITY      5
#define DMA_CHANNEL_4_Interupt_Sub_PRIORITY  3
#define DmaChannel_4_DataBuffer              &ADCDATA10
#define Dma4RunContinously                   1
#define Dma4InterruptFunction                1

#endif


#ifdef DmaChannel_5

#define DmaChannel_5_Array_Data_Type         3
#define DmaChannel_5_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_5_Interupt_PRIORITY      5
#define DMA_CHANNEL_5_Interupt_Sub_PRIORITY  3
#define DmaChannel_5_DataBuffer              &ADCDATA10
#define Dma5RunContinously                   1
#define Dma5InterruptFunction                1

#endif

#ifdef DmaChannel_6

#define DmaChannel_6_Array_Data_Type         3
#define DmaChannel_6_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_6_Interupt_PRIORITY      5
#define DMA_CHANNEL_6_Interupt_Sub_PRIORITY  3
#define DmaChannel_6_DataBuffer              &ADCDATA10
#define Dma6RunContinously                   1
#define Dma6InterruptFunction                1

#endif


#ifdef DmaChannel_7

#define DmaChannel_7_Array_Data_Type         3
#define DmaChannel_7_InterruptVector         _ADC_EOS_VECTOR
#define DMA_CHANNEL_7_Interupt_PRIORITY      5
#define DMA_CHANNEL_7_Interupt_Sub_PRIORITY  3
#define DmaChannel_7_DataBuffer              &ADCDATA10
#define Dma7RunContinously                   1
#define Dma7InterruptFunction                1

#endif

#ifdef Chain_Dma_0_And_1

#define DMA_Chain_0_And_1_Array_Data_Type         3
#define DMA_Chain_0_And_1_InterruptVector          _ADC_EOS_VECTOR
#define DMA_Chain_0_Interupt_PRIORITY             5
#define DMA_Chain_1_Interupt_PRIORITY             2
#define DMA_Chain_0_Interupt_Sub_PRIORITY         3
#define DMA_Chain_1_Interupt_Sub_PRIORITY         2
#define DMA_Chain_0_And_1_DataBuffer              &ADCDATA10
#define DMA_Chain_0_And_1_RunContinously          0
#define DMA_Chain_0_And_1_InterruptFunction       1
#endif


#ifdef Chain_Dma_2_And_3

#define DMA_Chain_2_And_3_Array_Data_Type         3
#define DMA_Chain_2_And_3_InterruptVector          _ADC_EOS_VECTOR
#define DMA_Chain_2_Interupt_PRIORITY             5
#define DMA_Chain_3_Interupt_PRIORITY             2
#define DMA_Chain_2_Interupt_Sub_PRIORITY         3
#define DMA_Chain_3_Interupt_Sub_PRIORITY         2
#define DMA_Chain_2_And_3_DataBuffer              &ADCDATA10
#define DMA_Chain_2_And_3_RunContinously          1
#define DMA_Chain_2_And_3_InterruptFunction       1

#endif


#ifdef Chain_Dma_4_And_5

#define DMA_Chain_4_And_5_Array_Data_Type         3
#define DMA_Chain_4_And_5_InterruptVector          _ADC_EOS_VECTOR
#define DMA_Chain_4_Interupt_PRIORITY             5
#define DMA_Chain_5_Interupt_PRIORITY             2
#define DMA_Chain_4_Interupt_Sub_PRIORITY         3
#define DMA_Chain_5_Interupt_Sub_PRIORITY         2
#define DMA_Chain_4_And_5_DataBuffer              &ADCDATA10
#define DMA_Chain_4_And_5_RunContinously          1
#define DMA_Chain_4_And_5_InterruptFunction       1

#endif


#ifdef Chain_Dma_6_And_7

#define DMA_Chain_6_And_7_Array_Data_Type         3
#define DMA_Chain_6_And_7_InterruptVector          _ADC_EOS_VECTOR
#define DMA_Chain_6_Interupt_PRIORITY             5
#define DMA_Chain_7_Interupt_PRIORITY             2
#define DMA_Chain_6_Interupt_Sub_PRIORITY         3
#define DMA_Chain_7_Interupt_Sub_PRIORITY         2
#define DMA_Chain_6_And_7_DataBuffer              &ADCDATA10
#define DMA_Chain_6_And_7_RunContinously          1
#define DMA_Chain_6_And_7_InterruptFunction       1

#endif



#ifdef MemtoMemDma_Channel_0

#define MemtoMemDma_0_Array_Data_Type         7
#define MemtoMemDma_0_Interupt_PRIORITY       5
#define MemtoMemDma_0_Interupt_Sub_PRIORITY   3

#endif

#ifdef MemtoMemDma_Channel_1

#define MemtoMemDma_1_Array_Data_Type         7
#define MemtoMemDma_1_Interupt_PRIORITY       5
#define MemtoMemDma_1_Interupt_Sub_PRIORITY   3

#endif

#ifdef MemtoMemDma_Channel_2

#define MemtoMemDma_2_Array_Data_Type         7
#define MemtoMemDma_2_Interupt_PRIORITY       5
#define MemtoMemDma_2_Interupt_Sub_PRIORITY   3

#endif

#ifdef MemtoMemDma_Channel_3

#define MemtoMemDma_3_Array_Data_Type         7
#define MemtoMemDma_3_Interupt_PRIORITY       5
#define MemtoMemDma_3_Interupt_Sub_PRIORITY   3

#endif




/****************  DMA CHANNEL 0 **********************************************/
#if DmaChannel_0_Array_Data_Type == 1
typedef BYTE Dma0BuffferDataType;
#define Dma0SourceSize 1
#endif
#if DmaChannel_0_Array_Data_Type == 2
typedef INT16 Dma0BuffferDataType;
#define Dma0SourceSize 2
#endif
#if DmaChannel_0_Array_Data_Type == 3
typedef UINT16 Dma0BuffferDataType;
#define Dma0SourceSize 2
#endif
#if DmaChannel_0_Array_Data_Type == 4
typedef INT32 Dma0BuffferDataType;
Dma0SourceSize 4
#endif
#if DmaChannel_0_Array_Data_Type == 5
typedef UINT32 Dma0BuffferDataType;
Dma0SourceSize 4
#endif


#if DMA_CHANNEL_0_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_0_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_0_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_0_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_0_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_0_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_0_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_0_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_0_INT_NAME      ipl7AUTO
#endif

/****************  DMA CHANNEL 1 **********************************************/
#if DmaChannel_1_Array_Data_Type == 1
typedef BYTE Dma1BuffferDataType;
#define Dma1SourceSize 1
#endif
#if DmaChannel_1_Array_Data_Type == 2
typedef INT16 Dma1BuffferDataType;
#define Dma1SourceSize 2
#endif
#if DmaChannel_1_Array_Data_Type == 3
typedef UINT16 Dma1BuffferDataType;
#define Dma1SourceSize 2
#endif
#if DmaChannel_1_Array_Data_Type == 4
typedef INT32 Dma1BuffferDataType;
#define Dma1SourceSize 4
#endif
#if DmaChannel_1_Array_Data_Type == 5
typedef UINT32 Dma1BuffferDataType;
#define Dma1SourceSize 4
#endif


#if DMA_CHANNEL_1_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_1_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_1_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_1_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_1_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_1_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_1_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_1_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_1_INT_NAME      ipl7AUTO
#endif
/****************  DMA CHANNEL 2 **********************************************/
#if DmaChannel_2_Array_Data_Type == 1
typedef BYTE Dma2BuffferDataType;
#define Dma2SourceSize 1
#endif
#if DmaChannel_2_Array_Data_Type == 2
typedef INT16 Dma2BuffferDataType;
#define Dma2SourceSize 2
#endif
#if DmaChannel_2_Array_Data_Type == 3
typedef UINT16 Dma2BuffferDataType;
#define Dma2SourceSize 2
#endif
#if DmaChannel_2_Array_Data_Type == 4
typedef INT32 Dma2BuffferDataType;
#define Dma2SourceSize 4
#endif
#if DmaChannel_2_Array_Data_Type == 5
typedef UINT32 Dma2BuffferDataType;
#define Dma2SourceSize 4
#endif


#if DMA_CHANNEL_2_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_2_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_2_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_2_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_2_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_2_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_2_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_2_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_2_INT_NAME      ipl7AUTO
#endif


/****************  DMA CHANNEL 3 **********************************************/
#if DmaChannel_3_Array_Data_Type == 1
typedef BYTE Dma3BuffferDataType;
#define Dma3SourceSize 1
#endif
#if DmaChannel_3_Array_Data_Type == 2
typedef INT16 Dma3BuffferDataType;
#define Dma3SourceSize 2
#endif
#if DmaChannel_3_Array_Data_Type == 3
typedef UINT16 Dma3BuffferDataType;
#define Dma3SourceSize 2
#endif
#if DmaChannel_3_Array_Data_Type == 4
typedef INT32 Dma3BuffferDataType;
#define Dma3SourceSize 4
#endif
#if DmaChannel_3_Array_Data_Type == 5
typedef UINT32 Dma3BuffferDataType;
#define Dma3SourceSize 4
#endif


#if DMA_CHANNEL_3_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_3_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_3_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_3_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_3_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_3_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_3_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_3_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_3_INT_NAME      ipl7AUTO
#endif

/****************  DMA CHANNEL 4 **********************************************/
#if DmaChannel_4_Array_Data_Type == 1
typedef BYTE Dma4BuffferDataType;
#define Dma4SourceSize 1
#endif
#if DmaChannel_4_Array_Data_Type == 2
typedef INT16 Dma4BuffferDataType;
#define Dma4SourceSize 2
#endif
#if DmaChannel_4_Array_Data_Type == 3
typedef UINT16 Dma4BuffferDataType;
#define Dma4SourceSize 2
#endif
#if DmaChannel_4_Array_Data_Type == 4
typedef INT32 Dma4BuffferDataType;
#define Dma4SourceSize 4
#endif
#if DmaChannel_4_Array_Data_Type == 5
typedef UINT32 Dma4BuffferDataType;
#define Dma4SourceSize 4
#endif


#if DMA_CHANNEL_4_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_4_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_4_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_4_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_4_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_4_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_4_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_4_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_4_INT_NAME      ipl7AUTO
#endif

/****************  DMA CHANNEL 5 **********************************************/
#if DmaChannel_5_Array_Data_Type == 1
typedef BYTE Dma5BuffferDataType;
#define Dma5SourceSize 1
#endif
#if DmaChannel_5_Array_Data_Type == 2
typedef INT16 Dma5BuffferDataType;
#define Dma5SourceSize 2
#endif
#if DmaChannel_5_Array_Data_Type == 3
typedef UINT16 Dma5BuffferDataType;
#define Dma5SourceSize 2
#endif
#if DmaChannel_5_Array_Data_Type == 4
#define Dma5SourceSize 4
typedef INT32 Dma5BuffferDataType;
#endif
#if DmaChannel_5_Array_Data_Type == 5
#define Dma5SourceSize 4
typedef UINT32 Dma5BuffferDataType;
#endif


#if   DMA_CHANNEL_5_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_5_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_5_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_5_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_5_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_5_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_5_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_5_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_5_INT_NAME      ipl7AUTO
#endif
/****************  DMA CHANNEL 6 **********************************************/
#if DmaChannel_6_Array_Data_Type == 1
typedef BYTE Dma6BuffferDataType;
#define Dma6SourceSize 1
#endif
#if DmaChannel_6_Array_Data_Type == 2
typedef INT16 Dma6BuffferDataType;
#define Dma6SourceSize 2
#endif
#if DmaChannel_6_Array_Data_Type == 3
typedef UINT16 Dma6BuffferDataType;
#define Dma6SourceSize 2
#endif
#if DmaChannel_6_Array_Data_Type == 4
typedef INT32 Dma6BuffferDataType;
#define Dma6SourceSize 4
#endif
#if DmaChannel_6_Array_Data_Type == 5
typedef UINT32 Dma6BuffferDataType;
#define Dma6SourceSize 4
#endif


#if   DMA_CHANNEL_6_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_6_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_6_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_6_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_6_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_6_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_6_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_6_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_6_INT_NAME      ipl7AUTO
#endif


/****************  DMA CHANNEL 7 **********************************************/
#if DmaChannel_7_Array_Data_Type == 1
typedef BYTE Dma7BuffferDataType;
#define Dma7SourceSize 1
#endif
#if DmaChannel_7_Array_Data_Type == 2
typedef INT16 Dma7BuffferDataType;
#define Dma7SourceSize 2
#endif
#if DmaChannel_7_Array_Data_Type == 3
typedef UINT16 Dma7BuffferDataType;
#define Dma7SourceSize 2
#endif
#if DmaChannel_7_Array_Data_Type == 4
typedef INT32 Dma7BuffferDataType;
#define Dma7SourceSize 4
#endif
#if DmaChannel_7_Array_Data_Type == 5
typedef UINT32 Dma7BuffferDataType;
#define Dma7SourceSize 4
#endif


#if   DMA_CHANNEL_7_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_7_INT_NAME      ipl1AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_7_INT_NAME      ipl2AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_7_INT_NAME      ipl3AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_7_INT_NAME      ipl4AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_7_INT_NAME      ipl5AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_7_INT_NAME      ipl6AUTO
#elif DMA_CHANNEL_7_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_7_INT_NAME      ipl7AUTO
#endif


/***** FUNCTIONS FOR DMA CHANNELS *********************************************/

#ifdef DmaChannel_0
void SpiDmaSingleChannel_0_Config(Dma0BuffferDataType *Array,size_t BufferSize);
inline void StartDma0();
inline void StopDma0();
bool CheckDma0Flag();
#if Dma0InterruptFunction == 1
void AttachDMA0Interrupt(void *(Address));
void (*DMA0LocalIsr)(void);
#endif
#endif

#ifdef DmaChannel_1
void SpiDmaSingleChannel_1_Config(Dma1BuffferDataType *Array,size_t BufferSize);
inline void StartDma1();
inline void StopDma1();
bool CheckDma1Flag();
#if Dma1InterruptFunction == 1
void AttachDMA1Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_2
void SpiDmaSingleChannel_2_Config(Dma2BuffferDataType *Array,size_t BufferSize);
inline void StartDma2();
inline void StopDma2();
#if Dma2InterruptFunction == 1
void AttachDMA2Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_3
void SpiDmaSingleChannel_3_Config(Dma3BuffferDataType *Array,size_t BufferSize);
inline void StartDma3();
inline void StopDma3();
#if Dma3InterruptFunction == 1
void AttachDMA3Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_4
void SpiDmaSingleChannel_4_Config(Dma4BuffferDataType *Array,size_t BufferSize);
inline void StartDma4();
inline void StopDma4();
#if Dma4InterruptFunction == 1
void AttachDMA4Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_5
void SpiDmaSingleChannel_5_Config(Dma5BuffferDataType *Array,size_t BufferSize);
inline void StartDma5();
inline void StopDma5();
#if Dma5InterruptFunction == 1
void AttachDMA5Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_6
void SpiDmaSingleChannel_6_Config(Dma6BuffferDataType *Array,size_t BufferSize);
inline void StartDma6();
inline void StopDma6();
#if Dma6InterruptFunction == 1
void AttachDMA6Interrupt(void *(Address));
#endif
#endif

#ifdef DmaChannel_7
void SpiDmaSingleChannel_7_Config(Dma7BuffferDataType *Array,size_t BufferSize);
inline void StartDma7();
inline void StopDma7();
#if Dma7InterruptFunction == 1
void AttachDMA7Interrupt(void *(Address));
#endif
#endif

/******************* CHAINING DMA *********************************************/
#ifdef Chain_Dma_0_And_1

#if DMA_Chain_0_And_1_Array_Data_Type == 1
typedef BYTE Chain_0_1_BuferDataType;
#define Dma0SourceSize 1
#define Dma1SourceSize 1
#endif
#if DMA_Chain_0_And_1_Array_Data_Type == 2
typedef INT16 Chain_0_1_BuferDataType;
#define Dma0SourceSize 2
#define Dma1SourceSize 2
#endif
#if DMA_Chain_0_And_1_Array_Data_Type == 3
typedef UINT16 Chain_0_1_BuferDataType;
#define Dma0SourceSize 2
#define Dma1SourceSize 2
#endif
#if DMA_Chain_0_And_1_Array_Data_Type == 4
typedef INT32 Chain_0_1_BuferDataType;
#define Dma0SourceSize 4
#define Dma1SourceSize 4
#endif
#if DMA_Chain_0_And_1_Array_Data_Type == 5
typedef UINT32 Chain_0_1_BuferDataType;
#define Dma0SourceSize 4
#define Dma1SourceSize 4
#endif


#if   DMA_Chain_0_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_0_INT_NAME      ipl1AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_0_INT_NAME      ipl2AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_0_INT_NAME      ipl3AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_0_INT_NAME      ipl4AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_0_INT_NAME      ipl5AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_0_INT_NAME      ipl6AUTO
#elif DMA_Chain_0_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_0_INT_NAME      ipl7AUTO
#endif

#if   DMA_Chain_1_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_1_INT_NAME      ipl1AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_1_INT_NAME      ipl2AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_1_INT_NAME      ipl3AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_1_INT_NAME      ipl4AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_1_INT_NAME      ipl5AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_1_INT_NAME      ipl6AUTO
#elif DMA_Chain_1_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_1_INT_NAME      ipl7AUTO
#endif

#endif

#ifdef Chain_Dma_2_And_3

#if DMA_Chain_2_And_3_Array_Data_Type == 1
typedef BYTE Chain_2_3_BuferDataType;
#define Dma2SourceSize 1
#define Dma3SourceSize 1
#endif
#if DMA_Chain_2_And_3_Array_Data_Type == 2
typedef INT16 Chain_2_3_BuferDataType;
#define Dma2SourceSize 2
#define Dma3SourceSize 2
#endif
#if DMA_Chain_2_And_3_Array_Data_Type == 3
typedef UINT16 Chain_2_3_BuferDataType;
#define Dma2SourceSize 2
#define Dma3SourceSize 2
#endif
#if DMA_Chain_2_And_3_Array_Data_Type == 4
typedef INT32 Chain_2_3_BuferDataType;
#define Dma2SourceSize 4
#define Dma3SourceSize 4
#endif
#if DMA_Chain_2_And_3_Array_Data_Type == 5
typedef UINT32 Chain_2_3_BuferDataType;
#define Dma2SourceSize 4
#define Dma3SourceSize 4
#endif


#if   DMA_Chain_2_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_2_INT_NAME      ipl1AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_2_INT_NAME      ipl2AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_2_INT_NAME      ipl3AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_2_INT_NAME      ipl4AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_2_INT_NAME      ipl5AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_2_INT_NAME      ipl6AUTO
#elif DMA_Chain_2_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_2_INT_NAME      ipl7AUTO
#endif

#if   DMA_Chain_3_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_3_INT_NAME      ipl1AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_3_INT_NAME      ipl2AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_1_INT_NAME      ipl3AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_3_INT_NAME      ipl4AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_3_INT_NAME      ipl5AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_3_INT_NAME      ipl6AUTO
#elif DMA_Chain_3_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_3_INT_NAME      ipl7AUTO
#endif

#endif


#ifdef Chain_Dma_4_And_5

#if DMA_Chain_4_And_5_Array_Data_Type == 1
typedef BYTE Chain_4_5_BuferDataType;
#define Dma4SourceSize 1
#define Dma5SourceSize 1
#endif
#if DMA_Chain_4_And_5_Array_Data_Type == 2
typedef INT16 Chain_4_5_BuferDataType;
#define Dma4SourceSize 2
#define Dma5SourceSize 2
#endif
#if DMA_Chain_4_And_5_Array_Data_Type == 3
typedef UINT16 Chain_4_5_BuferDataType;
#define Dma4SourceSize 2
#define Dma5SourceSize 2
#endif
#if DMA_Chain_4_And_5_Array_Data_Type == 4
typedef INT32 Chain_4_5_BuferDataType;
#define Dma4SourceSize 4
#define Dma5SourceSize 4
#endif
#if DMA_Chain_4_And_5_Array_Data_Type == 5
typedef UINT32 Chain_4_5_BuferDataType;
#define Dma4SourceSize 4
#define Dma5SourceSize 4
#endif


#if   DMA_Chain_4_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_4_INT_NAME      ipl1AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_4_INT_NAME      ipl2AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_4_INT_NAME      ipl3AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_4_INT_NAME      ipl4AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_4_INT_NAME      ipl5AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_4_INT_NAME      ipl6AUTO
#elif DMA_Chain_4_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_4_INT_NAME      ipl7AUTO
#endif

#if   DMA_Chain_5_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_5_INT_NAME      ipl1AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_5_INT_NAME      ipl2AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_5_INT_NAME      ipl3AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_5_INT_NAME      ipl4AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_5_INT_NAME      ipl5AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_5_INT_NAME      ipl6AUTO
#elif DMA_Chain_5_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_5_INT_NAME      ipl7AUTO
#endif

#endif


#ifdef Chain_Dma_6_And_7

#if DMA_Chain_6_And_7_Array_Data_Type == 1
typedef BYTE Chain_6_7_BuferDataType;
#define Dma6SourceSize 1
#define Dma7SourceSize 1
#endif
#if DMA_Chain_6_And_7_Array_Data_Type == 2
typedef INT16 Chain_6_7_BuferDataType;
#define Dma6SourceSize 2
#define Dma7SourceSize 2
#endif
#if DMA_Chain_6_And_7_Array_Data_Type == 3
typedef UINT16 Chain_6_7_BuferDataType;
#define Dma6SourceSize 2
#define Dma7SourceSize 2
#endif
#if DMA_Chain_6_And_7_Array_Data_Type == 4
typedef INT32 Chain_6_7_BuferDataType;
#define Dma6SourceSize 4
#define Dma7SourceSize 4
#endif
#if DMA_Chain_6_And_7_Array_Data_Type == 5
typedef UINT32 Chain_6_7_BuferDataType;
#define Dma6SourceSize 4
#define Dma7SourceSize 4
#endif


#if   DMA_Chain_6_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_6_INT_NAME      ipl1AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_6_INT_NAME      ipl2AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_6_INT_NAME      ipl3AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_6_INT_NAME      ipl4AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_6_INT_NAME      ipl5AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_6_INT_NAME      ipl6AUTO
#elif DMA_Chain_6_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_6_INT_NAME      ipl7AUTO
#endif

#if   DMA_Chain_7_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_7_INT_NAME      ipl1AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_7_INT_NAME      ipl2AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_7_INT_NAME      ipl3AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_7_INT_NAME      ipl4AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_7_INT_NAME      ipl5AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_7_INT_NAME      ipl6AUTO
#elif DMA_Chain_7_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_7_INT_NAME      ipl7AUTO
#endif

#endif

/********* FUNCTIONS FOR DMA CHAINING *****************************************/

#ifdef Chain_Dma_0_And_1
void Dma_Chain_Init_0_And_1(Chain_0_1_BuferDataType *Array1,size_t BufferSize1,Chain_0_1_BuferDataType *Array2,size_t BufferSize2);
bool CheckDma0Flag();
bool CheckDma1Flag();
void Start_Dma_Chain_0_1();
void Stop_Dma_Chain_0_1();
void (*DMA_Chain_0_LocalIsr)(void);
void (*DMA_Chain_1_LocalIsr)(void);
void AttachDMA_Chain_0_And_1Interrupt(void *(Address1),void *(Address2));
#endif

#ifdef Chain_Dma_2_And_3
void Dma_Chain_Init_2_And_3(Chain_2_3_BuferDataType *Array1,size_t BufferSize1,Chain_2_3_BuferDataType *Array2,size_t BufferSize2);
bool CheckDma2Flag();
bool CheckDma3Flag();
void Start_Dma_Chain_2_3();
void Stop_Dma_Chain_2_3();
void (*DMA_Chain_2_LocalIsr)(void);
void (*DMA_Chain_3_LocalIsr)(void);
void AttachDMA_Chain_2_And_3Interrupt(void *(Address1),void *(Address2));
#endif

#ifdef Chain_Dma_4_And_5
void Dma_Chain_Init_4_And_5(Chain_4_5_BuferDataType *Array1,size_t BufferSize1,Chain_4_5_BuferDataType *Array2,size_t BufferSize2);
bool CheckDma4Flag();
bool CheckDma5Flag();
void Start_Dma_Chain_4_5();
void Stop_Dma_Chain_4_5();
void (*DMA_Chain_4_LocalIsr)(void);
void (*DMA_Chain_5_LocalIsr)(void);
void AttachDMA_Chain_4_And_5Interrupt(void *(Address1),void *(Address2));
#endif

#ifdef Chain_Dma_6_And_7
void Dma_Chain_Init_0_And_1(Chain_6_7_BuferDataType *Array1,size_t BufferSize1,Chain_6_7_BuferDataType *Array2,size_t BufferSize2);
bool CheckDma6Flag();
bool CheckDma7Flag();
void Start_Dma_Chain_6_7();
void Stop_Dma_Chain_6_7();
void (*DMA_Chain_6_LocalIsr)(void);
void (*DMA_Chain_7_LocalIsr)(void);
void AttachDMA_Chain_6_And_7Interrupt(void *(Address1),void *(Address2));
#endif
/******************** MEM TO MEM **********************************************/

/************* CHANNEL 0 ******************************************************/

#ifdef MemtoMemDma_Channel_0

#if MemtoMemDma_0_Array_Data_Type == 1
typedef BYTE Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 2
typedef INT16 Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 3
typedef UINT16 Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 4
typedef INT32 Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 5
typedef UINT32 Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 6
typedef float Dma0BuffferDataType;
#endif
#if MemtoMemDma_0_Array_Data_Type == 7
typedef double Dma0BuffferDataType;
#endif


#if MemtoMemDma_0_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_0_INT_NAME      ipl1AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_0_INT_NAME      ipl2AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_0_INT_NAME      ipl3AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_0_INT_NAME      ipl4AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_0_INT_NAME      ipl5AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_0_INT_NAME      ipl6AUTO
#elif MemtoMemDma_0_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_0_INT_NAME      ipl7AUTO
#endif

#endif

#ifdef MemtoMemDma_Channel_1
#if MemtoMemDma_1_Array_Data_Type == 1
typedef BYTE Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 2
typedef INT16 Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 3
typedef UINT16 Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 4
typedef INT32 Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 5
typedef UINT32 Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 6
typedef float Dma1BuffferDataType;
#endif
#if MemtoMemDma_1_Array_Data_Type == 7
typedef double Dma1BuffferDataType;
#endif

#if MemtoMemDma_1_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_1_INT_NAME      ipl1AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_1_INT_NAME      ipl2AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_1_INT_NAME      ipl3AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_1_INT_NAME      ipl4AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_1_INT_NAME      ipl5AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_1_INT_NAME      ipl6AUTO
#elif MemtoMemDma_1_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_1_INT_NAME      ipl7AUTO
#endif

#endif

#ifdef MemtoMemDma_Channel_2

#if MemtoMemDma_2_Array_Data_Type == 1
typedef BYTE Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 2
typedef INT16 Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 3
typedef UINT16 Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 4
typedef INT32 Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 5
typedef UINT32 Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 6
typedef float Dma2BuffferDataType;
#endif
#if MemtoMemDma_2_Array_Data_Type == 7
typedef double Dma2BuffferDataType;
#endif

#if MemtoMemDma_2_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_2_INT_NAME      ipl1AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_2_INT_NAME      ipl2AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_2_INT_NAME      ipl3AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_2_INT_NAME      ipl4AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_2_INT_NAME      ipl5AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_2_INT_NAME      ipl6AUTO
#elif MemtoMemDma_2_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_2_INT_NAME      ipl7AUTO
#endif

#endif
#ifdef MemtoMemDma_Channel_3

#if MemtoMemDma_3_Array_Data_Type == 1
typedef BYTE Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 2
typedef INT16 Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 3
typedef UINT16 Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 4
typedef INT32 Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 5
typedef UINT32 Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 6
typedef float Dma3BuffferDataType;
#endif
#if MemtoMemDma_3_Array_Data_Type == 7
typedef double Dma3BuffferDataType;
#endif

#if MemtoMemDma_3_Interupt_PRIORITY == 1
#define     DMA_CHANNEL_3_INT_NAME      ipl1AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 2
#define     DMA_CHANNEL_3_INT_NAME      ipl2AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 3
#define     DMA_CHANNEL_3_INT_NAME      ipl3AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 4
#define     DMA_CHANNEL_3_INT_NAME      ipl4AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 5
#define     DMA_CHANNEL_3_INT_NAME      ipl5AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 6
#define     DMA_CHANNEL_3_INT_NAME      ipl6AUTO
#elif MemtoMemDma_3_Interupt_PRIORITY == 7
#define     DMA_CHANNEL_3_INT_NAME      ipl7AUTO
#endif

#endif
/******************** MEMORY TO MEMORY DMA FUNCTIONS **************************/

#ifdef MemtoMemDma_Channel_0
void MemToMemDma0(Dma0BuffferDataType *Array1,Dma0BuffferDataType *Array2,UINT16 Size);
void StartMemtoMemDma0();
inline void StopMemtoMemDma0();
#endif

#ifdef MemtoMemDma_Channel_1

void MemToMemDma1(Dma1BuffferDataType *Array1,Dma1BuffferDataType *Array2,UINT16 Size);
void StartMemtoMemDma1();
inline void StopMemtoMemDma1();

#endif

#ifdef MemtoMemDma_Channel_2

void MemToMemDma2(Dma2BuffferDataType *Array1,Dma2BuffferDataType *Array2,UINT16 Size);
void StartMemtoMemDma2();
inline void StopMemtoMemDma2();

#endif

#ifdef MemtoMemDma_Channel_3

void MemToMemDma3(Dma2BuffferDataType *Array1,Dma2BuffferDataType *Array2,UINT16 Size);
void StartMemtoMemDma3();
inline void StopMemtoMemDma3();

#endif

#ifdef  MemToPeripheralCh0

void InitMemToPerSrcDma0(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs0(void *Address, UINT16 Size);
void StartMemToPerDma0(void);
void StopMemToPerDma0(void);

#endif
#ifdef  MemToPeripheralCh1

void InitMemToPerSrcDma1(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs1(void *Address, UINT16 Size);
void StartMemToPerDma1(void);
void StopMemToPerDma1(void);

#endif
#ifdef  MemToPeripheralCh2

void InitMemToPerSrcDma2(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs2(void *Address, UINT16 Size);
void StartMemToPerDma2(void);
void StopMemToPerDma2(void);

#endif
#ifdef  MemToPeripheralCh3

void InitMemToPerSrcDma3(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs3(void *Address, UINT16 Size);
void StartMemToPerDma3(void);
void StopMemToPerDma3(void);

#endif
#ifdef  MemToPeripheralCh4

void InitMemToPerSrcDma4(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs4(void *Address, UINT16 Size);
void StartMemToPerDma4(void);
void StopMemToPerDma4(void);

#endif
#ifdef  MemToPeripheralCh5

void InitMemToPerSrcDma5(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs5(void *Address, UINT16 Size);
void StartMemToPerDma5(void);
void StopMemToPerDma5(void);

#endif
#ifdef  MemToPeripheralCh6
void InitMemToPerSrcDma6(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs6(void *Address, UINT16 Size);
void StartMemToPerDma6(void);
void StopMemToPerDma6(void);

#endif
#ifdef  MemToPeripheralCh7

void InitMemToPerSrcDma7(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority);
void SetMemToPerSrcAddrs7(void *Address, UINT16 Size);
void StartMemToPerDma7(void);
void StopMemToPerDma7(void);
#endif
/********** END OF FILE ********************************************************/




//
//#define MemToPeripheralCh1
//#define MemToPeripheralCh2
//#define MemToPeripheralCh3
//#define MemToPeripheralCh4
//#define MemToPeripheralCh5
//#define MemToPeripheralCh6
//#define MemToPeripheralCh7


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SPIDMADRIVER_H */













#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PIC32DMA_H */

