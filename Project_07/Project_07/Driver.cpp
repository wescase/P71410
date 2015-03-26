/*
* Author: Westley Case & Morgan Allred
* Assignment: Project 7
* File: Driver.cpp
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written: March 26, 2015
* Description: Manage the memory correctly, overload operators to handle copying objects
*
* I declare the the following source code was written by Wes and Morgan,
* I understand the copying of any source code in whole or in part constitutes cheating,
* and I will recieve a 0 on this assignment if I violate this policy
*/

#include <iostream>
#include "MyVector.h"     
using namespace std;

// the printV function
// used to test the copy constructor
// parameter: a MyVector object
void printV(MyVector);

int main()
{
	cout << "\nCreating a vector Sam of size 4.";
	MyVector sam(4);

	cout << "\nPush 12 values into the vector.";
	for (int i = 0; i < 12; i++)
		sam.push_back(i);

	cout << "\nHere is sam: ";
	cout << sam;
	cout << "\n---------------\n";

	cout << "\nCreating a vector Joe of size 4.";
	MyVector joe(4);
	cout << "\nPush 6 values into the vector.";
	for (int i = 0; i < 6; i++)
		joe.push_back(i * 3);

	cout << "\nHere is joe: ";
	cout << joe;
	cout << "\n---------------\n";

	cout << "\nTest the overloaded assignment operator \"joe = sam\": ";
	joe = sam;

	cout << "\nHere is sam: ";
	cout << sam;
	cout << "\n---------------\n";

	cout << "\nHere is joe: ";
	cout << joe;
	cout << "\n---------------\n";

	// pass a copy of sam by value
	printV(sam);


	cout << endl;
	system("PAUSE");
	return 0;
}

void printV(MyVector v)
{
	cout << "\n--------------------\n";
	cout << "Printing a copy of a vector\n";
	cout << v;
}