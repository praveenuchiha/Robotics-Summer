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
    high(3); 
    else if(a==17)
    high(5);  
    else if(a==18)
    high(4); 
    else if(a==19)
    high(6); 
    pause(100);
  }  
}
