/*  PhotoresistorTest.c
  1-> when the light intensity is high
  0-> when the light intensity is low
*/
#include "simpletools.h"                      // Include simpletools
#include "wavplayer.h"
int main()                                     // main function
{
   int DO = 22, CLK = 23, DI = 24, CS = 25;        // SD I/O pins
    sd_mount(DO, CLK, DI, CS);                      // Mount SD card
    const char techloop[] = {"techloop.wav"}; 

  while(1)                                    // Endless loop
  {
    
    int state = input(3);              // P3 input -> state variable
    printf("state of pin P3= %d\n",state);
    pause(500);        
    if (!state)
      { 
        high(3);                      //light up the LED
        wav_play(techloop);           //play the lullaby
        pause(4000);                  // play for 4 seconds
        wav_stop();                   //stop
      } else
      { 
      low(3);                         //LED does not light up
      }  
  }
}