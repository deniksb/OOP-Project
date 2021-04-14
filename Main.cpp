#include <iostream>
#include "Point.cpp"
using namespace std;



int main(){

    Point p1(2.3,4,5);

    Point p2(p1);

     Point p3(2.2,4,5);

    p1==p3;



    return 0;
}

