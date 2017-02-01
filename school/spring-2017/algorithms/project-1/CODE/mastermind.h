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
                
                // Constructors
		mastermind(int n, int m);         // n = length, m = range
		mastermind();			  // n = 5, m = 10 - default
    
                // Public member functions
		void printSecretCode() const;   
		code humanGuess() const;          // retrieves user guess
		response getResponse(const code &guessCode) const;
		bool isSolved(response r) const;  // checks if user won
		void playGame();                  // runs a single mastermind 
                                                  // game
	private:
		code secretCode;                // stores secret code object
};
