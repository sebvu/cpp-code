#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include <iostream>

    class Circle : public Figure {
    private:
        double radius;
    public:
        Circle(double x, double y, double radius) : Figure(x, y), radius(radius) {}

        void draw() {
        cout << "A circle with center ";
        location().print();
        cout << " and radius " << radius << endl;
        }
    };

#endif