#pragma once
#include"Vector.h"

class Line : public Vector {
public:
	Line();
	//������������� ���� ����� � ������
	Line(const Point&, const Vector&);
	//������������� ���� ��� �����
	Line(const Point&, const Point&);

	//copy constructor
	Line(const Line&);

	~Line();

	Line&operator=(const Line &);

	//�������� �������� �� ������� �����
	Vector findDirection() const;

	//�������� ��������� ������ �� �������� �����
	Vector findNormalVector() const;

	//�������� ����� ����� ��� �����
	double findAngleBetweenTwoLines(const Line&) const;

	//+ operator �������� ���� ����� ���� �� ������ �����
	bool operator+(const Point&) const;

	//|| operator �������� ���� ��� ����� �� ���������
	friend bool operator||(const Line&, const Line&);
	//== operator �������� ���� ��� ����� ��������
	friend bool operator==(const Line&,const Line&);
	//operator !=
	friend bool operator!=(const Line &, const Line &);
	//operator| ����������������� �� �����
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
