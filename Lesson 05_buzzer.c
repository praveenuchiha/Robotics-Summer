/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"
#include "sirc.h"

int main()                                    // Main function
{
  int a;
  sirc_setTimeout(1000);
  while(1)
  {
    a=sirc_button(3);
    if(a==16)
    freqout(4, 2000, 3000); 
    else if(a==17)
    freqout(4, 2000, 1000); 
    else if(a==18)
    freqout(4, 2000, 4000); 
    else if(a==19)
    freqout(4, 2000, 1500); 
    pause(100);
  }  
}
