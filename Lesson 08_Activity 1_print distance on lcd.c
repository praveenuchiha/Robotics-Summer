 
#include "simpletools.h"                      // Include simpletools header 
#include"my_lcd_lib.h" 
#include "ping.h" 
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
    lcd_print_number(distance_inches);
    lcd_write_char('i'); 
     lcd_write_char('n'); 
   } 
} 