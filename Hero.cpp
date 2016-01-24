/****************************************************************************************
 **Program Filename: Hero.cpp 
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Abstract hero class implimentation files 
 **Input: uses pointers to heros defending for attack function
 **Output: returns information with get functions and returns integer representing damage
 ***************************************************************************************/
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

//Constructor which passes variable to their proper set methods
//and sets achillies to uncut(true)
Hero::Hero(int arm, int str, string heroName, string heroType, 
	    int attackDice,int attackFaces, int defendDice, int defendFaces,
	       bool cut, int teamNum, int ptNum)
{  setArmor(arm);
   setStrength(str);
   startingStrength = str;
   setName(heroName);
   setType(heroType);
   setNumAttackDice(attackDice);
   setNumAttackFaces(attackFaces);
   setNumDefendDice(defendDice);
   setNumDefendFaces(defendFaces);
   cutAchilles(cut);   
   setTeam(teamNum);
   setPoints(ptNum);
   killBonus = 5;
}

//Set methods for private variables
void Hero::setArmor(int arm)
{  armor = arm;
}
void Hero::setStrength(int str)
{  strength =  str;
}
void Hero::setName(string heroName)
{  name = heroName;
}
void Hero::setType(string heroRace)
{  type = heroRace;
}
void Hero::setNumAttackDice(int attackDice)
{  numAttackDice = attackDice;
}
void Hero::setNumAttackFaces(int attackFaces)
{  numAttackFaces = attackFaces;
}
void Hero::setNumDefendDice(int defendDice)
{  numDefendDice = defendDice;
}
void Hero::setNumDefendFaces(int defendFaces)
{  numDefendFaces = defendFaces;
}
void Hero::setTeam(int teamNum)
{  team = teamNum;
}
void Hero::setPoints(int ptNum)
{  points = ptNum;
}


//Get method for private variables
//Note dice/faces need get methods only to be used in subclasses like Shadow
int Hero::getArmor()
{  return armor;
}
int Hero::getStrength()
{  return strength;
}
string Hero::getName()
{  return name;   
}
string Hero::getType()
{  return type;
}
int Hero::getAttackDice()
{  return numAttackDice;
}
int Hero::getAttackFaces()
{  return numAttackFaces;
}
int Hero::getDefendDice()
{  return numDefendDice;
}
int Hero::getDefendFaces()
{  return numDefendFaces;
}
int Hero::getTeam()
{  return team;
}
int Hero::getPoints()
{  return points;
}


/****************************************************************************************
**Function: cut achillies
**Description: This method allows an achilles to be cut (set true) or healed (set false)
**Parameters: bool indicating achilles status
**Pre-Conditions: Hero must have been created and bool must be passed
**Post-Conditions: Must change the achilles private variable as appropriate
****************************************************************************************/
void Hero::cutAchilles(bool cut)
{  if(cut == true) 
   {  achillesCheck = true;
   }
   else if (cut == false)
   {  achillesCheck  = false;
   }
}


/****************************************************************************************
**Function: achilles
**Description: This method check if the achilles has been cut
**Parameters: None
**Pre-Conditions: Hero must have been created and achilles set
**Post-Conditions: Must return true if achilles is cut (private bool true) false otherwise
****************************************************************************************/
bool Hero::achilles()
{  return achillesCheck;
}


/****************************************************************************************
**Function: rollAttackDice
**Description: This method calculates the sum of a roll of random dice
**Parameters: None
**Pre-Conditions: Hero object must have been created and must be called
**Post-Conditions: Must return an integer value
****************************************************************************************/
int Hero::rollAttackDice()
{  
   //Declare integer for total
   int roll, total = 0;
   
   //Create a for loop to find the random value of each dice 
   for(int count = 1; count <= numAttackDice; count ++)
   {
      roll = (rand() % numAttackFaces + 1);
      total += roll;
   }
   for(int count = 1; count <= numDefendDice; count ++)
   //return the value of all the dice combines
   return total;
}


/****************************************************************************************
**Function: rollDefendDice (is overridden in the Shadow subclass)
**Description: This method calculates the sum of a roll of random dice
**Parameters: None
**Pre-Conditions: Hero object must have been created and must be called
**Post-Conditions: Must return an integer value
****************************************************************************************/
int Hero::rollDefendDice()
{  
   //Declare integer for total
   int roll, total = 0;
   
   //Create a for loop to find the random value of each dice 
   for(int count = 1; count <= numDefendDice; count ++)
   {
      roll = (rand() % numDefendFaces + 1);
      total += roll;
   }
   for(int count = 1; count <= numDefendDice; count ++)
   //return the value of all the dice combines
   return total;
}


/****************************************************************************************
**Function: attack (overridden in Goblin and Blue subclasses)
**Description: Method allows attacker to deduct points from defender's strength
**depending on randomized dice rolls, then switch rolls
**Parameters: Pointer to a hero (defender)
**Pre-Conditions: two heros creater, dice rolling functions created
**Post-Conditions: defender's strength is accurately changed and total pointsare returned
****************************************************************************************/
int Hero::attack(Hero *defender)
{  //Create variables for the atack and defense scores, damage and adjusted strength
   int attack, defense, newStrength;
   int damage = 0;

   //Check for a cut achilles tendon and calculate attack and defense
   if((this->achilles()) == false)
   {  attack = (this->rollAttackDice());
   }
   else if ((this->achilles()) == true)
   {  attack = ((this->rollAttackDice())/2);
   }
   defense = (defender->rollDefendDice());

   //Check for -1 flag for Shadow evasion
   if(defense == (-1))
   {  damage = 0;
   }
   
   else
   {  //Use attack and defense scores to find damage
      damage = ((attack - defense) - (defender->getArmor()));
	 
      //The attack was not successful if  less than or equal to 0
      if(damage <= 0)
      {	 damage = 0;
      }

      //If there was damage find new strength
      else if(damage > 0)
      {  newStrength = ((defender->getStrength()) - damage);
         defender->setStrength(newStrength);
	 //Add damage to attackers points
	 this->setPoints(this->points + damage);
	 //If damage greater than strength declare death the defender has died
         //mend attacker achillies, and set choice to 'n' to stop battle
         if(defender->getStrength() <= 0)
         {  //Add killer bonus to attackers points and to damage (for return)
	    this->setPoints(this->points + killBonus);
	    damage += killBonus;
	    //Call heal function to heal attacker if needed
	    this->heal();
	    if(this->achilles() == true)
            {  this->cutAchilles(false);
	    }
	 }  
      } 
   }
   //Return the damage
   return damage;
}


/****************************************************************************************
**Function: heal
**Description: if strength is less than 1/2 of starting returns to 1/2 of starting
**Pre-Conditions: hero object instantiated
**Post-Conditions: hero's strenght is a minimum of 1/2 starting strenght
****************************************************************************************/
void Hero::heal()
{  //Checks current strenght compared to 1/2 starting strenght 
   if((this->getStrength()) < (((this->startingStrength) / 2)))
   {  //If less than 1/2 starting strength, adds back to 1/2 starting strength
      this->setStrength( ((this->startingStrength) / 2) );
   }

}
