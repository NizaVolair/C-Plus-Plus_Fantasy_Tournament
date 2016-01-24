/****************************************************************************************
 **Program Filename: Battle.hpp 
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Battle declaration for a hero fighting program allows hero pointers in 
 **two lists to fight and determine the winners and losers
 **Input: Two queue linked lists of heros
 **Output: Messages about 1st 2nd and 3rd places, winning team, list of winners and losers
 ***************************************************************************************/
#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "Hero.hpp"
#include "StackList.hpp"
#include "QueueList.hpp"

using std::cout;
using std::cin;
using std::endl;

class Battle
{  private:
      Hero *first;
      Hero *second;
      Hero *third;
      Hero *fighter1;
      Hero *fighter2;
      int pts1;
      int pts2;
      QueueList * team1;
      QueueList * team2;
      StackList losers;
      StackList winners;
   public:
      Battle();
      Battle(QueueList *, QueueList *);
      void fight();
      void showWinners();
      void showLosers();
};

#endif
