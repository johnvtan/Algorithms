// Mary Forde, John Tan
// Project 1a

// This file implements the methods of the "code" class

#include<stdlib.h>
#include<vector>
#include<iostream>
#include"code.h"

using namespace std;

code::code(int n, int m)
// constructor for "code" class object
// n is the length of the code, and m is the range of values in the code
{
	
	// initialize the length and range 
	length = n;
	range = m;
	
	// resize sequence to size n
	sequence.resize(length);
	
	// initializes each of the values randomly, using n and m
	randomCode();
	
} // end code constructor

code::code(const code &secretCode) 
// constructor for the "code" class object, where "n" is the length of the
// guess code, then the user inputs the values of the sequence
{
	length = secretCode.getLength();
	range = secretCode.getRange();
	
	// asks the user for input, and sets the sequence to that input
	getGuessCode();	
	
} // end code constructor

void code::getGuessCode() 
// gets the values of sequence from the user (their guess code)
{
	
	// empties the sequence of it's current values, so new values can be
        // added
	sequence.clear();
	
	// prompt the user for their guess code, 1 value at a time
	cout << "Enter your guess code, 1 value at a time." << endl;
	
	// iterate until enough values have been added to sequence
	for (int i = 0; i < length; i++)
	{
		cout << "Value " << i + 1 << ": ";
		
		int val;
		cin >> val;
		
		// if the entered value is not an integer
		if (cin.fail()) 
		{
			cout << "Invalid input. Enter an integer value." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			i--;
		}
		
		// if the entered value is out of bounds
		else if (val < 0 || val >= range) 
		{
			cout << "Value entered is out of range" << endl;
			cout << "Enter another value, between 0 and " << range - 1 << endl;
			i--;
		}

                // otherwise, the input value is valid and we add it to the vector
		else 
		{
			sequence.push_back(val);
		}
	}
	
} // end getGuessCode 

int code::checkCorrect(const code &c) const
// Returns the number of digits which are the correct value and in the correct 
// place
{
	
	//initialize numCorrect to 0
	int numCorrect = 0;
	
	// iterate through each code, calculate the number of values that are equal
	// and at the same index
	for (int i = 0; i < sequence.size(); i++) 
	{
		if (getIndex(i) == c.getIndex(i)) 
		{
			numCorrect++;
		}
	}
	
	return numCorrect;
	
} // end checkCorrect

int code::checkIncorrect(const code &c) const
// Returns the number of digits which are the correct value and in the 
// incorrect place
{
	
	// create shadow copies of both sequences
	vector<int> secretSequence(sequence);
	vector<int> guessSequence(c.getSequence());
	
	int numIncorrect = 0; // the number correct, to be returned
	
	// index points of both sequences - used for iterating
	int secretI = 0;
	int guessI = 0;
	
	// contains the indexes of the guesses that have already been looked at
	vector<int> checkedGuessIndexes;
	
	
        // tracks if the current index of the guess code was already matched
	bool checkedAlready = false;
	
	// increment through the sequences until we reach the end of either sequence
	while (secretI < length) 
	{
		// goes through checkedGuessIndexes to see if guessI has been checked
		for (int i = 0; i < checkedGuessIndexes.size(); i++) 
		{
			if (checkedGuessIndexes[i] == guessI)
			{
                
                                // we set this true so that we skip the section below
                                // and prevent double counting
				checkedAlready = true;
			}	
		}
		
                // if we haven't matched this index of the guess code already
		if (!checkedAlready) 
		{
		
                	// if the two values are equal
			if (secretSequence[secretI] == guessSequence[guessI]) 
			{
                
                                // first we want to increment our numIncorrect count
				numIncorrect++;

                                // then move on to the next value in the secret code
				secretI++;

                                // then we append the guess index onto the checked vector to 
                                // prevent double counting
				checkedGuessIndexes.push_back(guessI);

                                // reset the guess code index to start at the beginning again
				guessI = 0;	
			}
			
			// if the two values are not equal
			else 
			{

                                // move on to the next guess code value
				guessI++;
				
                                // if we've reached the end of the guess code and we haven't
                                // found a match
				if (guessI >= guessSequence.size()) {

                                        // reset guess code index to beginning
					guessI = 0;

                                        // move on to the next value in the secret code
					secretI++;
				}
			}
		}
		
                // if we have matched this index of the guess code
		else 
                {
                        // move on to the next value in the guess code 
			guessI++;

                        // reset to false to be ready for next cycle
			checkedAlready = false;
		}
		
	}
	
        // we have to subtract the number of values in the correct place since otherwise
        // we're double counting the correct count using this method
	return numIncorrect - checkCorrect(c); 
} // end guessIncorrect

int code::getIndex(int i) const 
// returns the value of the sequence at index "i"
{
	return sequence.at(i);
}

void code::randomCode() 
// initializes sequence with length of "n" and random value in range of [0:m) 
{
	
	// iterates until "n" values are assigned
	for (int i = 0; i < length; i++) 
	{
		sequence[i] = rand() % range;
	}
	
}

void code::printCode() const
// prints the sequence vector, separating values by spaces on a single line
{
	
	// iterates through sequence vector
	for (int i = 0; i < length; i++) 
	{
		cout << sequence[i] << " ";
	}
	
	cout << endl;
	
} // end printCode

int code::getLength() const
// returns the length data member
{
	return length;
}

int code::getRange() const
// returns the range data member
{
	return range;
}

vector<int> code::getSequence() const
// returns the sequence data member
{
	return sequence;
}
