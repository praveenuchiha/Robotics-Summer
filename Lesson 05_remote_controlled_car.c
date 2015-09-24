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
    drive_speed(128,128);		//Move forward
    else if(a==17)
    drive_speed(-128,-128);		//Move backward
    else if(a==18)
    drive_goto(50,0);		//Move Right
    else if(a==19)
    drive_goto(0,50);		//Move left
    else if(a==20)
    drive_speed(0,0);		//Stop moving
    pause(100);
  }  
}
