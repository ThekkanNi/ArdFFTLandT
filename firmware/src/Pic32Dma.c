#include "app.h"


#include "app.h"



/***** FLAGS FOR EACH DMA *****************************************************/
bool Dma0Flag = 0;
bool Dma1Flag = 0;
bool Dma2Flag = 0;
bool Dma3Flag = 0;
bool Dma4Flag = 0;
bool Dma5Flag = 0;
bool Dma6Flag = 0;
bool Dma7Flag = 0;
 
/***** THIS FUNCTION COVERT VITUAL MEMORY TO PHYSICAL MEMMORY IT IS NESCASSARY FOR DMA APPLICATION  *************/

extern __inline__ unsigned int __attribute__((always_inline)) virt_to_phys(const void* p) {
return (int)p<0?((int)p&0x1fffffffL):(unsigned int)((unsigned char*)p+0x40000000L);
}

/*************** TEST VARIABLES ***********************************************/








/*************** END OF TEST VARIABLES ****************************************/


/*********************** DMA CHANNEL 0 ****************************************/

#ifdef DmaChannel_0


void (*DMA0LocalIsr)(void);


void AttachDMA0Interrupt(void *(Address))
{
    DMA0LocalIsr = Address;
}


void SpiDmaSingleChannel_0_Config(Dma0BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH0ECONbits.CHSIRQ = DmaChannel_0_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH0ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH0CONbits.CHPRI   = DMA_CHANNEL_0_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
    
    DCH0SSA = virt_to_phys((const void*)DmaChannel_0_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH0DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH0SSIZ = Dma0SourceSize;                                     // Source size is 2 byte data.
    DCH0DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH0CSIZ = Dma0SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH0INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC33bits.DMA0IP = DMA_CHANNEL_0_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA0IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA0IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH0INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 0.
 */
void __ISR(_DMA0_VECTOR, DMA_CHANNEL_0_INT_NAME) _IntHandlerSysDmaCh0(void)
{
    DCH0CONbits.CHEN = Dma0RunContinously;  
    IFS4bits.DMA0IF  = 0;                            // DMA Channel 0 Interrupt Flag Cleared.
    DCH0INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/   
Dma0Flag = 1;
#if Dma0InterruptFunction == 1
    DMA0LocalIsr();  
#endif 
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_0);
}



bool CheckDma0Flag()
{
    if(Dma0Flag == 1)
    {
        Dma0Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma0()
{
   DCH0CONbits.CHEN = 1;       
}

inline void StopDma0()
{
   DCH0CONbits.CHEN = 0;       
}


#endif


/*********************** DMA CHANNEL 1 ****************************************/

#ifdef DmaChannel_1


void (*DMA1LocalIsr)(void);


void AttachDMA1Interrupt(void *(Address))
{
    DMA1LocalIsr = Address;
}

void SpiDmaSingleChannel_1_Config(Dma1BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH1ECONbits.CHSIRQ = DmaChannel_1_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH1ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH1CONbits.CHPRI   = DMA_CHANNEL_1_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
    
    DCH1SSA = virt_to_phys((const void*)DmaChannel_1_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH1DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH1SSIZ = Dma1SourceSize;                                     // Source size is 2 byte data.
    DCH1DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH1CSIZ = Dma1SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH1INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC33bits.DMA1IP = DMA_CHANNEL_1_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA1IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA1IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH1INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 1.
 */
void __ISR(_DMA1_VECTOR, DMA_CHANNEL_1_INT_NAME) _IntHandlerSysDmaCh1(void)
{
    DCH1CONbits.CHEN = Dma1RunContinously;  
    IFS4bits.DMA1IF  = 0;                                          // DMA Channel 1 Interrupt Flag Cleared.
    DCH1INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma1Flag = 1;
#if Dma1InterruptFunction == 1
    DMA1LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_1);
}


bool CheckDma1Flag()
{
    if(Dma1Flag == 1)
    {
        Dma1Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma1()
{
   DCH1CONbits.CHEN = 1;       
}

inline void StopDma1()
{
   DCH1CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 2 ****************************************/

#ifdef DmaChannel_2


void (*DMA2LocalIsr)(void);


void AttachDMA2Interrupt(void *(Address))
{
    DMA2LocalIsr = Address;
}

void SpiDmaSingleChannel_2_Config(Dma2BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH2ECONbits.CHSIRQ = DmaChannel_2_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH2ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH2CONbits.CHPRI   = DMA_CHANNEL_2_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
    
    DCH2SSA = virt_to_phys((const void*)DmaChannel_2_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH2DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH2SSIZ = Dma2SourceSize;                                     // Source size is 2 byte data.
    DCH2DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH2CSIZ = Dma2SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH2INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC34bits.DMA2IP = DMA_CHANNEL_2_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA2IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA2IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH2INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 2.
 */
void __ISR(_DMA2_VECTOR, DMA_CHANNEL_2_INT_NAME) _IntHandlerSysDmaCh2(void)
{
    DCH2CONbits.CHEN = Dma2RunContinously;  
    IFS4bits.DMA2IF  = 0;                                          // DMA Channel 2 Interrupt Flag Cleared.
    DCH2INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma2Flag = 1;
#if Dma2InterruptFunction == 1
    DMA2LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_2);
}


bool CheckDma2Flag()
{
    if(Dma2Flag == 1)
    {
        Dma2Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma2()
{
   DCH2CONbits.CHEN = 1;       
}

inline void StopDma2()
{
   DCH2CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 3 ****************************************/

#ifdef DmaChannel_3

void (*DMA3LocalIsr)(void);


void AttachDMA3Interrupt(void *(Address))
{
    DMA3LocalIsr = Address;
}

void SpiDmaSingleChannel_3_Config(Dma3BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH3ECONbits.CHSIRQ = DmaChannel_3_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH3ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH3CONbits.CHPRI   = DMA_CHANNEL_3_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
   
    DCH3SSA = virt_to_phys((const void*)DmaChannel_3_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH3DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH3SSIZ = Dma3SourceSize;                                     // Source size is 2 byte data.
    DCH3DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH3CSIZ = Dma3SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH3INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC34bits.DMA3IP = DMA_CHANNEL_3_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA3IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA3IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH3INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 3.
 */
void __ISR(_DMA3_VECTOR, DMA_CHANNEL_3_INT_NAME) _IntHandlerSysDmaCh3(void)
{
    DCH3CONbits.CHEN = Dma3RunContinously;  
    IFS4bits.DMA3IF  = 0;                                          // DMA Channel 3 Interrupt Flag Cleared.
    DCH3INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma3Flag = 1;
#if Dma3InterruptFunction == 1
    DMA3LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_3);
}


bool CheckDma3Flag()
{
    if(Dma3Flag == 1)
    {
        Dma3Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma3()
{
   DCH3CONbits.CHEN = 1;       
}

inline void StopDma3()
{
   DCH3CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 4 ****************************************/

#ifdef DmaChannel_4

void (*DMA4LocalIsr)(void);


void AttachDMA4Interrupt(void *(Address))
{
    DMA4LocalIsr = Address;
}

void SpiDmaSingleChannel_4_Config(Dma4BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH4ECONbits.CHSIRQ = DmaChannel_4_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH4ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH4CONbits.CHPRI   = DMA_CHANNEL_4_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
   
    DCH4SSA = virt_to_phys((const void*)DmaChannel_4_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH4DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH4SSIZ = Dma4SourceSize;                                     // Source size is 2 byte data.
    DCH4DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH4CSIZ = Dma4SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH4INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC34bits.DMA4IP = DMA_CHANNEL_4_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA4IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA4IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH4INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 4.
 */
void __ISR(_DMA4_VECTOR, DMA_CHANNEL_4_INT_NAME) _IntHandlerSysDmaCh4(void)
{
    DCH4CONbits.CHEN = Dma4RunContinously;  
    IFS4bits.DMA4IF  = 0;                                          // DMA Channel 4 Interrupt Flag Cleared.
    DCH4INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma4Flag = 1;
#if Dma4InterruptFunction == 1
    DMA4LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_4);
}


bool CheckDma4Flag()
{
    if(Dma4Flag == 1)
    {
        Dma4Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma4()
{
   DCH4CONbits.CHEN = 1;       
}

inline void StopDma4()
{
   DCH4CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 5 ****************************************/

#ifdef DmaChannel_5

void (*DMA5LocalIsr)(void);


void AttachDMA5Interrupt(void *(Address))
{
    DMA5LocalIsr = Address;
}

void SpiDmaSingleChannel_5_Config(Dma5BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH5ECONbits.CHSIRQ = DmaChannel_5_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH5ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH5CONbits.CHPRI   = DMA_CHANNEL_5_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
   
    DCH5SSA = virt_to_phys((const void*)DmaChannel_5_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH5DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH5SSIZ = Dma5SourceSize;                                     // Source size is 2 byte data.
    DCH5DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH5CSIZ = Dma5SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH5INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC34bits.DMA5IP = DMA_CHANNEL_5_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA5IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA5IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH5INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 5.
 */
void __ISR(_DMA5_VECTOR, DMA_CHANNEL_5_INT_NAME) _IntHandlerSysDmaCh5(void)
{
    DCH5CONbits.CHEN = Dma5RunContinously;  
    IFS4bits.DMA5IF  = 0;                            // DMA Channel 0 Interrupt Flag Cleared.
    DCH5INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma5Flag = 1;
#if Dma5InterruptFunction == 1
    DMA5LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_5);
}


bool CheckDma5Flag()
{
    if(Dma5Flag == 1)
    {
        Dma5Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma5()
{
   DCH5CONbits.CHEN = 1;       
}

inline void StopDma5()
{
   DCH5CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 6 ****************************************/

#ifdef DmaChannel_6

void (*DMA6LocalIsr)(void);


void AttachDMA6Interrupt(void *(Address))
{
    DMA6LocalIsr = Address;
}

void SpiDmaSingleChannel_6_Config(Dma6BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH6ECONbits.CHSIRQ = DmaChannel_6_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH6ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH6CONbits.CHPRI   = DMA_CHANNEL_6_Interupt_Sub_PRIORITY;     // Channel 5 has the highest Priority.
   
    DCH6SSA = virt_to_phys((const void*)DmaChannel_6_DataBuffer);  // Source Destination is the readings from Dedicated ADC Module 0.
    DCH6DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH6SSIZ = Dma6SourceSize;                                     // Source size is 2 byte data.
    DCH6DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH6CSIZ = Dma6SourceSize;                                     // Cell transfer size is 2 bytes    
    
    
    DCH6INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC35bits.DMA6IP = DMA_CHANNEL_6_Interupt_PRIORITY;            // DMA Channel 5 Interrupt Priority 5.
    IFS4bits.DMA6IF  = 0;                                          // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA6IE  = 1;                                          // DMA Channel 5 Interrupt is enabled.
    DCH6INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 6.
 */
void __ISR(_DMA6_VECTOR, DMA_CHANNEL_6_INT_NAME) _IntHandlerSysDmaCh6(void)
{
    DCH6CONbits.CHEN = Dma6RunContinously;  
    IFS4bits.DMA6IF  = 0;                            // DMA Channel 0 Interrupt Flag Cleared.
    DCH6INT          = 0xff0000;
    
/************ DMA OPERATIONS ***************************************************/
   
Dma6Flag = 1;
#if Dma6InterruptFunction == 1
    DMA6LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_6);
}


bool CheckDma6Flag()
{
    if(Dma6Flag == 1)
    {
        Dma6Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma6()
{
   DCH6CONbits.CHEN = 1;       
}

inline void StopDma6()
{
   DCH6CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHANNEL 7 ****************************************/

#ifdef DmaChannel_7

void (*DMA7LocalIsr)(void);


void AttachDMA7Interrupt(void *(Address))
{
    DMA7LocalIsr = Address;
}

void SpiDmaSingleChannel_7_Config(Dma7BuffferDataType *Array,size_t BufferSize)
{
    DMACON = 0;
    

    DCH7ECONbits.CHSIRQ = DmaChannel_7_InterruptVector;            // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH7ECONbits.SIRQEN = 1;                                       // start cell transfer if Interrupt Event Occurs.
    DCH7CONbits.CHPRI   = DMA_CHANNEL_7_Interupt_Sub_PRIORITY;     // Channel 7 Priority.
   
    DCH7SSA = virt_to_phys((const void*)DmaChannel_7_DataBuffer);  // Source Destination is the readings from Dedicated Buffer Module
    DCH7DSA = virt_to_phys(Array);                                 // Destination Address to which data to be transfered.
   
    DCH7SSIZ = Dma7SourceSize;                                     // Source size
    DCH7DSIZ = BufferSize;                                         // Destination Buffer size.
    DCH7CSIZ = Dma7SourceSize;                                     // Cell transfer size    
    
    
    DCH7INT = 0;                                                   // All DMA Interrupts are disabled.
    IPC35bits.DMA7IP = DMA_CHANNEL_7_Interupt_PRIORITY;            // DMA Channel 7 Interrupt Priority 
    IFS4bits.DMA7IF  = 0;                                          // DMA Channel 7 Interrupt Flag Cleared.
    IEC4bits.DMA7IE  = 1;                                          // DMA Channel 7 Interrupt is enabled.
    DCH7INTbits.CHBCIE = 1;                                        // DMA Destination Done interrupt enabled.
    DMACONbits.ON = 1;                                             // DMA Module is enabled.
    
}



/**
 * This is the ISR of DMA Channel 0.
 */
void __ISR(_DMA7_VECTOR, DMA_CHANNEL_7_INT_NAME) _IntHandlerSysDmaCh7(void)
{
    DCH7CONbits.CHEN = Dma7RunContinously;                          // Controls Continues function of DMA 7
    IFS4bits.DMA7IF  = 0;                                           // DMA Channel 7 Interrupt Flag Cleared.
    DCH7INT          = 0xff0000;                                    // Clear DMA 7 Flag
    
/************ DMA OPERATIONS ***************************************************/
   
Dma7Flag = 1;         // User DMA 7 Flag
#if Dma7InterruptFunction == 1
    DMA7LocalIsr();  
#endif 
         
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_7);
}


bool CheckDma7Flag()
{
    if(Dma7Flag == 1)
    {
        Dma7Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


inline void StartDma7()
{
   DCH7CONbits.CHEN = 1;       
}

inline void StopDma7()
{
   DCH7CONbits.CHEN = 0;       
}


#endif

/*********************** DMA CHAINING FUNCTIONS *******************************/

#ifdef Chain_Dma_0_And_1

void (*DMA_Chain_0_LocalIsr)(void);
void (*DMA_Chain_1_LocalIsr)(void);


void AttachDMA_Chain_0_And_1Interrupt(void *(Address1),void *(Address2))
{
    DMA_Chain_0_LocalIsr = Address1;
    DMA_Chain_1_LocalIsr = Address2;
}


void Dma_Chain_Init_0_And_1(Chain_0_1_BuferDataType *Array1,size_t BufferSize1,Chain_0_1_BuferDataType *Array2,size_t BufferSize2)
{
    
    DMACON = 0;
    

    DCH0ECONbits.CHSIRQ = DMA_Chain_0_And_1_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH0ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH0CONbits.CHPRI   = DMA_Chain_0_Interupt_Sub_PRIORITY;          // Channel 0 Priority.
    
    DCH1ECONbits.CHSIRQ = DMA_Chain_0_And_1_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH1ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH1CONbits.CHPRI   = DMA_Chain_1_Interupt_Sub_PRIORITY;          // Channel 1 Priority.
    
    DCH0SSA = virt_to_phys((const void*)DMA_Chain_0_And_1_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH0DSA = virt_to_phys(Array1);                                   // Destination Address to which data to be transfered.
   
    DCH0SSIZ = Dma0SourceSize;                                        // Source size 
    DCH0DSIZ = BufferSize1;                                           // Destination Buffer size.
    DCH0CSIZ = Dma0SourceSize;                                        // Cell transfer size  
    
    DCH1SSA = virt_to_phys((const void*)DMA_Chain_0_And_1_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH1DSA = virt_to_phys(Array2);                                   // Destination Address to which data to be transfered.
   
    DCH1SSIZ = Dma1SourceSize;                                        // Source size
    DCH1DSIZ = BufferSize2;                                           // Destination Buffer size.
    DCH1CSIZ = Dma1SourceSize;                                        // Cell transfer size 
    
    
       
    DCH0INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC33bits.DMA0IP = DMA_Chain_0_Interupt_PRIORITY;                 // DMA Channel 0 Interrupt Priority 
    IFS4bits.DMA0IF  = 0;                                             // DMA Channel 0 Interrupt Flag Cleared.
    IEC4bits.DMA0IE  = 1;                                             // DMA Channel 0 Interrupt is enabled.
    DCH0INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.
 
    
    DCH1INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC33bits.DMA1IP = DMA_Chain_1_Interupt_PRIORITY;                 // DMA Channel 1 Interrupt Priority 
    IFS4bits.DMA1IF  = 0;                                             // DMA Channel 1 Interrupt Flag Cleared.
    IEC4bits.DMA1IE  = 1;                                             // DMA Channel 1 Interrupt is enabled.
    DCH1INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.

    DMACONbits.ON = 1;                                                // DMA Module is enabled.
 
    
}


void Start_Dma_Chain_0_1()
{
    DCH0CONbits.CHEN = 1;                                             // DMA Channel 0 is enabled.   
}


void Stop_Dma_Chain_0_1()
{
    DCH0CONbits.CHEN = 0;                                             // DMA Channel 0 is disabled.   
    DCH1CONbits.CHEN = 0;                                             // DMA Channel 1 is disabled.   
}


void __ISR(_DMA0_VECTOR, DMA_CHANNEL_0_INT_NAME) _IntHandlerSysDmaCh0(void)
{
    DCH0CONbits.CHEN = 0;                                              // Disable DMA Channel 0
    DCH1CONbits.CHEN = 1;                                              // Enable DMA Channel 1
    IFS4bits.DMA0IF  = 0;                                              // DMA Channel 0 Interrupt Flag Cleared.
    DCH0INT          = 0xff0000;                                       // Clear DMA channel 0 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma0Flag = 1;          // DMA 0 User Flag

#if DMA_Chain_0_And_1_InterruptFunction == 1
DMA_Chain_0_LocalIsr();
#endif

/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_0);
}




void __ISR(_DMA1_VECTOR, DMA_CHANNEL_1_INT_NAME) _IntHandlerSysDmaCh1(void)
{
    DCH1CONbits.CHEN = 0;                                             // Disable DMA Channel 1
    DCH0CONbits.CHEN = DMA_Chain_0_And_1_RunContinously;              // Determine continous Dma Chaining
    IFS4bits.DMA1IF  = 0;                                             // DMA Channel 0 Interrupt Flag Cleared.
    DCH1INT          = 0xff0000;                                      // Clear DMA channel 1 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma1Flag = 1;            // DMA 1 User Flag

#if DMA_Chain_0_And_1_InterruptFunction == 1
DMA_Chain_1_LocalIsr();
#endif

/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_1);
}

bool CheckDma0Flag()
{
    if(Dma0Flag == 1)
    {
        Dma0Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CheckDma1Flag()
{
    if(Dma1Flag == 1)
    {
        Dma1Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


#endif




#ifdef Chain_Dma_2_And_3

void (*DMA_Chain_2_LocalIsr)(void);
void (*DMA_Chain_3_LocalIsr)(void);


void AttachDMA_Chain_2_And_3Interrupt(void *(Address1),void *(Address2))
{
    DMA_Chain_2_LocalIsr = Address1;
    DMA_Chain_3_LocalIsr = Address2;
}


void Dma_Chain_Init_2_And_3(Chain_2_3_BuferDataType *Array1,size_t BufferSize1,Chain_2_3_BuferDataType *Array2,size_t BufferSize2)
{
    
    DMACON = 0;
    

    DCH2ECONbits.CHSIRQ = DMA_Chain_2_And_3_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH2ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH2CONbits.CHPRI   = DMA_Chain_2_Interupt_Sub_PRIORITY;          // Channel 2  Priority.
    
    DCH3ECONbits.CHSIRQ = DMA_Chain_2_And_3_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH3ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH3CONbits.CHPRI   = DMA_Chain_3_Interupt_Sub_PRIORITY;          // Channel 3 Priority.
    
    DCH2SSA = virt_to_phys((const void*)DMA_Chain_2_And_3_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH2DSA = virt_to_phys(Array1);                                   // Destination Address to which data to be transfered.
   
    DCH2SSIZ = Dma2SourceSize;                                        // Source size 
    DCH2DSIZ = BufferSize1;                                           // Destination Buffer size.
    DCH2CSIZ = Dma2SourceSize;                                        // Cell transfer size    
    
    DCH3SSA = virt_to_phys((const void*)DMA_Chain_2_And_3_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH3DSA = virt_to_phys(Array2);                                   // Destination Address to which data to be transfered.
   
    DCH3SSIZ = Dma3SourceSize;                                        // Source size 
    DCH3DSIZ = BufferSize2;                                           // Destination Buffer size.
    DCH3CSIZ = Dma3SourceSize;                                        // Cell transfer size 
    
    
       
    DCH2INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC34bits.DMA2IP = DMA_Chain_2_Interupt_PRIORITY;                 // DMA Channel 2 Interrupt Priority 
    IFS4bits.DMA2IF  = 0;                                             // DMA Channel 2 Interrupt Flag Cleared.
    IEC4bits.DMA2IE  = 1;                                             // DMA Channel 2 Interrupt is enabled.
    DCH2INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.
 
    
    DCH3INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC34bits.DMA3IP = DMA_Chain_3_Interupt_PRIORITY;                 // DMA Channel 3 Interrupt Priority 
    IFS4bits.DMA3IF  = 0;                                             // DMA Channel 3 Interrupt Flag Cleared.
    IEC4bits.DMA3IE  = 1;                                             // DMA Channel 3 Interrupt is enabled.
    DCH3INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.

    DMACONbits.ON = 1;                                                // DMA Module is enabled.
 
    
}


void Start_Dma_Chain_2_3()
{
    DCH2CONbits.CHEN = 1;                                             // DMA Channel 2 is enabled.   
}


void Stop_Dma_Chain_2_3()
{
    DCH2CONbits.CHEN = 0;                                             // DMA Channel 2 is disabled.   
    DCH3CONbits.CHEN = 0;                                             // DMA Channel 2 is disabled.   
}

void __ISR(_DMA2_VECTOR, DMA_CHANNEL_2_INT_NAME) _IntHandlerSysDmaCh2(void)
{
    DCH2CONbits.CHEN = 0;                                            // DMA Channel 2 Disable
    DCH3CONbits.CHEN = 1;                                            // DMA Channel 3 Enable
    IFS4bits.DMA2IF  = 0;                                            // DMA Channel 2 Interrupt Flag Cleared.
    DCH2INT          = 0xff0000;                                     // Clear DMA Channel 2 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma2Flag = 1;             // DMA 2 User Flag
#if DMA_Chain_2_And_3_InterruptFunction == 1
DMA_Chain_2_LocalIsr();
#endif

/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_2);
}




void __ISR(_DMA3_VECTOR, DMA_CHANNEL_3_INT_NAME) _IntHandlerSysDmaCh3(void)
{
    DCH3CONbits.CHEN = 0;                                             // Disable DMA Channel 3
    DCH2CONbits.CHEN = DMA_Chain_2_And_3_RunContinously;              // Determine continous Dma Chaining
    IFS4bits.DMA3IF  = 0;                                             // DMA Channel 3 Interrupt Flag Cleared.
    DCH3INT          = 0xff0000;                                      // Clear DMA Channel 3 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma3Flag = 1;     // DMA 3 User Flag
#if DMA_Chain_2_And_3_InterruptFunction == 1
DMA_Chain_3_LocalIsr();
#endif
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_3);
}

bool CheckDma2Flag()
{
    if(Dma2Flag == 1)
    {
        Dma2Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CheckDma3Flag()
{
    if(Dma3Flag == 1)
    {
        Dma3Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}


#endif




#ifdef Chain_Dma_4_And_5

void (*DMA_Chain_4_LocalIsr)(void);
void (*DMA_Chain_5_LocalIsr)(void);


void AttachDMA_Chain_4_And_5Interrupt(void *(Address1),void *(Address4))
{
    DMA_Chain_4_LocalIsr = Address1;
    DMA_Chain_5_LocalIsr = Address4;
}


void Dma_Chain_Init_4_And_5(Chain_4_5_BuferDataType *Array1,size_t BufferSize1,Chain_4_5_BuferDataType *Array4,size_t BufferSize4)
{
    
    DMACON = 0;
    

    DCH4ECONbits.CHSIRQ = DMA_Chain_4_And_5_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH4ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH4CONbits.CHPRI   = DMA_Chain_4_Interupt_Sub_PRIORITY;          // Channel 4  Priority.
    
    DCH5ECONbits.CHSIRQ = DMA_Chain_4_And_5_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH5ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH5CONbits.CHPRI   = DMA_Chain_5_Interupt_Sub_PRIORITY;          // Channel 5 Priority.
    
    DCH4SSA = virt_to_phys((const void*)DMA_Chain_4_And_5_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH4DSA = virt_to_phys(Array1);                                   // Destination Address to which data to be transfered.
   
    DCH4SSIZ = Dma4SourceSize;                                        // Source size 
    DCH4DSIZ = BufferSize1;                                           // Destination Buffer size.
    DCH4CSIZ = Dma4SourceSize;                                        // Cell transfer size    
    
    DCH5SSA = virt_to_phys((const void*)DMA_Chain_4_And_5_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH5DSA = virt_to_phys(Array4);                                   // Destination Address to which data to be transfered.
   
    DCH5SSIZ = Dma5SourceSize;                                        // Source size 
    DCH5DSIZ = BufferSize4;                                           // Destination Buffer size.
    DCH5CSIZ = Dma5SourceSize;                                        // Cell transfer size 
    
    
       
    DCH4INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC34bits.DMA4IP = DMA_Chain_4_Interupt_PRIORITY;                 // DMA Channel 4 Interrupt Priority 
    IFS4bits.DMA4IF  = 0;                                             // DMA Channel 4 Interrupt Flag Cleared.
    IEC4bits.DMA4IE  = 1;                                             // DMA Channel 4 Interrupt is enabled.
    DCH4INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.
 
    
    DCH5INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC34bits.DMA5IP = DMA_Chain_5_Interupt_PRIORITY;                 // DMA Channel 5 Interrupt Priority 
    IFS4bits.DMA5IF  = 0;                                             // DMA Channel 5 Interrupt Flag Cleared.
    IEC4bits.DMA5IE  = 1;                                             // DMA Channel 5 Interrupt is enabled.
    DCH5INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.

    DMACONbits.ON = 1;                                                // DMA Module is enabled.
 
    
}


void Start_Dma_Chain_4_5()
{
    DCH4CONbits.CHEN = 1;                                             // DMA Channel 4 is enabled.   
}


void Stop_Dma_Chain_4_5()
{
    DCH4CONbits.CHEN = 0;                                             // DMA Channel 4 is disabled.   
    DCH5CONbits.CHEN = 0;                                             // DMA Channel 4 is disabled.   
}

void __ISR(_DMA4_VECTOR, DMA_CHANNEL_4_INT_NAME) _IntHandlerSysDmaCh4(void)
{
    DCH4CONbits.CHEN = 0;                                            // DMA Channel 4 Disable
    DCH5CONbits.CHEN = 1;                                            // DMA Channel 5 Enable
    IFS4bits.DMA4IF  = 0;                                            // DMA Channel 4 Interrupt Flag Cleared.
    DCH4INT          = 0xff0000;                                     // Clear DMA Channel 4 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma4Flag = 1;             // DMA 4 User Flag
#if DMA_Chain_4_And_5_InterruptFunction == 1
DMA_Chain_4_LocalIsr();
#endif

/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_4);
}




void __ISR(_DMA5_VECTOR, DMA_CHANNEL_5_INT_NAME) _IntHandlerSysDmaCh5(void)
{
    DCH5CONbits.CHEN = 0;                                             // Disable DMA Channel 5
    DCH4CONbits.CHEN = DMA_Chain_4_And_5_RunContinously;              // Determine continous Dma Chaining
    IFS4bits.DMA5IF  = 0;                                             // DMA Channel 5 Interrupt Flag Cleared.
    DCH5INT          = 0xff0000;                                      // Clear DMA Channel 5 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma5Flag = 1;     // DMA 5 User Flag
#if DMA_Chain_4_And_5_InterruptFunction == 1
DMA_Chain_5_LocalIsr();
#endif
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_5);
}

bool CheckDma4Flag()
{
    if(Dma4Flag == 1)
    {
        Dma4Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CheckDma5Flag()
{
    if(Dma5Flag == 1)
    {
        Dma5Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}



#endif





#ifdef Chain_Dma_6_And_7

void (*DMA_Chain_6_LocalIsr)(void);
void (*DMA_Chain_7_LocalIsr)(void);


void AttachDMA_Chain_6_And_7Interrupt(void *(Address1),void *(Address6))
{
    DMA_Chain_6_LocalIsr = Address1;
    DMA_Chain_7_LocalIsr = Address6;
}


void Dma_Chain_Init_6_And_7(Chain_6_7_BuferDataType *Array1,size_t BufferSize1,Chain_6_7_BuferDataType *Array6,size_t BufferSize6)
{
    
    DMACON = 0;
    

    DCH6ECONbits.CHSIRQ = DMA_Chain_6_And_7_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH6ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH6CONbits.CHPRI   = DMA_Chain_6_Interupt_Sub_PRIORITY;          // Channel 6  Priority.
    
    DCH7ECONbits.CHSIRQ = DMA_Chain_6_And_7_InterruptVector;          // ADC Data Ready Interrupt event selected for DMA Transfer.
    DCH7ECONbits.SIRQEN = 1;                                          // start cell transfer if Interrupt Event Occurs.
    DCH7CONbits.CHPRI   = DMA_Chain_7_Interupt_Sub_PRIORITY;          // Channel 7 Priority.
    
    DCH6SSA = virt_to_phys((const void*)DMA_Chain_6_And_7_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH6DSA = virt_to_phys(Array1);                                   // Destination Address to which data to be transfered.
   
    DCH6SSIZ = Dma6SourceSize;                                        // Source size 
    DCH6DSIZ = BufferSize1;                                           // Destination Buffer size.
    DCH6CSIZ = Dma6SourceSize;                                        // Cell transfer size    
    
    DCH7SSA = virt_to_phys((const void*)DMA_Chain_6_And_7_DataBuffer);// Source Destination is the readings from Dedicated Buffer Module 0.
    DCH7DSA = virt_to_phys(Array6);                                   // Destination Address to which data to be transfered.
   
    DCH7SSIZ = Dma7SourceSize;                                        // Source size 
    DCH7DSIZ = BufferSize6;                                           // Destination Buffer size.
    DCH7CSIZ = Dma7SourceSize;                                        // Cell transfer size 
    
    
       
    DCH6INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC35bits.DMA6IP = DMA_Chain_6_Interupt_PRIORITY;                 // DMA Channel 6 Interrupt Priority 
    IFS4bits.DMA6IF  = 0;                                             // DMA Channel 6 Interrupt Flag Cleared.
    IEC4bits.DMA6IE  = 1;                                             // DMA Channel 6 Interrupt is enabled.
    DCH6INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.
 
    
    DCH7INT = 0;                                                      // All DMA Interrupts are disabled.
    IPC35bits.DMA7IP = DMA_Chain_7_Interupt_PRIORITY;                 // DMA Channel 7 Interrupt Priority 
    IFS4bits.DMA7IF  = 0;                                             // DMA Channel 7 Interrupt Flag Cleared.
    IEC4bits.DMA7IE  = 1;                                             // DMA Channel 7 Interrupt is enabled.
    DCH7INTbits.CHBCIE = 1;                                           // DMA Destination Done interrupt enabled.

    DMACONbits.ON = 1;                                                // DMA Module is enabled.
 
    
}


void Start_Dma_Chain_6_7()
{
    DCH6CONbits.CHEN = 1;                                             // DMA Channel 6 is enabled.   
}


void Stop_Dma_Chain_6_7()
{
    DCH6CONbits.CHEN = 0;                                             // DMA Channel 6 is disabled.   
    DCH7CONbits.CHEN = 0;                                             // DMA Channel 6 is disabled.   
}

void __ISR(_DMA6_VECTOR, DMA_CHANNEL_6_INT_NAME) _IntHandlerSysDmaCh6(void)
{
    DCH6CONbits.CHEN = 0;                                            // DMA Channel 6 Disable
    DCH7CONbits.CHEN = 1;                                            // DMA Channel 7 Enable
    IFS4bits.DMA6IF  = 0;                                            // DMA Channel 6 Interrupt Flag Cleared.
    DCH6INT          = 0xff0000;                                     // Clear DMA Channel 6 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma6Flag = 1;             // DMA 6 User Flag
#if DMA_Chain_6_And_7_InterruptFunction == 1
DMA_Chain_6_LocalIsr();
#endif

/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_6);
}




void __ISR(_DMA7_VECTOR, DMA_CHANNEL_7_INT_NAME) _IntHandlerSysDmaCh7(void)
{
    DCH7CONbits.CHEN = 0;                                             // Disable DMA Channel 7
    DCH6CONbits.CHEN = DMA_Chain_6_And_7_RunContinously;              // Determine continous Dma Chaining
    IFS4bits.DMA7IF  = 0;                                             // DMA Channel 7 Interrupt Flag Cleared.
    DCH7INT          = 0xff0000;                                      // Clear DMA Channel 7 Interrupts
    
/************ DMA OPERATIONS ***************************************************/
   
Dma7Flag = 1;     // DMA 7 User Flag
#if DMA_Chain_6_And_7_InterruptFunction == 1
DMA_Chain_7_LocalIsr();
#endif
/*******   END OF DMA OPERATION ***********************************************/ 
    SYS_DMA_Tasks(sysObj.sysDma, DMA_CHANNEL_7);
}

bool CheckDma6Flag()
{
    if(Dma6Flag == 1)
    {
        Dma6Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool CheckDma7Flag()
{
    if(Dma7Flag == 1)
    {
        Dma7Flag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}



#endif

/************************* MEMMORY TO MEMMORY DMA FUNCTIONS *******************/


#ifdef MemtoMemDma_Channel_0

void MemToMemDma0(Dma0BuffferDataType *Array1,Dma0BuffferDataType *Array2,UINT16 Size)
{
    
IEC4bits.DMA0IE =0; // disable DMA channel 0 interrupts
IFS4bits.DMA0IF =0; // clear any existing DMA channel 0 interrupt flag
DMACONbits.ON = 1;  // enable the DMA controller
DCH0CON = 0; // channel off, priority 0 , no chaining
DCH0CONbits.CHPRI = 3; // channel off, priority 3, no chaining

DCH0ECON=0; // no start or stop irq?s, no pattern match
// program the transfer
DCH0SSA=virt_to_phys(Array1); // transfer source physical address
DCH0DSA=virt_to_phys(Array2); // transfer destination physical address
DCH0SSIZ=Size; // source size 200 bytes
DCH0DSIZ=Size; // destination size 200 bytes
DCH0CSIZ=Size; // 200 bytes transferred per event


DCH0INTCLR=0x00ff00ff; // clear existing events, disable all interrupts
//DCH0INTSET=0x00090000; // enable Block Complete and error interrupts
//DCH0INTbits.CHDDIE = 1;  // enable Block Complete and error interrupts
//
//IPC33bits.DMA0IP = 0; // clear the DMA channel 0 priority and sub-priority
//IPC33bits.DMA0IS = 0; // clear the DMA channel 0 priority and sub-priority
//
//IPC33bits.DMA0IP = 1; // clear the DMA channel 0 priority and sub-priority
//IPC33bits.DMA0IS = 1; // clear the DMA channel 0 priority and sub-priority
//
//IEC4bits.DMA0IE =1; // enable DMA channel 0 interrupt

DCH0CONbits.CHEN=1; // turn channel on
DCH0CONbits.CHAEN = 1; // turn channel on

// initiate a transfer
//DCH0ECONSET=0x00000080; // set CFORCE to 1
 
}

void StartMemtoMemDma0()
{
    // initiate a transfer
    DCH0ECONbits.CFORCE = 1; // set CFORCE to 1
}

inline void StopMemtoMemDma0()
{
    // stop a transfer
    DCH0ECONbits.CABORT = 1; // set CABORT to 1
}



//void __ISR(_DMA0_VECTOR, DMA_CHANNEL_0_INT_NAME) _IntHandlerSysDmaCh0(void)
//{
////int dmaFlags=DCH0INT&0xff; // read the interrupt flags
///*
//perform application specific operations in response to any interrupt flag set
//*/
//printf("Hello");
//DCH0INTCLR=0x000000ff; // clear the DMA channel interrupt flags
//IFS4bits.DMA0IF =0;                          // clear any existing DMA channel 0 interrupt flag
//// before exiting the service routine.
//}



void __ISR(_DMA0_VECTOR, DMA_CHANNEL_0_INT_NAME) __DMA0Interrupt(void)
{
int dmaFlags=DCH0INT&0xff; // read the interrupt flags
/*
perform application specific operations in response to any interrupt flag set
*/
//printf("Hello");
DCH0INTCLR=0x000000ff; // clear the DMA channel interrupt flags
IFS1CLR = 0x00010000; // Be sure to clear the DMA0 interrupt flags
// before exiting the service routine.
}

#endif

#ifdef MemtoMemDma_Channel_1

void MemToMemDma1(Dma1BuffferDataType *Array1,Dma1BuffferDataType *Array2,UINT16 Size)
{


IEC4bits.DMA1IE =0; // disable DMA channel 0 interrupts
IFS4bits.DMA1IF =0; // clear any existing DMA channel 0 interrupt flag
DMACONbits.ON = 1;  // enable the DMA controller
DCH1CON = 0; // channel off, priority 0 , no chaining
DCH1CONbits.CHPRI = 2; // channel off, priority 3, no chaining

DCH1ECON=0; // no start or stop irq?s, no pattern match
// program the transfer
DCH1SSA=virt_to_phys(Array1); // transfer source physical address
DCH1DSA=virt_to_phys(Array2); // transfer destination physical address
DCH1SSIZ=Size; // source size 200 bytes
DCH1DSIZ=Size; // destination size 200 bytes
DCH1CSIZ=Size; // 200 bytes transferred per event


DCH1INTCLR=0x00ff00ff; // clear existing events, disable all interrupts
DCH1CONbits.CHEN=1; // turn channel on
DCH1CONbits.CHAEN = 1; // turn channel on

 
}




void StartMemtoMemDma1()
{
    // initiate a transfer
    DCH1ECONbits.CFORCE = 1; // set CFORCE to 1
}

inline void StopMemtoMemDma1()
{
    // stop a transfer
    DCH1ECONbits.CABORT = 1; // set CABORT to 1
}



#endif



#ifdef MemtoMemDma_Channel_2

void MemToMemDma2(Dma2BuffferDataType *Array1,Dma2BuffferDataType *Array2,UINT16 Size)
{


IEC4bits.DMA2IE =0; // disable DMA channel 0 interrupts
IFS4bits.DMA2IF =0; // clear any existing DMA channel 0 interrupt flag
DMACONbits.ON = 1;  // enable the DMA controller
DCH2CON = 0; // channel off, priority 0 , no chaining
DCH2CONbits.CHPRI = 1; // channel off, priority 3, no chaining

DCH2ECON=0; // no start or stop irq?s, no pattern match
// program the transfer
DCH2SSA=virt_to_phys(Array1); // transfer source physical address
DCH2DSA=virt_to_phys(Array2); // transfer destination physical address
DCH2SSIZ=Size; // source size 200 bytes
DCH2DSIZ=Size; // destination size 200 bytes
DCH2CSIZ=Size; // 200 bytes transferred per event


DCH2INTCLR=0x00ff00ff; // clear existing events, disable all interrupts
DCH2CONbits.CHEN=1; // turn channel on
DCH2CONbits.CHAEN = 1; // turn channel on

 
}




void StartMemtoMemDma2()
{
    // initiate a transfer
    DCH2ECONbits.CFORCE = 1; // set CFORCE to 1
}

inline void StopMemtoMemDma2()
{
    // stop a transfer
    DCH2ECONbits.CABORT = 1; // set CABORT to 1
}



#endif


#ifdef MemtoMemDma_Channel_3

void MemToMemDma3(Dma3BuffferDataType *Array1,Dma3BuffferDataType *Array2,UINT16 Size)
{


IEC4bits.DMA3IE =0; // disable DMA channel 0 interrupts
IFS4bits.DMA3IF =0; // clear any existing DMA channel 0 interrupt flag
DMACONbits.ON = 1;  // enable the DMA controller
DCH3CON = 0; // channel off, priority 0 , no chaining
DCH3CONbits.CHPRI = 1; // channel off, priority 3, no chaining

DCH3ECON=0; // no start or stop irq?s, no pattern match
// program the transfer
DCH3SSA=virt_to_phys(Array1); // transfer source physical address
DCH3DSA=virt_to_phys(Array2); // transfer destination physical address
DCH3SSIZ=Size; // source size 200 bytes
DCH3DSIZ=Size; // destination size 200 bytes
DCH3CSIZ=Size; // 200 bytes transferred per event


DCH3INTCLR=0x00ff00ff; // clear existing events, disable all interrupts
DCH3CONbits.CHEN=1; // turn channel on
DCH3CONbits.CHAEN = 1; // turn channel on

 
}




void StartMemtoMemDma3()
{
    // initiate a transfer
    DCH3ECONbits.CFORCE = 1; // set CFORCE to 1
}

inline void StopMemtoMemDma3()
{
    // stop a transfer
    DCH3ECONbits.CABORT = 1; // set CABORT to 1
}



#endif


#ifdef  MemToPeripheralCh0


void InitMemToPerSrcDma0(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA0IE = 0;      
    IFS4bits.DMA0IF = 0;      
    DMACONbits.ON = 1;       
    DCH0CON = 0;              
    DCH0CONbits.CHPRI = Priority;    
    DCH0ECON = 0;                             
    DCH0ECONbits.CHSIRQ = InterruptVector;  
    DCH0ECONbits.SIRQEN = 1;  
    DCH0DSA = virt_to_phys((const void*)Peripheral);  
    DCH0DSIZ = 1;  
    DCH0CSIZ = 1;  
    DCH0INTCLR = 0x00FF00FF;  
    DCH0CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs0(void *Address, UINT16 Size)
{
    DCH0SSA = virt_to_phys(Address);  
    DCH0SSIZ = Size;  
}



void StartMemToPerDma0(void) 
{   
    while(DCH0CONbits.CHBUSY);
    DCH0CONbits.CHEN = 1;
    DCH0ECONbits.CFORCE = 1; 
}

void StopMemToPerDma0(void) 
{
     DCH0CONbits.CHEN = 0;
     DCH0ECONbits.CABORT = 1; 
}

#endif
#ifdef  MemToPeripheralCh1

void InitMemToPerSrcDma1(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA1IE = 0;      
    IFS4bits.DMA1IF = 0;      
    DMACONbits.ON = 1;       
    DCH1CON = 0;              
    DCH1CONbits.CHPRI = Priority;    
    DCH1ECON = 0;                             
    DCH1ECONbits.CHSIRQ = InterruptVector;  
    DCH1ECONbits.SIRQEN = 1;  
    DCH1DSA = virt_to_phys((const void*)Peripheral);  
    DCH1DSIZ = 1;  
    DCH1CSIZ = 1;  
    DCH1INTCLR = 0x00FF00FF;  
    DCH1CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs1(void *Address, UINT16 Size)
{
    DCH1SSA = virt_to_phys(Address);  
    DCH1SSIZ = Size;  
}



void StartMemToPerDma1(void) 
{   
    while(DCH1CONbits.CHBUSY);
    DCH1CONbits.CHEN = 1;
    DCH1ECONbits.CFORCE = 1; 
}

void StopMemToPerDma1(void) 
{
     DCH1CONbits.CHEN = 0;
     DCH1ECONbits.CABORT = 1; 
}

#endif
#ifdef  MemToPeripheralCh2

void InitMemToPerSrcDma2(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA2IE = 0;      
    IFS4bits.DMA2IF = 0;      
    DMACONbits.ON = 1;       
    DCH2CON = 0;              
    DCH2CONbits.CHPRI = Priority;    
    DCH2ECON = 0;                             
    DCH2ECONbits.CHSIRQ = InterruptVector;  
    DCH2ECONbits.SIRQEN = 1;  
    DCH2DSA = virt_to_phys((const void*)Peripheral);  
    DCH2DSIZ = 1;  
    DCH2CSIZ = 1;  
    DCH2INTCLR = 0x00FF00FF;  
    DCH2CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs2(void *Address, UINT16 Size)
{
    DCH2SSA = virt_to_phys(Address);  
    DCH2SSIZ = Size;  
}



void StartMemToPerDma2(void) 
{   
    while(DCH2CONbits.CHBUSY);
    DCH2CONbits.CHEN = 1;
    DCH2ECONbits.CFORCE = 1; 
}

void StopMemToPerDma2(void) 
{
     DCH2CONbits.CHEN = 0;
     DCH2ECONbits.CABORT = 1; 
}

#endif
#ifdef  MemToPeripheralCh3

void InitMemToPerSrcDma3(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA3IE = 0;      
    IFS4bits.DMA3IF = 0;      
    DMACONbits.ON = 1;       
    DCH3CON = 0;              
    DCH3CONbits.CHPRI = Priority    
    DCH3ECON = 0;                             
    DCH3ECONbits.CHSIRQ = InterruptVector;  
    DCH3ECONbits.SIRQEN = 1;  
    DCH3DSA = virt_to_phys((const void*)Peripheral);  
    DCH3DSIZ = 1;  
    DCH3CSIZ = 1;  
    DCH3INTCLR = 0x00FF00FF;  
    DCH3CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs3(void *Address, UINT16 Size)
{
    DCH3SSA = virt_to_phys(Address);  
    DCH3SSIZ = Size;  
}



void StartMemToPerDma3(void) 
{   
    while(DCH3CONbits.CHBUSY);
    DCH3CONbits.CHEN = 1;
    DCH3ECONbits.CFORCE = 1; 
}

void StopMemToPerDma3(void) 
{
     DCH3CONbits.CHEN = 0;
     DCH3ECONbits.CABORT = 1; 
}
#endif
#ifdef  MemToPeripheralCh4

void InitMemToPerSrcDma4(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA4IE = 0;      
    IFS4bits.DMA4IF = 0;      
    DMACONbits.ON = 1;       
    DCH4CON = 0;              
    DCH4CONbits.CHPRI = Priority;    
    DCH4ECON = 0;                             
    DCH4ECONbits.CHSIRQ = InterruptVector;  
    DCH4ECONbits.SIRQEN = 1;  
    DCH4DSA = virt_to_phys((const void*)Peripheral);  
    DCH4DSIZ = 1;  
    DCH4CSIZ = 1;  
    DCH4INTCLR = 0x00FF00FF;  
    DCH4CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs4(void *Address, UINT16 Size)
{
    DCH4SSA = virt_to_phys(Address);  
    DCH4SSIZ = Size;  
}



void StartMemToPerDma4(void) 
{   
    while(DCH4CONbits.CHBUSY);
    DCH4CONbits.CHEN = 1;
    DCH4ECONbits.CFORCE = 1; 
}

void StopMemToPerDma4(void) 
{
     DCH4CONbits.CHEN = 0;
     DCH4ECONbits.CABORT = 1; 
}
#endif
#ifdef  MemToPeripheralCh5

void InitMemToPerSrcDma5(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA5IE = 0;      
    IFS4bits.DMA5IF = 0;      
    DMACONbits.ON = 1;       
    DCH5CON = 0;              
    DCH5CONbits.CHPRI = Priority;    
    DCH5ECON = 0;                             
    DCH5ECONbits.CHSIRQ = InterruptVector;  
    DCH5ECONbits.SIRQEN = 1;  
    DCH5DSA = virt_to_phys((const void*)Peripheral);  
    DCH5DSIZ = 1;  
    DCH5CSIZ = 1;  
    DCH5INTCLR = 0x00FF00FF;  
    DCH5CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs5(void *Address, UINT16 Size)
{
    DCH5SSA = virt_to_phys(Address);  
    DCH5SSIZ = Size;  
}



void StartMemToPerDma5(void) 
{   
    while(DCH5CONbits.CHBUSY);
    DCH5CONbits.CHEN = 1;
    DCH5ECONbits.CFORCE = 1; 
}

void StopMemToPerDma5(void) 
{
     DCH5CONbits.CHEN = 0;
     DCH5ECONbits.CABORT = 1; 
}

#endif
#ifdef  MemToPeripheralCh6

void InitMemToPerSrcDma6(BYTE InterruptVector,volatile void *Peripheral ,BYTE Priority) 
{
    IEC4bits.DMA6IE = 0;      
    IFS4bits.DMA6IF = 0;      
    DMACONbits.ON = 1;       
    DCH6CON = 0;              
    DCH6CONbits.CHPRI = Priority;    
    DCH6ECON = 0;                             
    DCH6ECONbits.CHSIRQ = InterruptVector;  
    DCH6ECONbits.SIRQEN = 1;  
    DCH6DSA = virt_to_phys((const void*)Peripheral);  
    DCH6DSIZ = 1;  
    DCH6CSIZ = 1;  
    DCH6INTCLR = 0x00FF00FF;  
    DCH6CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs6(void *Address, UINT16 Size)
{
    DCH6SSA = virt_to_phys(Address);  
    DCH6SSIZ = Size;  
}



void StartMemToPerDma6(void) 
{   
    while(DCH6CONbits.CHBUSY);
    DCH6CONbits.CHEN = 1;
    DCH6ECONbits.CFORCE = 1; 
}

void StopMemToPerDma6(void) 
{
     DCH6CONbits.CHEN = 0;
     DCH6ECONbits.CABORT = 1; 
}

#endif
#ifdef  MemToPeripheralCh7

void InitMemToPerSrcDma7(BYTE InterruptVector,volatile void *Peripheral,BYTE Priority) 
{
    IEC4bits.DMA7IE = 0;      
    IFS4bits.DMA7IF = 0;      
    DMACONbits.ON = 1;       
    DCH7CON = 0;              
    DCH7CONbits.CHPRI = Priority;    
    DCH7ECON = 0;                             
    DCH7ECONbits.CHSIRQ = InterruptVector;  
    DCH7ECONbits.SIRQEN = 1;  
    DCH7DSA = virt_to_phys((const void*)Peripheral);  
    DCH7DSIZ = 1;  
    DCH7CSIZ = 1;  
    DCH7INTCLR = 0x00FF00FF;  
    DCH7CONbits.CHEN = 0;  
     
}



void SetMemToPerSrcAddrs7(void *Address, UINT16 Size)
{
    DCH7SSA = virt_to_phys(Address);  
    DCH7SSIZ = Size;  
}



void StartMemToPerDma6(void) 
{   
    while(DCH7CONbits.CHBUSY);
    DCH7CONbits.CHEN = 1;
    DCH7ECONbits.CFORCE = 1; 
}

void StopMemToPerDma6(void) 
{
     DCH7CONbits.CHEN = 0;
     DCH7ECONbits.CABORT = 1; 
}


#endif








