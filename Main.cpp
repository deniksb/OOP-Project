#include <iostream>
#include "Triangle.cpp"
using namespace std;



int main(){

    Point p1(2.3,4,5);

    Point p2(6,7,8);
    
    

    Point p3(2.2,4,5);

    Point p4(p2);

    Triangle(p1,p2,p3);

    cout << p3;



    return 0;
}

