/****************************************************************************************
**Program Filename: Hero.hpp 
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Abstract hero class header files 
 ***************************************************************************************/
#ifndef HERO_HPP
#define HERO_HPP
#include <string>

using std::string;

class Hero
{  protected:
      int armor;
      int strength;
      int startingStrength;
      string name;
      string type;
      int numAttackDice;
      int numAttackFaces;
      int numDefendDice;
      int numDefendFaces;
      bool achillesCheck;
      int team;
      int points;
      int killBonus;
   public:
      Hero();
      Hero(int, int, string, string, int, int, int, int, bool, int, int);
      void setArmor(int);
      void setStrength(int);
      void setName(string);
      void setType(string);
      void setNumAttackDice(int);
      void setNumAttackFaces(int);
      void setNumDefendDice(int);
      void setNumDefendFaces(int);
      void cutAchilles(bool);
      void setTeam(int);
      void setPoints(int);
      int getArmor();
      int getStrength();
      string getName();
      string getType();
      int getAttackDice();
      int getAttackFaces();
      int getDefendDice();
      int getDefendFaces();
      int getTeam();
      int getPoints();
      bool achilles();
      int rollAttackDice();
      virtual int rollDefendDice();
      virtual int attack(Hero *defender);
      void heal();
};
#endif
