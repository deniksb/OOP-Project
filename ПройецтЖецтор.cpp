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
    cout << " vector v1" << v1;
    cout << endl;

    Vector v2(3, 4, 1, 5, 0, 2);
    cout << " vector v2" << v2;
    cout << endl;

    cout <<  " |v1|= " << v1.lenghtOfV() << endl;
    cout << " |v2| = " << v2.lenghtOfV();
    cout << endl;
    cout << endl;

    cout << "Direction of vector v2" << v2 << endl;
    cout << " __" << endl;
    cout<< " v2" << v2.directionOfV();
    cout << endl;
    cout << endl;

    cout << "Is vector v1" << v1 << " null vector? ";
    cout << endl;
    cout << " Answer: ";
    v1.isNullVector() ? cout << " Yes, it is a null vector." : cout << " No, it is not a null vector.";
    cout << endl;
    cout << endl;
    v1.arePararell(v2) ? cout << "vector v1" << v1 << " and v2"<< v2 << " are pararell": cout << "vector v1" << v1 << " and v2" << v2 << " are NOT pararell";
    cout << endl << endl;
    v1.arePerpendicular(v2) ? cout << "vector v1" << v1 << " and v2" << v2 << " are perpendicular" : cout << "vector v1" << v1 << " and v2" << v2 << " are NOT perpendicular";
    return 0;
}