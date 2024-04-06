#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"

    class Figure {
    private:
        Point center; // able to store a point object
    public:
        Figure(double x = 0, double y = 0) : center(x,y) {}

        Point location() const { return center; }

        void move(Point new_center) {
            center = new_center;
            draw();
        }

        virtual void draw() = 0;
    };

#endif