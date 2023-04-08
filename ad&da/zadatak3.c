#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

const char PCF8591 = 0x48; 
int fd;
int adcVal=0;


int main() {
 if (wiringPiSetup () == -1) exit (1);
 fd = wiringPiI2CSetup(PCF8591);


 while (1) {
   
    /*
    //TROUGAONI SIGNAL

    for(int i=0; i<=255; i++) {  
        wiringPiI2CWriteReg8(fd, PCF8591 + 4, i);
        delay(10);
    }
    for(int i=255; i>=0; i--) {  
        wiringPiI2CWriteReg8(fd, PCF8591 + 4, i);
        delay(10);
    }    
    */



    /*
   //TESTERAST SIGNAL

   wiringPiI2CWriteReg8(fd, PCF8591 + 4, adcVal) ;
   adcVal=(adcVal+1)%256;

   delay(10);
   */

    
 }
 return 0;
}
