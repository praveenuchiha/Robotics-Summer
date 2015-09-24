/*
  RFID Read.c
  
  Reads and displays RFID tag numbers.
  
  Connect: Vcc to 5V, /ENABLE to P2, SOUT to (R = 2.2 k) to P1, GND to GND
  
  http://www.parallax.com/product/28140
  16001A00DC (white circle)
  010DBEA632 (black circle)
  07000CDB16 (key chain)
  1E009BC215
  1E009D9881
*/

#include "simpletools.h"                      // Include simpletools
#include "rfidser.h"                          // Include rfidser

int rfidEn = 2;                               // Reader /ENABLE pin to P2
int rfidSout = 1;                             // Reader SOUT pin to P1

rfidser *rfid;                                // Set up device ID

int main()                                    // Main function
{
  rfid = rfid_open(rfidSout, rfidEn);         // Open reader, start reading

  while(1)                                    // Main loop
  {
    char *str = rfid_get(rfid, 1000);         // Wait up to 1 s for card
    print("id = %s.\n", str);                 // Print ID.
  }  
}

/*
  RFID Read and Compare.c
  
  After scanning your ID tags, you can copy their ID strings over the ones
  in the else if statements in this program to recognize them.
  
  Connect: Vcc to 5V, /ENABLE to P2, SOUT to (R = 2.2 k) to P1, GND to GND
  
  http://www.parallax.com/product/28140
*/

#include "simpletools.h"                      // Include simpletools
#include "rfidser.h"                          // Include rfidser

int rfidEn = 2;                               // Reader /ENABLE pin
int rfidSout = 1;                             // Reader SOUT pin

rfidser *rfid;                                // Set up device ID

int main()                                    // Main function
{
  rfid = rfid_open(rfidSout, rfidEn);         // Open reader, start reading

  while(1)                                    // Main loop
  {
    char *str = rfid_get(rfid, 1000);         // Wait up to 1 s for card

    if(!strcmp(str, "timed out"))             // Timed out?
      print("No ID scanned.\n");              //   display "No ID..."
    else if(!strcmp(str, "1E009BC215"))       // Tag A ID match?
      print("Tag A detected.\n");             //   display "Tag A..."
    else if(!strcmp(str, "1E009D9881"))       // Tag B ID match?
      print("Tag B detected.\n");             //   display "Tag B..."
    else if(!strcmp(str, "16001A00DC"))       // Tag B ID match?
      print("Tag C detected.\n");      
    else if(!strcmp(str, "010DBEA632"))       // Tag B ID match?
      print("Tag D detected.\n");      
    else                                      // No matches?
      print("Unknown ID = %s.\n", str);       //   print ID.
  }  
}

//RFID
#include "simpletools.h"                      // Include simpletools
#include "rfidser.h"                          // Include rfidser
#include "abdrive.h"

int rfidEn = 2;                               // Reader /ENABLE pin
int rfidSout = 1;                             // Reader SOUT pin

rfidser *rfid;                                // Set up device ID

int main()                                    // Main function
{
  rfid = rfid_open(rfidSout, rfidEn);         // Open reader, start reading

  while(1)                                    // Main loop
  {
    char *str = rfid_get(rfid, 1000);         // Wait up to 1 s for card

    if(!strcmp(str, "timed out"))  {           // Timed out?
      print("No ID scanned.\n");              //   display "No ID..."
      drive_speed(0,0);
    }      
    else if(!strcmp(str, "1E009BC215"))  {     // Tag A ID match?
      print("Tag A detected.\n");             //   display "Tag A..."
      drive_speed(64,64);
    }      
    else if(!strcmp(str, "1E009D9881")){       // Tag B ID match?
      print("Tag B detected.\n");             //   display "Tag B..."
      drive_speed(-64,-64);
    }      
    else if(!strcmp(str, "16001A00DC")) {      
      print("Tag C detected.\n");      
      drive_speed(-32,32);
    }      
    else if(!strcmp(str, "010DBEA632")){       
      print("Tag D detected.\n");      
      drive_speed(32,-32);
    }      
    else                                      // No matches?
      print("Unknown ID = %s.\n", str);       //   print ID.
  }  
}
