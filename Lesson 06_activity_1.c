/*
  Test Whiskers with Terminal.c
 
  Display whisker states in terminal.  1 = not pressed, 0 = pressed. 
*/

#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"
#include "wavplayer.h"
int main()                                    // main function
{
  int DO = 22,CLK = 23, DI = 24, CS = 25;
  sd_mount(DO,CLK,DI,CS);
  wav_volume(10);
  freqout(4, 2000, 3000);                     // Speaker tone: P4, 2 s, 3 kHz
  while(1)                                    // Endless loop
  {
    int wL = input(7);                        // Left whisker -> wL variable
    int wR = input(8);                        // Right whisker -> wR variable
    //print("%c", HOME);                        // Terminal cursor home (top-left)
    //print("wL = %d  wR = %d", wL, wR);        // Display whisker variables
    drive_speed(128,128);
    if(input(7)==0 || input(8) == 0)
    {
    drive_speed(0,0);
    pause(500);/
    drive_goto(-150,-150);
    }
  }
}
