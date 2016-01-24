/****************************************************************************************
 **Program Filename: QueueList.hpp 
 **Author: Niza Volair
 **Date: 05-21-15
 **Description: Header files for class which produces a queue like list
 ***************************************************************************************/
#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP
#include "Hero.hpp"
#include <iostream>
#include <cstdlib>


class QueueList
{
   protected:
      //Declare a class for the list node
      int team;
      struct ListNode
      {   
	 Hero *obj;
         ListNode *next;
	 ListNode *previous;
	 ListNode(Hero *obj1, ListNode *previous1 = NULL, ListNode *next1 = NULL)
	 {
	    obj = obj1;
	    previous = previous1;
	    next = next1;
	 }
      };
      ListNode *head;
      ListNode *back;
   public:
      QueueList(int teamNum) { head = NULL, back = NULL, team = teamNum; } //Constructor
      ~QueueList();  //Deconstructor
      void addBack(Hero *);
      Hero * getFront();
      void removeFront();
      bool isEmpty();
      void display() const;
};
#endif
