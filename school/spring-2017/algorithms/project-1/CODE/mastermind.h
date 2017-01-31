// Mary Forde, John Tan
// Project 1

#include<iostream>
#include<stdlib.h>
#include"code.h"
#include"response.h"

// This file declares the "mastermind" class

using namespace std;

class mastermind {
	public:
		mastermind(int n, int m); // n = length, m = range
		mastermind();			  // n = 5, m = 10 (needed?)
		void printSecretCode() const;
		code humanGuess() const;
		response getResponse(const code &guessCode) const;
		bool isSolved(response r) const;
		void playGame();
	private:
		code secretCode;
};
