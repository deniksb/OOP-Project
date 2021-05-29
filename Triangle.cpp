#include "Triangle.hpp"
#include "Vector.h"
#include "EqualPointException.hpp"
using namespace std;

Triangle::Triangle():Point(0,0,0)
{
	point1 = Point(0, 0, 0);
	point2 = Point(0, 0, 0);
	point3 = Point(0, 0, 0);
}

Triangle::Triangle(const Point &p1,const Point &p2,const Point &p3)
{
    try{
         if (p1 == p2)
    {
        throw EqualPointException("Points 1 and 2 are matching!");
    }
    else if (p2 == p3)
    {
        throw EqualPointException("Points 2 and 3 are matching!");
    }
    else if (p1 == p3)
    {
        throw EqualPointException("Points 1 and 3 are matching!");
    }
    else
    {
        point1 = p1;
        point2 = p2;
        point3 = p3;
    }
    }
    catch( exception& e ){
        cout << e.what() << endl;
    }
   
}

Triangle::Triangle(const Triangle & rhs) :Point(rhs), point1(rhs.point1), point2(rhs.point2), point3(rhs.point3) {}

Triangle::~Triangle(){}

Triangle & Triangle::operator=(const Triangle & rhs)
{
	if (this != &rhs) {
		Point::operator=(rhs);
		point1 = rhs.point1;
		point2 = rhs.point2;
		point3 = rhs.point3;
	}
	return *this;
}

//namirame tipa na triugulnika TODO
int Triangle::findType() const
{

    double angle1, angle2, angle3;

    Vector v1(point1, point2);
    Vector v2(point1, point3);

    angle1 = v1*v2;

    Vector v11(point2, point1);
    Vector v22(point2, point3);

    angle2 = v11*v22;

    Vector v111(point3, point1);
    Vector v222(point3, point2);

    angle3 = v111*v222;

    if (angle1 == angle2 == angle3)
    {
        cout << "Ravnostranen" << endl;
    }
    else if (angle1 == angle2 || angle3 == angle1 || angle3 == angle2)
    {
        cout << "Ravnobedren" << endl;
    }
    else
    {
        cout << "Raznostranen" << endl;
    }

    if (angle1 == 0 || angle2 == 0 || angle3 == 0)
    {
        cout << "Pravougulen" << endl;
    }
    else if (angle1 < 0 || angle2 < 0 || angle3 < 0)
    {
        cout << "Tupougulen" << endl;
    }
    else
    {
        cout << "Ostrougulen" << endl;
    }

    return 0;
}

  //namirame liceto na triugulnika
    double Triangle::findArea() const{ 

        Vector v1(point1, point2);
        Vector v2(point1, point3);

        Vector cross(v1^v2);



        return 0.5 * cross.lenghtOfV();
    }

     //namirame perimetura na triugulnika
    double Triangle::findPerimeter() const{ 
        
        Vector v1(point1, point2);
        Vector v2(point2, point3);
        Vector v3(point1, point3);

        double side1 = v1.lenghtOfV();
        double side2 = v2.lenghtOfV();
        double side3 = v3.lenghtOfV();

        return side1 + side2 + side3;
    }

    //namirame medicentura na triugulnika
    Point Triangle::findMedicenter() const{
        
        double p1 = (point1.getX() + point2.getX() + point3.getX())/3;
        double p2 = (point1.getY() + point2.getY() + point3.getY())/3; 
        double p3 = (point1.getZ() + point2.getZ() + point3.getZ())/3;

        Point medicetner(p1, p2, p3);
 
         return medicetner;
    }

    
    
    std::ostream &operator<<(std::ostream& os,const Triangle& tr){
         os << "Triangle: " <<tr.getA() <<  tr.getB() <<  tr.getC() ;
        return os;
    }

     bool operator==(const Triangle& lhs,const Point& rhs){
         
       
    }

    //operator <Point<Triangle дали лежи в триъгълника
    bool operator<(const Point& lhs, const Triangle& rhs){
        
    }

