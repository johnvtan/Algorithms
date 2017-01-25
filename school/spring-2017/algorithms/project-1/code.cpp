// Mary Forde, John Tan
// Project 1a

// This file implements the methods of the "code" class

#include<stdlib.h>
#include<vector>
#include<iostream>
#include"code.h"

using namespace std;

//constructor for "code" class object
// n is the length of the code, and m is the range of values in the code
code::code(int n, int m) {
	sequence.resize(n);
	// initializes each of the values randomly, using n and m
	randomCode(n, m);
}

//constructor for the "code" class object
// n is the length of the guess code, then the user inputs the values of the sequence
code::code(int n) {
	// asks the user for input, 
	getGuessCode(n);
}


void code::getGuessCode(int n) {
	sequence.clear();
	
	cout << "Enter your guess code, 1 value at a time." << endl;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val; //ADD INPUT CHECKING
		sequence.push_back(val);
	}
}

// Returns the number of digits which are the correct value and in the correct place
int code::checkCorrect(const code &c) {
	int numCorrect = 0;
	for(int i = 0; i < sequence.size(); i++) {
		if(getIndex(i) == c.getIndex(i)) {
			numCorrect++;
		}
	}
	
	return numCorrect;
}

// Returns the number of digits which are the correct value and in the incorrect place
int code::checkIncorrect(const code &c) {
	return 0;
}

int code::getIndex(int i) const {
	return sequence.at(i);
}

void code::randomCode(int n, int m) {
	for (int i = 0; i < n; i++) {
		sequence[i] = rand() % m;
	}
}

//prints the sequence vector
void code::printCode() {
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
}
