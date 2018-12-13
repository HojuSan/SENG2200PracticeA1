/*
1.has two double precision floating point values for x and y format is 4.2f
2.has a method that calculates distance from current point to origin point(needs a linked list)
3.has a method that outputs double point into a string
*/

#ifndef POINT_H
#define POINT_H

//Library
#include <string>           //string
#include <cstdlib>
#include <cmath>
#include <iostream>         //cout cin
#include <sstream>          //double to string
#include <iomanip>          // std::setprecision

using namespace std;

class Point
{
	public:

    Point();
    Point(double x,double y);
    double getX();
    double getY();
    string getP();
    void setX(double x);
    void setY(double y);
    void printString();

    private:

    double xValue;
    double yValue;
    string p;       //(x,y) point saved in string value
    double d;       //point distance from origin
};
#endif