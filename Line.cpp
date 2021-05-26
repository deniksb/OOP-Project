#include "Line.hpp"
using namespace std;
#include <math.h> 

Line::Line():Vector(){
    vc = Vector(0,0,0);
    pt = Point(0,0,0);
}

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

Line::~Line(){}

Line& Line::operator=(const Line & rhs){
    if(this!=&rhs){
        Vector::operator=(rhs);
        vc=rhs.vc;
        pt=rhs.pt;
    }
    return *this;
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

bool Line::operator+(const Point& rhs) const{ 
    double equationX = ((rhs.getX() - pt.getX())/vc.getVectorX());
    double equationY = ((rhs.getY() - pt.getY())/vc.getVectorY());
    double equationZ = ((rhs.getZ() - pt.getZ())/vc.getVectorZ());
    cout << equationX << endl << equationY << endl << equationZ << endl;
    if(equationX == 0 && equationY== 0 && equationZ==0){
        return true;
    }
    else if(equationX == equationY && equationY == equationZ){
        return true;
    }
    else if(isnan(equationX)){
        if(equationY == equationZ){
            return true;
        }
    }
    else if(isnan(equationY)){
        if(equationX == equationZ){
            return true;
        }
    }
        else if(isnan(equationZ)){
        if(equationX == equationY){
            
            return true;
        }
        
    }

    return false;
}

//|| operator проверка дали две прави са успоредни
bool operator||(const Line& lhs,const Line& rhs){ 
    Vector crossProd(lhs.getVector()^rhs.getVector());
    
    //ako e nulev vektor znachi 2ta vektora sa usporedni i ot tam i pravite
    return crossProd.isNullVector();
}
//operator== дали две прави съвпадат
bool operator==(const Line& lhs,const Line& rhs){
    
    Vector v1(lhs.getPoint(),rhs.getPoint());

    if( (lhs.getVector().arePararell(rhs.getVector())) && (v1.arePararell(lhs.getVector()))  && (v1.arePararell(rhs.getVector())) ){
        return true;
    }
    return false;
    

}
//operator&& дали се пресичат
bool operator&&(const Line&lhs, const Line& rhs){
    if(lhs.getPoint()==rhs.getPoint()){
        return true;
    }
    return false;

}

//operator!= дали са кръстосани
bool operator!=(const Line& lhs,const Line& rhs){
    if(!(lhs==rhs) && !(lhs||rhs) && !(lhs&&rhs) ){
        return true;
    }
    return false;
}

//operator | дали са перпендикулярни
bool operator|(const Line& lhs,const Line& rhs){
    if((lhs.getVector()).arePerpendicular(rhs.getVector())){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& lhs,const Line& rhs){
    lhs << "(Vector: " << rhs.getVector() << ", Point:" << rhs.getPoint() << ")" << endl;
    return lhs;
}