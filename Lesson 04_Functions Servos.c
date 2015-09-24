#include "simpletools.h"
#include "abdrive.h"

void square(void){
  
  drive_goto(-33,31);//turn 90 degrees
  pause(100); //pause for 2 seconds
  drive_goto(164, 164);// go a distance of 208 or 1 revolution
  drive_goto(-32,31);//turn 90 degrees 2nd time
  pause(100); //pause for 2 seconds
  drive_goto(164, 164);// go a distance of 208 or 1 revolution
  drive_goto(-32,31);//turn 90 degrees 3rd time
  pause(100); //pause for 2 seconds
  drive_goto(164, 164);// go a distance of 208 or 1 revolution
  drive_goto(-32,31);//turn 90 degrees 4th time
  pause(100); //pause for 2 seconds
  drive_goto(164, 164);// go a distance of 208 or 1 revolution
}  
  
  
  
  
  
 // #include "simpletools.h" 
//#include "abdrive.h"                     // Include simple tools
void right(void){
pause(500);
drive_goto(40,-40);
}
void left(void){
pause(500);
drive_goto(0,50);
}
void forward(int speed){
pause(500);
drive_goto(speed,speed);
}
void backward(int speed){
  pause(500);
  drive_goto(-(speed),-(speed));
}  
  void triangle(int speed){
  forward(speed);
  right();
  forward(speed);
  right();
  forward(speed);
  right();
}  
  
int main()                                    // Main function
{
  int button,button1;
  while(1){
    button=input(1);
    button1=input(0);
  if(button==1){
    triangle(100);
  }    
  if (button1==1)
  {
    square();
    }
}  
}

  
