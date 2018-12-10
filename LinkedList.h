/*
Name: 				Juyong Kim
Subject: 			SENG1120
Assignment: 		Assignment1`
Code Description: 	Basically a header file that contains all the functions in LinkedList.cpp
*/

//MacroGuards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Libraries
#include "Node.h"							
#include <string>
#include <iostream>
#include <sstream>
#include <array>

//Stating the class
class LinkedList
{
	typedef string dataType;

	public:
		
		LinkedList();
		//Summary:			empty constructor for linked list
		//Precondition:		
		//Postcondition:	creates an empty linkedlist
		LinkedList(dataType data);
		//Summary:			creates a linkedlist with data saved into the nodes 
		//Precondition:		
		//Postcondition:	creats a linkedlist with recreateSentences

		~LinkedList();
		//Summary:			deconstructor
		//Precondition:		has a linkedlist to delete
		//Postcondition:	deletes linkedlist and sets remaining nodes to null

		void add(dataType data);
		//Summary:			seperated the sentence into words and saves them into individual nodes
		//Precondition:		linkedlist has been constructed and data has been inserted
		//Postcondition:	linkedlist with the sentence saved as individual sentence will have been created

		void addHead(dataType data);
		//Summary:			adds a new node to the head of the linkedlist
		//Precondition:		linkedlist exists
		//Postcondition:	adds a new node to the head of the linkedlist

		void addTail(dataType data);
		//Summary:			adds a new node to the tail of the linkedlist
		//Precondition:		linkedlist exists
		//Postcondition:	adds a new node to the tail of the linkedlist

		void removeHead();
		//Summary:			removes the head node of the linked list
		//Precondition:		linkedlist exists with a head
		//Postcondition:	linkedlist is reduced by one

		void removeTail();
		//Summary:			removes the tail node of the linked list
		//Precondition:		linkedlist exists with a tail
		//Postcondition:	linkedlist is reduced by one

		void removeCurrent();
		//Summary:			removes the current node of the linkedlist
		//Precondition:		linkedlist exists
		//Postcondition:	linkedlist is reduced by one

		void forward();
		//Summary:			moves the linked list forward
		//Precondition:		linkedlist needs to exist
		//Postcondition:	moves the linked list forward

		void backward();
		//Summary:			moves the linkedlist backwards
		//Precondition:		linkedlist needs to exist
		//Postcondition:	moves the linkedlist backwards

		void moveToHeadNode();
		//Summary:			moves the linkedlist to the head node
		//Precondition:		linkedlist needs to exist
		//Postcondition:	moves the linkedlist to the head node

		void moveToTailNode();
		//Summary:			moves the linkedlist to the tail node
		//Precondition:		linkedlist needs to exist
		//Postcondition:	moves the linkedlist to the tail node

		dataType retrieveCurrent();
		//Summary:			returns the dataa in the current node
		//Precondition:		linkedlist needs to exist and data must be in the node
		//Postcondition:	data in node is returned

		size_t getSize();
		//Summary:			returns the length of the linkedlist
		//Precondition:		linkedlist needs to exist
		//Postcondition:	returns the length of the linkedlist

		bool remove(dataType data);
		//Summary:			removes a word from a linkedlist
		//Precondition:		data must be in the linkedlist
		//Postcondition:	node with the word will be deleted

		string recreateSentence();
		//Summary:			concatenates all the nodes in a list into a string
		//Precondition:		linkedlist exists with words stored in them
		//Postcondition:	returns string in the form of a sentence
		
		void reverse();							//memory dump is happening
		//Summary:			reverses the linkedlist
		//Precondition:		linkedlist exists
		//Postcondition:	linkedlist has been reversed
	
	//Private variables or functions
	private:
		//head node
		Node* head;
		//tail node
		Node* tail;
		//current node
		Node* current;
		//size_t retains the number of nodes in the linked list
		size_t listLength;
};
	//Overloaded Operators
	
	//concatenates 2 Linked lists
	bool operator +=(LinkedList& sentence1, LinkedList& sentence2);
	
	//Prints out linkedLists
	ostream& operator << (ostream& out, LinkedList& target);
	
//#include "LinkedList.cpp"
#include "LinkedList.cpp"
#endif