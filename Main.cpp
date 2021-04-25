#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
#include "Line.cpp"
using namespace std;



int main(){

    Point a(7,6,0);

    Point b(7,8,0);
    
    Point c(1,2,0); 


    // Vector vec1(1,-2,2);
    // Vector vec2(2,-3,0);

    // cout << vec1.findCrossProduct(vec2);

    Line l1(a,b);

    Vector vtest(l1.getVector());

    cout << vtest*l1.findNormalVector();



    



    return 0;
}

