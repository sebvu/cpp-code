#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
     Shape (float cx=0, float cy=0)
        : center_x(cx), center_y(cy), area(0.0)
     {}
     float getCenter_x() {return center_x;}
     float getCenter_y() {return center_y;}
     float getArea() {return area;}
     void setCenter(float cx=0, float cy=0)
     {   center_x = cx; center_y = cy;}
     void setArea(float a) {area = a;}
     void printArea() { cout << "No area computed!" << endl;}

private:
     float center_x, center_y;
     float area;
};

#endif