/****************************************************************************************
 **Program Filename: StackList.cpp 
 **Author: Niza Volair
 **Date: 05-21-15
 **Description: Implimentation files for class which produces a stack like list
 **Input: None
 **Output: Integers which have been removed and a display of all integers in the list
 ***************************************************************************************/
#include "StackList.hpp"
#include "Hero.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::endl;
using std::setw;
using std::left;


/****************************************************************************************
**Function: push
**Description: adds an integer to the head of the list
**Parameters: an integer to be added 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is at the head of the list
*****************************************************************************************/
void StackList::push(Hero * obj1)
{
   if(isEmpty())
   {  //Start list with num if list is empty
      head = new ListNode(obj1);
   }
   else
   {  //Insert node before every other node in the list
      head = new ListNode(obj1, head);
   }
}


/****************************************************************************************
**Function: peek
**Description: return an integer from the head of the list
**Parameters: none 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is returned from the head of the list
*****************************************************************************************/
Hero * StackList::peek()
{  if(isEmpty())
   {  return 0;
   }
   else
   {  //Return the value stored in head   
      return head->obj;
   }
}


/****************************************************************************************
**Function: pop
**Description: deletes a node from the head of the list
**Parameters: none 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is deleted from the head of the list
*****************************************************************************************/
void StackList::pop()
{  if( ! (isEmpty()) )	//Check for empty list
   {  //Garbage keeps track of origional head node to be deleted
      ListNode *garbage = head;
      //Head becomes next node
      head = head-> next;
      //Delete the "garbage" node
      delete garbage;
   }
}


/****************************************************************************************
**Function: isEmpty 
**Description: returns true if empty and false otherwise
**Parameters: none
**Pre-Conditions: object instantiated
**Post-Conditions: true or false return
*****************************************************************************************/
bool StackList::isEmpty()
{  //Return true is head i.e. list is empty
   if(head == NULL)
   {  return true;
   }
   else
   {  return false;
   }
}


/****************************************************************************************
**Function: display 
**Description: displays all integers in the list
**Parameters: none
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is display head first 
*****************************************************************************************/
void StackList::display(string name) const
{
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << name;
   cout << " Warriors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
   cout << left << setw(3) << "#";
   cout << left << setw(20) << "Name";
   cout << left << setw(14) << "Type"; 
   cout << left << setw(10) << "Armor";
   cout << left << setw(13) << "Strength";
   cout << left << setw(9) << "Team";
   cout << left << setw(11) << "Points";
   cout << left << setw(20) << "Status\n" << endl;
 
   //Display each warrior and their  stats
   ListNode *nodePtr = head; //Start at head of the list
   int num = 1;
   while(nodePtr != NULL)
   {
      cout << left << setw(3) << num;
      cout << left << setw(20) << (nodePtr->obj->getName());
      cout << left << setw(14) << (nodePtr->obj->getType()); 
      cout << left << setw(10) << (nodePtr->obj->getArmor());
      cout << left << setw(13) << (nodePtr->obj->getStrength());
      cout << left << setw(9) << (nodePtr->obj->getTeam());
      cout << left << setw(11) << (nodePtr->obj->getPoints());

      if((nodePtr->obj->getStrength()) > 0)
      {	 cout << left << setw(10) << "Alive\n" << endl;
      }
      else
      {	 cout << left << setw(10) << "Dead\n" << endl;
      }
      //Move on to the next node
      nodePtr = nodePtr->next;
      num++;
   }
   cout << endl << endl;
}


/****************************************************************************************
**Function: ~StackList (deconstructor) 
**Description: deletes all nodes in the list
**Parameters: none
**Pre-Conditions: object instantiated
**Post-Conditions: list is properly deleted and memory freed
*****************************************************************************************/
StackList::~StackList()
{
   ListNode *nodePtr = head; //Start at head of the list (last in)
   while(nodePtr != NULL)
   {  //garbage keeps track of node to be deleted
      ListNode *garbage = nodePtr;
      //Move on to the next node, if any
      nodePtr = nodePtr-> next;
      //Delete the "garbage" node
      delete garbage;
   }
}


