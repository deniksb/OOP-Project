#include "Vector.h"

class Line : public Vector {
public:

//инициализация чрез точка и вектор
Line(const Point&,const Vector&);
//инициализация чрез две точки
Line(const Point&, const Point&);

//намираме посоката на правата линия
Vector findDirection() const;


private:
Vector vc;
Point pt;
};
