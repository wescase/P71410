/*
* Author: Westley Case & Morgan Allred
* Assignment: Project 7
* File: MyVector.cpp
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written: March 24, 2015
* Description: Manage the memory correctly, overload the 
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
}

MyVector::MyVector(int _cap)
{
	mass = 0;
	volume = _cap;
	vPointer = new int[_cap];
}

MyVector::MyVector(const MyVector& ob1)
{
	if (vPointer != nullptr)
	{
		delete vPointer;
	}

	this->mass = ob1.mass;
	this->volume = ob1.volume;
	vPointer = new int[volume];
}

MyVector& MyVector::operator=(const MyVector& obj)
{
	if (vPointer != nullptr)
	{
		delete vPointer;
	}

	this->mass = obj.mass;
	this->volume = obj.volume;
	vPointer = new int[volume];

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

// End of file