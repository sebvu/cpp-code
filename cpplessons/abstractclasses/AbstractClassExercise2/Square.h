#ifndef SQUARE_H
#define SQUARE_H
#include "Figure.h"

    class Square : public Figure {
    private:
        double side;
    public:
        Square(double x, double y, double side) : Figure(x, y), side(side) {}
        void vertices() {
        cout << "The vertices of the square are: " << endl;
        cout << "(" << (location().X() - side / 2) << ", " << (location().Y() + side / 2) << ")  (" << (location().X() + side / 2) << ", " << (location().Y() + side / 2) << ")  " << endl;
        cout << "(" << (location().X() - side / 2) << ", " << (location().Y() - side / 2) << ")  (" << (location().X() + side / 2) << ", " << (location().Y() - side / 2) << ")  " << endl;
        }

        void draw() {
            cout << "A square with center ";
            location().print();
            cout << " side length " << side << endl;

        }
    };

#endif