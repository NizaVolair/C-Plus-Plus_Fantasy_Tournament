/****************************************************************************************
**Program Filename: Blue.cpp
 **Author: Niza Volair
 **Date: 05-06-15
 **Description: Blue class inplimentation files 
 **Input: none
 **Output: integer representing damage
***************************************************************************************/
#include "Hero.hpp"
#include "Blue.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


/****************************************************************************************
**Function: attack
**Description: This is a method which allows an attacker to deduct points from defender's 
**strength depending on randomized dice rolls
**Parameters: Pointer to a hero (defender) 
**Pre-Conditions: two heros created, dice rolling functions created
**Post-Conditions: defender's strength is accurately changed and points are returned
*****************************************************************************************/
int Blue::attack(Hero *defender)
{  //Create variables for the atack and defense scores, damage and adjusted strength
   int attack, defense, newStrength;
   int damage = 0;

   //Use roll methods for defense and attack check for a cut achilles tendon
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
   {  //Use attack defense scores to find damage
      damage = ((attack -  defense) - (defender->getArmor()));
   }

   //The attack was not successful if  less than or equal to 0
   if(damage <= 0)
   {  damage = 0;
   }
   //If there was damage get new strength
   else
   {  newStrength = ((defender->getStrength()) - damage);
      defender->setStrength(newStrength);
      //Add damage to attackers points
      this->setPoints(points + damage);
      //If damage greater than strength declare death the defender has died
      //mend attacker achillies
      if(defender->getStrength() <= 0)
      {  //Add killer bonus to attackers points and adjust damage to include kill bonus
	 this->setPoints(points + killBonus);
	 damage += killBonus;
	 //Call heal function to heal attacker if needed
	 this->heal();
	 if(this->achilles() == true)
	 {  this->cutAchilles(false);
	 }
      }  
   } 
   //Return the damage
   return damage;
}
