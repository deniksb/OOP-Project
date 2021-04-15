#include <iostream>
#include "Point.h"
#include "Vector.h"
using namespace std;



int main() {
    cout << "Points:\n\n";

    Point p1;
    cout << "enter for x, y, z \n";
    cin >> p1;
  
    Point p2;
    cout << "enter for x, y, z: \n";
    cin >> p2;

  

    cout << " p1 =" << p1 << " p2 =";
    cout << p2;
    cout << endl;
    
    
    cout << " p1 == p2 ";
    p1 == p2 ? cout << "true" :cout<< "false";
    cout << endl;
    cout << endl;

    cout << "Vectors:";
    cout << endl;
    Vector v1(p1, p2);
    cout << "Vector v1(A,B)";
    cout << endl;

    cout << v1;
    cout << endl;

    Vector v2(3, 4, 1, 5, 0, 2);
    cout << "Vector v2(A,B)";
    cout << endl;

    cout << v2;
    cout << endl;

    cout <<  "v1 |AB| = " << v1.lenghtOfV() << endl;
    cout << "v2 |AB| = " << v2.lenghtOfV();
    cout << endl;
    cout << endl;

    cout << "Direction of vector v2";
    cout << endl;

    cout << "AB direction " << v2.directionOfV();
    cout << endl;
    cout << endl;

    cout << "Is vector v1(A,B) null vector? ";
    cout << endl;
    cout << "Answer: ";
    v1.isNullVector() ? cout << "Yes, it is a null vector." : cout << "No, it is not a null vector.";
    cout << endl;
    cout << endl;
    return 0;
}