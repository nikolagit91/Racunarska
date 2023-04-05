// gcc -o zadatak2 zadatak2.c -l -lwiringPi -lpthread -l lirc_client
// sudo ./zadatak2

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>


//#define PIN 20


int main(int argc, char **argv)
{
    struct lirc_config *config;
    char *code;
    int i=0;

    //startuj lirc
    if(lirc_init("lirc",1)==-1)
    return 1;
    
    if (wiringPiSetup() == -1)
    exit(1); // return 2 ?

    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH); 

    if (softPwmCreate(28, 0, 100) != 0)
    exit (2); 
    i=0;

    //procitaj /etc/lirc/lircrc/lircd.conf
    if(lirc_readconfig(NULL, &config,NULL)==0)
    {
   
    //radimo dok je LIRC soket otvoren 0=otvoren -1=zatvoren
    while (lirc_nextcode(&code)==0)
        {
        // if code=NULL ništa nije primljeno-preskoči
        if(code==NULL) continue; {
            
        delay(400);

        if (strstr(code,"Vol+")){
           
            i+=20;
            if (i > 100) i=0;
            printf("Ispuna = %d %",i);
            fflush(stdout);
            softPwmWrite(28,i);
           
        delay(500);

        }
        else if (strstr(code,"Vol-")){

            i-=20;
            if (i < 0) i=0;
            printf("Ispuna = %d %",i);
            fflush(stdout);
            softPwmWrite(28,i);
                   
         delay(500);
            }
        }
        
        free(code);
        }
    lirc_freeconfig(config);
    }
    
    lirc_deinit();
 return 0;
}