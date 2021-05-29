#ifndef _POINT_H
#define _POINT_H
#include"Element.h"
#include <iostream>

class Point : public Element {
public:
	//constructors
	Point(double = 0, double = 0, double = 0);
	Point(const Point&);
	//destructor
	~Point();
	//overloading operator = 
	Point& operator=(const Point&);
	//overloading operator +
	Point operator+(const Point&)const;
	//print
	void print() {
		std::cout << "(" << x << "," << y << "," << z << ")";
	};
	//getters
	double getX()const { return x; }
	double getY()const { return y; }
	double getZ()const { return z; }
	//setters
	int setX(double _x) { x = _x; return 0; }
	int setY(double _y) { y = _y; return 0; }
	int setZ(double _z) { z = _z; return 0; }

	//operator Point == Point : 1?0
	bool operator==(const Point&) const;

	//vvirtual Point ins
	virtual std::ostream& ins(std::ostream&)const;
	//virtual point ext
	virtual std::istream& ext(std::istream&);
private:
	double x, y, z;

};
//operator <_cout_> << <_Point_>
std::ostream& operator<<(std::ostream& lhs, const Point& rhs);
//operator <_cin_> >> <_Point_>
std::istream& operator>>(std::istream&, Point&);
#endif