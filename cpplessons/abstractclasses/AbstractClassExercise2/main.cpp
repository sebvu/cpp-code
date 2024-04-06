#include "Figure.h"
#include "Circle.h"
#include "Square.h"

int main( )
{
    Circle c(1, 2, 3);
    Square s(4, 5, 6);
    Figure *f = &c, &g = s;

    f -> draw( );
    f -> move(Point(2, 2));

    g.draw( );
    g.move(Point(1,1));
       
    s.vertices( );
	
    return 0;
}
