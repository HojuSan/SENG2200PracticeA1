
//Libraries 
#include "Point.h"

Point::Point()
{
    xValue = 0;
    yValue = 0;
    p = "";
}

Point::Point(double x,double y)
{
    xValue = x;
    yValue = y;
    stringstream stream;
    stream << fixed << setprecision(2) << "(" << getX() << "," << getY() << ")";
    p = stream.str();
}
//getters
double Point::getX()
{
    return xValue;
}
double Point::getY()
{
    return yValue;
}
string Point::getP()
{
    return p;
}
//note after point has been set
//printed value will not change even if i have set it
void Point::setX(double x)
{
    xValue = x;
}
void Point::setY(double y)
{
    yValue = y;
}
void Point::printString()
{
    cout << getP() << endl;
}