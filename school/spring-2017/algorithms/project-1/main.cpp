// Mary Forde, John Tan
// Project 1a

// This file initializes a secret code and prints out the result of calling 
// checkCorrect and checkIncorrect for three sample guess codes

#include"code.h"
#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main() 
// Generates a random secret code, then allows user to input 3 separate guesses
// Prints out the secret code, as well as the number of correct and incorrect
// digits for each input guess. The length and range of the codes are
// constrained to 5 and 10, respectively, for this iteration of the program. 
{
	
	//initialize the seed for the random number generator using time
	srand(time(NULL));
	
	int length = 5;
	int range = 10;
	
	code secretCode(length, range);
	
	cout << "The secret code has a length of " << length << "." << endl;
	cout << "The secret code has a range of " << range << "." << endl;
	
	cout << "Secret Code: " ;
	secretCode.printCode();
	
        // User input for guess 1
        cout << endl << "Getting input for first guess..." << endl;
	code guessCode1(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode1) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode1) << endl;
	
        // User input for guess 2
        cout << endl << "Getting input for second guess..." << endl;
	code guessCode2(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode2) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode2) << endl;
	
        // User input for guess 3
        cout << endl << "Getting input for final guess..." << endl;
	code guessCode3(secretCode);
	
	cout << "Number Correct: " << secretCode.checkCorrect(guessCode3) << endl;
	cout << "Number Incorrect: " << secretCode.checkIncorrect(guessCode3) << endl;

	return 0;
}
