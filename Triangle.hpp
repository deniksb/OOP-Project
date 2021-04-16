#include <iostream>
#include "Point.cpp"

 class Triangle : public Point {
    public:
    Triangle(Point&,Point&,Point&);

    //namirame tipa na triugulnika TODO
    int findType() const{

        return 0;
    }



    private:
    Point point1,point2,point3;

};