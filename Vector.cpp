#include "Vector.h"
#include "VectorLengthException.h"
//default constructor
Vector::Vector() :Point(), vX(0), vY(0), vZ(0) {}

//Vector constructor with Point parameters Vector
Vector::Vector(const Point& _A, const Point& _B) : Point(), vX(_B.getX() - _A.getX()), vY(_B.getY() - _A.getY()), vZ(_B.getZ() - _A.getZ()) {}

//Vector constructor with double parameters
Vector::Vector(double vectorX, double vectorY, double vectorZ) : Point(), vX(vectorX), vY(vectorY), vZ(vectorZ) {}

//copy constructor
Vector::Vector(const Vector& rhs) : Point(rhs), vX(rhs.vX), vY(rhs.vY), vZ(rhs.vZ) {}

//destructor
Vector::~Vector() {}

//overloading operator <_Vector_> = <_vector_>
Vector& Vector::operator=(const Vector& rhs) {
	if (this != &rhs)
	{
		Point::operator=(rhs);
		vX = rhs.vX;
		vY = rhs.vY;
		vZ = rhs.vZ;
	}
	return *this;
}

//printV() <==> prints the vector
int Vector::printV() {
	std::cout << "(" << vX << ", " << vY << "," << vZ << ")";
	return 0;
}
//virtual Vector ins
std::ostream& Vector::ins(std::ostream& out)const {
	out << "(" << vX << "," << vY << "," << vZ << ")";
	return out;
}
//overloading operator <_cout_> << <_Vector_>
std::ostream& operator<<(std::ostream& lhs, const Vector& rhs) {
	return rhs.ins(lhs);
}


//function for lenght of a vector <==> единичен вектор
double Vector::lenghtOfV()const {
	return sqrt(pow(vX, 2) + pow(vY, 2) + pow(vZ, 2));
}

//direction of a vector
Vector Vector::directionOfV()const {
	try
	{
		if (lenghtOfV() == 0)
		{
			throw VectorLengthException("Direction of this Vector has the Lenght of 0! There for this action can't be performed.");
		}
		return Vector(vX / (lenghtOfV()), vY / (lenghtOfV()), vZ / (lenghtOfV()));
	}
	catch (const std::exception& e )
	{
		std::cout << e.what() << std::endl;
		
	}
	
	return Vector();
}

//is it NULL vector
bool Vector::isNullVector()const {
	if (vX == 0 && vY == 0 && vZ == 0)
	{
		return true;
	}
	return false;
}

//parallelism of two vectors
bool Vector::arePararell(const Vector& v1)const {
	//x : v1 = y : v2 = z : v3

	try
	{
		if (lenghtOfV() == 0 || v1.lenghtOfV() == 0)
		{
			throw VectorLengthException("Vector lenght is 0! There for this action can't be performed. ");
		}
		double x = vX / v1.getVectorX();
		double y = vY / v1.getVectorY();
		double z = vZ / v1.getVectorZ();
		if (x == y && y == z && z == x) {
			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

//perpendicularity of two vectors
bool Vector::arePerpendicular(const Vector& v1)const {
	//x.v1 + y.v2 + z*v3 = 0
	try
	{
		if (lenghtOfV() == 0 || v1.lenghtOfV() == 0)
		{
			throw VectorLengthException("Vector lenght is 0! There for this action can't be performed. ");
		}
		return (vX * v1.vX) + (vY * v1.vY) + (vZ * v1.vZ) == 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}


//overloading operator + Vectors
Vector Vector::operator+(const Vector& rhs)const {
	return Vector(getVectorX() + rhs.getVectorX(), getVectorY() + rhs.getVectorY(), getVectorZ() + rhs.getVectorZ());
}
//overloading operator - Vectors
Vector Vector::operator-(const Vector& rhs)const {
	return Vector(getVectorX() - rhs.getVectorX(), getVectorY() - rhs.getVectorY(), getVectorZ() - rhs.getVectorZ());
}

//finding the scalar product of 2 vectors
double Vector::operator*(const Vector& rhs) const {

	return (this->getVectorX() * rhs.getVectorX()) + (this->getVectorY() * rhs.getVectorY()) + (this->getVectorZ() * rhs.getVectorZ());

}
//overloading operator^ vector*vector
Vector Vector::operator^(const Vector& rhs)const {
	return Vector(getVectorY() * rhs.getVectorZ() - getVectorZ() * rhs.getVectorY(), -getVectorX() * rhs.getVectorZ() + getVectorZ() * rhs.getVectorX(), getVectorX() * rhs.getVectorY() - getVectorY() * rhs.getVectorX());
}

//overloading operator* double*vector
Vector operator*(double r, const Vector& rhs) {
	return Vector(r * rhs.getVectorX(), r * rhs.getVectorY(), r * rhs.getVectorZ());
}
//overloading operator() mixed product
double Vector::operator()(const Vector& v, const Vector& w)const {
	return ((*this ^ v) * w);

}
//projection of a vector u on v
Vector Vector::Projection(const Vector& u, const Vector& v)const {
	return Vector((((u * v) / pow(v.lenghtOfV(), 2)) * v));
}

//virtual Vector ext
std::istream& Vector::ext(std::istream& in) {
	std::cout << " \n x = ";
	in >> vX;
	std::cout << "\n y = ";
	in >> vY;
	std::cout << "\n z = ";
	in >> vZ;
	std::cout << std::endl;
	return in;
}

//overloading right shift
std::istream& operator>>(std::istream& lhs, Vector& rhs) {

	return rhs.ext(lhs);

}

