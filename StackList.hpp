/***************************************************************************************
 **Program Filename: StackList.hpp 
 **Author: Niza Volair
 **Date: 05-21-15
 **Description: Header files for class which produces a stack like list
 ***************************************************************************************/
#ifndef STACKLIST_HPP
#define STACKLIST_HPP
#include "Hero.hpp"
#include <iostream>
#include <cstdlib>


class StackList
{
   protected:
      //Declare a clas for the list node
      struct ListNode
      {   
	 Hero *obj;
         ListNode *next;
	 ListNode(Hero *obj1, ListNode *next1 = NULL)
	 {
	    obj = obj1;
	    next = next1;
	 }
      };
      ListNode *head;
   public:
      StackList() { head = NULL; } //Constructor
      ~StackList();  //Deconstructor
      void push(Hero *);
      Hero * peek();
      void pop();
      bool isEmpty();
      void display(string) const;
};

#endif
