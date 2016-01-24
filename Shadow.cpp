/****************************************************************************************
**Program Filename: Shadow.cpp
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: shadow class implimentation files
 **Input: None
 **Output: integers representing evasion, and dice rolls 
 ***************************************************************************************/
#include "Shadow.hpp"
#include "Hero.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


/****************************************************************************************
**Function: overridden rollDefendDice 
**Description: This method determines if a shadow is in location to be hit (%50 chance)
**and if the shadow can be hit, calculates the sum of a roll of random dice
**Parameters: None
**Pre-Conditions: Hero object must have been created and must be called
**Post-Conditions: Must return an integer value
****************************************************************************************/
int Shadow::rollDefendDice()
{  //Declare integer for total
   int roll, total = 0;
   bool evade;

   //Check if the Shadow has evaded the attack by returning a -1 flag 50% of the time 
   //and a normal dice roll 50% of the time
   evade = (rand() % 2);
   if(evade)
   {   return -1;
   }
   else
   {  //Create a for loop to find the random value of each dice 
      for(int count = 1; count <= getDefendDice(); count ++)
      {
	 roll = (rand() % getDefendFaces() + 1);
	 total += roll;
      }
      for(int count = 1; count <= getDefendDice(); count ++)
      //return the value of all the dice combines
      return total;
   }
}
