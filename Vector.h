#ifndef _VECTOR_H
#define _VECTOR_H
#include "Point.h"
#include <cmath>
// #include "VectorLengthException.h"

class Vector :public Point{
public:
	//constructors
	Vector();
	Vector(const Point&, const Point&);
	Vector(double, double, double);
	Vector(const Vector&);
	~Vector();
	//getters
	double getVectorX()const { return vX;}
	double getVectorY()const { return vY; }
	double getVectorZ()const { return vZ;}
	//setters
	/*
	int setVectorX(double _x) { vX = _x; return 0; }
	int setVectorX(double _y) { vY = _y; return 0; }
	int setVectorX(double _z) { vZ = _z; return 0; }
	*/
	//overloading operator =  
	Vector& operator=(const Vector&);
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
	//overloading operator + Vectors
	Vector operator+(const Vector&)const;

	//finding the scalar product of 2 vectors
	double findScalarProduct(const Vector& rhs) const;

	//finding the cross product of 2 Vectors
	Vector findCrossProduct(const Vector& rhs) const;

private:
	//Point A, B, vector;
	double vX, vY, vZ;
};



#endif
