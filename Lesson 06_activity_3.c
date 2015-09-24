/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "wavplayer.h"
#include "sirc.h"

int main()                                    // Main function
{
  int a;
  sirc_setTimeout(1000);
  while(1)
  {
    a=sirc_button(3);
    if(a==16)
    {
      wav_play("ouch.wav");
      pause(1000);
    }      
    else if(a==17)
    {
      wav_play("no.wav");
      pause(1000);
    }      
    else if(a==18)
    {
      wav_play("meow.wav");
      pause(1500);
    } 
    else if(a==19)
    {
      wav_play("hello1.wav");
      pause(1500);
    } 

  }  
}
