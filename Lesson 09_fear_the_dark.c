/*
  Navigate by Light.c

  http://learn.parallax.com/activitybot/roaming-light-sensors
*/

#include "simpletools.h"
#include "abdrive.h"
#include "my_lcd_lib.h"

int lightLeft, lightRight, ndiff;
int speedLeft, speedRight;

int main()                    
{
  lcd_init(10); 
  while(1)
  {
    high(9);
    pause(1);
    lightLeft = rc_time(9, 1);
    
    high(5);
    pause(1);
    lightRight = rc_time(5, 1);

    ndiff = 200 * lightRight / (lightRight + lightLeft) - 100; // difference equation yields a value in the range of -100 and 100; 
                                                               // postitive=left photoresistor is sensing bright light 
                                                               // negative=right photoresistor is sensing bright light            
    speedLeft = 100;
    speedRight = 100;
    if(ndiff >= 0) 
{
    speedLeft -= (ndiff * 4);                  // turn left towards the brighter light
    lcd_print_string("turning left");
    pause(2000);
    lcd_clear();
}
    else 
    {
    speedRight += (ndiff * 4);                           // turn right towards the brighter light
    lcd_print_string("turning right");
    pause(2000);
    lcd_clear();     
  }    
    drive_speed(speedRight, speedLeft);
  }
}
