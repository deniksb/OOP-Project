#ifndef _VECTOR_H
#define _VECTOR_H
#include "Point.h"
#include <cmath>
#include "VectorLengthException.h"

class Vector :public Point{
public:
	//constructors
	Vector();
	Vector(Point,Point);
	Vector(double, double, double,double, double, double);
	Vector(const Vector&);
	~Vector();
	//getters
	double getVectorX()const { return vector.getX();}
	double getVectorY()const { return vector.getY();}
	double getVectorZ()const { return vector.getZ();}
	//overloading operator =  
	Vector& operator=(const Vector&);
	//overloading operator <_Vector_>(double,double,double)
	Vector& operator()(double, double, double, double, double, double);
	//virtual Vector ins
	virtual std::ostream& ins(std::ostream&)const;
	//function for lenght of a vector <==> single vector
	double lenghtOfV()const;
	//direction of a vector
	Point directionOfV()const;
	//is it NULL vector
	bool isNullVector()const;
	//parallelism of two vectors
	bool arePararell(const Vector&)const;
	//perpendicularity of two vectors
	bool arePerpendicular(const Vector&)const;
	//printV() <==> prints the vector
	int printV();
private:
	Point A, B, vector;

};

#endif
