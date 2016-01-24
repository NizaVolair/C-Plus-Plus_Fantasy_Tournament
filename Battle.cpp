
/****************************************************************************************
 **Program Filename: Battle.hpp 
 **Author: Niza Volair
 **Date: 05-22-15
 **Description: Battle declaration for a hero fighting program allows hero pointers in 
 **two lists to fight and determine the winner
 **Input: Two queue linked lists of heros
 **Output: Messages about 1st 2nd and 3rd places winners and a list of losers
 ***************************************************************************************/
#include "Battle.hpp"
#include "Hero.hpp"
#include "StackList.hpp"
#include "QueueList.hpp"

using std::cout;
using std::cin;
using std::endl;


//Default constructori sets hero poinerts to null and points to zero
Battle::Battle()
{  first = second = third = fighter1 = fighter2 = 0;
   pts1 = pts2 = 0;
}

//Constructor sets queues to private variables, hero poinerts to null and points to zero
Battle::Battle(QueueList *one, QueueList *two)
{  team1 = one;
   team2 = two;
   first = second = third = fighter1 = fighter2 = NULL;
   pts1 = pts2 = 0;
}


/****************************************************************************************
**Function: fight
**Description: This method allows 2 queue list objects of heros to fight and determine 
**1st, 2nd, and 3rd place winners and a stack of losers and overall winning team
**Parameters: None
**Pre-Conditions: Battle object instantiated with 2 queue objects
**Post-Conditions: must determine winners and losers accurately
****************************************************************************************/
void Battle::fight()
{  //Make pointers to winner and loser to shorten if/else checks
   Hero * winner;
   Hero * loser;
   Hero * temp;

   //In loop fight heads of queues while neither queue is not empty
   while((! (team1->isEmpty()) ) && ( ! (team2->isEmpty()) ))
   {  //Get first two fighters from front of queues
      fighter1 = team1->getFront();
      fighter2 = team2->getFront();
       
      //Fight the two heros until one is dead
      while(((fighter1->getStrength()) > 0) && ((fighter2->getStrength()) > 0))
      {  pts1 += fighter1->attack(fighter2);
	 if((fighter2->getStrength()) > 0)
	 {  pts2 += fighter2->attack(fighter1);
	 }
      }
      //Fighter 1 is the winner if they have the most points
      //Note this doesn't mean they are alive and will continue to the next round
      if(fighter1->getPoints() > fighter2->getPoints())
      {	 winner = fighter1;
	 loser = fighter2;
      }
      //Fighter 2 wins with higher points or in case of a draw since fighter 2 went 2nd
      else
      {	 winner = fighter2;
	 loser = fighter1;
      }
      //If first pointer is empty second is too. The winner is first, loser is second
      if(! (first))
      {	 first = winner;
	 second = loser;
      }
      else
      {  //Check the points of first and second to winner's and replace if needed
      	 if(first->getPoints() < winner->getPoints())
	 {  third = second;
	    second = first;
	    first = winner;
	 }
      	 else if((second->getPoints() < winner->getPoints()) && (first != winner))
	 {  third = second;
	    second = winner;
	 }
	 //If third points are less than winner or there isn't a third, winner is third
	 else if (((third->getPoints() < winner->getPoints()) || (!third)) && 
		     (first != winner) && (second != winner))
	 {  third = winner;
	 }
	 //If third isn't winner, check if loser is second or third, replace as needed
	 if(third != winner)
	 {  if(second->getPoints() < loser->getPoints())
	    {  third = second;
	       second = loser;
	    }
	    else if(((third->getPoints() < loser->getPoints()) || (!third)) && (
		     second != loser))
	    {  third = loser;
	    } 
	 }
      }      

      //Check that the points winner is also the actual winner in terms of being alive
      //Note: this will most likely be the case but for exceptions, so swap if needed
      if(winner->getStrength() < 0)
      {  temp = loser;
         loser = winner;
	 winner = temp;
      }
      //Winner is added to the back of their queue and loser is added to loser stack
      if((winner->getTeam()) == 1)
      {  team1->addBack(winner);
      }
      else
      {  team2->addBack(winner);
      }
      //This is my favorite line of code
      losers.push(loser);
      
      //Remove the front of each queue
      team1->removeFront();
      team2->removeFront();
   }
}

/****************************************************************************************
**Function: show winners
**Description: This method displays 1st, 2nd, and 3rd place fighters
**Parameters: none
**Pre-Conditions: Battle object instantiated and fight method called on two queue objects
**Post-Conditions: Must check team points, pass winners to stack list and display results
****************************************************************************************/
void Battle::showWinners()
{  //Team 1 wins if they have more points
   if(pts1 > pts2)
   {  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEAM 1 WINS " << pts1;
      cout << " to " << pts2 << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   }
   //Team 2 wins for if they have more points
   else if (pts2 > pts1)
   {  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEAM 2 WINS " << pts2;
      cout << " to " << pts1 << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   }
   //If points are the same it is a draw
   else
   {  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TEAMS TIED " << pts2;
      cout << " to " << pts1 << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   }
   cout << endl;
   
   //If there was a thrid place winner add it to the winner stack
   if(third)
   {  winners.push(third);
   }
   //If there was a first place winner (which means there was also second place) add both
   if(first)
   {  winners.push(second);
      winners.push(first);
   }
   //Display winners list if it isn't empty
   if( ! (winners.isEmpty()) )
   {  //display list titled winner with the stack list display method
      winners.display("Winner ");
   }  
}



/****************************************************************************************
**Function: show losers
**Description: This method calls the display function on a stack of losing hero pointer
**Parameters: none
**Pre-Conditions: battle and stack objects must be instantiated
**Post-Conditions: Must call display and show results
****************************************************************************************/
void Battle::showLosers()
{  if( ! (losers.isEmpty()) )
   {  //display list titled loser with the stack list display method
      losers.display("Loser ");
   }  
}

