#include "Point.h"
//constructors
Point::Point(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}

Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

Point& Point::operator=(const Point& rhs) {

    if (this != &rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }

    return *this;
}
//Destructor
Point::~Point() {}
//overloading operator <_Point_> ==  <_Point_>: 1?0
bool Point::operator==(const Point& rhs) const {
    if (x == rhs.x && y == rhs.y && z == rhs.z) {
        return true;
    }
    return false;
}
//virtual Point ins
std::ostream& Point::ins(std::ostream& out)const{
    out << " (" << x << "," << y << "," << z << ")\n";
    return out;
}
//virtual Point ext
std::istream& Point::ext(std::istream& in) {
    std::cout << " \n x = ";
    in >> x;
    std::cout << "\n y = ";
    in >> y;
    std::cout << "\n z = ";
    in >> z;
    std::cout << std::endl;
return in;
    }
//overloading operator <_cout_> << <_Point_>  
std::ostream& operator<<(std::ostream& lhs, const Point & rhs) {
    return rhs.ins(lhs);
}
//operator <_cin_> >> <_Point_>
std::istream& operator>>(std::istream& lhs, Point& rhs) {
    return rhs.ext(lhs);
}
//overloading operator +
Point Point::operator+(const Point& rhs)const {
    Point tmpP(rhs.x-x,rhs.y-y,rhs.z-z);
    return tmpP;
    //return Point(rhs.x-x,rhs.y-y,rhs.z-z);
}