#include <iostream>
#include "Triangle.cpp"
#include "Vector.cpp"
#include "Segment.cpp"

using namespace std;



int main(){

    int command;
    do{
        cout << "Choose a geometric object: " << endl;
        cout << "1-Point" << endl;
        cout << "2-Vector" << endl;
        cout << "3-Line" << endl;
        cout << "4-Segment" << endl;
        cout << "5-Triangle" << endl;
        cin >> command;
        if(command == 1){
            cout << "Enter values for the X,Y,Z coordinates of the Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            while(true){
                cout << "Choose an operation: " << endl;
            cout << "1-Compare to another point" << endl;
            cin >> command;
            if(command == 1){
            cout << "Enter values for the X,Y,Z coordinates of the other Point: " << endl;
            Point b;
            cin >> b;
            if(a==b){
                cout << "Points are equal!" << endl;
            }
            else{
                cout << "Points are not equal!";
            }
            cout << "Choose another operation? y/n" << endl;
            char command2;
            cin >> command2;
            if(command2 == 'y'){
                continue;
            }
            else {
                 cout << "Choose another geometric object? y/n" << endl;
                 cin >> command2;
                 if(command2 == 'y'){
                     break;
                 }
                 else{
                     exit(0);
                 }
            }
            }  
            }
          
        }
        else if(command == 2){
            cout << "How do you want to initialize the vector?" << endl;
            cout << "1-Two Points" << endl;
            cout << "2-X,Y,Z coordinates" << endl;
            cin >> command;
            Vector v;
            if(command == 1){
            cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
            Point b;
            cin >> b;
            cout << b << endl;
            Vector v2 (a,b);
            v = v2;
            cout << v << endl;  

            }
            else if(command == 2){
            cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
            Vector v2;
            cin >> v2;
            v = v2;
            cout << v << endl; 
            }
            while(true){
            cout << "Choose an operation: " << endl;
            cout << "1-Vector length" << endl;
            cout << "2-Vector direction" << endl;
            cout << "3-Check null vector" << endl;
            cout << "4-Check parallel" << endl;
            cout << "5-Check perpendicular" << endl;
            cout << "6-Vector sum" << endl;
            cout << "7-Vector subtract" << endl;
            cout << "8-Vector product with real number" << endl;
             cout <<"9-Vector dot product" << endl;
            cout << "10-Vector cross product" << endl;
            cout << "11-Mixed product" << endl;
            cout << "12-Projection of vector a on b" << endl;

            cin >> command;

            switch (command){
                case 1: 
                cout << v.lenghtOfV() << endl;break;
                case 2:
                cout << v.directionOfV() << endl;break;
                case 3:
                if(v.isNullVector()){
                    cout << "It is a null vector." << endl;
                }
                else {
                    cout << "It is not a null vector." << endl;
                }
                break;
                case 4:
                {
                     cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                if(v.arePararell(v2)){
                    cout << "The vectors are parallel." << endl;
                }
                else {
                    cout << "The vectors are not parallel." << endl;
                }
                break; 
                }
               
                case 5: 
                {
                   cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                if(v.arePerpendicular(v2)){
                    cout << "The vectors are perpendicular." << endl;
                }
                else {
                    cout << "The vectors are not perpendicular." << endl;
                }
                break; 
                }
                case 6:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                cout << "Sum: " << v + v2 << endl; 
                }
                case 7:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                cout << "Subtract: " << v - v2 << endl; 
                }
                case 8:
                {
                cout << "Enter a real number:" << endl;
                double Nan;
                cin >> Nan;
                cout << "Product with real number: " << Nan*v << endl; 
                break;
                }
                case 9:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                cout << "Dot product: " << v*v2 << endl; 
                break;
                }
                case 10:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                cout << "Cross product: " << (v^v2) << endl; 
                break;
                }
                case 11:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                cout << "Enter values for the X,Y,Z coordinates of the 3nd Vector: " << endl;
                Vector v3;
                cin >> v3;
                cout << "Mixed product: " << (v(v2,v3)) << endl; 
                break;
                }
                case 12:
                {
                cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
                Vector v2;
                cin >> v2;
                
                cout << "Projection: " << v.Projection(v,v2) << endl; 
                break;
                }

            }
            
            cout << "Choose another operation? y/n" << endl;
            char command2;
            cin >> command2;
            if(command2 == 'y'){
                continue;
            }
            else {
                 cout << "Choose another geometric object? y/n" << endl;
                 cin >> command2;
                 if(command2 == 'y'){
                     break;
                 }
                 else{
                     exit(0);
                 }
            }
            }
             
        }
        else if(command == 3){
            cout << "How do you want to initialize the line?" << endl;
            cout << "1-Two Points" << endl;
            cout << "2-Point and Vector" << endl;
            cin >> command;
            if(command == 1){
            cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
            Point b;
            cin >> b;
            cout << b << endl;

            Line l(a,b);
            cout << l << endl;
            }
            else if(command == 2){
            cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
            Vector b;
            cin >> b;
            cout << b << endl; 
            Line l(a,b);
            cout << l << endl;

            }
        }
        else if(command == 4){
            cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
            Point b;
            cin >> b;
            cout << b << endl;
            Segment s(a,b);
            cout << s << endl;
        }
        else if(command == 5){
             cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
            Point a;
            cin >> a;
            cout << a << endl;
            cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
            Point b;
            cin >> b;
            cout << b << endl;
             cout << "Enter values for the X,Y,Z coordinates of the 3nd Point: " << endl;
            Point c;
            cin >> c;
            cout << c << endl;
            Triangle t(a,b,c);
            cout << t << endl;

        }
           
        
        
        
    }
    while(true);

    

    
    



    return 0;
}

