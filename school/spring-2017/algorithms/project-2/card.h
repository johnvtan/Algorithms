// Mary Forde, John Tan
// Project 2

// This file declares the "card" class, which represents a playing card
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

typedef enum 
// represents a card suit
{
	club, diamond, heart, spade
} suit;

typedef enum 
// represents a card value
{
	ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, 
	king
} value;

class card 
// declares the card class
{
	public:
		// constructors:
		card(suit s, value v);
		card() {}
		// getter methods:
		value getValue() const { return cardVal; }
		suit getSuit() const { return cardSuit; }
		// overloaded cout operator
		friend ostream& operator<< (ostream& ostr, const card& c);
	private:
		// data members:
		suit cardSuit;
		value cardVal;
		
		// setter methods:
		void setValue(value v) { cardVal = v; }
		void setSuit(suit s) { cardSuit = s; }
		
		// helper functions:
		string suitToString() const;
		string valueToString() const;
};


