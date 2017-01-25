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
	
	int length = 5;
	int range = 10;
	
	code secretCode(length, range);
	
	cout << "The secret code has a length of " << length << "." << endl;
	cout << "The secret code has a range of " << range << "." << endl;
	
	cout << "Secret Code: " ;
	secretCode.printCode();
	
	code guessCode1(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode1) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode1) << endl;
	
	code guessCode2(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode2) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode2) << endl;
	
	code guessCode3(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode3) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode3) << endl;

	return 0;
}
