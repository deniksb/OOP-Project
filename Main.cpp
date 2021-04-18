#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
using namespace std;



int main(){

    Point a(2,2,0);

    Point b(2,-1,0);
    
    

    Point c(-1,2,0);


    Vector vec1(a,b);
    Vector vec2(a,c);

    cout << vec1.findScalarProduct(vec2) << endl;



    return 0;
}

