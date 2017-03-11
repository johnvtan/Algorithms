// Mary Forde, John Tan
// Project 2

// This file implements the methods of the global playFlip function

#include"deck.h"
#include<time.h>
#include<vector>

using namespace std;

//declare helper methods
bool checkIfEndGame();
int getValidIndex();
bool indexNotChosen(int index, vector<int>& indexesChosen);
int scoreCard(const card& c, int currScore);

void playFlip() 
// implementation for the global function 'playFlip'
{
	// random seed
	srand(time(NULL));
	
	// initialize a standard deck
	deck d;
	
	// shuffle three times
	d.shuffle();
	d.shuffle();
	d.shuffle();
	
	// player's score
	int playerScore = 0;
		
	// deal 24 cards to a new deck
	// create the new deck with just the top card
	deck playerHand(d.deal()); //first card
	 
	for(int i = 0; i < 23; i++) 
	// deals next 23 cards
	{
		playerHand.replace(d.deal());
	}
	
	cout << "Top 24 cards: " << endl << playerHand << endl;
	cout << "Remaining deck (without top 24 cards): " << endl << d << endl << endl;
	
	int flipOrEndGameChoice;
	int cardIndexChoice;
	card chosenCard;
	
	vector<int> chosenCards;
	
	while (!checkIfEndGame())
	{
		cout << "Top 24 cards: " << endl << playerHand << endl;
		
		while (true) {
			
			cardIndexChoice = getValidIndex();
			
			if (indexNotChosen(cardIndexChoice, chosenCards)) 
			{
				break;
			}
			else 
			{
				cout << "You already chose the card at that index. Choose again." << endl;	
			}
		}
		
		chosenCard = playerHand.atIndex(cardIndexChoice);
		cout << endl << "Your chosen card: " << chosenCard;
		
		playerScore = scoreCard(chosenCard, playerScore);
		
		cout << "Your current score is: " << playerScore << endl << endl;
	}
	
	// when game over
	cout << endl << "Game over. Your score is: " << playerScore << endl;
}

bool checkIfEndGame()
// gives the player the choice to flip another card or end the game
// keeps running until a valid response is given
// returns true if choice is to end game, false if choice is to keep playing
{
	int response;
	
	while(true) 
	// Give the user a choice between flipping a card and ending the game
	{			
		cout << "Please enter '1' if you want to flip a card or '2' if you "
			 << "want to end the game: ";	
			 
		cin >> response;
		
		// if the entered value is not an integer, or is an invalid value
		if (cin.fail() || (response != 1  && response != 2)) 
		{
			cout << "Invalid input. Please enter '1' or '2': ";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			return response == 2; // returns true if choice was 2, to end game
		}
	}
}

int getValidIndex()
// keeps running until a valid index for a deck of 24 cards is given
// returns that index
{
	int response;
	
	while (true)
	{				
		cout << "Please input the index of the card you wish to flip, "
			 << "between 0 and 23: ";
			 
		cin >> response;
		
		if (cin.fail() || (response < 0 || response > 23))
		{
			cout << "Invalid input. Please enter an integer between 0 "
				 << "and 23: ";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else
		{
			return response;
		}
	}
}

bool indexNotChosen(int index, vector<int>& indexesChosen)
// returns true if the index is not in the vector, then adds the index to the vector
// returns false if the index is already in the vector
{
	for(int i = 0; i < indexesChosen.size(); i++)
	{
		if (indexesChosen[i] == index)
		{
			return false;
		}	
	}
	
	//if it iterates through without returning 'false', then the index isn't in the vector
	indexesChosen.push_back(index);
	return true;
}

int scoreCard(const card& c, int currScore) 
// returns the new score, given the current score and the card that was just flipped
{
	suit cardSuit = c.getSuit();
	value cardValue = c.getValue();
	
	cout << "For your card value: ";
	
	switch(cardValue) 
	{
		case ace:
			cout << "Score increased by 10." << endl;
			currScore += 10;
			break;
		case two:
		case three:
		case four:
		case five:
		case six:
			cout << "You lost all your points." << endl;
			currScore = 0;
			break;
		case seven:
			cout << "You lost half your points." << endl;
			currScore = currScore / 2;
			break;
		case eight:
		case nine:
		case ten:
			cout << "Your score is unchanged." << endl;
			break;
		case jack:
		case queen:
		case king:
			cout << "Your score increased by 5." << endl;
			currScore += 5;
			break;
		default:
			// shouldn't get here because enum
			break;
	}
	
	cout << "For your card suit: ";
	
	if (cardSuit == heart) 
	{
		cout << "You receive 1 extra point." << endl;
		currScore += 1;
	}
	else 
	{
		cout << "You receive no extra points." << endl;
	}
	
	return currScore;
}
