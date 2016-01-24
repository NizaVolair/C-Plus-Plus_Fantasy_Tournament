/**************************************************************************************
**Program Filename: Goblin.hpp
 **Author: Niza Volair
 **Date: 05-22-15
 ***************************************************************************************/
#ifndef GOBLIN_HPP
#define GOBLIN_HPP
#include "Hero.hpp"
#include <string>

using std::string;

class Goblin : public Hero
{  public:
      Goblin(string goblinName, int teamNum):
      Hero(3, 8, goblinName, "Goblin", 2, 6, 1,6, false, teamNum, 0){};
      int attack(Hero *defender);
};
#endif
