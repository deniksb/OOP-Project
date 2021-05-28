#include <iostream>
#include "Point.cpp"

 class Triangle : public Point {
    public:
    //big 5 rule
    Triangle();
    Triangle(const Point&,const Point&,const Point&);
    Triangle(const Triangle &);
    virtual~Triangle();
    Triangle& operator=(const Triangle &);

    //namirame tipa na triugulnika
    int findType() const;

    //namirame liceto na triugulnika
    double findArea() const;

    //namirame perimetura na triugulnika
    double findPerimeter() const;

    //namirame medicentura na triugulnika
    Point findMedicenter() const;

    //operator == Point==Triangle
    friend bool operator==(const Triangle& lhs,const Point& rhs);

      //operator <Point<Triangle дали лежи в триъгълника
    friend bool operator<(const Point& lhs, const Triangle& rhs);

    //getters for the 3 points of the triangle
    Point getA() const{
        return point1;
    }
    Point getB() const{
        return point2;
    }
    Point getC() const{
        return point3;
    }




    private:
    Point point1,point2,point3;

};

 std::ostream &operator<<(std::ostream&,const Triangle&);