#include "Vector.h"

class Line : public Vector {
public:

Line();
//инициализация чрез точка и вектор
Line(const Point&,const Vector&);
//инициализация чрез две точки
Line(const Point&, const Point&);

//copy constructor
Line(const Line&);
//destructor
virtual~Line();
//operator= part of big 5
Line& operator=(const Line &);
//намираме посоката на правата линия
Vector findDirection() const;

//намираме нормалния вектор на праватта линия
Vector findNormalVector() const;

//намираме ъгъла между две прави
double findAngleBetweenTwoLines(const Line&) const;

//+ operator проверка дали точка лежи на дадена права
bool operator+(const Point&) const;

//|| operator проверка дали две прави са успоредни
	bool operator||(const Line&)const;
	//== operator проверка дали две прави съвпадат
	bool operator==(const Line&)const;
	//operator !=
	bool operator!=(const Line &)const;
	//operator| перпендикулярност на прави
	bool operator|(const Line&)const;

	bool operator&&(const Line&)const;

//getters
Vector getVector() const{ return vc;}
Point getPoint() const{ return pt;}

//extractor and right shift



private:
Vector vc;
Point pt;
};

std::ostream& operator<<(std::ostream& lhs,const Line& rhs);
