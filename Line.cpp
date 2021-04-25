#include "Line.hpp";
using namespace std;

Line::Line(const Point& p,const Vector& v){
    pt = p;
    vc = v;
}

Line::Line(const Point& p1, const Point& p2){
    Vector vt(p1,p2);
    vc = vt;
    pt = p1;
}

Vector Line::findDirection() const{
    return vc;
}