// Modified by Nathan Smith 2/2/2016
// Original is copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch


// Template Stack class definition
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>
#include "Node.h"
#include "Book.h"
using namespace std;

template< class ItemType >
class Stack {
public:
   Stack();      // constructor
   ~Stack();     // destructor
   bool push( const ItemType & );
   ItemType pop();
   bool top( ItemType & );
   bool isEmpty() const;
   bool isFull() const;
   void print();
   ItemType search(const string);
   bool remove(const string);

private:
   Node< ItemType > *stackPtr;  // pointer to first node

};

// Default constructor
template< class ItemType >
Stack< ItemType >::Stack() 
{
	stackPtr = NULL;
}

// Destructor
template< class ItemType >
Stack< ItemType >::~Stack()
{
   Node< ItemType > *currentPtr;
   
   while ( stackPtr != NULL ) 
   {    
		currentPtr = stackPtr;
		stackPtr = stackPtr->nextPtr;
		delete currentPtr;
   }
   
}

// Insert a node at the front of the Stack
template< class ItemType >
bool Stack< ItemType >::push( const ItemType &value )
{
   Node< ItemType > *newPtr = new Node< ItemType>(value);

   if (newPtr == NULL)		//failure to allocate new node
	  return false;
   else 
   {
      newPtr->nextPtr = stackPtr;
      stackPtr = newPtr;
  	  return true;		// push is successful
   }
}

// Returns a node from the front of the list for use
template< class ItemType >
ItemType Stack< ItemType >::pop( )
{
   if ( isEmpty() )             // List is empty
      return NULL;             // delete unsuccessful
   else {
      Node< ItemType > *tempPtr = stackPtr;

      stackPtr = stackPtr->nextPtr;

	  return tempPtr->getInfo();    // delete is successful
   }
}

template< class ItemType >
bool Stack< ItemType >::top( ItemType & value  )
{
   if ( isEmpty() )             // List is empty
      return false;             // top is unsuccessful
   else {
     
      value = stackPtr->info;  // value is set to be data at top 
      return true;            // top is successful
   }
}

// Is the Stack empty?
template< class ItemType > 
bool Stack< ItemType >::isEmpty() const
	{ return (stackPtr == NULL); }

// Is the Stack full?
template< class ItemType > 
bool Stack< ItemType >::isFull() const 
{
	Node< ItemType > *newPtr = new Node< ItemType >;

   if (newPtr == NULL)		//failure to allocate new node
	   return true;

   else {
	   delete newPtr;
	   return false;
   }
}

// Prints the whole stack to standard output
template< class ItemType >
void Stack< ItemType >::print()
{
	Node< ItemType > *temp = stackPtr;

	if (!(isEmpty()))		//check for non-empty list
	{
		cout << "List of books:\n";
		do
		{
			cout << temp->getInfo();
			temp = temp->nextPtr;
			cout << endl;
		} while (temp != NULL);
		cout << endl << endl;
	}
}

// Searches the stack for an ID that matches
template< class ItemType >
ItemType Stack< ItemType >::search( const string id )
{
	Node< ItemType > *temp = stackPtr;
	if (!(isEmpty()))		//check for non-empty list
	{
		do
		{
			if (temp->getInfo().getID() == id)
				return temp->getInfo(); //book is found, return it
			temp = temp->nextPtr;
		} while (temp != NULL);
	}
	return Book(); //book not found
}

// Searches the stack for an ID that matches and then deletes it
template< class ItemType >
bool Stack< ItemType >::remove(const string id)
{
	Node< ItemType > *temp = stackPtr;
	Node< ItemType > *delete_this = NULL;
	string book_id;
	bool found = false;
	if (!(isEmpty()))		// check for non-empty list
	{
		if (temp->getInfo().getID() == id) // first item in list
		{
			found = true;
			delete_this = temp;
			stackPtr = temp->nextPtr;
			delete delete_this;
		}
		else
		{
			while (temp->nextPtr != NULL && found == false) // second item or later
			{
				book_id = temp->nextPtr->getInfo().getID();

				if (book_id == id)
				{
					found = true;
					delete_this = temp->nextPtr;
					if (delete_this->nextPtr)
						temp->nextPtr = delete_this->nextPtr; // connect the two
					else
						temp->nextPtr = NULL; // unless there's nothing afterward
					delete delete_this; // and delete
					break;
				}

				temp = temp->nextPtr;
			}
		}
	}
	return found;
}

#endif