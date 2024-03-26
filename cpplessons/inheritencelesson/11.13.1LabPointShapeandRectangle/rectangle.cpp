#include <iostream>
#include rectangle.h

//Add default constructor to set center coordinates to (0,0) and set width and length to 1
   
//Add constructor with parameters (Point, double, double)

//Add overloaded operator +

double Rectangle::getArea() 
{ 
   //FIX ME: compute area using private helper updateArea() and return area;
}

double Rectangle::getPerimeter() 
{ 
   //FIX ME: compute perimeter using private helper updateArea() and return perimeter;
}

//DO NOT CHANGE CODE BELOW
void Rectangle::updateArea()
{
   area = width * length;
}

void Rectangle::updatePerimeter()
{
   perimeter = 2 * (width + length);
}
   
void Rectangle::setLength(double l) { length = l; }
void Rectangle::setWidth(double w) { width = w; }

double Rectangle::getLength() { return length; }
double Rectangle::getWidth() { return width; }




