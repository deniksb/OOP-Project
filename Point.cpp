#include "Point.hpp"

//constructors
Point::Point(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
Point::Point(const Point& rhs):x(rhs.x),y(rhs.y),z(rhs.z){}


Point& Point::operator=(const Point& rhs){

    if(this != &rhs){
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }

    return *this;
}

Point::~Point(){}



bool Point::operator==(const Point& rhs) const{
        if(x == rhs.x && y == rhs.y && z == rhs.z){
            std::cout<< "1" << std::endl;
            return true;
        }
        std::cout<< "0" << std::endl;
        return false;
}

double Point::getX() const{
    return x;

}
double Point::getY() const{
    return y;
}
double Point::getZ() const{
    return z;
}










