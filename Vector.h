#ifndef _VECTOR_H
#define _VECTOR_H
#include "Point.h"
#include <cmath>

class Vector :public Point{
public:
	//constructors
	Vector();
	Vector(Point,Point);
	Vector(double, double, double,double, double, double);
	Vector(const Vector&);
	~Vector();
	//overloading operator =  
	Vector& operator=(const Vector&);
	//overloading operator <_Vector_>(double,double,double)
	Vector& operator()(double, double, double, double, double, double);
	//virtual Vector ins
	virtual std::ostream& ins(std::ostream&)const;
	//function for lenght of a vector
	double lenghtOfV()const;
	//direction of a vector
	Point directionOfV()const;
	//is it NULL vector
	bool isNullVector()const;
private:
	Point A, B, vector;
};

#endif
