/*
Name: 				Juyong Kim
Subject: 			SENG1120
Assignment: 		Assignment1
Code Description: 	Basically a header file that contains all the functions in Node.cpp
*/

//MacroGuards
#ifndef NODE_H
#define NODE_H

//Libraries 
#include <string>
#include <cstdlib>

//Namespaces, for easier coding
using namespace std;

//Stating the class
class Node
{
	//Stating public functions/variables within the Node.cpp
	public:
	
		//Stating public variables, in this case typedef as string
		typedef string dataType;
		//Constructor
		Node(const dataType& input = NULL, Node* nextInput = NULL, Node* previousInput = NULL);		
		Node();
		//Deconstructor
		~Node();
		
		void setData(const dataType& newData);
		
		void setNext(Node* nextrecreateSentence);	
		
		void setPrevious(Node* previousrecreateSentence);
		
		dataType getCurrent() const;
		
		Node* getNext();
		
		Node* getPrevious();
		
		const Node* getNext() const;
		
		const Node* getPrevious() const;
	
	private:
	
		//Variable that stores data in the node
		dataType data;
		
		//Variable that stores the data in the next node
		Node* next;
		
		//Variable that stores the data in the previous node
		Node* previous;

};
#endif