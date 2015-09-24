/* 
  Line Follow when there are no objects in 30cms distance
*/

#include "simpletools.h"                       // Include libraries
#include "abdrive.h"
#include "ping.h"                             // Include ping header

int distance;                                 // Declare distance variable
int getQTIs(int highPin, int lowPin);          // Forward declare function

int main()                                     // Main function
{
  while(1)                                     // Main loop
  {
    distance = ping_cm(8);                 // Get cm distance from Ping)))
if(distance>30){
    int qtis = getQTIs(7, 4);                  // Check stripe position
    if(qtis == 0b1000) drive_speed(-64, 64);   // Far left, rotate left
    if(qtis == 0b1100) drive_speed(0, 64);     // Left, pivot left
    if(qtis == 0b0100) drive_speed(32, 64);    // A little left, curve left
    if(qtis == 0b0110) drive_speed(64, 64);    // Stripe centered, forward
    if(qtis == 0b0010) drive_speed(64, 32);    // A little right, curve right
    if(qtis == 0b0011) drive_speed(64, 0);     // Right, pivot right
    if(qtis == 0b0001) drive_speed(64, -64);   // Far right, rotate right
  }
}  
}

int getQTIs(int highPin, int lowPin)           // Function - getQTIs
{
  int dt = (CLKFREQ / 1000000) * 230;          // Set up 230 us time increment
  set_outputs(highPin, lowPin, 0b1111);        // highPin...lowPin set high
  set_directions(highPin, lowPin, 0b1111);     // highPin...lowPin set to output
  waitcnt(dt + CNT);                           // Wait 230 us
  set_directions(highPin, lowPin, 0b0000);     // highPin...lowPin st to input
  waitcnt(dt + CNT);                           // Wait 230 us
  int qtis = get_states(highPin, lowPin);      // Get 4-bit pattern QTIs apply 
  return qtis;                                 // Return val containing pattern
}