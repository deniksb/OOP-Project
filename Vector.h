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
	virtual~Vector();
	//getters
	double getVectorX()const { return vX;}
	double getVectorY()const { return vY; }
	double getVectorZ()const { return vZ;}
	//setters
	int setVectorX(double _x) { vX = _x; return 0; }
	int setVectorY(double _y) { vY = _y; return 0; }
	int setVectorZ(double _z) { vZ = _z; return 0; }
	
	//overloading operator =  
	Vector& operator=(const Vector&);
	//virtual Vector ins
	virtual std::ostream& ins(std::ostream&)const;
	//function for lenght of a vector <==> single vector
	double lenghtOfV()const;
	//direction of a vector
	Vector directionOfV()const;
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
	//overloading operator - Vectors
	Vector operator-(const Vector&)const;

	//finding the scalar product of 2 vectors
	double operator*(const Vector& rhs) const;

	//overloading operator^ векторно произведение
	Vector operator^(const Vector&)const;
	//overloading operator() triple scalar product
	double operator()(const Vector&,const Vector&)const;
	//projection of a vector a on b
	Vector Projection(const Vector &, const Vector &) const;
	
	virtual std::istream& ext(std::istream&);

private:
	//Point A, B, vector;
	double vX, vY, vZ;
};
//overloading operator* double*vector
Vector operator*(double,const Vector&);
std::istream& operator>>(std::istream&, Vector&);



#endif
