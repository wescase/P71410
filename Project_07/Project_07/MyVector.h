/*
* Author: Westley Case & Morgan Allred
* Assignment: Project 7
* File: MyVector.h
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written:
* Description:
*
* I declare the the following source code was written by Wes and Morgan,
* I understand the copying of any source code in whole or in part constitutes cheating,
* and I will recieve a 0 on this assignment if I violate this policy
*/

#include <string>
#include <iostream>
using namespace std;

// Constants
const int MIN_VALUE = 0;
const char NULL_CHAR = '\0';
const int INI_ARR = 1;
const int DOUBLE = 2;

class MyVector
{
public:

	// Purpose: Creates and initiallizes an empty vector object.
	// Parameters: None
	// Returns: None
	MyVector();

	// Purpose: Deletes the vector object
	// Parameters: None	
	// Returns: None
	~MyVector();

	// Purpose: Creates and initiallizes a vector of a given size.
	// Parameters: Int - capacity of vector
	// Returns: None
	MyVector(int);

// Purpose: 
// Parameters:
// Returns:
MyVector& operator=(const MyVector&);

// Purpose: 
// Parameters:
// Returns:
MyVector(const MyVector&);

	// Purpose: Gives the number of elements in the vector
	// Parameters: none
	// Returns: size - # of elements
	int size() const;

	// Purpose: Gives the number of spaces in the vector
	// Parameters: none
	// Returns: capacity - # of 
	int capacity() const;

	// Purpose: Deletes the array and sets the pointer to null	
	// Parameters: none
	// Returns: none	
	void clear();

	// Purpose: Pushes values into the vector
	// Parameters: int - takes an integer to store
	// Returns: none
	void push_back(int);

	// Purpose: Get the data at a given location in the array
	// Parameters: int - location of the pointer
	// Returns: int value and given location
	int at(int point);
	
private:

	// Variables
	int mass;
	int volume;
	int* vPointer;
};