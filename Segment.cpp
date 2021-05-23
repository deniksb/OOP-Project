#include "Segment.hpp"
using namespace std;

Segment::Segment():Line(){
    a = Point(0,0,0);
    b = Point(0,0,0);
}

Segment::Segment(const Segment& rhs):Line(rhs){
    a = rhs.a;
    b = rhs.b;
}

Segment::Segment(Point p1,Point p2):Line(){
a = p1;
b = p2;
}

Segment::~Segment(){}

Segment& Segment::operator=(const Segment& rhs){
    a = rhs.a;
    b = rhs.b;
}



double Segment::findLength() const { 
    
    Vector v (a,b);

    return v.lenghtOfV();
}

Point Segment::findCenter() const{

    int x =  (a.getX() + b.getX())/2;
    int y =  (a.getY() + b.getY())/2;
    int z =  (a.getZ() + b.getZ())/2;

    Point center(x,y,z);
    return center;
}

 std::ostream &operator<<(std::ostream& os,const Segment& rhs){

     os << rhs.getPointA() << rhs.getPointB() << endl;
    return os;
    
 }


// ░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄
// ░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄
// ░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█
// ░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░█
// ░▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░█
// █▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒█
// █▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█
// ░█▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█
// ░░█░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█
// ░░░█░░██░░▀█▄▄▄█▄▄█▄████░█
// ░░░░█░░░▀▀▄░█░░░█░███████░█
// ░░░░░▀▄░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█
// ░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░█
// ░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░█
// ░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░█ Problem?

