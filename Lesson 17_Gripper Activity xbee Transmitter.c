
// transmitter code
#include "simpletools.h"
#include "fdserial.h"
#include "abdrive.h"
#include "adcDCpropab.h"
fdserial *xbee;
int ud, lr, n;
int main()
{
 pause(1000);
 print("This is transmitter!");
 xbee = fdserial_open(9,8,0,9600);
 pause(500);
 //print("Sent the message!\n");

adc_init(21, 20, 19, 18);

float lrV, udV;
int ud, lr; // <-- add

while(1)
{

udV = adc_volts(2);
lrV = adc_volts(3);
ud = 200*(udV-2.5)/5; // <-- add
lr = 200*(lrV-2.5)/5; // <-- add

putChar(HOME);

//print("Up/Down = %d %c\n", ud, CLREOL); // <-- modify

//print("Left/Right = %d %c\n", lr, CLREOL); // <-- modify

//pause(100);

if (ud>20)
{
  //print("1");// pause(50);
 fdserial_txChar(xbee,1);
}  
else if (ud<-20)
{
 // print("2"); //pause(50);
  fdserial_txChar(xbee,2);
}   
else if (lr>20)
{
  //print("3"); //pause(50);
 fdserial_txChar(xbee,3);
}  
else if (lr<-20)
{
 // print("4"); //pause(50);
 fdserial_txChar(xbee,4);
}  
else
{
 // print("5"); //pause(50);
 fdserial_txChar(xbee,5);
}  
/*
print("Enter a number and press enter \n");
scan("%d\n",&n);
print("Your number is = %d \n", n);
pause(500);

if (n==1)
{
  print("1\n"); //pause(50);
 fdserial_txChar(xbee,1);
}  
else if (n==2)
{
  print("2\n"); //pause(50);
  fdserial_txChar(xbee,2);
}   
else if (n==3)
{
  print("3\n"); //pause(50);
 fdserial_txChar(xbee,3);
}  
else if (n==4)
{
  print("4\n"); //pause(50);
 fdserial_txChar(xbee,4); 
}  
else if (n==5)
{
  print("5\n"); //pause(50);
 fdserial_txChar(xbee,5);
}  */
}
}