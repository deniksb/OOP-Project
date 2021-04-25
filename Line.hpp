#include "Vector.h"

class Line : public Vector {
public:

//инициализация чрез точка и вектор
Line(const Point&,const Vector&);
//инициализация чрез две точки
Line(const Point&, const Point&);

//copy constructor
Line(const Line&);

//намираме посоката на правата линия
Vector findDirection() const;

//getters
Vector getVector() const{ return vc;}
Point getPoint() const{ return pt;}


private:
Vector vc;
Point pt;
};
