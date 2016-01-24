/**************************************************************************************
**Program Filename: Shadow.hpp
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Shadow class header files 
 ***************************************************************************************/
#ifndef SHADOW_HPP
#define SHADOW_HPP
#include "Hero.hpp"
#include <string>

using std::string;

class Shadow : public Hero
{  public:
      Shadow(string shadowName, int teamNum):
      Hero(0, 12, shadowName, "Shadow", 2, 10, 1, 6, false, teamNum, 0){};
      int rollDefendDice();
};
#endif
