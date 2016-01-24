/****************************************************************************************
**Program Filename: Goblin.cpp
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: goblin class implimentation files 
 **Input: hero pointer for defender
 **Output: integer representing damage
 ***************************************************************************************/
#include "Hero.hpp"
#include "Goblin.hpp"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


/****************************************************************************************
**Function: attack (overridden method of the hero base class)
**Description: This method allows an attacker to deduct points from defender's strength
**depending on randomized dice rolls if Goblin gets a 12 roll defenders achillies is cut
**until one of them dies 
**Parameters: Pointer to a hero (defender)
**Pre-Conditions: two heros creater, dice rolling functions created
**Post-Conditions: defender's strength is accurately changed and points are returned
****************************************************************************************/
int Goblin::attack(Hero *defender)
{  //Create variables for the atack and defense scores, damage and adjusted strength
   int attack, defense, newStrength;
   int damage = 0;

   //Call roll methods for defense and attack
   attack = (this->rollAttackDice());

   //Check to see if attack is a 12, defender has tendon, and they are not a goblin
   if((attack == 12) && ((defender->achilles()) == false) && 
      (((defender->getType()) != "Goblin")))
   {  defender->cutAchilles(true);
      //Roll for defense and if Shadow evades tendon snap display message and heal achilles
      defense = (defender->rollDefendDice());
      if(defense == (-1)) 
      {   defender->cutAchilles(false);
      }
   }
   //Roll for normal defense
   else
   {   defense = (defender->rollDefendDice());
   }

   //Check for -1 flag for Shadow evasion
   if(defense == (-1))
   {  damage = 0;
   }
   else
   {  //Use attack defense scores to find damage
      damage = ((attack -  defense) - (defender->getArmor()));
      //The attack was not successful if  less than or equal to 0
      if(damage <= 0)
      {  damage = 0; 
      }
      //If there was damage print new strength
      else if(damage > 0)
      {  newStrength = ((defender->getStrength()) - damage);
         defender->setStrength(newStrength);
	 //Add damage to attackers points
	 this->setPoints(points + damage);
	 //If damage was greater than strength declare death and set choice to 'n' to stop battle
	 if(defender->getStrength() <= 0)
	 {  //Add killer bonus to attackers points and adjust damage to include kill bouns
	    this->setPoints(points + killBonus);
	    damage += killBonus;
	    //Call heal function to heal attacker if needed
	    this->heal();
	 }  
      } 
   }
   //Return the damage
   return damage;
}
