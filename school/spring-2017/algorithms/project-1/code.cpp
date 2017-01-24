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
};

int code::checkCorrect() {

}

int code::checkIncorrect(code c) {

}

void code::randomCode(int n, int m) {
	for (int i = 0; i < n; i++) {
		sequence[i] = rand() % m;
	}
};

//prints the sequence vector
void code::printCode() {
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
}
