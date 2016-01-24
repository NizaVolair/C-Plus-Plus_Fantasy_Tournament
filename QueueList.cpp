/****************************************************************************************
 **Program Filename: QueueList.cpp 
 **Author: Niza Volair
 **Date: 05-21-15
 **Description: Implimentation files for class which produces a queue like list
 **Input: None
 **Output: Integers which have been removed and a display of all integers in the list
 ***************************************************************************************/
#include "QueueList.hpp"
#include "Hero.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::endl;
using std::setw;
using std::left;


/****************************************************************************************
**Function: addBack 
**Description: adds an integer to the bottom of the list
**Parameters: an integer to be added 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is at the bottom of the list
*****************************************************************************************/
void QueueList::addBack(Hero *obj1)
{  ListNode *ptr = new ListNode(obj1);

   if(head == NULL)
   {  //make both the head and back equal to the new ptr since there is only one value
      head = ptr;
      back = ptr;
   }
   else
   {  //Make backs next point to the new ptr and its previous point to itself
      back->next = ptr;
      ptr->previous = back;

      //Make the pointer into the new back and set the next value to null
      back = ptr;
      back->next = NULL;
   }
}

/****************************************************************************************
**Function: getFront 
**Description: returns an integer from the head of the list
**Parameters: none 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is returned from the head of the list
*****************************************************************************************/
Hero * QueueList::getFront()
{  if(isEmpty())
   {  return 0;
   }
   else //Return head of list value
   {  return head->obj;
   }
}


/****************************************************************************************
**Function: removeFront 
**Description: removes an integer from the head of the list
**Parameters: none 
**Pre-Conditions: object instantiated
**Post-Conditions: the integer is removed from the head of the list
*****************************************************************************************/
void QueueList::removeFront()
{  if( ! (isEmpty()) )	//Check for empty list
   {  //garbage keeps track of origional head node to be deleted
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
bool QueueList::isEmpty()
{  //Return true if head is NULL i.e. list is empty
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
void QueueList::display() const
{
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Team " << team;
   cout << " Warriors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
   cout << left << setw(3) << "#";
   cout << left << setw(20) << "Name";
   cout << left << setw(14) << "Type"; 
   cout << left << setw(10) << "Armor";
   cout << left << setw(13) << "Strength";
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
**Function: ~QueueList (deconstructor) 
**Description: deletes all nodes in the list
**Parameters: none
**Pre-Conditions: object instantiated
**Post-Conditions: list is properly deleted and memory freed
*****************************************************************************************/
QueueList::~QueueList()
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
