/*
  Write a code that asks for and prints the initial if your first name. 
  Write another that asks for a prints your age. 
  Write a third that asks for and prints your height. 
  Light P26 or P27 each time.
 */
#include "simpletools.h"                      

int main()                                    
{
   char initial;
   printf("Please insert your name \n");
   scanf("%c", &initial); 
   printf("This is your initial: %c\n", initial);
   high(26);
   pause(1000);
   low(26);
   int age;
   printf("Please insert your age \n");
   scanf("%d", &age); 
   printf("This is your age: %d\n", age);
   high(26);
   pause(1000);
   low(26);
   int height;
   printf("Please insert your height in inches \n");
   scanf("%d", &height); 
   printf("This is your height: %d\n", height);
   high(26);
   pause(1000);
   low(26);
}

/*
  Write a code that starts with 1 and 
  multiplies the previous value by two until it reaches 1024. 
  After it reaches 1024 it will only output the number of occurences when the
  button is pressed 
 */
#include "simpletools.h"                      

int main()                                    
{
   int occur = 0;
   for(int mult = 1; mult <=1024; occur++){
     mult *= 2;
     }
   int button = input(0);
   while(1){
   if (button == 1){
   printf("Number of occurences: %d\n", occur);
      }       
    }   
}

//print two numbers
#include "simpletools.h"

int main(){
  print("Hi there!\n");
  print("My name is Rafi.\n");
  }

//ask for two numbers and print them
#include "simpletools.h"

int main(){
  int num1;
  int num2;
  print("Please input two numbers:\n");
  scan("%d", &num1);
  scan("%d", &num2);
  print("Number 1: %d\n", num1);
  print("Number 2: %d\n", num2);
}

//program that subtracts two values, take result and multiply and print

#include "simpletools.h"

int main(){
  int num1 = 5;
  int num2 = 10;
  int difference = num1 - num2;
  int result = difference * 20;
  print("Final result is: %d", result);
}

/*
  Write a function that asks for the radius of a sphere and calculates 
  the surface area. Print that value after.
 */
#include "simpletools.h"                      

int main()                                    
{
  int radius;
  print("Please enter the radius of your sphere: ");
  pause(100);
  scanf("%d", &radius); 
  printf("This is your radius: %d\n", radius);
  float area = radius * radius * radius * 4 * PI;
  printf("The area of the sphere with radius %d is: %5.2f\n", radius, area);
}

//LED and switch
#include "simpletools.h"

int main(){
  while(1){
    if(input(3) == 1){
      high(27);
      pause(100);
      low(27);
      pause(100);
    }
  }
}

//chicken or egg?
#include "simpletools.h"

int main(){
  while(1){
    if(input(3) == 1){
      print("The chicken came first.\n");
      pause(1000);
    }
    else if(input(4) == 1){
      print("The egg came first.\n");
      pause(1000);
    }
  }
}

//taller or shoter than Jordan
#include "simpletools.h"

int main(){
  float height = 5.9;
  if(height > 6.6){
    print("I am taller than Michael Jordan.\n");
  }
  else{print("I am smaller than Michael Jordan.\n");}
}

//NBA or Tennis?
int main(){
  float height = 5.9;
  int age = 20;
  if(height > 6.0 && age > 18){
    print("I could be playing in the NBA!\n");
  }
  else{print("Tennis is better!\n");}
}

//NBA triple double

#include "simpletools.h"

int main(){
	int points;
	int rebounds;
	int assists;
	print("Hi, please input the points scored by the player.\n");
	scan("%d", &points);
	print("Please input the number of rebounds.\n")
	scan("%d", &rebounds);
	print("Please input the numbers of assists.\n");
	scan("%d", &assists);
	print("The player's stats are: %d points, %d rebounds, %d assists\n", points, rebounds, assists); //display stats
	if(points > 10 && rebounds > 10 && assists > 10){ //check for triple double
		print("The player has a triple double!!!\n");
	}
	else{
		print("The player does not have a triple double!\n");
	}
}