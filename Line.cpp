#include "Line.hpp"
using namespace std;
#include <math.h> 

Line::Line(const Point& p,const Vector& v):Vector(v){
    pt = p;
    vc = v;
}

Line::Line(const Point& p1, const Point& p2):Vector(p1,p2){
    Vector vt(p1,p2);
    vc = vt;
    pt = p1;
}

Line::Line(const Line& rhs):Vector(rhs.getVector()){ 
    pt = rhs.getPoint();
    vc = rhs.getVector();
}

Vector Line::findDirection() const{
    return vc;
}

Vector Line::findNormalVector() const{

    if(vc.getVectorZ() < vc.getVectorX()){
        Vector normal(vc.getVectorY(),-(vc.getVectorX()),0);
        return normal;
    }
    else {
        Vector normal(0,-(vc.getVectorZ()),vc.getVectorY());
        return normal;
    }
}

double Line::findAngleBetweenTwoLines(const Line& rhs) const{ 
    Vector v1 = vc;
    Vector v2 = rhs.getVector();

    double cosine = (v1*v2) / ((v1.lenghtOfV()) * (v2.lenghtOfV()));
    double result = acos(cosine);
    return result;
}