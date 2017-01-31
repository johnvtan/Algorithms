// Mary Forde, John Tan
// Project 1

// This file initializes a secret code and prints out the result of calling 
// checkCorrect and checkIncorrect for three sample guess codes

#include"mastermind.h"
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
	
	int length;
	int range;
	
	// ask the user for length and range
	cout << "Enter the desired length of the secret code: ";
	cin >> length;
	cout << "Enter the desired range of values (0, x]";
	cin >> range;
	
	// 
	mastermind m(length, range);
	
	m.playGame();

	return 0;
}
