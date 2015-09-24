//MTA
#include "simpletools.h"                       // Include libraries
#include "abdrive.h"
#include "wavplayer.h"
#include "rfidser.h"
#include "ping.h"

int getQTIs(int highPin, int lowPin);          // Forward declare function
int rfidEn = 9;                                //Reader / ENABLE pin
int rfidSout = 10;                               //Reader SOUT pin
rfidser *rfid;                                  //set up device ID

int main()                                     // Main function
{
  int distance;
  rfid = rfid_open(rfidSout, rfidEn);         // Open reader, start reading
  while(1)                                     // Main loop
  {
    distance = ping_cm(11);
    pause(100);
    int qtis = getQTIs(7, 4);                  // Check stripe position
    int DO = 22, CLK = 23, DI = 24, CS = 25;        // SD I/O pins 
    sd_mount(DO, CLK, DI, CS);                      // Mount SD card 
    wav_volume(7);
    if(distance <= 30){drive_speed(0,0);} //too close!
    else{
      if(qtis == 0b1000) {drive_speed(32, -32);   // Far left, rotate left
      //printf("Far left, rotate left. \n");
    }    
      else if(qtis == 0b1100 || qtis == 0b1110) {drive_speed(32, 0);     // Left, pivot left
      //printf("Left, pivot left. \n");
    }   
      else if(qtis == 0b0100) {drive_speed(32, 16);    // A little left, curve left
      //printf("A little left, curve left. \n");
    }  
      else if(qtis == 0b0110) {drive_speed(64, 64);    // Stripe centered, forward
      //printf("Stripe centered, forward. \n");
    }    
      else if(qtis == 0b0010) {drive_speed(16, 32);    // A little right, curve right
      //printf("A little right, curve right. \n");
    }  
      else if(qtis == 0b0011 || qtis == 0b0111) {drive_speed(0, 32);     // Right, pivot right
      //printf("Right, pivot right. \n");
    }  
      else if(qtis == 0b0001) {drive_speed(-32, 32);   // Far right, rotate right
      //printf("Far right, rotate right. \n");
    } 
      else if(qtis == 0b1111){
        drive_speed(0,0); //stop robot
        pause(500);
        char *str = rfid_get(rfid, 5000); //check for a rfid scan
        if(!strcmp(str, "timed out"))  {           // Timed out?
          //print("No ID scanned.\n");              //   display "No ID..."
          drive_speed(0,0);    }   
        else if(!strcmp(str, "16001A00DC"))  {     // Right station stop?
          //print("Tag A detected.\n");             //   display "Tag A..."
          wav_play("stand.wav");
          pause(19000);
          drive_goto(32,32);}  
        else if(!strcmp(str, "010DBEA632")){ //alternate route?
          wav_play("techloop.wav");
          pause(5000);
          //wav_stop();
          drive_goto(0,54); //turn left onto alternate route
          drive_goto(32,32); //push forward and continue on
          }
        }
      else{drive_speed(0,0);
      //printf("Nothing works!\n");
      }
    pause(50);
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
