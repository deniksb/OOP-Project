#include <iostream>
#include "Point.cpp"

 class Triangle : public Point {
    public:
    Triangle(Point&,Point&,Point&);

    //namirame tipa na triugulnika
    int findType() const;

    //namirame liceto na triugulnika
    double findArea() const;

    //namirame perimetura na triugulnika
    double findPerimeter() const;



    private:
    Point point1,point2,point3;

};