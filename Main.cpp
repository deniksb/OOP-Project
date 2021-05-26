#include <iostream>
#include <fstream>
#include "Vector.cpp"
#include "Triangle.cpp"
#include "Segment.cpp"
using namespace std;

void printGreetings();

int main()
{

	//file for input
	double storage[100];
	ifstream inputFile;
	inputFile.open("output.txt");
	int count = 0;
	while (!inputFile.eof())
	{
		inputFile >> storage[count];
		count++;
	}

	// for(int i = 0; i < count;i++){
	// 	cout << storage[i] << endl;
	// }

	//file for output
	double outputArr[100];
	fstream outputFile("output.txt", ios::binary | ios::in | ios::out);

	int outInd = 0;

	//изброяваме елементите записани в масива с данни от файла
	int elem = 0;

	int command;

	//FILE MODE = 0 / CONSOLE INPUT MODE = 1
	int mode;
	printGreetings();

	do
	{
		cout << "Select a mode:" << endl;
		cout << "0-File input" << endl;
		cout << "1-Console input" << endl;
		cin >> mode;
		cout << "Choose a geometric object: " << endl;
		cout << "1-Point" << endl;
		cout << "2-Vector" << endl;
		cout << "3-Line" << endl;
		cout << "4-Segment" << endl;
		cout << "5-Triangle" << endl;
		if (mode == 0)
		{
			command = storage[elem];
			elem++;
		}
		else
		{
			cin >> command;
			outputArr[outInd] = command;
			outInd++;
		}
		if (command == 1)
		{

			cout << "Enter values for the X,Y,Z coordinates of the Point: " << endl;
			Point a;
			if (mode == 0)
			{
				a.setX(storage[elem]);
				elem++;
				a.setY(storage[elem]);
				elem++;
				a.setZ(storage[elem]);
				elem++;
			}
			else
			{
				cin >> a;
				outputArr[outInd] = a.getX();
				outInd++;
				outputArr[outInd] = a.getY();
				outInd++;
				outputArr[outInd] = a.getZ();
				outInd++;
			}

			cout << a << endl;
			while (true)
			{
				cout << "Choose an operation: " << endl;
				cout << "1-Compare to another point" << endl;
				if (mode == 0)
				{
					command = storage[elem];
					elem++;
				}
				else
				{
					cin >> command;
					outputArr[outInd] = command;
					outInd++;
				}

				if (command == 1)
				{
					cout << "Enter values for the X,Y,Z coordinates of the other Point: " << endl;
					Point b;
					if (mode == 0)
					{
						b.setX(storage[elem]);
						elem++;
						b.setY(storage[elem]);
						elem++;
						b.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getX();
						outInd++;
						outputArr[outInd] = b.getY();
						outInd++;
						outputArr[outInd] = b.getZ();
						outInd++;
					}
					cout << b << endl;

					if (a == b)
					{
						cout << "Points are equal!" << endl;
					}
					else
					{
						cout << "Points are not equal!";
					}
					cout << "Choose another operation? y/n" << endl;
					char command2;
					cin >> command2;

					if (command2 == 'y')
					{
						mode = 1;
						elem = 0;
						continue;
					}
					else
					{
						cout << "Choose another geometric object? y/n" << endl;
						cin >> command2;
						if (command2 == 'y')
						{
							mode = 1;
							elem = 0;
							break;
						}
						else
						{
							cout << "Would you like to save the last operation? y/n" << endl;
							cin >> command2;
							if (command2 == 'y')
							{
								outputFile.clear();
								for (int i = 0; i < outInd; i++)
								{
									outputFile << outputArr[i] << " ";
								}
								outputFile.close();
							}

							exit(0);
						}
					}
				}
			}
		}
		else if (command == 2)
		{
			cout << "How do you want to initialize the vector?" << endl;
			cout << "1-Two Points" << endl;
			cout << "2-X,Y,Z coordinates" << endl;
			if (mode == 0)
			{
				command = storage[elem];
				elem++;
			}
			else
			{
				cin >> command;
				outputArr[outInd] = command;
				outInd++;
			}

			Vector v;
			if (command == 1)
			{
				cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
				Point a;
				if (mode == 0)
				{
					a.setX(storage[elem]);
					elem++;
					a.setY(storage[elem]);
					elem++;
					a.setZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> a;
					outputArr[outInd] = a.getX();
					outInd++;
					outputArr[outInd] = a.getY();
					outInd++;
					outputArr[outInd] = a.getZ();
					outInd++;
				}

				cout << a << endl;
				cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
				Point b;
				if (mode == 0)
				{
					b.setX(storage[elem]);
					elem++;
					b.setY(storage[elem]);
					elem++;
					b.setZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> b;
					outputArr[outInd] = b.getX();
					outInd++;
					outputArr[outInd] = b.getY();
					outInd++;
					outputArr[outInd] = b.getZ();
					outInd++;
				}

				cout << b << endl;
				Vector v2(a, b);
				v = v2;
				cout << v << endl;
			}
			else if (command == 2)
			{
				cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
				Vector v2;
				if (mode == 0)
				{
					v2.setVectorX(storage[elem]);
					elem++;
					v2.setVectorY(storage[elem]);
					elem++;
					v2.setVectorZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> v2;
					outputArr[outInd] = v2.getVectorX();
					outInd++;
					outputArr[outInd] = v2.getVectorY();
					outInd++;
					outputArr[outInd] = v2.getVectorZ();
					outInd++;
				}

				v = v2;
				cout << v << endl;
			}
			while (true)
			{
				cout << "Choose an operation: " << endl;
				cout << "1-Vector length" << endl;
				cout << "2-Vector direction" << endl;
				cout << "3-Check null vector" << endl;
				cout << "4-Check parallel" << endl;
				cout << "5-Check perpendicular" << endl;
				cout << "6-Vector sum" << endl;
				cout << "7-Vector subtract" << endl;
				cout << "8-Vector product with real number" << endl;
				cout << "9-Vector dot product" << endl;
				cout << "10-Vector cross product" << endl;
				cout << "11-Mixed product" << endl;
				cout << "12-Projection of vector a on b" << endl;

				if (mode == 0)
				{
					command = storage[elem];
					elem++;
				}
				else
				{
					cin >> command;
					outputArr[outInd] = command;
					outInd++;
				}

				switch (command)
				{
				case 1:
					cout << v.lenghtOfV() << endl;
					break;
				case 2:
					cout << v.directionOfV() << endl;
					break;
				case 3:
					if (v.isNullVector())
					{
						cout << "It is a null vector." << endl;
					}
					else
					{
						cout << "It is not a null vector." << endl;
					}
					break;
				case 4:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					if (v.arePararell(v2))
					{
						cout << "The vectors are parallel." << endl;
					}
					else
					{
						cout << "The vectors are not parallel." << endl;
					}
					break;
				}

				case 5:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					if (v.arePerpendicular(v2))
					{
						cout << "The vectors are perpendicular." << endl;
					}
					else
					{
						cout << "The vectors are not perpendicular." << endl;
					}
					break;
				}
				case 6:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					cout << "Sum: " << v + v2 << endl;
					break;
				}
				case 7:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					cout << "Subtract: " << v - v2 << endl;
					break;
				}
				case 8:
				{
					cout << "Enter a real number:" << endl;
					double Nan;
					if (mode == 0)
					{
						Nan = storage[elem];
						elem++;
					}
					else
					{
						cin >> Nan;
						outputArr[outInd] = Nan;
						outInd++;
					}

					cout << "Product with real number: " << Nan * v << endl;
					break;
				}
				case 9:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					cout << "Dot product: " << v * v2 << endl;
					break;
				}
				case 10:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					cout << "Cross product: " << (v ^ v2) << endl;
					break;
				}
				case 11:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}
					cout << "Enter values for the X,Y,Z coordinates of the 3nd Vector: " << endl;
					Vector v3;
					if (mode == 0)
					{
						v3.setVectorX(storage[elem]);
						elem++;
						v3.setVectorY(storage[elem]);
						elem++;
						v3.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v3;
						outputArr[outInd] = v3.getVectorX();
						outInd++;
						outputArr[outInd] = v3.getVectorY();
						outInd++;
						outputArr[outInd] = v3.getVectorZ();
						outInd++;
					}
					cout << "Mixed product: " << (v(v2, v3)) << endl;
					break;
				}
				case 12:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 2nd Vector: " << endl;
					Vector v2;
					if (mode == 0)
					{
						v2.setVectorX(storage[elem]);
						elem++;
						v2.setVectorY(storage[elem]);
						elem++;
						v2.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> v2;
						outputArr[outInd] = v2.getVectorX();
						outInd++;
						outputArr[outInd] = v2.getVectorY();
						outInd++;
						outputArr[outInd] = v2.getVectorZ();
						outInd++;
					}

					cout << "Projection: " << v.Projection(v, v2) << endl;
					break;
				}
				}

				cout << "Choose another operation? y/n" << endl;
				char command2;
				cin >> command2;
				if (command2 == 'y')
				{
					mode = 1;
					elem = 0;
					continue;
				}
				else
				{
					cout << "Choose another geometric object? y/n" << endl;
					cin >> command2;
					if (command2 == 'y')
					{
						mode = 1;
						elem = 0;
						break;
					}
					else
					{
						cout << "Would you like to save the last operation? y/n" << endl;
						cin >> command2;
						if (command2 == 'y')
						{
							outputFile.clear();
							for (int i = 0; i < outInd; i++)
							{
								outputFile << outputArr[i] << " ";
							}
							outputFile.close();
						}

						exit(0);
					}
				}
			}
		}
		else if (command == 3)
		{
			cout << "How do you want to initialize the line?" << endl;
			cout << "1-Two Points" << endl;
			cout << "2-Point and Vector" << endl;
			if (mode == 0)
			{
				command = storage[elem];
				elem++;
			}
			else
			{
				cin >> command;
				outputArr[outInd] = command;
				outInd++;
			}

			Line l;
			if (command == 1)
			{
				cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
				Point a;
				if (mode == 0)
				{
					a.setX(storage[elem]);
					elem++;
					a.setY(storage[elem]);
					elem++;
					a.setZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> a;
					outputArr[outInd] = a.getX();
					outInd++;
					outputArr[outInd] = a.getY();
					outInd++;
					outputArr[outInd] = a.getZ();
					outInd++;
				}
				cout << a << endl;
				cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
				Point b;
				if (mode == 0)
				{
					b.setX(storage[elem]);
					elem++;
					b.setY(storage[elem]);
					elem++;
					b.setZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> b;
					outputArr[outInd] = b.getX();
					outInd++;
					outputArr[outInd] = b.getY();
					outInd++;
					outputArr[outInd] = b.getZ();
					outInd++;
				}
				cout << b << endl;

				Line l2(a, b);
				l = l2;
				cout << l << endl;
			}
			else if (command == 2)
			{
				cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
				Point a;
				if (mode == 0)
				{
					a.setX(storage[elem]);
					elem++;
					a.setY(storage[elem]);
					elem++;
					a.setZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> a;
					outputArr[outInd] = a.getX();
					outInd++;
					outputArr[outInd] = a.getY();
					outInd++;
					outputArr[outInd] = a.getZ();
					outInd++;
				}
				cout << a << endl;
				cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
				Vector b;
				if (mode == 0)
				{
					b.setVectorX(storage[elem]);
					elem++;
					b.setVectorY(storage[elem]);
					elem++;
					b.setVectorZ(storage[elem]);
					elem++;
				}
				else
				{
					cin >> b;
					outputArr[outInd] = b.getX();
					outInd++;
					outputArr[outInd] = b.getY();
					outInd++;
					outputArr[outInd] = b.getZ();
					outInd++;
				}
				cout << b << endl;
				Line l2(a, b);
				l = l2;
				cout << l << endl;
			}
			while (true)
			{
				cout << "Choose an operation: " << endl;
				cout << "1-Line direction" << endl;
				cout << "2-Normal vector" << endl;
				cout << "3-Angle between lines" << endl;
				cout << "4-Point on line check" << endl;
				cout << "5-Are lines parallel?" << endl;
				cout << "6-Do two lines coincide?" << endl;
				cout << "7-Check for intersection of lines" << endl;
				cout << "8-Are the lines crossed?" << endl;
				cout << "9-Are the lines perpendicular" << endl;

				if (mode == 0)
				{
					command = storage[elem];
					elem++;
				}
				else
				{
					cin >> command;
					outputArr[outInd] = command;
					outInd++;
				}

				switch (command)
				{
				case 1:
					cout << l.findDirection() << endl;
					break;
				case 2:
					cout << l.findNormalVector() << endl;
					break;
				case 3:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					cout << l.findAngleBetweenTwoLines(l2) << endl;
					break;
				}
				case 4:
				{
					cout << "Enter values for the X,Y,Z coordinates of the Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					if (l + a)
					{
						cout << "The point is on the line!" << endl;
					}
					else
					{
						cout << " The point is not on the line" << endl;
					}
					break;
				}
				case 5:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					if (l || l2)
					{
						cout << "The lines are parallel\n";
					}
					else
						cout << "The lines are not parallel\n";
					break;
				}
				case 6:
				{

					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					if (l == l2)
					{
						cout << "The lines coincide!\n";
					}
					else
						cout << "The lines do not coincide!\n";
					break;
				}
				case 7:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					if (l && l2)
					{
						cout << "The lines intersect!\n";
					}
					else
						cout << "The lines do not intersect!\n";
					break;
				}
				case 8:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					if (l != l2)
					{
						cout << "The lines are crossed!\n";
					}
					else
						cout << "The lines are not crossed!\n";
					break;
				}
				case 9:
				{
					cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					cout << "Enter values for the X,Y,Z coordinates of the Vector: " << endl;
					Vector b;
					if (mode == 0)
					{
						b.setVectorX(storage[elem]);
						elem++;
						b.setVectorY(storage[elem]);
						elem++;
						b.setVectorZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> b;
						outputArr[outInd] = b.getVectorX();
						outInd++;
						outputArr[outInd] = b.getVectorY();
						outInd++;
						outputArr[outInd] = b.getVectorZ();
						outInd++;
					}
					cout << b << endl;
					Line l2(a, b);
					if (l | l2)
					{
						cout << "The lines are perpendicular!\n";
					}
					else
						cout << "The lines are not perpendicular!\n";
					break;
				}
				}
				cout << "Choose another operation? y/n" << endl;
				char command2;
				cin >> command2;
				if (command2 == 'y')
				{
					mode = 1;
					elem = 0;
					continue;
				}
				else
				{
					cout << "Choose another geometric object? y/n" << endl;
					cin >> command2;
					if (command2 == 'y')
					{
						elem = 0;
						mode = 1;
						break;
					}
					else
					{
						cout << "Would you like to save the last operation? y/n" << endl;
						cin >> command2;
						if (command2 == 'y')
						{
							outputFile.clear();
							for (int i = 0; i < outInd; i++)
							{
								outputFile << outputArr[i] << " ";
							}
							outputFile.close();
						}

						exit(0);
					}
				}
			}
		}
		///////////
		else if (command == 4)
		{
			Segment s;
			cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
			Point a;
			if (mode == 0)
			{
				a.setX(storage[elem]);
				elem++;
				a.setY(storage[elem]);
				elem++;
				a.setZ(storage[elem]);
				elem++;
			}
			else
			{
				cin >> a;
				outputArr[outInd] = a.getX();
				outInd++;
				outputArr[outInd] = a.getY();
				outInd++;
				outputArr[outInd] = a.getZ();
				outInd++;
			}
			cout << a << endl;
			cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
			Point b;
			if (mode == 0)
			{
				b.setX(storage[elem]);
				elem++;
				b.setY(storage[elem]);
				elem++;
				b.setZ(storage[elem]);
				elem++;
			}
			else
			{
				cin >> b;
				outputArr[outInd] = b.getX();
				outInd++;
				outputArr[outInd] = b.getY();
				outInd++;
				outputArr[outInd] = b.getZ();
				outInd++;
			}
			cout << b << endl;
			Segment s2(a, b);
			s = s2;
			cout << s << endl;

			while (true)
			{
				cout << "Choose an operation: " << endl;
				cout << "1-Segment length" << endl;
				cout << "2-Find the middle of a segment" << endl;
				cout << "3-Check if a point is on the Segment" << endl;
				if (mode == 0)
				{
					command = storage[elem];
					elem++;
				}
				else
				{
					cin >> command;
					outputArr[outInd] = command;
					outInd++;
				}

				switch (command)
				{
				case 1:
					cout << s.findLength() << endl;
					break;
				case 2:
					cout << s.findCenter() << endl;
					break;
				case 3:
				{
					cout << "Enter values for the X,Y,Z coordinates of the Point: " << endl;
					Point a;
					if (mode == 0)
					{
						a.setX(storage[elem]);
						elem++;
						a.setY(storage[elem]);
						elem++;
						a.setZ(storage[elem]);
						elem++;
					}
					else
					{
						cin >> a;
						outputArr[outInd] = a.getX();
						outInd++;
						outputArr[outInd] = a.getY();
						outInd++;
						outputArr[outInd] = a.getZ();
						outInd++;
					}
					cout << a << endl;
					if (s == a)
					{
						cout << "The point is on the segment!\n";
					}
					else
						cout << "The point is not on the segment!\n";
					break;
				}
				}
				cout << "Choose another operation? y/n" << endl;
				char command2;
				cin >> command2;
				if (command2 == 'y')
				{
					mode = 1;
					elem = 0;
					continue;
				}
				else
				{
					cout << "Choose another geometric object? y/n" << endl;
					cin >> command2;
					if (command2 == 'y')
					{
						elem = 0;
						mode = 1;
						break;
					}
					else
					{
						cout << "Would you like to save the last operation? y/n" << endl;
						cin >> command2;
						if (command2 == 'y')
						{
							outputFile.clear();
							for (int i = 0; i < outInd; i++)
							{
								outputFile << outputArr[i] << " ";
							}
							outputFile.close();
						}

						exit(0);
					}
				}
			}
		}
		//Triangle TODO file input and output
		else if (command == 5)
		{
			cout << "Enter values for the X,Y,Z coordinates of the 1st Point: " << endl;
			Point a;
			cin >> a;
			cout << a << endl;
			cout << "Enter values for the X,Y,Z coordinates of the 2nd Point: " << endl;
			Point b;
			cin >> b;
			cout << b << endl;
			cout << "Enter values for the X,Y,Z coordinates of the 3nd Point: " << endl;
			Point c;
			cin >> c;
			cout << c << endl;
			Triangle t(a, b, c);
			cout << t << endl;
		}

	} while (true);

	inputFile.close();
	outputFile.close();
	return 0;
}

void printGreetings()
{
	cout << R"(
 ____   _____   ___   _______  _   _  ___      _______ 
| ___ \/ _ \ \ / / | / /  _  || | | |/ _ \    / /____ |
| |_/ / /_\ \ V /| |/ /| | | || | | / /_\ \  / /    / /
|    /|  _  |\ / |    \| | | || | | |  _  | < <     \ \
| |\ \| | | || | | |\  \ \_/ /\ \_/ / | | |  \ \.___/ /
\_| \_\_| |_/\_/ \_| \_/\___/  \___/\_| |_/   \_\____/)"
		 << '\n';
}
