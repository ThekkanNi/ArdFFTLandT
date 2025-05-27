#include "app.h"

DMACHECK DmaCheck __attribute__((coherent));

 __inline__ unsigned int __attribute__((always_inline)) virt_to_phys(const void* p) {
return (int)p<0?((int)p&0x1fffffffL):(unsigned int)((unsigned char*)p+0x40000000L);
}

void SetSourceAddress(void *Address, UINT16 Size) {
    DCH0SSA = virt_to_phys(Address);  // Set source address
    DCH0SSIZ = Size;  // Set source size
}

void UartDmaInit() {
    IEC4bits.DMA0IE = 0;  // Disable DMA interrupts
    IFS4bits.DMA0IF = 0;  // Clear DMA interrupt flag
    DMACONbits.ON = 1;    // Enable the DMA controller

    DCH0CON = 0;  // Reset DMA channel
    DCH0CONbits.CHPRI = 3; // Set high priority


    DCH0ECON = 0;  // No automatic IRQ trigger
    DCH0ECONbits.CHSIRQ = _UART1_TX_VECTOR; // UART1 TX interrupt as trigger
    DCH0ECONbits.SIRQEN = 1; // Enable IRQ triggering

    DCH0DSA = virt_to_phys((const void*)&U1TXREG); // Destination: UART TX Register
    DCH0DSIZ = 1; // Set destination size equal to source size
    DCH0CSIZ = 1; // Transfer all bytes per event

    DCH0INTCLR = 0x00FF00FF; // Clear all interrupts

    DCH0CONbits.CHEN = 0; // Enable DMA Channel 0
    
    
   
}

void StartUartDma0() {
    
    while(DCH0CONbits.CHBUSY);
    DCH0CONbits.CHEN = 1;
    DCH0ECONbits.CFORCE = 1; // Force DMA transfer
}

void StopUartDma0() {
    DCH0ECONbits.CABORT = 1; // Abort DMA transfer
}



//BYTE CheckDma1[4]  __attribute__((coherent)) = {1,2,3,4};
BYTE AlphabetArray[26] __attribute__((coherent)) = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z'
};
BYTE CheckDma2[4]  __attribute__((coherent));






void CheckDmaWorking()
{
  
   
UartDmaInit();
 memcpy(DmaCheck.Payload.Header, HEADER, HEADER_SIZE);
 memcpy(DmaCheck.Payload.Footer, FOOTER, FOOTER_SIZE);
SetSourceAddress(&DmaCheck.Data, 8);
//SetSourceAddress(&AlphabetArray,26);
StartUartDma0();   

//printf("Data:   %s\n\r",   DmaCheck.Data);
//printf("Header: %s\n\r", DmaCheck.Payload.Header);
//printf("Footer: %s\n\r", DmaCheck.Payload.Footer);
    
//    U1TXREG = 'A';
}


