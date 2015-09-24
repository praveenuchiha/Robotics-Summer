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
    set_outputs(13, 6, 0b11110101); 			//A
    else if(a==17)
    set_outputs(13, 6, 0b00110111);				//b
    else if(a==18)
    set_outputs(13, 6, 0b11000110);				//C
    else if(a==19)
    set_outputs(13, 6, 0b10010111);				//d
    else if(a==20)
    set_outputs(13, 6, 0b01110011);				//E
    pause(100);
  }  
}