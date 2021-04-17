#include "Triangle.hpp"


Triangle::Triangle(Point & p1, Point& p2, Point& p3){
    if(p1 == p2){
        throw EqualPointException("Points 1 and 2 are matching!");
    }
    else if(p2 == p3){
         throw EqualPointException("Points 2 and 3 are matching!");
    }
    else if(p1 == p3){
          throw EqualPointException("Points 1 and 3 are matching!");
    }
    else {
        point1 = p1;
        point2 = p2;
        point3 = p3;
    }
}