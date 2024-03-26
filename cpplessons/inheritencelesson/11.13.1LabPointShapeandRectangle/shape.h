#include point.h

#ifndef SHAPE_H
#define SHAPE_H

class Shape {   
   public:
      Shape();             //Default constructor, sets center coordinates to (0,0)
      Shape(Point c);      //Constructor to set center to other coordinates
      void setCenter(double _x, double _y); 
      Point getCenter();
      double getArea();          //Area not defined yet: return 0
      double getPerimeter();     //Perimeter not defined yet: return 0
   
   protected:
      Point center;
      double area;
      double perimeter;
};

#endif
