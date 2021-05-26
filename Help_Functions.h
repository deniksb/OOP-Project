#ifndef _HELP_FUNCTIONS_H
#define _HELP_FUNCTIONS_H
#include<iostream>
#include"Vector.h"

void VectorMenu() {
	std::cout << "Choose an operation: " << std::endl;
	std::cout << "1-Vector length" << std::endl;
	std::cout << "2-Vector direction" << std::endl;
	std::cout << "3-Check null vector" << std::endl;
	std::cout << "4-Check parallel" << std::endl;
	std::cout << "5-Check perpendicular" << std::endl;
	std::cout << "6-Vector sum" << std::endl;
	std::cout << "7-Vector subtract" << std::endl;
	std::cout << "8-Vector product with real number" << std::endl;
	std::cout << "9-Vector dot product" << std::endl;
	std::cout << "10-Vector cross product" << std::endl;
	std::cout << "11-Mixed product" << std::endl;
	std::cout << "12-Projection of vector a on b" << std::endl;
}

void LineMenu() {
	std::cout << "Choose an operation: " << std::endl;
	std::cout << "1-Line direction" << std::endl;
	std::cout << "2-Normal vector" << std::endl;
	std::cout << "3-Angle between lines" << std::endl;
	std::cout << "4-Point on line check" << std::endl;
	std::cout << "5-Are lines parallel?" << std::endl;
	std::cout << "6-Do two lines coincide?" << std::endl;
	std::cout << "7-Check for intersection of lines" << std::endl;
	std::cout << "8-Are the lines crossed?" << std::endl;
	std::cout << "9-Are the lines perpendicular" << std::endl;
}

void TriangleMenu() {
	std::cout << "Choose an operation: " << std::endl;
	std::cout << "1-Find the type of the triangle" << std::endl;
	std::cout << "2-Find the perimeter of the triangle" << std::endl;
	std::cout << "3-Find the area of the triangle" << std::endl;
	std::cout << "4-Find the medicenter of the triangle" << std::endl;
}

Point SetPointHelp(Point&b, double storage[], int elem) {

		b.setX(storage[elem]);
		elem++;
		b.setY(storage[elem]);
		elem++;
		b.setZ(storage[elem]);
		elem++;
	
	return b;
 }

Vector SetVectorHelp(Vector&v,double storage[],int elem) {

	v.setVectorX(storage[elem]);
	elem++;
	v.setVectorY(storage[elem]);
	elem++;
	v.setVectorZ(storage[elem]);
	elem++;

	return v;
}


#endif
