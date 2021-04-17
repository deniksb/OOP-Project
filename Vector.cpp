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

//printV() <==> prints the vector
int Vector::printV() {
	std::cout << "(" << getVectorX() << ", " << getVectorY() << "," << getVectorZ() << ")";
	return 0;
}
//virtual Vector ins
std::ostream& Vector::ins(std::ostream& out)const {
	out << "(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ")";
	return out;
}
//overloading operator <_cout_> << <_Vector_>
std::ostream& operator<<(std::ostream& lhs, const Vector& rhs) {
	return rhs.ins(lhs);
}
//overloading operator <c_Vector_>(double,double,double) 
Vector& Vector::operator()(double A_x, double A_y, double A_z, double B_x, double B_y, double B_z) {
	Point tmpA(A_x,A_y,A_z);
	Point tmpB(B_x,B_y,B_z);
	Vector tmpV(tmpA,tmpB);
	*this = tmpV;
	vector = tmpA + tmpB;
	return *this;
}

//function for lenght of a vector <==> единичен вектор
double Vector::lenghtOfV()const {
	return sqrt(pow(vector.getX(),2)+pow(vector.getY(),2)+pow(vector.getZ(),2));
}

//direction of a vector
Point Vector::directionOfV()const {
	if (lenghtOfV()==0)
	{
		throw VectorLengthException("Direction of this Vector has the Lenght of 0! There for this action can't be performed.");
	}
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

//parallelism of two vectors
bool Vector::arePararell(const Vector& v1)const {
	//x : v1 = y : v2 = z : v3
	if (lenghtOfV()==0 || v1.lenghtOfV()==0)
	{
		throw VectorLengthException("Vector lenght is 0! There for this action can't be performed. ");
	}
	return (vector.getX() / v1.getVectorX()) == 0 && (vector.getY() / v1.getVectorY()) == 0 && (vector.getZ() / v1.getVectorZ()) == 0;
}

//perpendicularity of two vectors
bool Vector::arePerpendicular(const Vector& v1)const {
	//x.v1 + y.v2 + z*v3 = 0
	if (lenghtOfV() == 0 || v1.lenghtOfV() == 0)
	{
		throw VectorLengthException("Vector lenght is 0! There for this action can't be performed. ");
	}
	return (vector.getX() * v1.getVectorX()) + (vector.getY() * v1.getVectorY()) + (vector.getZ() * v1.getVectorZ()) == 0;
}