  
#include "simpletools.h"
#include "fdserial.h"
#include "abdrive.h"
#include "servo.h"

fdserial *xbee;
int msg_buffer;
int function1(int ud,int turn)
  //xbee = fdserial_open(9,8,0,9600);
  {
if (msg_buffer == 1)
  {
    print("Up \n");
    //pause(1000);
    drive_speed(ud,ud); 
  }
  else if (msg_buffer == 2)
  {
    print("down \n");
    //pausesg_buffer == 3)
    drive_speed(-ud,-ud);
  }
  else if (msg_buffer ==3)    
  {
    print("Right \n");
    //pause(1000);
   drive_speed(turn,-turn);
   pause(20); 
  }
   else if (msg_buffer == 4)
  {
    print("Left \n");
    //pause(1000);
   drive_speed(-turn,turn);;
   pause(20); 
  }
  else if (msg_buffer==5)
                   
  {
    //print("Stop\n");
    //pause(1000);
   drive_speed(0,0);
   servo_angle(16,1800); 
  }

}


int main()
{
  int msg_buffer;
  pause(1000);
  print("This is the Reciever!\n");
  xbee = fdserial_open(9,8,0,9600);
  //pause(100);
 
  //high(7);
  
  while (1)
  {
    msg_buffer=fdserial_rxChar(xbee);
    
   if (msg_buffer ==10) //red
   { 
     print("Red");
     low(5);
     high(7); 
   }
   
   
   if (msg_buffer ==11) //blue
   {
     print("Blue");
     low(7);
     high(5);
   }
  
  function1(125,20);
  if (msg_buffer==6)
  
  {
    print("ServoClose\n");
    
    // speed1 = speed1*10;
    servo_angle(16,0);  
    //drive_speed(15,15); 
  }
  if (msg_buffer==7) // toggle speed
  {
    msg_buffer=fdserial_rxChar(xbee);
    print("toggle");
 
    //drive_speed(20,20);
    //pause(100);    
   function1(30,10); 
  }

  if (msg_buffer ==12)
  {
    print("shot");
  drive_speed(-50,50);
  pause(250);
  drive_speed(126,-126);
  pause(1000);
  } 
   
}//while loop
}  //int main




