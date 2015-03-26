/*
* Author: Westley Case & Morgan Allred
* Assignment: Project 7
* File: MyVector.cpp
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written: March 26, 2015
* Description: Manage the memory correctly, overload operators to handle copying objects
*
* I declare the the following source code was written by Wes and Morgan,
* I understand the copying of any source code in whole or in part constitutes cheating,
* and I will recieve a 0 on this assignment if I violate this policy
*/

#include "MyVector.h"

MyVector::MyVector()
{
	mass = 0;
	volume = 0;
	vPointer = nullptr;
}

MyVector::~MyVector()
{
	delete[] vPointer;
	vPointer = nullptr;
}

MyVector::MyVector(int _cap)
{
	mass = 0;
	volume = _cap;
	vPointer = new int[_cap];
}

MyVector::MyVector(const MyVector& ob1)
{
	mass = ob1.mass;
	volume = ob1.volume;
	vPointer = new int[volume];
	
	for (unsigned i = 0; i < mass; i++)
	{
		vPointer[i] = ob1.vPointer[i];
	}
}

MyVector& MyVector::operator=(const MyVector& obj)
{
	if (vPointer != nullptr)
	{
		delete[] vPointer;
	}
		mass = obj.mass;
		volume = obj.volume;
		vPointer = new int[volume];
		for (unsigned i = 0; i < mass; i++)
		{
			vPointer[i] = obj.vPointer[i];
		}
	return *this;
}

int MyVector::size() const
{
	return mass;
}

int  MyVector::capacity() const
{
	return volume;
}

void MyVector::clear()
{
	delete[] vPointer;
	vPointer = nullptr;
	mass = 0;
	volume = 0;
}

void MyVector::push_back(int _newEle)
{
	if (vPointer == nullptr)
	{
		vPointer = new int[DOUBLE];
		volume = DOUBLE;
	}

	// Vector grows if size equals capacity
	else if (mass == volume)
	{
		volume *= DOUBLE;
		int* temp = new int[volume];

		for (int i = 0; i < mass; i++)
		{
			// Copy contents of old array into the new array
			temp[i] = vPointer[i];
		}

		delete[] vPointer;
		vPointer = temp;
	}

	vPointer[mass] = _newEle;
	mass++;
}

int MyVector::at(int _pos)
{
	if (_pos >= mass)
	{
		// Throw exception with the bad index as value
		throw _pos;
	}
	return vPointer[_pos];
}

int MyVector::operator[](int i) const
{
	if (i < volume)
	{
		return vPointer[i];
	}
	return 0;
}

int& MyVector::operator[](int i)
{
	if (i < volume)
	{
		return vPointer[i];
	}
	return i;
}

ostream& operator<<(ostream& out, const MyVector& value)
{
	for (unsigned i = 0; i < value.size(); i++)
	{
		out << value[i];
	}
	return out;
}
// End of file