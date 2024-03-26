#ifndef POINT_H
#define POINT_H

class Point {
   public:
      Point():x(0),y(0) {};
      Point(double _x, double _y):x(_x),y(_y) {};
      void setX(double _x) { x = _x; };
      void setY(double _y) { y = _y; };
      double getX() { return x; };
      double getY() { return y; }; 
   private:
      double x;
      double y;
};


#endif
