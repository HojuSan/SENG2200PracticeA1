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
		LinkedList(dataType data);
		~LinkedList();
		void add(dataType data);
		void addHead(dataType data);
		void addTail(dataType data);
		void removeHead();
		void removeTail();
		void removeCurrent();
		void forward();
		void backward();
		void moveToHeadNode();
		void moveToTailNode();
		dataType retrieveCurrent();
		size_t getSize();
		bool remove(dataType data);
		string recreateSentence();		
		void reverse();							
	
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
	
#endif