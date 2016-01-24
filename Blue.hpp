/**************************************************************************************
**Program Filename: Blue.hpp
 **Author: Niza Volair
 **Date: 05-06-15
 **Description: Blue class header files 
 ***************************************************************************************/
#ifndef BLUE_HPP
#define BLUE_HPP
#include "Hero.hpp"
#include <string>

using std::string;

class Blue : public Hero
{  public:
      Blue(string blueName, int teamNum):
      Hero(3, 12, blueName, "Blue", 2, 10, 3, 6, false, teamNum, 0){};
      int attack(Hero *defender);
};
#endif


