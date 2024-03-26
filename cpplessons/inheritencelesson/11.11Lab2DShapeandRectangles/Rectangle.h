#pragma once
#include "Shape2D.h"
// Include the header that contains the Shape2D class

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape2D {
private:
    float width;
    float height;
public:
    Rectangle();
    Rectangle(float, float, float, float);
    float getWidth();
    float getHeight();
    void setWidth(float);
    void setHeight(float);
    void compArea();
};


#endif