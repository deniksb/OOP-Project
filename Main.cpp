#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
using namespace std;



int main(){

    Point a(-1,-1,9);

    Point b(3,1,5);
    
    Point c(0,-5,1); 


    // Vector vec1(1,-2,2);
    // Vector vec2(2,-3,0);

    // cout << vec1.findCrossProduct(vec2);

    Triangle tri(a,b,c);
    
    cout << tri.findPerimeter() << endl;

    



    return 0;
}

