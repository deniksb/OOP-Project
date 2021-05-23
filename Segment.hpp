#include "Line.cpp"

class Segment : public Line {
public:
//constructors
Segment();

Segment(Point,Point);

Segment(const Segment&);

//destructor
~Segment();

Segment& operator=(const Segment&);

double findLength() const;

Point findCenter() const;

bool operator==(const  Point& rhs) const{
    Vector ab(a,b);
    double t1 = (rhs.getX() - a.getX()) / ab.getVectorX(); 
    cout << t1 << endl;
    double t2 = (rhs.getY() - a.getY()) / ab.getVectorY(); 
    cout << t2 << endl;
    double t3 = (rhs.getZ() - a.getZ()) / ab.getVectorZ();
    cout << t3 << endl;
    
    if(((t1 >= 0 && t1 <= 1) || isnan(t1))  && ((t2 >= 0 && t2 <= 1) || isnan(t2)) && ((t3 >= 0 && t3 <= 1) || isnan(t3))){
        return true;
    }
    return false;  
    
}

Point getPointA() const{
    return a;
}

Point getPointB() const{
    return b;
}




private:
Point a;
Point b;
const double tBegin = 0;
const double tEnd = 1;
};

//overloading operator <<
 std::ostream &operator<<(std::ostream&,const Segment&);