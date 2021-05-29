#pragma once
#include <iostream>
#include "Point.h"
#include"EqualPointException.h"
#include"Vector.h"

class Triangle : public Point {
public:
	Triangle();
	Triangle(const Point&,const Point&,const Point&);
	Triangle(const Triangle &);
	virtual~Triangle();
	Triangle& operator=(const Triangle &);

	//namirame tipa na triugulnika
	int findType() const;

	//namirame liceto na triugulnika
	double findArea() const;

	//namirame perimetura na triugulnika
	double findPerimeter() const;

	//namirame medicentura na triugulnika
	Point findMedicenter() const;

	//operator == Point==Triangle
	friend bool operator==(const Triangle& lhs, const Point& rhs);

	//getters for the 3 points of the triangle
	Point getA() const {
		return point1;
	}
	Point getB() const {
		return point2;
	}
	Point getC() const {
		return point3;
	}




private:
	Point point1, point2, point3;

};
std::ostream &operator<<(std::ostream&, const Triangle&);