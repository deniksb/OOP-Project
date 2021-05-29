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

void TetrahedronMenu() {
	std::cout << "Choose an operation: " << std::endl;
	std::cout << "1-Check if the tetrahedron is regular: " << std::endl;
	std::cout << "2-Check if the tetrahedron is orthogonal: " << std::endl;
	std::cout << "3-Find the surface area of the tetrahedron: " << std::endl;
	std::cout << "4-Find the volume of the tetrahedron: " << std::endl;
}

void MainMenu() {
	std::cout << "Choose a geometric object: " << std::endl;
	std::cout << "1-Point" << std::endl;
	std::cout << "2-Vector" << std::endl;
	std::cout << "3-Line" << std::endl;
	std::cout << "4-Segment" << std::endl;
	std::cout << "5-Triangle" << std::endl;
	std::cout << "6-Tetrahedron" << std::endl;
}

Point GetP2Help(Point &a, double outputArr[], int outInd) {
	std::cin >> a;
	outputArr[outInd] = a.getX();
	outInd++;
	outputArr[outInd] = a.getY();
	outInd++;
	outputArr[outInd] = a.getZ();
	outInd++;

	return a;
}


Vector GetVhelp(Vector &v, double outputArr[], int outInd) {
	std::cin >> v;
	outputArr[outInd] = v.getVectorX();
	outInd++;
	outputArr[outInd] = v.getVectorY();
	outInd++;
	outputArr[outInd] = v.getVectorZ();
	outInd++;
	return v;
}


#endif
