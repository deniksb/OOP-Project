#pragma once
#include"Vector.h"

class Line : public Vector {
public:
	Line();
	//инициализация чрез точка и вектор
	Line(const Point&, const Vector&);
	//инициализация чрез две точки
	Line(const Point&, const Point&);

	//copy constructor
	Line(const Line&);

	~Line();

	Line&operator=(const Line &);

	//намираме посоката на правата линия
	Vector findDirection() const;

	//намираме нормалния вектор на праватта линия
	Vector findNormalVector() const;

	//намираме ъгъла между две прави
	double findAngleBetweenTwoLines(const Line&) const;

	//+ operator проверка дали точка лежи на дадена права
	bool operator+(const Point&) const;

	//|| operator проверка дали две прави са успоредни
	friend bool operator||(const Line&, const Line&);
	//== operator проверка дали две прави съвпадат
	friend bool operator==(const Line&,const Line&);
	//operator !=
	friend bool operator!=(const Line &, const Line &);
	//operator| перпендикулярност на прави
	friend bool operator|(const Line&, const Line&);

	friend bool operator&&(const Line&, const Line&);

	//getters
	Vector getVector() const { return vc; }
	Point getPoint() const { return pt; }


private:
	Vector vc;
	Point pt;
};
std::ostream& operator<<(std::ostream& lhs, const Line& rhs);
