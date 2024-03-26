//Include the header that contains the Rectangle class declaration
#include "Rectangle.h"

//Provide the implementation of the member functions of the Rectangle class below

Rectangle::Rectangle() : Shape2D(), width(0.0), height(0.0) {}

Rectangle::Rectangle(float cx, float cy, float width, float height) : Shape2D(cx, cy), width(width), height(height) {
    compArea();
}

float Rectangle::getWidth() {
    return width;
}

float Rectangle::getHeight() {
    return height;
}

void Rectangle::setWidth(float w) {
    width = w;
}

void Rectangle::setHeight(float h) {
    height = h;
}

void Rectangle::compArea() {
    setArea(width * height);
}