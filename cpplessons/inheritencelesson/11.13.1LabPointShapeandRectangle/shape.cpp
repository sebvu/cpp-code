#include <iostream>
#include shape.h

using namespace std;

Shape::Shape():center(Point(0,0)) 
{
   area = 0;
   perimeter = 0;
}#include <iostream>
#include shape.h

using namespace std;

Shape::Shape():center(Point(0,0)) 
{
   area = 0;
   perimeter = 0;
}
   
Shape::Shape(Point c):center(c) 
{
   area = 0;
   perimeter = 0;
}

void Shape::setCenter(double _x, double _y)
{
   //FIX ME: set center to _x and _y
}

Point Shape::getCenter() { return center; }
double Shape::getArea() { return 0; }
double Shape::getPerimeter() { return 0; }


   
   
Shape::Shape(Point c):center(c) 
{
   area = 0;
   perimeter = 0;
}

void Shape::setCenter(double _x, double _y)
{
   //FIX ME: set center to _x and _y
}

Point Shape::getCenter() { return center; }
double Shape::getArea() { return 0; }
double Shape::getPerimeter() { return 0; }
