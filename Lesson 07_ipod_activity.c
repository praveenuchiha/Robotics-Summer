/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "my_lcd_lib.h"                       // Including LCD 
#include "wavplayer.h"                        // Including speaker 

int main()                                    // Main function
{
  int DO = 22, CLK = 23, DI = 24, CS = 25;    // serial peripheral interface || data out
  sd_mount(DO, CLK, DI, CS);                  // Mounting the SD card
  
  lcd_init(0);                                // LCD connected to IO pin 0
  lcd_clear();                                // Clearing LCD
  
  
  /* User Interface for the terminal - will print just once - that's why outside while */
  print("                   Welcome!                     \n");
  print("************************************************\n");
  print("Press: 0 to stop or a Song Number to play a song\n");
  print("************************************************\n");
  print("What would you like to listen to today?\n");
  print("1. songA\n");
  print("2. songB\n");
  
  
  int key;                                  //input 
  
  
  /* keep reading input and doing the corresponding instructions */
  while(1){
    
  
    scan("%d", &key);                       

    
    if(key == 1){                           
    
      wav_stop();
      wav_play("songA.wav");
      wav_volume(8);
      lcd_clear();
      lcd_print_string("songA");
      
      }
    if(key == 2){
      
   
      wav_stop();
      wav_play("songB.wav");
      wav_volume(8);
      lcd_clear();
      lcd_print_string("songB");
      
      }
    if(key == 0){

      wav_stop();
      lcd_clear();
      lcd_print_string("Stopped");
      
      } 
      
       
    }//end of whilie
    
    wav_stop();
}
