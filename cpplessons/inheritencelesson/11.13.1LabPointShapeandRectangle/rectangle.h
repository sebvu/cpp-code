#include shape.h

#ifndef RECT_H
#define RECT_H

class Rectangle: public Shape {      
   public:
      //Add default constructor to set center coordinates to (0,0) and set width and length to 1
      //Add constructor with parameters (Point, double, double)
      void setLength(double l);                 //Changes length and updates area and perimeter
      void setWidth(double w);                  //Changes width and updates area and perimeter
      double getLength(); 
      double getWidth();
      double getArea();                         //Overridden from Shape
      double getPerimeter();                    //Overridden from Shape
      Rectangle operator+(const Rectangle &other);

   private:
      double length;
      double width;
      void updateArea();
      void updatePerimeter();
};

#endif
