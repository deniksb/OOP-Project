#ifndef _EQUALPOINTEXCEPTION_HPP_
#define _EQUALPOINTEXCEPTION_HPP_
#include <iostream>
#include "Point.h"
#include "EqualPointException.hpp"

 class Triangle : public Point {
    public:
    Triangle(Point&, Point&, Point&);
    //namirame tipa na triugulnika TODO
    int findType() const{

        return 0;
    }
    private:
    Point point1, point2, point3;
};

#endif