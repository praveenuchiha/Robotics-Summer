/*
  Follow with Ping.c

  Maintain a constant distance between ActivityBot and object.

  http://learn.parallax.com/activitybot/follow-objects-ultrasound
*/

#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"  
#include "servo.h"                           // Include ping header  

int distance;  // Navigation variables

int main()                                    // main function
{
                   // Proportional control
  
  servo_angle(16, 650);                       // 7 ticks/sec / 20 ms

  while(1)                                    // main loop
  {
    //pause(200);
    distance = ping_cm(17);
    //print("distance= %d\n", distance);
    pause(200); 
      if (distance >25)
      {
        drive_speed(75,75);
      }
else    
{
    drive_speed(0,0);
    servo_angle(16, 10);
    pause(1000);
    int distanceleft = ping_cm(17);
    pause(1000);
    //print("distance left= %d\n", distanceleft);
    servo_angle(16, 1600);
    pause(1000);
    //print("distance= %d\n", distanceleft);
    int distanceright = ping_cm(17);
    pause(1000);
    //print("distance right= %d\n", distanceright);
    servo_angle(16, 650);
    pause(1000);
    //print("distance= %d\n", distanceleft);
    //servo_angle(16, 750);
int a = distanceleft - distanceright;
//pause(200);
//print("a= %d\n", a);
pause(200);
      if (a == 0)
            {
            drive_speed(64,-64);
            pause(300);
            print("1\n");
            }
      else if (a > 0)
            {
            drive_speed(-64,64);
            pause(150);
            print("2\n");
            }
      else if(a < 0)
        {
          drive_speed(64,-64);
            pause(150);
          print("3\n"); 
        }
}                   
                      // Calculate correction speed
}
}
