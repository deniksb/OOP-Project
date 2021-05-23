#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
#include "Segment.cpp"
using namespace std;



int main(){

    Point a(1,2,3);
    Point b(3,2,1);
    Segment s1(a,b);

    Segment s2;

    s2 = s1;
    
    cout << s2;
   



    return 0;
}

