/*
this is a template 
*/
//Macro Guards
#ifndef NODE_H
#define NODE_H

//Libraries
#include <iostream>
#include <cstdlib>
#include <string>

//namespaces
using namespace std;
//templates
template <typename value_type>

class Node
{
    public:

    Node(const value_type& inputData = value_type(), Node<value_type>* previousInput = NULL, Node<value_type>* nextInput = NULL);
    
    ~Node();

    void setData(const value_type newData);
    		
    void setPrevious(Node<value_type>* newPrev);
    		
    void setNext(Node<value_type>* newNext);

    value_type& getData();
    		
    const value_type& getData() const;
    		
    Node<value_type>* getPrevious();
    		
    const Node<value_type>* getPrevious() const;
    		
    Node<value_type>* getNext();
    		
    const  Node<value_type>* getNext() const;
    		
    private:
    value_type data;              //data saved in node
    Node<value_type>* next;     //pointer of next node
    Node<value_type>* previous;     //pointer of previous

};

#endif