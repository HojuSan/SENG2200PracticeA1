/*
Name: 				Juyong Kim
Subject: 			SENG1120
Assignment: 		Assignment1`
Code Description: 	has all the basic functions to create nodes in a linkedlist
*/

//Libraries
#include <iostream>															
#include <cstdlib>
#include "Node.h"

//NameSpace for simplicities sake
using namespace std;														

	//The non empty Constructor, stores the data of what was passed in or sets default recreateSentences to null
	Node::Node(const dataType& input, Node* nextInput, Node* previousInput)
	{
		data = input;													//Sets data to what was passed in
		next = nextInput;												//Sets next to what was passed in
		previous = previousInput;										//Sets previous to what was passed in
	}

	//The epmty Constructor
	Node::Node()
	{
		data = "";														//Sets data to be empty
		next = NULL;													//Sets next to NULL
		previous = NULL;												//Sets prev to NULL
	}

	//empty Deconstructor
	Node::~Node()
	{
		
	}
	
	//Sets the data in the node
	void Node::setData(const dataType& newData)
	{	
		data = newData;													//Changes the data to what was passed in
	}

	//Sets pointer to another node
	void Node::setNext(Node* newNext)
	{
		next = newNext;													//Sets the pointer to a new object, in this case a node
	}

	//Sets pointer to another node
	void Node::setPrevious(Node* newPrev)
	{
		previous = newPrev;												//Sets the pointer to a new object, in this case a node
	}

	//Returns the data stored in a node
	Node::dataType Node::getCurrent()const
	{
		return data;													//Returns data
	}

	//Returns the pointer of an object
	const Node* Node::getNext() const
	{
		return next;													//Returns next
	}

	//Returns the pointer of an object
	const Node* Node::getPrevious() const
	{
		return previous;												//Returns previous
	}

	//Returns the pointer of an object
	Node* Node::getNext()
	{
		return next;													//Returns next
	}

	//Returns the pointer of an object
	Node* Node::getPrevious()
	{
		return previous;												//returns previous
	}
