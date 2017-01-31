// Mary Forde, John Tan
// Project 1

// This file implements the methods of the "response" class
#include<iostream>
#include"response.h"

using namespace std;

response::response(int c, int i) 
// constructor for "response" class object
// c is the number correct, and i is the number incorrect
{
	setCorrect(c);
	setIncorrect(i);
}

void response::setCorrect(int x) 
// setter function for the "response" class's numCorrect data member
{
	numCorrect = x;
}

void response::setIncorrect(int x)
// setter function for the "response" class's numIncorrect data member
{
	numIncorrect = x;
}

int response::getCorrect()
// getter function for the "response" class's numCorrect data member
{
	return numCorrect;
}

int response::getIncorrect()
// getter function for the "response" class's numIncorrect data member
{
	return numIncorrect;
}

ostream& operator<< (ostream& ostr, const response& r)
// the friend operator overloader which overloads the operator "<<" for a response
{
	ostr << "Number Correct: " << r.numCorrect << endl
		 << "Number Incorrect: " << r.numIncorrect << endl;
		 
	return ostr;
}
