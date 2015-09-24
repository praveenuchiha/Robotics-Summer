//function
#include "simpletools.h"
#include "fdserial.h"


fdserial *xbee;
int command;

void move_robot_receiver();

int main(){
  //servo_angle(16,1800);
  //pause(500);
  print("This is Receiver!\n");
  xbee = fdserial_open(9,8,0,9600); //access these port with the xbee
  while(1){
    command = fdserial_rxChar(xbee); //recieve one bit of data from transmitter
    if(command == 0) {
      high(0);
      low(1);
      low(2);
    }      
    else if(command == 1) {
      low(0);
      high(1);
      low(2);
    } 
    else if(command == 2) {
      low(0);
      low(1);
      high(2);
    } 
    else {
      low(0);
      low(1);
      low(2);
    } 
  }  
}