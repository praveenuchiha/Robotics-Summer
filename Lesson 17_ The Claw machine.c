
#include "adcDCpropab.h"
#include "simpletools.h"
#include "abdrive.h"
#include "servo.h"


int main()

{

pause(1000);

adc_init(21, 20, 19, 18);

float lrV, udV;

int ud, lr; // <-- add

int button;

while(1)

{
button=input(1);
udV = adc_volts(2);

lrV = adc_volts(3);

ud = 200*(udV-2.5)/5; // <-- add

lr = 200*(lrV-2.5)/5; // <-- add

putChar(HOME);

print("Up/Down = %d %c\n", ud, CLREOL); // <-- modify

print("Left/Right = %d %c\n", lr, CLREOL); // <-- modify

pause(100);

  if (ud>20)
{
 print("up %c\n", CLREOL);
 drive_speed(50,50); 
}  
else if (ud<-20)
{
  print("down %c\n", CLREOL );
  drive_speed(-50,-50);
}   
else if (lr>20)
{
 print("right %c\n", CLREOL); 
 drive_speed(50,-50);
}  
else if (lr<-20)
{
  print("left %c\n", CLREOL);
  drive_speed(-50,50);
}  
else
{
  print("stop %c\n", CLREOL);
  drive_speed(0,0);
  servo_angle(16,0);
 if (button==1)
{
  servo_angle(16,1800);
 
} 
}  
}
}






