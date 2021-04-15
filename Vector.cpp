#include "Vector.h"

//default constructor
Vector::Vector():A(Point(0,0,0)),B(Point(0,0,0)),vector(Point(0,0,0)){}

//Vector constructor with Point parameters Vector
Vector::Vector(Point _A, Point _B):A(_A), B(_B),vector(_A+_B){}

//Vector constructor with double parameters
Vector::Vector(double A_x, double A_y, double A_z, double B_x, double B_y, double B_z) {
	Point tmpA(A_x, A_y, A_z);
	Point tmpB(B_x, B_y, B_z);
	Vector tmpV(tmpA, tmpB);
	vector = tmpA + tmpB;
	*this = tmpV;
}

//copy constructor
Vector::Vector(const Vector& rhs):A(rhs.A),B(rhs.B),vector(rhs.vector){}

//destructor
Vector::~Vector() {}

//overloading operator <_Vector_> = <_vector_>
Vector& Vector::operator=(const Vector& rhs) {
	if (this!=&rhs)
	{
		A = rhs.A;
		B = rhs.B;
		vector = rhs.vector;
	}
	return *this;
}
//virtual Vector ins
std::ostream& Vector::ins(std::ostream& out)const {
	out << " A(" << A.getX() << "," << A.getY() << "," << A.getZ() << ")\n" << " B(" << B.getX() << "," << B.getY() << "," << B.getZ() << ")\n" << " vector AB(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ")\n";
	return out;
}
//overloading operator <_cout_> << <_Vector_>
std::ostream& operator<<(std::ostream& lhs, const Vector& rhs) {
	return rhs.ins(lhs);
}
//overloading operator <_Vector_>(double,double,double) 
Vector& Vector::operator()(double A_x, double A_y, double A_z, double B_x, double B_y, double B_z) {
	Point tmpA(A_x,A_y,A_z);
	Point tmpB(B_x,B_y,B_z);
	Vector tmpV(tmpA,tmpB);
	*this = tmpV;
	vector = tmpA + tmpB;
	return *this;
}

//function for lenght of a vector
double Vector::lenghtOfV()const {
	return sqrt(pow(vector.getX(),2)+pow(vector.getY(),2)+pow(vector.getZ(),2));
}

//direction of a vector
Point Vector::directionOfV()const {
	return Point(vector.getX() / (lenghtOfV()), vector.getY() / (lenghtOfV()), vector.getZ() / (lenghtOfV()));
}

//is it NULL vector
bool Vector::isNullVector()const {
	if (vector.getX() == 0 && vector.getY() == 0 && vector.getZ() == 0)
	{
		return true;
	}
	return false;
}