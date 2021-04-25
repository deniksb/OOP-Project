#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
#include "Line.cpp"
using namespace std;



int main(){

    Point a(2,3,4);

    Point b(5,3,0);
    
    Point c(7,2,4); 


    // Vector vec1(1,-2,2);
    // Vector vec2(2,-3,0);

    // cout << vec1.findCrossProduct(vec2);
    Vector v1(1,2,3);
    Vector v2(2,2,2);
    Line l1(a,v1);
    Line l2(b,v2);


    cout << l2+c;


    return 0;
}

