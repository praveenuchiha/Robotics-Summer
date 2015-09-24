#include "simpletools.h"                      // Include simpletools header 
#include"my_lcd_lib.h" 
#include "ping.h" 
#include "abdrive.h"

int main() 
{   
  int distance_inches=0; 
  lcd_init(0); 
  pause(100); 
  lcd_clear(); 
    
    while(1) 
    { 
      pause(30); 
      lcd_clear(); 
      distance_inches=ping_inches(8); 
        
        if (distance_inches < 10)
        {
          lcd_print_number(distance_inches);
          lcd_write_char(':'); 
          lcd_write_char('('); 
          pause(100);
          drive_speed(27,-27);
          lcd_clear();
        }
        else  
        drive_speed(0,0);        
   } 
}   
