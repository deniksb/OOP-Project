#include "Tetrahedron.h"
using namespace std;
Tetrahedron::Tetrahedron():Point()
{
	A = Point(0, 0, 0);
	B = Point(0, 0, 0);
	C = Point(0, 0, 0);
	D = Point(0, 0, 0);
}

Tetrahedron::Tetrahedron(const Point & _A,const Point & _B,const Point & _C,const Point & _D):Point()
{
	try {
		if (_A == _B) {
			EqualPointException A("Points A and B are matching!");
			throw A;
		}
		else if (_A == _C) {
			EqualPointException B("Points A and C are matching!");
			throw B;
		}
		else if (_A == _D) {
			throw EqualPointException("Points A and D are matching!");
		}
		else if (_B == _C) {
			throw EqualPointException("Points B and C are matching!");
		}
		else if (_B == _D) {
			throw EqualPointException("Points B and D are matching!");
		}
		else if (_C == _D) {
			throw EqualPointException("Points C and D are matching!");
		}
		else {
		A = _A;
		B = _B;
		C = _C;
		D = _D;
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

Tetrahedron::Tetrahedron(const Tetrahedron & rhs) :Point(rhs), A(rhs.A), B(rhs.B), C(rhs.C), D(rhs.D)
{
}

Tetrahedron::~Tetrahedron()
{
}

Tetrahedron & Tetrahedron::operator=(const Tetrahedron & rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
		D = rhs.D;
	}
	return *this;
}

bool Tetrahedron::IsRegular() const
{
	Vector AB(A, B), AC(A, C), AD(A, D), BC(B, C), BD(B, D), CD(C, D);
	if (AB.lenghtOfV() == AC.lenghtOfV() == AD.lenghtOfV() == BC.lenghtOfV() == BD.lenghtOfV() == CD.lenghtOfV()) {
		return true;
	}
	 return false;
}

bool Tetrahedron::IsOrthogonal() const
{
	Vector AB(A, B), AC(A, C), AD(A, D), BC(B, C), BD(B, D), CD(C, D);
	if ((pow(AB.lenghtOfV(), 2) + pow(CD.lenghtOfV(), 2)) == (pow(AC.lenghtOfV(), 2) + pow(BD.lenghtOfV(), 2)) == (pow(AD.lenghtOfV(), 2) + pow(BC.lenghtOfV(), 2))) {
		return true;
	}
	return false;
}

double Tetrahedron::SurfaceArea() const
{
	Vector AB(A, B);
	if (IsRegular()) {
		return sqrt(3)*pow(AB.lenghtOfV(), 2);
	}
	else {
		Triangle ABD(A, B, D), ABC(A, B, C), BCD(B, C, D), ACD(A, C, D);
		return ABD.findArea() + ABC.findArea() + BCD.findArea() + ACD.findArea();
	}
}

double Tetrahedron::Volume() const
{
	Vector AB(A, B), AC(A, C), AD(A, D);
	double V = abs(0.16666666 * AB(AC, AD));
	return V;
}

std::ostream & Tetrahedron::ins(std::ostream & out) const
{
	//cout << "before point ins\n";
	//Point::ins(out);
	//cout << "after ins point\n";
	out << "Tetrahedron Point A: " << A << endl;
	out << "Tetrahedron Point B: " << B << endl;
	out << "Tetrahedron Point C: " << C << endl;
	out << "Tetrahedron Point D: " << D << endl;
	return out;
}
