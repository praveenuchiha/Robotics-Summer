//Transmitter function
#include "simpletools.h"
#include "fdserial.h"

fdserial *xbee;

void tx_xbee(int data)
{
fdserial_txChar(xbee,data);
}

int main(){
  pause(1000); // Wait 1 s for Terminal app //Start of JoyStick code in int main
  
  int red,blue,green; //End of Joystick code in int main
  print("This is transmitter!\n");
  xbee = fdserial_open(9, 8, 0, 9600);
  pause(1000);
//read your joystick
  while(1){
    red = input(0);
	blue = input(1);
	green = input(2);
    pause(100);
    
    if (red && !blue && !green){//red click
      tx_xbee(0);
    }
    else if(!red && blue && !green){//blue click
      tx_xbee(1);
    }
    else if(!red && !blue && green){//green click
      tx_xbee(2);
    }
    else {							//click multiple button or no button
		tx_xbee(5);
    }        
  }
}