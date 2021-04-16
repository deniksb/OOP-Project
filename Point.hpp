#include <iostream>

class Point{
public:
//constructors
Point(double=0,double=0,double=0);
Point(const Point&);

//overloading = operator
Point& operator=(const Point&);

//destructor
virtual ~Point();

//overloading = operator
bool operator==(const Point&) const;

double getX() const;
double getY() const;
double getZ() const;




protected:
double x,y,z;

};