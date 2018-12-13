/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
#include "Node.h"

//constructor
template<typename value_type>
Node<value_type>::Node(const value_type& inputData, Node<value_type>* previousInput, Node<value_type>* nextInput)
{
    data = inputData;                                     //sets data
    next = nextInput;                                 //sets left child
    previous = previousInput;    
}

//deconstructor
template<typename value_type>
Node<value_type>::~Node()
{
    previous = NULL;                                      //sets left child to null
    next = NULL;                                      //sets right child to null 
}

//sets data in node
template<typename value_type>
void Node<value_type>::setData(const value_type newData)
{
    data = newData;                                     //sets data
}

//set previous
template<typename value_type>
void Node<value_type>::setPrevious(Node<value_type>* newPrev)
{
    previous = newPrev;                                 //sets previous
}

//sets next
template<typename value_type>
void Node<value_type>::setNext(Node<value_type>* newNext)
{
    next = newNext;                                 //sets next
}

//up to here

//retrieves data from node
template<typename value_type>
value_type& Node<value_type>::getData()
{
    return data;                                        //return data
}

//retrieves data from node
template<typename value_type>
const value_type& Node<value_type>::getData() const
{
    return data;                                        //return data
}

//retrieves data from left child node
template<typename value_type>
Node<value_type>* Node<value_type>::getPrevious()
{
    return previous;                                      //return left child data
}

//retrieve data from left child node
template<typename value_type>
const Node<value_type>* Node<value_type>::getPrevious() const
{
    return previous;                                      //return left child data
}

//retrieves data from right child node
template<typename value_type>
Node<value_type>* Node<value_type>::getNext()
{
    return next;                                      //return right child data
}

//retrieve data from right child node
template<typename value_type>
const  Node<value_type>* Node<value_type>::getNext() const
{
    return next;                                      //return right child data
}