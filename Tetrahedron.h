#ifndef _TETRAHEDRON_H
#define _TETRAHEDRON_H
#include "Point.h"
#include"Triangle.hpp"
#include"Vector.h"
#include"EqualPointException.hpp"
class Tetrahedron : public Point
{
public:
	Tetrahedron();//def
	Tetrahedron(Point&, Point&, Point&, Point&);//param
	Tetrahedron(const Tetrahedron &);//copy
	~Tetrahedron();//destructor
	Tetrahedron& operator=(const Tetrahedron&);
	// check if a tetrahedron is regular
	bool IsRegular()const;
	//check if a tetrahedron is Orthogonal
	bool IsOrthogonal()const;
	//Surface area
	double SurfaceArea()const;
	//Volume
	double Volume()const;

	virtual std::ostream& ins(std::ostream&)const;
private:
	Point A, B, C, D;
};

#endif