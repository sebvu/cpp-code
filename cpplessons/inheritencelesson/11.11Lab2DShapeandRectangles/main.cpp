#include <iostream>
using namespace std;

#include "Rectangle.h"


int main()
{
   Shape2D *p_shape1 = new Shape2D();
   Rectangle rec1 (1.0, 2.5, 45.5, 36.6);
   
   
   p_shape1->setCenter(2, 2);
   
   // fix the following
   cout << "The center of shape 1 is (" << p_shape1.center_x << ", " << p_shape1.center_y
        <<"), and its area is " << p_shape1.getArea() << "." << endl;
        
   rec1.setCenter(0, 0);
   rec1.setWidth(2.0);
   rec1.setHeight(3.0);
   rec1.compArea();
   
   cout << "The center of shape 2 is (" << rec1.getCenter_x() << ", " << rec1.getCenter_y()
        <<"), and its area is " << rec1.getArea() << "." << endl;
    
   return 0;
}
