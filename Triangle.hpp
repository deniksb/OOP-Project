#include <iostream>
#include "Point.cpp"

class Triangle : public Point {
    public:
    Triangle(Point&,Point&,Point&);

    private:
    Point point1,point2,point3;

};