/****************************************************************************************
**Program Filename: Barbarian.hpp
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: barbarian class header files 
 ***************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Hero.hpp"
#include <string>

using std::string;

class Barbarian : public Hero
{  public:
      Barbarian(string barbarianName, int teamNum):
      Hero(0, 12, barbarianName, "Barbarian", 2, 6, 2, 6, false, teamNum, 0){};
};
#endif
