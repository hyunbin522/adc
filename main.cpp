#include "mbed.h"

// main() runs in its own thread in the OS
SPI spi(PB_5,PB_4,PB_3);
DigitalOut cs(PA_4);
int numFrameWords = 8;
unsigned long spiDummyWord[8] ={ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,0x00000000}; 
unsigned char shiftValue=0x08; 
signed long adcData;
unsigned long data[8]={ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,0x00000000};
unsigned short reset[4]= {0x0000,0x0000,0x0001,0x0001};
unsigned short standby[4]= {0x0000,0x0000,0x0010,0x0010};
unsigned short wakeup[4]= {0x0000,0x0000,0x0011,0x0011};

bool adcRegisterWrite(unsigned short addrMask, unsigned short data,
unsigned char adcWordLength){
unsigned char shiftValue; // Stores the amount of bit shift based on
 // ADC word length
if(adcWordLength==16){
shiftValue = 0; // If length is 16, no shift
}else if(adcWordLength==24){
shiftValue = 8; // If length is 24, shift left by 8
}else if(adcWordLength==32){
shiftValue = 16; // If length is 32, shift left by 16
}else{
return false; // If not, invalid length
}
// Shift to accommodate ADC word length

spi.write(data << shiftValue);// Write register data
while(true); // Wait for data to complete sending
return true;
}




int main()
{
    cs=1;
    spi.format(16,0);
    spi.frequency(1000000);
    cs = 0;

  
    while (true) { spi.write(wakeup);
printf("%c",data1);
    }
}

