
/*
!!!!!!!!!!!!!!!!!!
including the .cpp at the end of the header never do unless it is template???
also to use the make file type in "make" not g++ -o that is calling the compiler directly
hense i got marked down for it. which is quite fair*/

#include <iostream>
#include <iomanip>      // std::setprecision
#include "Point.h"

using namespace std;

int main()
{		
//	double x = 12;
//	double y = 24;
	cout << "start" << endl;
	Point one(12,24);
//	one.setX(x);
//	one.setY(y);
	cout << one.getX() << endl;
	cout << one.getY() << endl;
	cout << one.getP() << endl;
	one.printString();

	cout << "end" << endl;
	return 0;
}