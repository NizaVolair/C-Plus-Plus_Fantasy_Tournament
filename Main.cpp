/****************************************************************************************
 **Program Filename: Battle.cpp 
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Main for Hero program 
 **Input: Integers and strings for choices and names 
 **Output: Prints messages to screen to display winners and losers
 ***************************************************************************************/
#include "Hero.hpp"
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Blue.hpp"
#include "Shadow.hpp"
#include "StackList.hpp"
#include "QueueList.hpp"
#include "Battle.hpp"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{  //Create time seed to randomize dice rolls in hero methods
   srand(time(NULL));

   //Create integers for starting menu choice, choice of attacker and defender
   //Create a poitner to the defender so it may be passed to the attacker
   int choice, attacker, defender;
   char engage;
   Hero *defendPtr;
   
   //Make a int for size of team, type of hero, and number of blue heros
   unsigned size, type, numBlue = 0;

   //Make name string
   string name = " ";
   
   //Create Stack List object and Create Queue List object
   QueueList queue1(1);
   QueueList queue2(2);
  
   //Create Hero Pointer
   Hero *heroPtr;
   
   //Explain game and get user input
   cout << endl << "~~~~~~~~~~ NEW & IMPROVED ~~~~~~~~~~~\n";
   cout << "      ~~~~~ BATTLE TIME ~~~~~~\n" << endl;
   cout << "Number of Warriors per Team: ";
   cin >> size;

   //In a loop get types of warriors and names of warriors for each team
   for(int team = 1; team <=2; team++)
   {  //Display warrior types
      cout << endl << "~~~ WARRIORS TYPES ~~~\n";
      cout << "1) Goblin\n";
      cout << "2) Barbarian\n";
      cout << "3) Reptile\n";
      cout << "4) Blue Person*\n";
      cout << "5) Shadow\n" << endl;
      //Blue men fight in a team, so there must be at least 3 warriors to use this option
      cout << "*3 warrior minimum\n" << endl;
      
      //Prompt correct player for selections in loop equal to the number of warriors per team
      cout << "Player " << team << " Select Warriors!\n";
      for(int count = 1; count <= size; count++)
      {	 //Get the number type in a loop to ensure correct information
         cout << endl << count << " Warrior Type Number: ";
	 do
	 {  cin >> type;
	    //Ensure type is within range
	    if( (type < 1) || (5 < type) )
	    {  cout << "ERROR: Enter type from 1 ~ 5 to continue: ";
	    }
	    //Ensure at least 3 available warrior places to add a minimun of Blue People
	    if( (type == 4) && ((size - count + 1) < 3))
	    {  cout << "ERROR: Blue People require a minimum of 3 available warriors.\n";
	       cout << "Enter another type to continue: ";
	    }
	 } while ( ((type < 1) || (5 < type)) || ((type == 4) && ((size - count + 1) < 3)) );
	 if(type != 4)
	 {  //Get name for warrior- not Blue People since they need multiple names
	    cout << count << " Warrior Name: ";
	    cin.ignore();
	    getline(cin, name);
	 }
	 if(type == 1)
	 {  //Make goblin object
	    heroPtr = new Goblin(name, team);
	 }	 
	 else if(type == 2)
	 {  //Make Barbarian object
	    heroPtr = new Barbarian(name, team);
	 }
	 else if(type == 3)
	 {  //Make reptile object
	    heroPtr = new Reptile(name, team);
	 }
	 else if(type == 4)
	 {  //Get Number of Blue People in a loop to ensure correct information
	    cout << "Number of Blue People: ";
	    do
	    {  cin >> numBlue;
	       //Ensure number is within range
	       if((numBlue < 3) || (numBlue > (size - count + 1)))
	       {  //If there are only 3 remaining spaces force user to select 3 
		  if((size - count + 1) == 3)
		  {  cout << "ERROR: Only 3 warriors remaining. Enter 3 to continue: ";
		  }
		  //Get number in range from the user
		  else
		  {  cout << "ERROR: Enter number between 3 and " << (size - count + 1) << " to continue: ";
		  }
	       }
	    } while ((numBlue < 3) || (numBlue > (size - count + 1)));
	    cin.ignore();
	    //In a loop make all the Blue People objects
	    for(int countBlue = count; countBlue < (numBlue + count); countBlue++)
	    {  cout << countBlue << " Warrior Name: ";
	       getline(cin,name);
	       heroPtr = new Blue(name, team);
	       //Add to correct team
	       if( team == 1)
	       {  queue1.addBack(heroPtr);  	 
	       }
	       else
	       {  queue2.addBack(heroPtr);
	       }
	    }    
	    //Update the count to reflect the multiple adds of Blue People
	    count += (numBlue - 1);
	 }
	 else if(type == 5)
	 {  //Make shadow object
	    heroPtr = new Shadow(name, team);
	 }
	 //Add objects to the correct team
	 if(type != 4)
	 {  if( team == 1)
	    {  queue1.addBack(heroPtr);  	 
	    }
	    else
	    {  queue2.addBack(heroPtr);
	    }
	 }    
      }
   }
   //Test the queues to ensure they are correct
   cout << endl;
   queue1.display(); 
   queue2.display();

   //Make queue pointers to send to battle
   QueueList * qPtr1 = &queue1;
   QueueList * qPtr2 = &queue2;

   //Send queues to the the battle fight method, call show winner and losers
   Battle battle(qPtr1, qPtr2);
   battle.fight();
   battle.showWinners();
   battle.showLosers();
   return 0;
}
    
    
    
    
    
    
    
    
