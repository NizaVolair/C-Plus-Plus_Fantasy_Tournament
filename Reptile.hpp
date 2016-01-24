/**************************************************************************************
**Program Filename: Reptile.hpp
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Reptile class header files 
 ***************************************************************************************/
#ifndef REPTILE_HPP
#define REPTILE_HPP
#include "Hero.hpp"
#include <string>

using std::string;

class Reptile : public Hero
{  public:
      Reptile(string reptileName, int teamNum):
      Hero(7, 18, reptileName, "Reptile", 3, 6, 1, 6, false, teamNum, 0){};
};
#endif
