// Mary Forde, John Tan
// Project 1

// This file implements the methods of the "response" class

#include"mastermind.h"
using namespace std;

mastermind::mastermind(int n, int m) 
// constructor for "mastermind" class object
// n is the length of the secretCode, and m is the range of values in the code
{
        // initializing the secret code by calling code constructor
    	code secret(n, m);

        // setting our secretCode data member to the newly created code
	secretCode = secret;
}

mastermind::mastermind() 
// constructor for "mastermind" class object
// the length of secretCode is 5, and the range of values in the code is [0,10)
{
	code c(5, 10);
	secretCode = c;
}

void mastermind::printSecretCode() const
// prints the secretCode data member
{
	secretCode.printCode();
}

code mastermind::humanGuess() const 
// reads a guess from the keyboard, returns that guess as a code object
{
	code c(secretCode);
	return c;
}

response mastermind::getResponse(const code &guessCode) const 
// compares the secretCode and the given guessCode and returns a response
{
	response r(secretCode.checkCorrect(guessCode), 
		       secretCode.checkIncorrect(guessCode));
	return r;	
}

bool mastermind::isSolved(response r) const
// returns true if the response indicates that the board has been solved
{
	return r.getCorrect() == secretCode.getLength() && r.getIncorrect() == 0;
}

void mastermind::playGame() 
// prints the secret code, gets a guess from the user, and prints the response
// until the codemaker wins (guesses the code correctly) or loses (runs out of
// the ten available guesses)
{

        // local variables to track state of the game
	int guessesLeft = 10;
	bool isGameWon = false;
	
        // printing out the secret code for testing purposes
	cout << "Secret Code: ";
	printSecretCode();
	
        // variables to track the current guess and correctness of that guess
	code currentGuess;
	response currentResponse;
	
	// iterates until either the user runs out of guesses or the user wins
        // the game
	while(guessesLeft > 0 && !isGameWon)
        {

		// prints the current guess count
		cout << "Guesses left: " << guessesLeft << endl;
		
		// gets a guess from the user
		currentGuess = humanGuess();
		
		// gets the response, prints it
		currentResponse = getResponse(currentGuess);
		cout << currentResponse << endl;
		
		// checks if the game has been won
		isGameWon = isSolved(currentResponse);
	}
	
	// When we get here, the game is over
	if (isGameWon) 
        {
                // isGameWon flag only set if the user guesses correctly
		cout << "Congrats! You won!" << endl;
	}
	else 
        {
                // user loses if they couldn't guess right within 10 guesses
		cout << "You ran out of guesses. You lose." << endl;
	}
	
} // end playGame()
