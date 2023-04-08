#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>

unsigned char WriteBuf;
unsigned char ReadBuf;


int main(int argc, char **argv)
{
    if (!bcm2835_init())
        return 1; 

    bcm2835_i2c_begin();
    bcm2835_i2c_setSlaveAddress(0x48);
    bcm2835_i2c_set_baudrate(10000);
    
    
    while(1)
    {
        WriteBuf = 0x03;
        bcm2835_i2c_write_read_rs(&WriteBuf, 1,&ReadBuf, 1);
        //bcm2835_i2c_read(&ReadBuf, 1); mislim da ovo ne treba
        
        
        
        printf("Vrednost potenciometra je :\r\n",(double)ReadBuf * 3.3 / 255);
        fflush (stdout) ;
        bcm2835_delay(100);
    }
        bcm2835_i2c_end();
        bcm2835_close();
    
    return 0;
}
