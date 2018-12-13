
/*
!!!!!!!!!!!!!!!!!!
including the .cpp at the end of the header never do unless it is template???
also to use the make file type in "make" not g++ -o that is calling the compiler directly
hense i got marked down for it. which is quite fair*/

#include <iostream>
#include <iomanip>      // std::setprecision
#include "Point.h"
#include "Node.h"

using namespace std;

int main()
{		
	cout << "start" << endl;
	Point one(12.234534,24.23415);

	//note you can't change a double
	//but you can change how it is printed or shown
	cout << fixed << setprecision(2) << one.getX() << endl;
	cout << fixed << setprecision(2) << one.getY() << endl;

	//printing
	cout << one.getP() << endl;
	one.printString();

	cout << "end" << endl;
	return 0;
}