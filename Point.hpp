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




private:
double x,y,z;

};