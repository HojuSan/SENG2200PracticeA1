
//Libraries
#include "LinkedList.h"

using namespace std;

	//LinkedList Empty Constructor sets recreateSentences to Null and list length to zero
	LinkedList::LinkedList()
	{
		head = NULL;														
		tail = NULL;														
		current = NULL;														
		listLength = 0;													
	}
	
	//LinkedList Constructor with parameters 
	LinkedList::LinkedList(dataType data)									//recieves string from demo file
	{
		head = NULL;														
		tail = NULL;														
		current = NULL;														//sets list length to zero
		listLength = 0;													

		add(data);															//sends string to add so the words can be saved in individual nodes
	}
	
	//Deconstructor, starts removehead function that deletes the head then
	//cycles through the linkedlist till it reaches null then sets tail and
	//current to null
	LinkedList::~LinkedList()
	{	
		while(head!=NULL)													
		{
			removeHead();													
		}
		tail = NULL;														
		current = NULL;														
	}
	//adds value to a node then concatenates to back of linkedlist
	void LinkedList::add(dataType data)
	{
		int i = 0;															//counter						
		string tempString = "";												//temporary string to save words
		Node* nullEndNode = NULL;
		
		while(data.length() > 0)											//while loop to cycle through the string	
		{

			if(data.find(" ") != string::npos)								//looks for spaces which signifies a new word usually
			{
				i = data.find(" ");											//finds the position of the space		

				tempString = data.substr(0,i);								//saves word into the temp string

				istringstream buffer(tempString);							//istringstream buffer converts the data to whatever datatype needed, in this case string
				dataType tempAddString;										//create a new temp string in this case
				buffer >> tempAddString;									//saves word into tempADDSTRING

				addTail(tempAddString);										//adds new word to tail
				data = data.substr((i+1), string::npos);					//sets the new substring without the word and resaves the data
			}
			else 															
			{
				i = data.length();											//finds the length of the word

				tempString = data.substr(0,i);								//saves word into tempstring

				istringstream buffer(tempString);							//from here does the same thing as above
				dataType tempAddString;
				buffer >> tempAddString;									

				addTail(tempAddString);									

				data = data.substr((i), string::npos);						//basically sets data to something empty
			}
		}

		
	}

	//adds data to the head of the linkedlist
	void LinkedList::addHead(dataType data)
	{
		
		Node* headTemp = new Node(data);									//creates a new temporary node				

		head->setPrevious(headTemp);										//sets new head as previous
		headTemp->setNext(head);											//sets current head to next node

		head = headTemp;													//then sets recreateSentences in temporary node to the new head
		listLength++;														//increases list length
		
		delete headTemp;													//deletes temporary head
		headTemp = NULL;													//then sets it to null
		
	}

	//adds node with data to the tail of the linkedlist
	void LinkedList::addTail(dataType data)
	{

		if(listLength == 0)													//if listlink has nothing in it		
		{
			head = new Node(data);											//sets head current tail to data and increases list length
			tail = head;													
			current = head;													
			listLength++;													
		}
		else																
		{
			Node* tailTemp = new Node(data);								//create new temporary node

			tail->setNext(tailTemp);										//new data is set to the end of the list
			tailTemp->setPrevious(tail);									//from the new tail the old tail is set to previous

			tail = tailTemp;												//set the new tail
			listLength++;													//increases list length
			
			tailTemp = NULL;												//sets the tailTemp to null										
		}
	}

	//removes the head node of the linked list
	void LinkedList::removeHead()
	{

		if(listLength == 0)													//if listLength is zero just return									
		{
			return;															
		}
		else if (listLength == 1)											//if listLength is 1 means only one node, set everything to null
		{
			delete head;													
			head = NULL;													
			tail = NULL;													
			current = NULL;													
			listLength--;													//reduce listLength to 0
			return;															
		}
		else																
		{
			Node* headTemp = head;											//create new node, saves head into headTemp
			head = headTemp->getNext();										//saves the next node as the new head
			
			delete headTemp;												//deletes headtemp and sets it to null									
			headTemp = NULL;	

			listLength--;													//reduces listLength by 1
		}

	}

	//removes the tail node of the linkedlist
	void LinkedList::removeTail()
	{
		if(listLength == 0)													//if listLength is zero just return	
		{
			return;															
		}
		else if (listLength == 1)											//if listLength is 1 means only one node, set everything to null
		{
			delete head;												
			head = NULL;													
			tail = NULL;													
			current = NULL;												
			listLength--;												
			return;															
		}
		else																
		{
			Node* tailTemp = tail;											//creates new node, saves tail into tailTemp			
			tail = tailTemp->getPrevious();									//saves previous node as the new tail
			
			delete tailTemp;												//delets tailTemp sets it to null										
			tailTemp = NULL;		

			listLength--;													//reduces listLength by one
		}
	}

	//removes the current node of the linkedlist
	void LinkedList::removeCurrent()
	{
		if(listLength == 0)													//if listLength is zero just return				
		{
			return;															
		}
		else if(listLength == 1)											//if listLength is 1 means only one node, set everything to null		
		{
			delete head;												
			head = NULL;													
			tail = NULL;													
			current = NULL;					
			
			listLength--;						
			
			return;															
		}
		else																
		{
			Node* currentTemp = current;									
			Node* nextTemp = current->getNext();							//create three nodes one for current next previous			
			Node* previousTemp = current->getPrevious();					//saves recreateSentences accordingly		
		
			//if the current is the tail just delete tail
			if(currentTemp == tail)										
			{
				removeTail();												
			}
			//if the current is the head then delete head
			else if(currentTemp == head)									
			{
				removeHead();											
			}
			
			else															
			{
				previousTemp->setNext(nextTemp);							//previous points to the new next node	
				nextTemp->setPrevious(previousTemp);						//the new next node points to the new previous node		
				current = currentTemp->getNext();							//next is saves into the current

				delete currentTemp;											//deletes node sets it to null the decreases listLength by one									
				currentTemp = NULL;	
				listLength--;	
			}
		}

	}

	//Changes the current pointer to the next node
	void LinkedList::forward()
	{
		current = current->getNext();										//Sets the current pointer to the next node
	}

	//Changes the current pointer to the prev node
	void LinkedList::backward()
	{
		current = current->getPrevious();									//Sets the current pointer to the prev node
	}
	
	//Changes the current pointer to the head
	void LinkedList::moveToHeadNode()
	{
		current = head;														//Sets the current pointer to the head
	}

	//Changes the current pointer to the tail
	void LinkedList::moveToTailNode()
	{
		current = tail;														//Sets the current pointer to the tail
	}

	//Returns the data in the current node
	LinkedList::dataType LinkedList::retrieveCurrent()
	{
		return (current->getCurrent());										//Returns the data stored in the current node
	}

	//Returns the size of the list
	size_t LinkedList::getSize()
	{	
		return listLength;													//Returns the size of the list
	}

	//Removes all instances of a word in the list
	bool LinkedList::remove(string data)
	{
		moveToHeadNode();													//Calls the moveToHeadNode function

		if(listLength == 0)													//If the list is empty
		{
			return false;													//Return false, which will end the function
		}
		for(int i = 0; i < listLength;)										//For loop that runs for the number of nodes in the list
		{
			if(data == current->getCurrent())								//If the data in the current node equals the data passed in 
			{
				removeCurrent();											//Calls the removeCurrent function
				moveToHeadNode();											//Calls the moveToHeadNode function
				i = 0;														//Sets i to 0, which will restart to the for loop
			}
			else if(current == tail)										//If the current node is the tail
			{
				return true;												//return true
			}
			else															//If not												
			{
				forward();													//Moves the next node
				i++;														//increase i by one
			}
		}
		return true;														//Returns true
	}

	//Concatenates all the nodes in a list into a string
	string LinkedList::recreateSentence()
	{
		dataType stringList = "";											//Creates a temp string
		moveToHeadNode();													//Calles the moveToHeadNode function
		
		if(listLength == 0)													//If the list is empty
		{
			stringList = "List is empty";									//Sets this message to the string
		}
		else																//if there is one or more nodes
		{
			for(int i = 0; i < listLength; i++)								//For loop that runs for the number of nodes in the list
			{

				stringList = stringList + current->getCurrent() + " "; 		//Concatenates the nodes in to one string
				forward();													//Moves to the next node
			}
		}
		
	return stringList;														//Returns the list
	}
	
	//function that reverses the linkedlist using arrays
	//on a side note this took way to long to make work
	void LinkedList::reverse()
	{
		string reverseList [listLength];									//makes an array with the length of the listLength,saves strings
		dataType temp;														//temporary substring
		int t = getSize(); 													//will be used as a counter later
		moveToHeadNode();													//function that moves the current to the head
		
		for(int i = 0; i < listLength; i++)
		{
			temp = current->getCurrent();									//sets the current string into temp string
			reverseList[i] = temp;											//saves temp string into the array
			forward();														//moves current forward in the linkedlist
		}
		
		moveToHeadNode(); 													//set current to the head node
		
		//note to me this is actually a valid way of writing this
		for(t < 0; t--;) 													//dont use --t EVER AGAIN
		{
			temp = reverseList[t];											//saves value in array to temp string
			current->setData(temp);											//sets the data at current
			forward();														//moves forward
		}
	}
	
	
	//On another side note i don't know why this function isn't working
	//could you tell me why it core dumps?
	//its finishes the program then core dumps, ive tried everything and i just want to know
	// the solution to the problem that wasted 5 hours of my life. If you could kind marker
