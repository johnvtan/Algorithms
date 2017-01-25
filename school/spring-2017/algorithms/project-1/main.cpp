// Mary Forde, John Tan
// Project 1a

// This file initializes a secret code and prints out the result of calling 
// checkCorrect and checkIncorrect for three sample guess codes

#include"code.h"
#include<iostream>
#include<vector>
#include"time.h"
#include"stdlib.h"

using namespace std;

int main() 
// the main function
{
	
	//initialize the seed for the random number generator
	srand(time(NULL));
	
	code secretCode(5, 6);
	
	//code guessCode1(5);
	//guessCode1.printCode();
	
	secretCode.printCode();
	
	
	code guessCode(secretCode);
	guessCode.printCode();
	
	cout << "NumCorrect: " << secretCode.checkCorrect(guessCode) << endl;
	
	return 0;
}
