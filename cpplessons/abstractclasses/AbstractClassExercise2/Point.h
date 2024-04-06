// Point.h

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

// a Point class to represent one 2D point
class Point
{
public:
	Point(double i=0, double j=0) : x(i), y(j) { }

	void print( ) const  { 
		cout << "(" << x << ", " << y << ")" << endl; 
	}

	void set_coord(double x, double y) 	{
		this->x = x;
		this->y = y;
	}
	
	double X() {return x;}
	double Y() {return y;}

private:
    double x, y;
};


#endif