/*	void LinkedList::reverse()
	{
		Node* currentTemp; 
		Node* previousTemp;
		Node* nextTemp;
		
		moveToHeadNode();
		
		currentTemp = head;
		
		head = tail;
		tail = currentTemp;
		
		while(current)
		{
			previousTemp = current->getPrevious();
			nextTemp = current->getNext();
			
			current->setNext(previousTemp);
			current->setPrevious(nextTemp);
			
			current = current->getPrevious();
		}
		currentTemp = NULL;
		previousTemp = NULL;
		nextTemp = NULL;
	}
/**/

	//Overloaded += operator for Concatenating two lists together
	bool operator +=(LinkedList& sentence1, LinkedList& sentence2)
	{
		int i=0;															//Creates an int, sets it to 0
		string temp = "";													//Creates a temp string

		if(sentence1.getSize() == 0 || sentence2.getSize() == 0)			//If either of the lists is zero
		{
			return false;													//Return false, which will end the function
		}
		else																//If both lists have at least one node each
		{
			sentence2.moveToHeadNode();										//linkedlist2 Calls the moveToHeadNode function

			while(i < sentence2.getSize())									//While loop that runs for the number of nodes in linkedlist2		
			{
				temp = sentence2.retrieveCurrent();							//Sets the temp string to the data in the current node of linkedlist2
				sentence1.addTail(temp);									//Adds the data to the tail of linkedlist1
				sentence2.forward();										//Move to the next node in linkedlist2
				i++;														//increase i by one
			}
		}
		return true;														//Return true
	}

	//Overloaded << operator for printing the entire list
	ostream& operator<<(ostream& out, LinkedList& target)
	{
		
		out << target.recreateSentence();												//Calls the recreateSentence function, and send that to the out stream
		return out;															//Returns out
	}


